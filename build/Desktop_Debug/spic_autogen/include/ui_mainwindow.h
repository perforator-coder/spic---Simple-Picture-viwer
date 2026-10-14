/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_3;
    QAction *action_about;
    QAction *action_2;
    QAction *action_6;
    QAction *action_4;
    QAction *action_5;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGraphicsView *picture;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menu_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/folder.webp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action->setIcon(icon);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/exit.webp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_3->setIcon(icon1);
        action_about = new QAction(MainWindow);
        action_about->setObjectName("action_about");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/info_icon.webp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_about->setIcon(icon2);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_6 = new QAction(MainWindow);
        action_6->setObjectName("action_6");
        action_6->setCheckable(true);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName("action_4");
        action_4->setCheckable(true);
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::SystemLockScreen));
        action_4->setIcon(icon3);
        action_5 = new QAction(MainWindow);
        action_5->setObjectName("action_5");
        action_5->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        picture = new QGraphicsView(centralwidget);
        picture->setObjectName("picture");
        picture->setResizeAnchor(QGraphicsView::ViewportAnchor::AnchorViewCenter);

        gridLayout->addWidget(picture, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_4 = new QMenu(menu_2);
        menu_4->setObjectName("menu_4");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/viwer.webp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        menu_4->setIcon(icon4);
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action);
        menu->addSeparator();
        menu->addAction(action_5);
        menu->addSeparator();
        menu->addAction(action_3);
        menu_2->addAction(action_2);
        menu_2->addSeparator();
        menu_2->addAction(menu_4->menuAction());
        menu_4->addAction(action_4);
        menu_4->addSeparator();
        menu_4->addAction(action_6);
        menu_3->addAction(action_about);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        action_about->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\270", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        action_6->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\202\321\217\320\263\320\270\320\262\320\260\321\202\321\214 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\277\320\276\320\264\320\263\320\276\320\275\320\272\321\203 \320\277\320\276\320\264 \320\276\320\272\320\275\320\276", nullptr));
        action_5->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261 \321\204\320\260\320\271\320\273\320\265", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274\321\213 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\260", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
