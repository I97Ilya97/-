#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QAction>
#include <QDialog>
#include <QtGui>
#include <QTimer>
#include <QPainter>
#include <QColor>
#include <QPixmap>
#include <QPalette>
#include <math.h>

#include "ui_dgNewPlanet.h"

/// Базовый класс планета
class basePlanet{
private:
    /// Имя
    QString name;
    int Color;

protected:
    float weight, radius;
    float Pos[3];


public:
    basePlanet( QString nm, float w, float r, float px, float py, float pz,
                int xColor );
    basePlanet();
    virtual ~basePlanet();

    QString getName();
    QString getsPos();

    void DrawMe( int &xColor, int &rad, int &px, int &py, int &pz );
    virtual void move();
};

class Planet:public basePlanet{                 // Класс Планета, производный класс
    float Vel[3],Accel[3];

public:
    Planet( QString nm, float w, float r, float px, float py, float pz,
                                          float vx, float vy, float vz,
                                          int xColor );
    Planet();
    virtual ~Planet();
//    QString getsVel();

    virtual void move();
};

class RotPlanet:public basePlanet{              // Класс крутящаяся планета, производный класс
    float RotR, omega, alpha;
    int ttime;

public:
    RotPlanet( QString nm, float w, float r, float px, float py, float pz,
                                          float RotRx, float omegax, float alphax,
                                          int xColor );
    RotPlanet();
    virtual ~RotPlanet();
//    QString getsVel();

    virtual void move();
    void moveSatlt( basePlanet * home );
};

typedef struct satelliteList{
   RotPlanet *dPlanet;
   struct satelliteList *next;

} listSat;

typedef struct planetList{
   basePlanet *dPlanet;
   struct planetList *next;
   struct satelliteList *satlt;
} listEl;

namespace Ui {
class MainWindow;
}


class MyDialog : public  QDialog{
    Q_OBJECT

public:
    MyDialog(QWidget *parent = 0);
    ~MyDialog();

private:
    Ui::dgDialog *ui;

public:
    basePlanet* OkNewPlanet();

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    /* Определяем виртуальный метод родительского класса
     * для отрисовки содержимого виджета
     * */
    void paintEvent(QPaintEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *timer;

private:
    Ui::MainWindow *ui;
    listEl * PlanetList;
    bool GridOn;

private slots:
    void stReadConfigFile();
    void stNewPlanet();
    void stStartStopAnimation();
    void stGridOnOff( bool Gr );
    void stStepModelling();
};

#endif // MAINWINDOW_H
