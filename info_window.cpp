#include "info_window.h"
#include "ui_info_window.h"

Info_window::Info_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Info_window)
{
    ui->setupUi(this);
}

Info_window::~Info_window()
{
    delete ui;
}
