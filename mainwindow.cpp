#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PlanetList = NULL;
    timer = new QTimer(this);
    timer->stop();
    timer->setInterval(50);
    GridOn = true;

    //QPixmap pix("kosmos.jpg" );
    //ui->BackPicture->setPixmap(pix);
    //ui->BackPicture->setStyleSheet("background:transparent;");

    connect(ui->mnReadConfigFile, SIGNAL(triggered()), this, SLOT(stReadConfigFile())); // чтение файла конфигурации
    connect(ui->mnNewPlanet, SIGNAL(triggered()), this, SLOT(stNewPlanet()));           // новый объект
    connect(ui->mnStartStop, SIGNAL(triggered()), this, SLOT(stStartStopAnimation()));  // старт,стоп анимация
    connect(ui->mnGridOnOff, SIGNAL(toggled(bool)), this, SLOT(stGridOnOff(bool)));     // сетка
    connect(this->timer,SIGNAL(timeout()),this,SLOT(stStepModelling()));                // таймер

}

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dgDialog)
{
    ui->setupUi(this);
  //  connect(ui->buttonBox->Ok, SIGNAL(triggered()), this, SLOT(stOkNewPlanet()));
}

basePlanet* MyDialog::OkNewPlanet(){  // Нажатие Ок в диалоговом окне "Добавленияя нового объекта"
    basePlanet *Px;
    QString msg;
    QPalette plt_err = ui->edAlph->palette();
    QPalette plt_norm = ui->edAlph->palette();

    plt_err.setColor(QPalette::Base, Qt::red);
    plt_norm.setColor(QPalette::Base, Qt::white);


    if( ui->edPlanetName->text().length() == 0 ){
        msg = tr("Difine Planet name\n");
        ui->edPlanetName->setPalette(plt_err);
    }
    else{
        ui->edPlanetName->setPalette(plt_norm);
    }

    if( ui->edWeight->text().toFloat()<=0 ){
        msg = msg + tr("Difine positive Planet Weight\n");
        ui->edWeight->setPalette(plt_err);
    }
    else{
        ui->edWeight->setPalette(plt_norm);
    }

    if( ui->edSize->text().toFloat()<=0 ){
        msg = msg + tr("Difine positive Planet Size\n");
        ui->edSize->setPalette(plt_err);
    }
    else{
        ui->edSize->setPalette(plt_norm);
    }

    if( ui->edRadius->text().toFloat()<=0 ){
        msg = msg + tr("Difine positive Planet orbit Radius\n");
        ui->edRadius->setPalette(plt_err);
    }
    else{
        ui->edRadius->setPalette(plt_norm);
    }

    if( fabs( ui->edOmega->text().toFloat() ) >0.5 ){
        msg = msg + tr("Difine Planet orbit rotation < 0.5\n");
        ui->edOmega->setPalette(plt_err);
    }
    else{
        ui->edOmega->setPalette(plt_norm);
    }

    if( ui->edAlph->text().toFloat()<=0 ){
        msg = msg + tr("Difine Planet orbit Angle\n");
        ui->edAlph->setPalette(plt_err);
    }
    else{
        ui->edAlph->setPalette(plt_norm);
    }

    QString s_col1, s_col = ui->edColor->text();
    for( int i=0; i<s_col.length(); i+=2 ){
        QString tmp = s_col.mid(i,2);
        s_col1 = tmp + s_col1;
    }

    bool Ok;
    int col = s_col1.toInt(&Ok,16);
    if( !Ok ){
        msg = msg + tr("Difine Planet color RGB(hex)");
        ui->edColor->setPalette(plt_err);
    }
    else{
        ui->edColor->setPalette(plt_norm);
    }
    if( msg.isEmpty() == false ){
        QMessageBox::warning(this, tr("MyDialog Exit"), msg );
        return NULL;
    }


    Px = new RotPlanet( ui->edPlanetName->text(),
                        ui->edWeight->text().toFloat(),
                        ui->edSize->text().toFloat(),
                        0.0,0.0,0.0,
                        ui->edRadius->text().toFloat(),
                        ui->edOmega->text().toFloat(),
                        ui->edAlph->text().toFloat(),
                        col );
    return Px;
}

MyDialog::~MyDialog(){
    delete ui;
    QMessageBox::information(this, tr("MyDialog Exit"),
                        tr("Destructor MyDialog."));

}


