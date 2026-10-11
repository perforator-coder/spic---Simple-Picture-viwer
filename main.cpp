#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSysInfo>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "spic_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    // Сохраняем файлы в папку в зависимости от ОС
    const QString using_os = QSysInfo::kernelType();
    qDebug() <<"Current user's kernel --" <<using_os;

    if (using_os == "windows")
    {

    }
    else if (using_os == "osx")
    {

    }
    else if (using_os == "linux")
    {
        const QString save_place = "~/.config/spic/";

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



    w.show();
    return QApplication::exec();
}
