/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "canvas.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Save;
    QAction *Load;
    QAction *Select;
    QAction *Rectangle;
    QAction *Ellipse;
    QAction *Line;
    QAction *Clear;
    QAction *Info;
    QAction *Exit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    Canvas *CanvasWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        Save = new QAction(MainWindow);
        Save->setObjectName("Save");
        Load = new QAction(MainWindow);
        Load->setObjectName("Load");
        Select = new QAction(MainWindow);
        Select->setObjectName("Select");
        Rectangle = new QAction(MainWindow);
        Rectangle->setObjectName("Rectangle");
        Ellipse = new QAction(MainWindow);
        Ellipse->setObjectName("Ellipse");
        Line = new QAction(MainWindow);
        Line->setObjectName("Line");
        Clear = new QAction(MainWindow);
        Clear->setObjectName("Clear");
        Info = new QAction(MainWindow);
        Info->setObjectName("Info");
        Exit = new QAction(MainWindow);
        Exit->setObjectName("Exit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        CanvasWidget = new Canvas(centralwidget);
        CanvasWidget->setObjectName("CanvasWidget");

        verticalLayout->addWidget(CanvasWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(Save);
        menu->addAction(Load);
        menu_2->addAction(Select);
        menu_2->addAction(Rectangle);
        menu_2->addAction(Ellipse);
        menu_2->addAction(Line);
        menu_3->addAction(Clear);
        menu_4->addAction(Info);
        menu_4->addAction(Exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        Load->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        Select->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        Rectangle->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        Ellipse->setText(QCoreApplication::translate("MainWindow", "\320\255\320\273\320\273\320\270\320\277\321\201", nullptr));
        Line->setText(QCoreApplication::translate("MainWindow", "\320\233\320\270\320\275\320\270\321\217", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        Info->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        Exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 \321\200\320\270\321\201\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\205\320\276\320\273\321\201\321\202", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\320\224\321\200\321\203\320\263\320\276\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
