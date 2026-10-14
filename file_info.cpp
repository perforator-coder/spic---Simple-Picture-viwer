#include "file_info.h"
#include "ui_file_info.h"

File_info::File_info(QFileInfo *file,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::File_info)
{
    ui->setupUi(this);
    File_obj = file;
}

File_info::~File_info()
{
    delete ui;
}
