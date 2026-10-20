#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "info_window.h"
#include "file_info.h"
#include "settings.h"

#include <QKeySequence>
#include <QShortcut>
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QMovie>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QCloseEvent>

MainWindow::MainWindow(QString patch,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    save_dir = patch;
    load_json();
    set_value();
    this->setWindowIcon(QIcon(":/icons/icon.webp"));
    Shortcat();
    this->setWindowTitle("Spic");
    ui->picture->setAlignment(Qt::AlignCenter);
    ui->picture->setScene(pic_conteiner);
    ui->picture->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->picture->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->picture->viewport()->installEventFilter(this);
    if(!open_file)
    {
        ui->action_5->setEnabled(false);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    save_json();
    event->accept();
}
void MainWindow::set_value()
{

    if(menubar_hide)
    {
        ui->menubar->hide();
    }
    else
    {
        ui->menubar->show();
    }
    if(fullscreeen)
    {

        this->showFullScreen();

        ui->action_7->setChecked(fullscreeen);
    }
    else
    {
        this->showNormal();

        ui->action_7->setChecked(fullscreeen);
    }
}
void MainWindow::save_json()
{

    QJsonObject json_data;
    QJsonArray array;
    json_data["hide_menubar"] = menubar_hide;
    foreach (const QString &shortcat, shortcats) {
        array.append(shortcat);
    }
    json_data["shortcats"] = array;
    json_data["fullscreen"] = fullscreeen;
    QJsonDocument done_json_file(json_data);
    QFile json_file(save_dir+"/Spic.json");

    if(json_file.open(QIODevice::WriteOnly))
    {
        json_file.write(done_json_file.toJson(QJsonDocument::Indented));
        json_file.close();

    }

}
bool MainWindow::eventFilter(QObject *obj,QEvent *event)
{
    if(Strach_witch_extending){
    if(obj == ui->picture->viewport() && event->type() == QEvent::Wheel)
    {
        QWheelEvent *mouse = static_cast<QWheelEvent*>(event);
        if(mouse->angleDelta().y() > 0)
        {
            ui->picture->scale(zoom,zoom);
        }
        else
        {
            ui->picture->scale(1.0/zoom,1.0/zoom);
        }
        return true;
    }
    }
    return QMainWindow::eventFilter(obj,event);
}
void MainWindow::load_json()
{
    if(QFile::exists(save_dir+"/Spic.json"))
    {
        QJsonDocument data_convertor;
        QJsonParseError detector_er;
        QByteArray data;
        QJsonObject json_obj;
        QFile json_file(save_dir+"/Spic.json");
        if(!json_file.open(QIODevice::ReadOnly))
        {
            //ошибка если файл не открыт

        }else
        {
            data = json_file.readAll();
            json_file.close();

            data_convertor = QJsonDocument::fromJson(data,&detector_er);
            if(detector_er.error != QJsonParseError::NoError)
            {
                //ошибка если файл битый

            }
            else
            {
                if(data_convertor.isObject())
                {
                    json_obj = data_convertor.object();
                    menubar_hide = json_obj["hide_menubar"].toBool();
                    fullscreeen = json_obj["fullscreen"].toBool();
                    shortcats.clear();
                    QJsonArray array = json_obj["shortcats"].toArray();
                    foreach (const QJsonValue &i, array) {
                        shortcats.push_back(i.toString());
                    }
                }
            }
        }
    }
}
void MainWindow::resize_pic()
{
    if(!Strach_witch_extending){
     if(pic_conteiner && Strach_picture )
    {
        ui->picture->fitInView(pic_conteiner->itemsBoundingRect(),Qt::KeepAspectRatio);
         ui->action_6->setChecked(false);
    }
    else
    {
        ui->picture->fitInView(pic_conteiner->itemsBoundingRect());
        ui->action_6->setChecked(true);
    }
    }
}
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    resize_pic();
}