void MainWindow::stStepModelling(){
    listEl *tmp = PlanetList;
    int i1,i2;
    while( tmp ){
        tmp->dPlanet->move();
        if( tmp->satlt ){
            listSat *tt = tmp->satlt;
            while( tt ){
                tt->dPlanet->moveSatlt( tmp->dPlanet );
                tt = tt->next;
            }
        }

        tmp = tmp->next;
    }
    i1 = 0;
    tmp = PlanetList;
    QString db;
    while( tmp ){
        i1++;
        Planet *Px = (Planet*) (tmp->dPlanet);
        db = db + Px->getName() +
                  Px->getsPos() + QString( " [%1]\n" ).arg(i1);
//                  Px->getsVel() + "\n";

        listSat *tmp_sat = tmp->satlt;
        i2=0;
        while( tmp_sat ){
            i2++;
            Planet *Px = (Planet*) (tmp_sat->dPlanet);
            db = db + Px->getName() +
                      Px->getsPos() + QString( "[%1 %2]\n").arg(i1).arg(i2);
            tmp_sat = tmp_sat->next;
        }
        tmp = tmp->next;
    }
    ui->lbDebug->setText(db);
    repaint();
}

void MainWindow::stNewPlanet(){
    MyDialog *qd = new MyDialog;
    basePlanet *Px;
    bool Accept;

    do {
       Accept = qd->exec();
       if( Accept )
           Px = qd->OkNewPlanet();
    } while( Accept && Px==NULL );


    listEl *tmp = new listEl;
    tmp->dPlanet = Px;
    tmp->next = PlanetList;
    PlanetList = tmp;

    delete qd;
}

void MainWindow::stStartStopAnimation(){
    if( timer->isActive() ){
        timer->stop();
        ui->mnStartStop->setText( QString("Start"));
    }
    else{
        timer->start();
        ui->mnStartStop->setText( QString("Stop"));
    }
}

void MainWindow::stGridOnOff( bool Gr ){
    GridOn = Gr;
    repaint();
 //   QString dbg = QString( "Grid=( %1 %2 )" ).arg(Gr).arg(GridOn);
 //   ui->winsize->setText(dbg);
}

void MainWindow::stReadConfigFile(){
    int count = 0;

    QFile file("StarMap.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"Can't open file:",file.errorString());
        return;
    }

    QTextStream in(&file);

    QString db;
    while( PlanetList ){
        listEl *tmp = PlanetList;

        while( PlanetList->satlt ){
            listSat *tmp = PlanetList->satlt;

            PlanetList->satlt = tmp->next;
            delete tmp;
        }

        PlanetList = tmp->next;

        delete tmp->dPlanet;
        delete tmp;
    }


    while(!in.atEnd()) {

        QString line = in.readLine();
        int index_dublespace;
        while( (index_dublespace=line.indexOf("  ")) != -1 ){
            line.remove(index_dublespace, 1 );
        }

        QStringList  fields = line.split(" ");
        bool Ok;
        int clr = fields[13].toInt(&Ok, 16);

        basePlanet *Px;
        switch( fields[0].toStdString()[0] ){
            case 's' : db = db+QString('s');
            case '+' : db = db+QString('R');
                       Px = new RotPlanet( fields[0],
                               fields[1].toFloat(),
                               fields[2].toFloat(),
                               fields[4].toFloat(),
                               fields[5].toFloat(),
                               fields[6].toFloat(),
                               fields[9].toFloat(),
                               fields[10].toFloat(),
                               fields[11].toFloat(),
                               fields[13].toInt(&Ok,16) );
                       break;
            case '-' : db = db+QString('L');
                       Px = new Planet( fields[0],
                            fields[1].toFloat(),
                            fields[2].toFloat(),
                            fields[4].toFloat(),
                            fields[5].toFloat(),
                            fields[6].toFloat(),
                            fields[9].toFloat(),
                            fields[10].toFloat(),
                            fields[11].toFloat(),
                            fields[13].toInt(&Ok,16) );

        }
        switch( fields[0].toStdString()[0] ){
            case 's' : {    listSat *tmp = new listSat;
                            tmp->dPlanet = (RotPlanet*) Px;
                            tmp->next = PlanetList->satlt;
                            PlanetList->satlt = tmp;
                            break;
                        }
            case '-' : ;
            case '+' : {
                            listEl *tmp = new listEl;
                            tmp->dPlanet = Px;
                            tmp->satlt = NULL;
                            tmp->next = PlanetList;
                            PlanetList = tmp;
                        }
        }



        QString  crd = QString( "  crd=( %1 %2 %3 )" ).arg(fields[4]).arg(fields[5]).arg(fields[6]);
        QString  vct = QString( "  vel=( %1 %2 %3 )" ).arg(fields[9]).arg(fields[10]).arg(fields[11]);
        QString  cl = QString( " RGB(%1)=%2").arg(fields[13]).arg(clr);
        db = db+fields[0]+ crd + vct + cl +"\n";

        count++;
    }
    ui->lbDebug->setText(db);
    QMessageBox::information(this, tr("Read file success!!"),
                        tr("Read file with %1 objects.").arg(count));

}

