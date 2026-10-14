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
    explicit MainWindow(QString patch,QWidget *parent = nullptr);
    ~MainWindow() override;
    QVector<QString> shortcats = {"Ctrl+z","Ctrl+x","Ctrl+c","Ctrl+q","Ctrl+e"};
    bool menubar_hide = false;
    bool Strach_picture = false;
    bool Strach_witch_extending = false;
    bool open_file = false;
private slots:
    void Shortcat();
    void on_action_triggered();
    void resize_pic();

    void on_action_3_triggered();

    void on_action_about_triggered();

    void on_action_6_triggered();
    void set_value();
    void save_json();
    void load_json();



    void on_action_4_triggered();

    void on_action_5_triggered();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    bool eventFilter(QObject *obj,QEvent *event) override;
private:
    Ui::MainWindow *ui;
    bool is_animated = false; 
    QMovie* animated_pic;
    QFileInfo curret_file_open;
    QSize size_open_picture;
    QGraphicsScene *pic_conteiner = new QGraphicsScene(this);
    QGraphicsPixmapItem *file_pic_open = new QGraphicsPixmapItem();
    QLabel* pic_animated = new QLabel;
    QStringList valid_files = {"png" ,"jpeg" ,"jpg" ,"gif" ,"webp", "kra"};
    QString save_dir;
    const double zoom = 1.1;


};
#endif // MAINWINDOW_H
