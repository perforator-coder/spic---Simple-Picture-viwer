#ifndef FILE_INFO_H
#define FILE_INFO_H

#include <QDialog>
#include <QFileInfo>
namespace Ui {
class File_info;
}

class File_info : public QDialog
{
    Q_OBJECT

public:
    explicit File_info(QFileInfo *file,QWidget *parent = nullptr);
    ~File_info();

private:
    Ui::File_info *ui;
    QFileInfo *File_obj;
};

#endif // FILE_INFO_H