MainWindow::~MainWindow()
{
    delete ui;
}


typedef struct DrawList{
   QBrush br;
   int top, left, z, size;
   struct DrawList *next;

} listDr;

DrawList *AddList( basePlanet * Pl, listDr *head, int width, int height ){
    int col,rad,r,g,b,x,y,z,xp,yp; //, i,i1,rr1,ix,iy;
    listDr *tmpXYZ;

    Pl->DrawMe(col,rad,x,y,z);

    r = col & 0xFF;
    g = (col>>8)& 0xFF;
    b = (col>>16)& 0xFF;

    float deepth = exp( log(0.3)*(z /500.0));
    rad = rad*deepth;

    xp = x - width;
    xp = x*deepth + width;
    yp = y - height;
    yp = y*deepth + height;

    tmpXYZ = new listDr;

    tmpXYZ->br = QBrush(QColor( r,g,b,255 ), Qt::SolidPattern );
    tmpXYZ->left = xp-rad;
    tmpXYZ->top = yp-rad;
    tmpXYZ->size = 2*rad;
    tmpXYZ->z = z;

    if( head == NULL ){
        tmpXYZ->next = NULL;
        return tmpXYZ;
    }
    if( head->z < z ){
        tmpXYZ->next = head;
        return tmpXYZ;
    }

    listDr *dhead=head;
    listDr *tt = head->next;
    while( tt != NULL ){
        if( tt->z < z ){
            tmpXYZ->next = tt;
            dhead->next = tmpXYZ;
            return head;
        }
        dhead = tt;
        tt = dhead->next;
    }
    dhead->next = tmpXYZ;
    tmpXYZ->next = NULL;
    return head;
}

/* Определяем виртуальный метод родительского класса
 * для отрисовки содержимого виджета
**/
void MainWindow::paintEvent(QPaintEvent *event){

    QPainter painter(this); // Создаём объект отрисовщика
    // Устанавливаем кисть абриса

//    painter.setBrush(QBrush(QColor( 0,0,255,255 ), Qt::SolidPattern));
//    painter.drawEllipse(100, 50, 150, 150);

    listEl *tmp = PlanetList;
    int width, height, i,i1,rr1,ix,iy;

    QRect rct = this->geometry();


    width = rct.width()/2;
    height = rct.height()/2;
    QString db = QString( "width=%1\nheight=%2" ).arg(width).arg(height);
    ui->winsize->setText(db);

    if( GridOn ){
        float deepth_gr[3];
        deepth_gr[0] = 1;
        deepth_gr[1] = exp( log(0.3)*( 100/500.0));
        deepth_gr[2] = exp( log(0.3)*( 200/500.0));

        i = 75;
        while( i< width ){
            for( i1=0; i1<3; i1++){
              rr1 = i*deepth_gr[i1];
              painter.drawLine(rr1+width,0,rr1+width, height*2);
              painter.drawLine(-rr1+width,0,-rr1+width, height*2);
            }
            i += 150;
        }
        i = 75;
        while( i< height ){
            for( i1=0; i1<3; i1++){
              rr1 = i*deepth_gr[i1];
              painter.drawLine(0, height+rr1, width*2, height+rr1);
              painter.drawLine(0, height-rr1, width*2, height-rr1);
            }
            i += 150;
        }
        ix = 75;
        while( ix< width ){
            iy = 75;
            while( iy< height ){
                int x1, y1;

                x1 = ix;
                y1 = iy;
                for( i1=1; i1<3; i1++){
                    int x2,y2;
                    x2 = ix*deepth_gr[i1];
                    y2 = iy*deepth_gr[i1];

                    painter.drawLine(width+x1, height+y1, width+x2, height+y2);
                    painter.drawLine(width-x1, height+y1, width-x2, height+y2);
                    painter.drawLine(width+x1, height-y1, width+x2, height-y2);
                    painter.drawLine(width-x1, height-y1, width-x2, height-y2);

                    x1 = x2;
                    y1 = y2;
                }
                iy += 150;
            }
            ix += 150;
        }
    }

    listDr *tmpDraw = NULL;
    while( tmp ){
        tmpDraw = AddList( tmp->dPlanet, tmpDraw, width, height );

        if( tmp->satlt ){
            listSat *sat_tmp = tmp->satlt;
            while( sat_tmp ){
                tmpDraw = AddList( sat_tmp->dPlanet, tmpDraw, width, height );
                sat_tmp = sat_tmp->next;
            }
        }

        tmp = tmp->next;
    }
    while( tmpDraw ){
        listDr * tt = tmpDraw;
        tmpDraw = tmpDraw->next;

        painter.setBrush(tt->br);
        painter.drawEllipse(tt->left, tt->top, tt->size, tt->size);

        delete tt;
    }

    //       painter.setBrush(QBrush(QColor( r,g,b,255 ), Qt::SolidPattern));
    //        painter.drawEllipse(xp-rad, yp-rad, 2*rad, 2*rad);


}

