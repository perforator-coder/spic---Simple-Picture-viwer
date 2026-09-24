#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    QVector<QString> shortcats = {"Ctrl+H"};
private slots:
    void Shortcat();

private:
    Ui::MainWindow *ui;
    bool menubar_hide = false;
};
#endif // MAINWINDOW_H
