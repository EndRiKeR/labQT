/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_calc_metr;
    QPushButton *pushButton_file;
    QTextBrowser *textBrowser_name_file;
    QLabel *region_text;
    QLabel *column_number_text;
    QLabel *max_text;
    QTextBrowser *textBrowser_max;
    QTextBrowser *textBrowser_min;
    QTextBrowser *textBrowser_med;
    QLabel *min_text;
    QLabel *med_text;
    QPushButton *pushButton_load;
    QComboBox *comboBox_column_number;
    QComboBox *comboBox_region;
    QTableWidget *tableWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1350, 950);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 212, 176);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_calc_metr = new QPushButton(centralwidget);
        pushButton_calc_metr->setObjectName(QString::fromUtf8("pushButton_calc_metr"));
        pushButton_calc_metr->setGeometry(QRect(1030, 170, 301, 61));
        QFont font;
        font.setPointSize(14);
        pushButton_calc_metr->setFont(font);
        pushButton_calc_metr->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);\n"
"\n"
"\n"
""));
        pushButton_file = new QPushButton(centralwidget);
        pushButton_file->setObjectName(QString::fromUtf8("pushButton_file"));
        pushButton_file->setGeometry(QRect(380, 20, 191, 61));
        pushButton_file->setFont(font);
        pushButton_file->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);\n"
"\n"
""));
        textBrowser_name_file = new QTextBrowser(centralwidget);
        textBrowser_name_file->setObjectName(QString::fromUtf8("textBrowser_name_file"));
        textBrowser_name_file->setGeometry(QRect(50, 20, 321, 60));
        textBrowser_name_file->setFont(font);
        textBrowser_name_file->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        region_text = new QLabel(centralwidget);
        region_text->setObjectName(QString::fromUtf8("region_text"));
        region_text->setGeometry(QRect(610, 20, 111, 61));
        region_text->setFont(font);
        column_number_text = new QLabel(centralwidget);
        column_number_text->setObjectName(QString::fromUtf8("column_number_text"));
        column_number_text->setGeometry(QRect(1020, 20, 221, 51));
        column_number_text->setFont(font);
        column_number_text->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 212, 176);\n"
""));
        max_text = new QLabel(centralwidget);
        max_text->setObjectName(QString::fromUtf8("max_text"));
        max_text->setGeometry(QRect(1080, 320, 61, 61));
        max_text->setFont(font);
        max_text->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 212, 176);\n"
""));
        textBrowser_max = new QTextBrowser(centralwidget);
        textBrowser_max->setObjectName(QString::fromUtf8("textBrowser_max"));
        textBrowser_max->setGeometry(QRect(1160, 320, 171, 61));
        textBrowser_max->setFont(font);
        textBrowser_max->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        textBrowser_min = new QTextBrowser(centralwidget);
        textBrowser_min->setObjectName(QString::fromUtf8("textBrowser_min"));
        textBrowser_min->setGeometry(QRect(1160, 250, 171, 61));
        textBrowser_min->setFont(font);
        textBrowser_min->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        textBrowser_med = new QTextBrowser(centralwidget);
        textBrowser_med->setObjectName(QString::fromUtf8("textBrowser_med"));
        textBrowser_med->setGeometry(QRect(1160, 390, 171, 61));
        textBrowser_med->setFont(font);
        textBrowser_med->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        min_text = new QLabel(centralwidget);
        min_text->setObjectName(QString::fromUtf8("min_text"));
        min_text->setGeometry(QRect(1080, 250, 61, 61));
        min_text->setFont(font);
        min_text->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 212, 176);\n"
""));
        med_text = new QLabel(centralwidget);
        med_text->setObjectName(QString::fromUtf8("med_text"));
        med_text->setGeometry(QRect(1080, 390, 61, 61));
        med_text->setFont(font);
        med_text->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 212, 176);\n"
""));
        pushButton_load = new QPushButton(centralwidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));
        pushButton_load->setGeometry(QRect(1030, 100, 301, 61));
        pushButton_load->setFont(font);
        pushButton_load->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);\n"
"\n"
""));
        comboBox_column_number = new QComboBox(centralwidget);
        comboBox_column_number->setObjectName(QString::fromUtf8("comboBox_column_number"));
        comboBox_column_number->setGeometry(QRect(1260, 20, 71, 61));
        comboBox_column_number->setFont(font);
        comboBox_column_number->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox_region = new QComboBox(centralwidget);
        comboBox_region->setObjectName(QString::fromUtf8("comboBox_region"));
        comboBox_region->setGeometry(QRect(710, 20, 281, 61));
        QFont font1;
        font1.setPointSize(13);
        comboBox_region->setFont(font1);
        comboBox_region->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(50, 100, 941, 811));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableWidget->horizontalHeader()->setMinimumSectionSize(30);
        tableWidget->horizontalHeader()->setDefaultSectionSize(75);
        tableWidget->verticalHeader()->setMinimumSectionSize(14);
        tableWidget->verticalHeader()->setDefaultSectionSize(22);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_calc_metr->setText(QCoreApplication::translate("MainWindow", "Calculate Metrics", nullptr));
        pushButton_file->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        textBrowser_name_file->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p></body></html>", nullptr));
        region_text->setText(QCoreApplication::translate("MainWindow", "Region:", nullptr));
        column_number_text->setText(QCoreApplication::translate("MainWindow", "Column number:", nullptr));
        max_text->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        min_text->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        med_text->setText(QCoreApplication::translate("MainWindow", "Med", nullptr));
        pushButton_load->setText(QCoreApplication::translate("MainWindow", "Load Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
