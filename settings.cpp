#include "settings.h"
#include "ui_settings.h"

#include <QVector>

settings::settings(QWidget *parent, QVector<QString> *shortcats)
    : QDialog(parent)
    , ui(new Ui::settings)
{
    ui->setupUi(this);
    shortcat_list = shortcats;
    this->setWindowIcon(QIcon(":/icons/settings.webp"));
}

settings::~settings()
{
    delete ui;
}
QVector<QString>*  settings::get_shorcats()
{
    return shortcat_list;
}