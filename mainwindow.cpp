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
#include <QMimeData>
#include <QWindow>

MainWindow::MainWindow(QString patch,QString file_start_open,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Загрузка json
    save_dir = patch;
    load_json();
    set_value();
    Shortcat();

    //устанавливаем флаги
    this->setWindowIcon(QIcon(":/icons/icon.webp"));
    this->setWindowTitle("Spic");
    ui->picture->setAcceptDrops(false);
    ui->picture->viewport()->setAcceptDrops(false);
    this->setAcceptDrops(true);
    this->installEventFilter(this);
    ui->picture->setAlignment(Qt::AlignCenter);
    ui->picture->setScene(pic_conteiner);
    ui->picture->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->picture->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->picture->viewport()->installEventFilter(this);
    if(!open_file)
    {
        ui->action_5->setEnabled(false);
    }
    // проверяем открываем мы ли файл в начале или нет
    if(file_start_open != nullptr)
    {
        curret_file_open = QFileInfo(file_start_open);
        load_file(true);
    }
    else
    {

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    //срабатывает когда наводим курсор с файлом
    if(event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();
    }
    else
    {
        event->ignore();
    }
}
void MainWindow::dropEvent(QDropEvent *event)
{
    //После скинутого файла проверяем это 1 файл или несколько
    if(event->mimeData()->hasUrls())
    {
        QList<QUrl> patch = event->mimeData()->urls();
        if(patch.count() == 1)
        {
            QString file = patch[0].toLocalFile();
            curret_file_open = QFileInfo(file);
            load_file(true);
        }
        else{
            //приложение подерживает 1 фото
            QMessageBox::warning(this,"Ошибка drag and drop","drag and drop работает только с 1 файлом");
        }
    }
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    //переопределяем закрытие для сохранения json
    save_json();
    event->accept();
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //перепределенный метод перетаскивания окна
    // нужно для скрытых рамок
    if(event->button() == Qt::LeftButton)
    {
        this->windowHandle()->startSystemMove();
        event->accept();

    }
}
void MainWindow::set_value()
{
    // после установленых флагов проверяем и выполняем методы которые с ними связаны
    if(menubar_hide)
    {
        ui->menubar->hide();
        this->setWindowFlag(Qt::FramelessWindowHint,true);
    }
    else
    {
        ui->menubar->show();
        this->setWindowFlag(Qt::FramelessWindowHint,false);
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
    //Сохранение json
    QJsonObject json_data;
    QJsonArray array;
    json_data["hide_menubar"] = menubar_hide;
    json_data["fullscreen"] = fullscreeen;

    foreach (const QString &shortcat, shortcats) {
        array.append(shortcat);
    }
    json_data["shortcats"] = array;

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
    //метод для зумма
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
    //Загрузка json
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
                QMessageBox::warning(this,"Ошибка чтения Json","Файл битый\nЗагрузка стандартныйх значений");

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
    //метод для растягивания картинки под окно
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
    //переопределяем метод
    QMainWindow::resizeEvent(event);
    resize_pic();
}

void MainWindow::Shortcat()
{
    // загрузка и связывание комбинаций с методами
    shorcat_menubar = new QShortcut(QKeySequence(shortcats[0]),this);

    connect(shorcat_menubar,&QShortcut::activated,this,[this](){

        if(!menubar_hide){
            ui->menubar->hide();
            this->setWindowFlag(Qt::FramelessWindowHint,true);

            menubar_hide = true;

        }
        else
        {
            ui->menubar->show();
            this->setWindowFlag(Qt::FramelessWindowHint,false);

            menubar_hide = false;

        }
        this->show();
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
    //перезапись комбинаций после изменений
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
void MainWindow::load_file(bool patch_is_here )
{
    ///Метод для загрузки
    /// если patch_is_hear true - читает curret_file_open (QFileInfo)
    QString file_path;
    if(patch_is_here){
        file_path = curret_file_open.filePath();
    }else
    {
        file_path = QFileDialog::getOpenFileName(this,"Открыть изображение",QDir::homePath(),"Все расширения (*.*);;Все подерживаемые расшириения (*.png *.jpeg *.jpg *.gif *.webp *.kra);;png файлы (*.png);;jpeg файлы (*.jpeg *.jpg);;gif файлы (*.gif);;Webp файлы (*.webp);; Krita Файлы (*.kra)");
    }
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
void MainWindow::on_action_triggered()
{
    //кнопка загрузки
    load_file(false);
}


void MainWindow::on_action_3_triggered()
{
    //кнопка закрытия
    this->close();
}


void MainWindow::on_action_about_triggered()
{
    //показ сведений об приложении
    auto *Info_window = new class Info_window(this);
    Info_window->setAttribute(Qt::WA_DeleteOnClose);
    Info_window->show();
}


void MainWindow::on_action_6_triggered()
{
    //кнопка маштобирования
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
    // кнопка зум
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
    //кнопка об файле
    if(open_file){
    File_info *file_form = new File_info(&curret_file_open,this);
    file_form->show();
    }
}


void MainWindow::on_action_7_triggered()
{
    //кнопка полногоокна
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
    //кнопка настроек
    settings *seting_form = new settings(this,&shortcats);
    seting_form->exec();
    shortcats = *(seting_form->get_shorcats());
    shortcat_reset();
}

