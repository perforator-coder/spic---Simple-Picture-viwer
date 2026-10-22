#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSysInfo>
#include <QMessageBox>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>
#include <QJsonDocument>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "spic_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    QString file_path;
    if(argc > 1)
    {
        file_path = argv[1];
        qDebug() << "Найден параметр" << argv[1];
    }
    // Сохраняем файлы в папку в зависимости от ОС
    const QString using_os = QSysInfo::kernelType();
    qDebug() <<"Current user's kernel --" <<using_os;
    QString save_place;
    QDir dir_json;


    if (using_os == "windows")
    {

    }
    else if (using_os == "osx")
    {

    }
    else if (using_os == "linux")
    {
        save_place = QDir::homePath()+"/.config/spic";

    }
    else
    {
        qDebug() <<"ERROR -- USER is using unknown OS";

        // Отображаем предупреждение, что данные не могут быть сохранены
            // qWarning() <<"ОШИБКА - неизвестная ОС \n"
            //            "Данные не могут быть сохранены для следующей сессии";
        QMessageBox::warning(nullptr, "Предупреждение",
                             "Эта ОС не поддерживается.");
    }
    if(!dir_json.exists(save_place))
    {
        dir_json.mkdir(save_place);
    };
    MainWindow *w;
    if(!file_path.isNull()){

        w = new MainWindow(save_place,file_path);

    }
    else
    {
        w = new MainWindow(save_place,nullptr);
    }


    w->show();

    return QApplication::exec();
}
