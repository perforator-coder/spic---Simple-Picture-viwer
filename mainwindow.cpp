#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeySequence>
#include <QShortcut>
#include <QFileDialog>
#include <QGraphicsPixmapItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Shortcat();
    this->setWindowTitle("Spic");
    ui->picture->setAlignment(Qt::AlignCenter);
    ui->picture->setScene(pic_conteiner);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::resize_pic()
{
    if(!file_pic_open->pixmap().isNull())
    {
        ui->picture->fitInView(file_pic_open);
    }
}
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    resize_pic();
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
void MainWindow::on_action_triggered()
{
    QString file_path = QFileDialog::getOpenFileName(this,"Открыть изображение",QDir::homePath(),"Все расширения (*.*);;png файлы (*.png);;jpeg файлы (*.jpeg)");

    file_pic_open = new QGraphicsPixmapItem();
    file_pic_open->setPixmap(QPixmap(file_path));
    pic_conteiner->addItem(file_pic_open);
    ui->picture->fitInView(file_pic_open);


    curret_file_open = QFileInfo(file_path);
    this->setWindowTitle(curret_file_open.fileName());

}

