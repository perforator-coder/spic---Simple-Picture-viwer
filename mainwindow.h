#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFileInfo>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QLabel>
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
    QVector<QString> shortcats = {"Ctrl+z","Ctrl+x","Ctrl+c","Ctrl+q","Ctrl+e"};
private slots:
    void Shortcat();
    void on_action_triggered();
    void resize_pic();

    void on_action_3_triggered();

protected:
    void resizeEvent(QResizeEvent *event) override;
private:
    Ui::MainWindow *ui;
    bool menubar_hide = false;
    bool is_animated = false;
    bool Strach_picture = false;
    bool Strach_witch_extending = false;
    QMovie* animated_pic;
    QFileInfo curret_file_open;
    QGraphicsScene *pic_conteiner = new QGraphicsScene(this);
    QGraphicsPixmapItem *file_pic_open = new QGraphicsPixmapItem();
    QLabel* pic_animated = new QLabel;



};
#endif // MAINWINDOW_H
