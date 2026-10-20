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
    ui->keySequenceEdit_menu->setKeySequence(QKeySequence(shortcat_list->at(0)));
    ui->keySequenceEdit_open->setKeySequence(QKeySequence(shortcat_list->at(1)));
    ui->keySequenceEdit_close->setKeySequence(QKeySequence(shortcat_list->at(2)));
    ui->keySequenceEdit_resize->setKeySequence(QKeySequence(shortcat_list->at(3)));
    ui->keySequenceEdit_bloc->setKeySequence(QKeySequence(shortcat_list->at(4)));
    ui->keySequenceEdit_file_info->setKeySequence(QKeySequence(shortcat_list->at(5)));
    ui->keySequenceEdit_full->setKeySequence(QKeySequence(shortcat_list->at(6)));
    ui->keySequenceEdit_settings->setKeySequence(QKeySequence(shortcat_list->at(7)));
}

settings::~settings()
{
    delete ui;
}
QVector<QString>*  settings::get_shorcats()
{
    return shortcat_list;
}



void settings::on_keySequenceEdit_menu_editingFinished()
{
    QKeySequence new_key = ui->keySequenceEdit_menu->keySequence();
    shortcat_list->replace( 0,new_key.toString(QKeySequence::PortableText));
}


void settings::on_keySequenceEdit_open_editingFinished()
{
    QKeySequence new_key = ui->keySequenceEdit_open->keySequence();
    shortcat_list->replace( 1,new_key.toString(QKeySequence::PortableText));
}


void settings::on_keySequenceEdit_close_editingFinished()
{
    QKeySequence new_key = ui->keySequenceEdit_close->keySequence();
    shortcat_list->replace( 2,new_key.toString(QKeySequence::PortableText));
}


void settings::on_keySequenceEdit_resize_editingFinished()
{
    QKeySequence new_key = ui->keySequenceEdit_resize->keySequence();
    shortcat_list->replace( 3,new_key.toString(QKeySequence::PortableText));
}


void settings::on_keySequenceEdit_bloc_editingFinished()
{
    QKeySequence new_key = ui->keySequenceEdit_bloc->keySequence();
    shortcat_list->replace( 4,new_key.toString(QKeySequence::PortableText));
}


void settings::on_keySequenceEdit_file_info_editingFinished()
{
    QKeySequence new_key = ui->keySequenceEdit_file_info->keySequence();
    shortcat_list->replace( 5,new_key.toString(QKeySequence::PortableText));
}


void settings::on_keySequenceEdit_full_editingFinished()
{
    QKeySequence new_key = ui->keySequenceEdit_full->keySequence();
    shortcat_list->replace( 6,new_key.toString(QKeySequence::PortableText));
}


void settings::on_keySequenceEdit_settings_editingFinished()
{
    QKeySequence new_key = ui->keySequenceEdit_settings->keySequence();
    shortcat_list->replace( 7,new_key.toString(QKeySequence::PortableText));
}