basePlanet::basePlanet( QString nm, float w, float r, float px, float py, float pz,
                        int xColor ){

    name = nm;
    weight = w;
    radius = r;
    Pos[0] = px;
    Pos[1] = py;
    Pos[2] = pz;

    Color = xColor;
}

basePlanet::basePlanet(){

    name = QString("prototype");
    weight = 10;
    radius = 10;
    Pos[0] = 0;
    Pos[1] = 0;
    Pos[2] = 0;

    Color = 0x0000FF;
}

basePlanet::~basePlanet(){
}

void basePlanet::move(){
}

QString basePlanet::getName(){
    return name;
}

void basePlanet::DrawMe( int &xColor, int &rad, int &px, int &py, int &pz ){
    xColor = Color;
    rad = radius;
    px = Pos[0];
    py = Pos[1];
    pz = Pos[2];
}

QString basePlanet::getsPos(){
    QString  crd = QString( "  crd=( %1 %2 %3 )" ).arg(Pos[0])
                                                  .arg(Pos[1])
                                                  .arg(Pos[2]);
    return crd;
}


Planet::Planet( QString nm, float w, float r,
                float px, float py, float pz,
                float vx, float vy, float vz,
                int xColor ) :
    basePlanet( nm, w, r, px, py, pz, xColor ) {

    Vel[0] = vx;
    Vel[1] = vy;
    Vel[2] = vz;

}

Planet::Planet():basePlanet(){
    Vel[0] = 0;
    Vel[1] = 0;
    Vel[2] = 0;
}

Planet::~Planet(){
}


void Planet::move(){
    int i;
    for( i=0; i<3; i++ )
        Pos[i] += Vel[i];
}


RotPlanet::RotPlanet( QString nm, float w, float r,
                      float px, float py, float pz,
                      float RotRx, float omegax, float alphax,
                      int xColor ) :
    basePlanet( nm, w, r, px, py, pz, xColor ) {

    RotR = RotRx;
    omega = omegax;
    alpha = alphax;

    ttime = 0;
}

RotPlanet::RotPlanet():basePlanet(){
    RotR = 300;
    omega = 0.3;
    alpha = 1;
    ttime = 0;
}

RotPlanet::~RotPlanet(){
}

void RotPlanet::move(){                                                // функция движения планет
    Pos[1] = 100;
    Pos[0] = RotR*sin(omega*ttime + alpha );
    Pos[2] = RotR*cos(omega*ttime + alpha );

    ttime++;
}

void RotPlanet::moveSatlt( basePlanet * home ){                        //функция движения спутников
    int col, r, x, y, z;
    home->DrawMe(col, r, x, y, z);

    Pos[1] = 100;
    Pos[0] = RotR*sin(omega*ttime + alpha ) + x;
    Pos[2] = RotR*cos(omega*ttime + alpha ) + z;
    ttime++;
}
