#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeySequence>
#include <QShortcut>
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QMovie>
#include <QLabel>
#include <QTimer>
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
    if(pic_conteiner)
    {
        ui->picture->fitInView(pic_conteiner->itemsBoundingRect());
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
    QString file_path = QFileDialog::getOpenFileName(this,"Открыть изображение",QDir::homePath(),"Все расширения (*.*);;png файлы (*.png);;jpeg файлы (*.jpeg);;gif файлы (*.gif);;Webp файлы (*.webp)");
    if(file_path.endsWith(".gif")||file_path.endsWith(".webp"))
    {

        is_animated = true;
    }
    else
    {

        is_animated = false;
    }
    pic_conteiner->clear();
    delete pic_conteiner;
    pic_conteiner = new  QGraphicsScene(this);
    ui->picture->setScene(pic_conteiner);


    if(is_animated == false){
        ui->picture->setAlignment(Qt::AlignCenter);
        file_pic_open = new QGraphicsPixmapItem();
        file_pic_open->setPixmap(QPixmap(file_path));
        pic_conteiner->addItem(file_pic_open);

    }
    else
    {
        QMovie* animated_pic = new QMovie(file_path);
        pic_animated = new QLabel;
        pic_animated->setMovie(animated_pic);
        pic_animated->setAttribute(Qt::WA_NoSystemBackground);
        pic_conteiner->addWidget(pic_animated);

        QTimer::singleShot(0,this,&MainWindow::resize_pic);
        animated_pic->start();

    }
    resize_pic();
    curret_file_open = QFileInfo(file_path);
    this->setWindowTitle(curret_file_open.fileName());

}

