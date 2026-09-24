#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeySequence>
#include <QShortcut>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Shortcat();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Shortcat()
{
    QShortcut *shorcat_menubar = new QShortcut(QKeySequence(shortcats[0]),this);
    connect(shorcat_menubar,&QShortcut::activated,this,[this](){
        if(!menubar_hide){
            ui->menubar->hide();
            menubar_hide = true;
        }
        else
        {
            ui->menubar->show();
            menubar_hide = false;
        }
    });
}