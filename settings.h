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
private:
    Ui::settings *ui;
    QVector<QString> *shortcat_list;
};

#endif // SETTINGS_H
