#include "info_window.h"
#include "ui_info_window.h"


#include <QDesktopServices>
#include <QIcon>



Info_window::Info_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Info_window)
{
    ui->setupUi(this);
    this->setWindowTitle("Об приложении");
    QIcon logo(":/icons/icon.webp");
    QPixmap pic = logo.pixmap(64,64);
    ui->label->setPixmap(pic);
}

Info_window::~Info_window()
{
    delete ui;
}

void Info_window::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/perforator-coder/spic---Simple-Picture-viwer"));
}

