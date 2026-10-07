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
    QVector<QString> shortcats = {"Ctrl+H"};
    double size = 100;
private slots:
    void Shortcat();

    void on_action_triggered();
    void resize_pic();
protected:
    void resizeEvent(QResizeEvent *event) override;
private:
    Ui::MainWindow *ui;
    bool menubar_hide = false;
    bool is_animated = false;
    QFileInfo curret_file_open;
    QGraphicsScene *pic_conteiner = new QGraphicsScene(this);
    QGraphicsPixmapItem *file_pic_open = new QGraphicsPixmapItem();
    QLabel* pic_animated = new QLabel;


};
#endif // MAINWINDOW_H
