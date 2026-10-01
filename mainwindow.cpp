#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeySequence>
#include <QShortcut>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Shortcat();
    this->setWindowTitle("Spic");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Shortcat()
{
    foreach (QString shortcat_txt, shortcats) {


    QShortcut *shorcat_menubar = new QShortcut(QKeySequence(shortcat_txt),this);
    connect(shorcat_menubar,&QShortcut::activated,this,[this](){
        if()
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
}
void MainWindow::on_action_triggered()
{
    QString file_path = QFileDialog::getOpenFileName(this,"Открыть изображение",QDir::homePath(),"Все расширения (*.*);;png файлы (*.png);;jpeg файлы (*.jpeg)");
    QPixmap picture(file_path);
    curret_file_open = QFileInfo(file_path);
    this->setWindowTitle(curret_file_open.fileName());
    ui->picture->setPixmap(picture);
}

