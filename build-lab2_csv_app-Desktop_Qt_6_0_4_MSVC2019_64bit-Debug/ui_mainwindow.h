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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tbl_main;
    QPushButton *btn_view_all;
    QPushButton *btn_view_part;
    QTextEdit *txt_region;
    QLabel *lbl_region;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1033, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tbl_main = new QTableWidget(centralwidget);
        if (tbl_main->columnCount() < 7)
            tbl_main->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tbl_main->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tbl_main->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setText(QString::fromUtf8("Nat Pop Grow"));
        tbl_main->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tbl_main->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tbl_main->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tbl_main->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tbl_main->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tbl_main->setObjectName(QString::fromUtf8("tbl_main"));
        tbl_main->setGeometry(QRect(30, 280, 971, 291));
        tbl_main->setEditTriggers(QAbstractItemView::NoEditTriggers);
        btn_view_all = new QPushButton(centralwidget);
        btn_view_all->setObjectName(QString::fromUtf8("btn_view_all"));
        btn_view_all->setGeometry(QRect(810, 220, 191, 41));
        btn_view_part = new QPushButton(centralwidget);
        btn_view_part->setObjectName(QString::fromUtf8("btn_view_part"));
        btn_view_part->setGeometry(QRect(810, 170, 191, 41));
        txt_region = new QTextEdit(centralwidget);
        txt_region->setObjectName(QString::fromUtf8("txt_region"));
        txt_region->setGeometry(QRect(210, 170, 581, 41));
        lbl_region = new QLabel(centralwidget);
        lbl_region->setObjectName(QString::fromUtf8("lbl_region"));
        lbl_region->setGeometry(QRect(30, 170, 191, 41));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbl_main->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Year", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl_main->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Region", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl_main->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Birth Rate", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl_main->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Death Rate", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl_main->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Gen Dem Rate", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl_main->horizontalHeaderItem(6);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Urbanization", nullptr));
        btn_view_all->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\277\320\276\320\273\320\275\321\203\321\216 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        btn_view_part->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \321\207\320\260\321\201\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\207\320\272\320\270", nullptr));
        lbl_region->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\265\320\263\320\270\320\276\320\275 \320\264\320\273\321\217 \320\277\320\276\320\270\321\201\320\272\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H