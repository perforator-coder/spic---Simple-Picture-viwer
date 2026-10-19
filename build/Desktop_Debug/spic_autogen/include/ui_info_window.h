/********************************************************************************
** Form generated from reading UI file 'info_window.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_WINDOW_H
#define UI_INFO_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Info_window
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Info_window)
    {
        if (Info_window->objectName().isEmpty())
            Info_window->setObjectName("Info_window");
        Info_window->resize(400, 330);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Info_window->sizePolicy().hasHeightForWidth());
        Info_window->setSizePolicy(sizePolicy);
        Info_window->setMinimumSize(QSize(400, 330));
        Info_window->setMaximumSize(QSize(400, 330));
        gridLayout = new QGridLayout(Info_window);
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(Info_window);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 4, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        textEdit = new QTextEdit(Info_window);
        textEdit->setObjectName("textEdit");
        textEdit->setStyleSheet(QString::fromUtf8(""));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 2, 0, 1, 1);

        label = new QLabel(Info_window);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        label_2 = new QLabel(Info_window);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 700 10pt \"DejaVu Sans Condensed\";"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);


        retranslateUi(Info_window);

        QMetaObject::connectSlotsByName(Info_window);
    } // setupUi

    void retranslateUi(QWidget *Info_window)
    {
        Info_window->setWindowTitle(QCoreApplication::translate("Info_window", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Info_window", "Github", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Info_window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sPIC - \320\277\321\200\320\276\321\201\320\274\320\276\321\202\320\276\321\200\321\211\320\270\320\272 \321\204\320\276\321\202\320\276</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\224\320\260\320\275\320\275\320\276\320\265 \320\277\321\200\320\270\320\273\320\276\320\266\320"
                        "\265\320\275\320\270\320\265 \320\275\320\260\321\205\320\276\320\264\320\270\321\202\321\201\321\217 \320\275\320\260 \320\260\320\272\321\202\320\270\320\262\320\275\320\276\320\274 \321\215\321\202\320\260\320\277\320\265 \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\272\320\270 \320\270 \320\261\321\203\320\264\320\265\321\202 \320\277\320\276\320\277\320\276\320\273\320\275\321\217\321\202\321\214\321\201\321\217 \320\262\321\201\320\265 \320\275\320\276\320\262\321\213\320\274\320\270 \320\270 \320\275\320\276\320\262\321\213\320\274\320\270 \321\204\321\203\320\275\320\272\321\206\320\270\321\217\320\274\320\270. sPIC \320\275\320\260\320\277\320\270\321\201\320\260\320\275 \320\275\320\260 QT framework, \320\277\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\273\321\217\321\217 \321\201\320\276\320\261\320\276\320\271 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265, \320\277\321\200\320\270\320\276\321\200\320\270\321\202\320\265\320\267"
                        "\320\270\321\200\321\203\321\216\321\211\320\265\320\265 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-ind"
                        "ent:0px;\"><br /></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Info_window", "pic", nullptr));
        label_2->setText(QCoreApplication::translate("Info_window", "V: 0.0.1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Info_window: public Ui_Info_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_WINDOW_H
