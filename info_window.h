#ifndef INFO_WINDOW_H
#define INFO_WINDOW_H

#include <QDialog>

namespace Ui {
class Info_window;
}

class Info_window : public QDialog
{
    Q_OBJECT

public:
    explicit Info_window(QWidget *parent = nullptr);
    ~Info_window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Info_window *ui;
};

#endif // INFO_WINDOW_H
