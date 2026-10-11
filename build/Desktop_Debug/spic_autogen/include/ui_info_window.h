/********************************************************************************
** Form generated from reading UI file 'info_window.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_WINDOW_H
#define UI_INFO_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Info_window
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *Info_window)
    {
        if (Info_window->objectName().isEmpty())
            Info_window->setObjectName("Info_window");
        Info_window->resize(400, 300);
        textEdit = new QTextEdit(Info_window);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 80, 381, 211));
        textEdit->setStyleSheet(QString::fromUtf8(""));
        textEdit->setReadOnly(true);
        pushButton = new QPushButton(Info_window);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 20, 51, 51));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("color:white"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/icon.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(64, 64));
        pushButton->setCheckable(false);
        pushButton->setFlat(false);

        retranslateUi(Info_window);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Info_window);
    } // setupUi

    void retranslateUi(QWidget *Info_window)
    {
        Info_window->setWindowTitle(QCoreApplication::translate("Info_window", "Form", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Info_window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sPIC - \320\277\321\200\320\276\321\201\320\274\320\276\321\202\320\276\321\200\321\211\320\270\320\272 \321\204\320\276\321\202\320\276</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Info_window: public Ui_Info_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_WINDOW_H
