#include "file_info.h"
#include "ui_file_info.h"

#include <QImage>

File_info::File_info(QFileInfo *file,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::File_info)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icons/info_icon.webp"));
    this->setWindowTitle("Об файле");
    File_obj = file;
    ui->path->setText(ui->path->text() + " " +File_obj->filePath());
    QImage file_(File_obj->absoluteFilePath());
    ui->size_pic->setText(ui->size_pic->text() + " " + QString::number(file_.height()) + "X" + QString::number(file_.width()));
    ui->size_disk->setText(ui->size_disk->text() + " "+ QString::number(File_obj->size() / (1024.0*1024.0),'f',2) + " " + "Mb");

}

File_info::~File_info()
{
    delete ui;
}