void MainWindow::Shortcat()
{
    shorcat_menubar = new QShortcut(QKeySequence(shortcats[0]),this);

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
        resize_pic();
    });
    shortcat_open_file = new QShortcut(QKeySequence(shortcats[1]),this);
    connect(shortcat_open_file,&QShortcut::activated,this,[this](){
        on_action_triggered();
    });
    shortcat_close_app = new QShortcut(QKeySequence(shortcats[2]),this);
    connect(shortcat_close_app,&QShortcut::activated,this,[this](){
        on_action_3_triggered();
    });
    shortcat_modekeepaspect = new QShortcut(QKeySequence(shortcats[3]),this);
    connect(shortcat_modekeepaspect,&QShortcut::activated,this,[this](){
        if(!Strach_witch_extending){
        if(!Strach_picture)
        {
            Strach_picture = true;
            if(Strach_witch_extending)
            {
                Strach_witch_extending = false;
            }
            ui->action_6->setChecked(false);
        }else
        {
            Strach_picture= false;
            ui->action_6->setChecked(true);
        }
        resize_pic();
        }
    });
    shortcat_modebyextending = new QShortcut(QKeySequence(shortcats[4]),this);
    connect(shortcat_modebyextending,&QShortcut::activated,this,[this](){
        if(!Strach_witch_extending)
        {
            Strach_witch_extending = true;
            ui->action_6->setEnabled(false);
            ui->action_4->setChecked(true);

            if(ui->action_6->isChecked() == true)
            {
                ui->action_6->setChecked(false);
                ui->picture->fitInView(pic_conteiner->itemsBoundingRect());
            }
            ui->picture->setDragMode(QGraphicsView::ScrollHandDrag);
        }else
        {
            Strach_witch_extending = false;
            ui->action_4->setChecked(false);
            ui->action_6->setEnabled(true);
            ui->picture->setDragMode(QGraphicsView::NoDrag);
        }
        resize_pic();
    });
    shortcat_info_pic = new QShortcut(QKeySequence(shortcats[5]),this);
    connect(shortcat_info_pic,&QShortcut::activated,this,[this](){
        on_action_5_triggered();
    });
    shortcat_fillscrin = new QShortcut(QKeySequence(shortcats[6]),this);
    connect(shortcat_fillscrin,&QShortcut::activated,this,[this](){
        on_action_7_triggered();
    });
    shortcat_settings =  new QShortcut(QKeySequence(shortcats[7]),this);
    connect(shortcat_settings,&QShortcut::activated,this,[this](){
        on_action_2_triggered();
    });
}
void MainWindow::shortcat_reset()
{
    shorcat_menubar->setKey(shortcats[0]);

    shortcat_open_file->setKey(shortcats[1]);
    shortcat_close_app->setKey(shortcats[2]);
    shortcat_modekeepaspect->setKey(shortcats[3]);
    shortcat_modebyextending->setKey(shortcats[4]);
    shortcat_info_pic->setKey(shortcats[5]);
    shortcat_fillscrin->setKey(shortcats[6]);
    shortcat_settings->setKey(shortcats[7]);
    update();
}
void MainWindow::on_action_triggered()
{
    QString file_path = QFileDialog::getOpenFileName(this,"Открыть изображение",QDir::homePath(),"Все расширения (*.*);;Все подерживаемые расшириения (*.png *.jpeg *.jpg *.gif *.webp *.kra);;png файлы (*.png);;jpeg файлы (*.jpeg *.jpg);;gif файлы (*.gif);;Webp файлы (*.webp);; Krita Файлы (*.kra)");
    if(file_path == nullptr)
    {
        open_file = false;
        return;
    }
    QFileInfo file(file_path);
    if(valid_files.contains(file.suffix().toLower())){
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

        file_pic_open = new QGraphicsPixmapItem();
        file_pic_open->setPixmap(QPixmap(file_path));
        size_open_picture = QPixmap(file_path).size();
        pic_conteiner->addItem(file_pic_open);

    }
    else
    {
        animated_pic = new QMovie(file_path);


        pic_animated = new QLabel;
        pic_animated->setMovie(animated_pic);
        pic_animated->setAttribute(Qt::WA_NoSystemBackground);
        pic_conteiner->addWidget(pic_animated);

        QTimer::singleShot(0,this,&MainWindow::resize_pic);
        animated_pic->start();
        animated_pic->jumpToFrame(0);
        size_open_picture = animated_pic->frameRect().size();

    }
    resize_pic();
    curret_file_open = QFileInfo(file_path);
    this->setWindowTitle(QString("%1 -- %2 X %3").arg(curret_file_open.fileName()).arg(size_open_picture.height()).arg(size_open_picture.width()));
    open_file = true;
    }
    else
    {
        QMessageBox::information(nullptr,"Ошибка: файл не подерживается","Текущий файл не подерживается для просмотра");
        open_file = false;
    }
    if(open_file)
    {
        ui->action_5->setEnabled(open_file);
    }
    else
    {
        ui->action_5->setEnabled(open_file);
    }
}


void MainWindow::on_action_3_triggered()
{
    this->close();
}


void MainWindow::on_action_about_triggered()
{
    auto *Info_window = new class Info_window(this);
    Info_window->setAttribute(Qt::WA_DeleteOnClose);
    Info_window->show();
}


void MainWindow::on_action_6_triggered()
{
    if(!Strach_picture)
    {
        Strach_picture = true;
        if(Strach_witch_extending)
        {
            Strach_witch_extending = false;
        }
        ui->action_6->setChecked(false);
    }else
    {

        Strach_picture= false;
        ui->action_6->setChecked(true);
    }
    resize_pic();
}





void MainWindow::on_action_4_triggered()
{
    if(!Strach_witch_extending){
        ui->action_6->setEnabled(false);
        Strach_witch_extending = true;
        if(ui->action_6->isChecked() == true)
        {
            ui->action_6->setChecked(false);
            ui->picture->fitInView(pic_conteiner->itemsBoundingRect());
        }
        ui->picture->setDragMode(QGraphicsView::ScrollHandDrag);
        ui->picture->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    }
    else{
        Strach_witch_extending = false;
        ui->action_6->setEnabled(true);
        ui->picture->setDragMode(QGraphicsView::NoDrag);
       resize_pic();
    }
}


void MainWindow::on_action_5_triggered()
{
    if(open_file){
    File_info *file_form = new File_info(&curret_file_open,this);
    file_form->show();
    }
}


void MainWindow::on_action_7_triggered()
{
    if(!fullscreeen)
    {

        this->showFullScreen();
        fullscreeen=true;
        ui->action_7->setChecked(fullscreeen);
    }
    else
    {
        this->showNormal();
        fullscreeen = false;
        ui->action_7->setChecked(fullscreeen);
    }
}


void MainWindow::on_action_2_triggered()
{
    settings *seting_form = new settings(this,&shortcats);
    seting_form->exec();
    shortcats = *(seting_form->get_shorcats());
    shortcat_reset();
}

