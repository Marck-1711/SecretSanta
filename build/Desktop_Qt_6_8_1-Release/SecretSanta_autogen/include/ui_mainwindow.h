/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *titolo;
    QGroupBox *groupBox;
    QLineEdit *form_nome;
    QPushButton *pushButton;
    QLineEdit *form_email;
    QTextEdit *errorMsg;
    QPushButton *InviaEmail;
    QLabel *bells;
    QLabel *christmas_hat;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1159, 766);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	background-color:#00743c;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(470, 210, 641, 491));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	background-color:#AE0D13;\n"
"border: 3px solid black;\n"
"}"));
        scrollArea = new QScrollArea(groupBox_2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(20, 20, 601, 451));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 599, 449));
        scrollArea->setWidget(scrollAreaWidgetContents);
        titolo = new QLabel(centralwidget);
        titolo->setObjectName("titolo");
        titolo->setGeometry(QRect(330, 50, 541, 111));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 210, 401, 491));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	background-color:#AE0D13;\n"
"	border: 3px solid black;\n"
"}"));
        form_nome = new QLineEdit(groupBox);
        form_nome->setObjectName("form_nome");
        form_nome->setGeometry(QRect(50, 50, 311, 51));
        QFont font;
        font.setPointSize(15);
        form_nome->setFont(font);
        form_nome->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color:white;\n"
"border: 3px solid black;\n"
"border-radius: 10px;\n"
"color:black\n"
"}"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 230, 311, 61));
        QFont font1;
        font1.setPointSize(17);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:white;\n"
"	color: black;\n"
"	border:3px solid black;\n"
"	border-radius: 5px;\n"
"}"));
        form_email = new QLineEdit(groupBox);
        form_email->setObjectName("form_email");
        form_email->setGeometry(QRect(50, 140, 311, 51));
        form_email->setFont(font);
        form_email->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color:white;\n"
"border: 3px solid black;\n"
"border-radius: 10px;\n"
"color:black;\n"
"}"));
        errorMsg = new QTextEdit(groupBox);
        errorMsg->setObjectName("errorMsg");
        errorMsg->setGeometry(QRect(50, 300, 251, 31));
        QFont font2;
        font2.setBold(true);
        errorMsg->setFont(font2);
        errorMsg->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"	background-color:#AE0D13;\n"
"	color:#AE0D13;\n"
"	font-size:15px;\n"
"	font-weight:bold;\n"
"	border:none;\n"
"}"));
        InviaEmail = new QPushButton(groupBox);
        InviaEmail->setObjectName("InviaEmail");
        InviaEmail->setGeometry(QRect(50, 350, 311, 61));
        InviaEmail->setFont(font1);
        InviaEmail->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:white;\n"
"	color: black;\n"
"	border:3px solid black;\n"
"	border-radius: 5px;\n"
"}"));
        bells = new QLabel(centralwidget);
        bells->setObjectName("bells");
        bells->setGeometry(QRect(110, 30, 151, 141));
        christmas_hat = new QLabel(centralwidget);
        christmas_hat->setObjectName("christmas_hat");
        christmas_hat->setGeometry(QRect(900, 50, 161, 131));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Secret Santa", nullptr));
        groupBox_2->setTitle(QString());
        titolo->setText(QCoreApplication::translate("MainWindow", "TITOLO", nullptr));
        groupBox->setTitle(QString());
        form_nome->setText(QString());
        form_nome->setPlaceholderText(QCoreApplication::translate("MainWindow", " Nome", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "AGGIUNGI", nullptr));
        form_email->setText(QString());
        form_email->setPlaceholderText(QCoreApplication::translate("MainWindow", " Email", nullptr));
        errorMsg->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:15px; font-weight:700; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:400;\">Compila tutti i campi del form</span></p></body></html>", nullptr));
        InviaEmail->setText(QCoreApplication::translate("MainWindow", "INVIA EMAIL", nullptr));
        bells->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        christmas_hat->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
