#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QVector>

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr,QVector<QString> *shortcats = nullptr);
    ~settings();
public slots:
    QVector<QString>* get_shorcats();
private slots:
    \

        void on_keySequenceEdit_menu_editingFinished();

    void on_keySequenceEdit_open_editingFinished();

        void on_keySequenceEdit_close_editingFinished();

    void on_keySequenceEdit_resize_editingFinished();

        void on_keySequenceEdit_bloc_editingFinished();

    void on_keySequenceEdit_file_info_editingFinished();

        void on_keySequenceEdit_full_editingFinished();

    void on_keySequenceEdit_settings_editingFinished();

private:
    Ui::settings *ui;
    QVector<QString> *shortcat_list = new QVector<QString>;
    bool read_keys_now = false;
};

#endif // SETTINGS_H
