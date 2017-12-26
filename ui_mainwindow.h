/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *mnStartStop;
    QAction *mnNewPlanet;
    QAction *mnReadConfigFile;
    QAction *action_3;
    QAction *mnGridOnOff;
    QWidget *centralWidget;
    QLabel *lbDebug;
    QLabel *winsize;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1299, 693);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 0, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(118, 116, 108, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        mnStartStop = new QAction(MainWindow);
        mnStartStop->setObjectName(QStringLiteral("mnStartStop"));
        mnNewPlanet = new QAction(MainWindow);
        mnNewPlanet->setObjectName(QStringLiteral("mnNewPlanet"));
        mnReadConfigFile = new QAction(MainWindow);
        mnReadConfigFile->setObjectName(QStringLiteral("mnReadConfigFile"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        mnGridOnOff = new QAction(MainWindow);
        mnGridOnOff->setObjectName(QStringLiteral("mnGridOnOff"));
        mnGridOnOff->setCheckable(true);
        mnGridOnOff->setChecked(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lbDebug = new QLabel(centralWidget);
        lbDebug->setObjectName(QStringLiteral("lbDebug"));
        lbDebug->setGeometry(QRect(10, 0, 441, 241));
        winsize = new QLabel(centralWidget);
        winsize->setObjectName(QStringLiteral("winsize"));
        winsize->setGeometry(QRect(10, 260, 121, 61));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1299, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(mnStartStop);
        menu->addAction(mnNewPlanet);
        menu->addAction(mnReadConfigFile);
        menu_2->addAction(mnGridOnOff);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        mnStartStop->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\320\272 \320\260\320\275\320\270\320\274\320\260\321\206\320\270\321\216", 0));
        mnNewPlanet->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\276\320\262 \320\275\320\276\320\262\320\276\320\263\320\276 \321\202\320\265\320\273\320\260", 0));
        mnReadConfigFile->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\207\320\270\321\202\320\260\321\202\321\214 \321\204\320\260\320\271\320\273 \320\272\320\276\320\275\321\204\320\270\320\263\321\203\321\200\320\260\321\206\320\270\320\270", 0));
        action_3->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\260\320\275\320\274\320\260\321\206\320\270\321\216", 0));
        mnGridOnOff->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\321\202\321\200\320\260\320\275\321\201\321\202\320\262\320\265\320\275\320\275\320\260\321\217 \321\201\320\265\321\202\320\272\320\260", 0));
        lbDebug->setText(QApplication::translate("MainWindow", "File", 0));
        winsize->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\270\320\265 \320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
