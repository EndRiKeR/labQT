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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tbl_main;
    QPushButton *btn_view_all;
    QPushButton *btn_view_part;
    QLabel *lbl_region;
    QLabel *lbl_column;
    QPushButton *btn_column_count;
    QLabel *lbl_txt_main;
    QLabel *lbl_max;
    QLabel *lbl_txt_min;
    QLabel *lbl_min;
    QLabel *lbl_med;
    QLabel *lbl_txt_med;
    QPushButton *btn_connect_file;
    QLabel *lbl_file;
    QLabel *lbl_file_name;
    QComboBox *cb_region;
    QComboBox *cb_colunm;
    QLabel *lbl_y;
    QLabel *lbl_x;
    QLabel *lbl_graf;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1033, 841);
        MainWindow->setMinimumSize(QSize(1033, 513));
        MainWindow->setMaximumSize(QSize(9000, 9000));
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
        tbl_main->setGeometry(QRect(30, 190, 971, 291));
        tbl_main->setEditTriggers(QAbstractItemView::NoEditTriggers);
        btn_view_all = new QPushButton(centralwidget);
        btn_view_all->setObjectName(QString::fromUtf8("btn_view_all"));
        btn_view_all->setGeometry(QRect(810, 30, 191, 41));
        btn_view_part = new QPushButton(centralwidget);
        btn_view_part->setObjectName(QString::fromUtf8("btn_view_part"));
        btn_view_part->setGeometry(QRect(810, 130, 191, 41));
        lbl_region = new QLabel(centralwidget);
        lbl_region->setObjectName(QString::fromUtf8("lbl_region"));
        lbl_region->setGeometry(QRect(30, 130, 261, 41));
        QFont font;
        font.setPointSize(12);
        lbl_region->setFont(font);
        lbl_column = new QLabel(centralwidget);
        lbl_column->setObjectName(QString::fromUtf8("lbl_column"));
        lbl_column->setGeometry(QRect(30, 80, 261, 41));
        lbl_column->setFont(font);
        btn_column_count = new QPushButton(centralwidget);
        btn_column_count->setObjectName(QString::fromUtf8("btn_column_count"));
        btn_column_count->setGeometry(QRect(810, 80, 191, 41));
        lbl_txt_main = new QLabel(centralwidget);
        lbl_txt_main->setObjectName(QString::fromUtf8("lbl_txt_main"));
        lbl_txt_main->setGeometry(QRect(400, 80, 41, 41));
        lbl_txt_main->setFont(font);
        lbl_max = new QLabel(centralwidget);
        lbl_max->setObjectName(QString::fromUtf8("lbl_max"));
        lbl_max->setGeometry(QRect(440, 80, 41, 41));
        lbl_max->setFont(font);
        lbl_max->setMouseTracking(true);
        lbl_max->setAcceptDrops(false);
        lbl_txt_min = new QLabel(centralwidget);
        lbl_txt_min->setObjectName(QString::fromUtf8("lbl_txt_min"));
        lbl_txt_min->setGeometry(QRect(520, 80, 41, 41));
        lbl_txt_min->setFont(font);
        lbl_min = new QLabel(centralwidget);
        lbl_min->setObjectName(QString::fromUtf8("lbl_min"));
        lbl_min->setGeometry(QRect(560, 80, 41, 41));
        lbl_min->setFont(font);
        lbl_min->setMouseTracking(true);
        lbl_med = new QLabel(centralwidget);
        lbl_med->setObjectName(QString::fromUtf8("lbl_med"));
        lbl_med->setGeometry(QRect(670, 80, 41, 41));
        lbl_med->setFont(font);
        lbl_med->setMouseTracking(true);
        lbl_med->setTabletTracking(false);
        lbl_med->setAcceptDrops(false);
        lbl_txt_med = new QLabel(centralwidget);
        lbl_txt_med->setObjectName(QString::fromUtf8("lbl_txt_med"));
        lbl_txt_med->setGeometry(QRect(630, 80, 41, 41));
        lbl_txt_med->setFont(font);
        btn_connect_file = new QPushButton(centralwidget);
        btn_connect_file->setObjectName(QString::fromUtf8("btn_connect_file"));
        btn_connect_file->setGeometry(QRect(380, 30, 411, 41));
        lbl_file = new QLabel(centralwidget);
        lbl_file->setObjectName(QString::fromUtf8("lbl_file"));
        lbl_file->setGeometry(QRect(30, 30, 141, 41));
        QFont font1;
        font1.setPointSize(14);
        lbl_file->setFont(font1);
        lbl_file_name = new QLabel(centralwidget);
        lbl_file_name->setObjectName(QString::fromUtf8("lbl_file_name"));
        lbl_file_name->setGeometry(QRect(180, 30, 191, 41));
        QFont font2;
        font2.setPointSize(10);
        lbl_file_name->setFont(font2);
        cb_region = new QComboBox(centralwidget);
        cb_region->addItem(QString());
        cb_region->addItem(QString());
        cb_region->setObjectName(QString::fromUtf8("cb_region"));
        cb_region->setGeometry(QRect(260, 130, 531, 41));
        cb_colunm = new QComboBox(centralwidget);
        cb_colunm->addItem(QString());
        cb_colunm->setObjectName(QString::fromUtf8("cb_colunm"));
        cb_colunm->setGeometry(QRect(260, 80, 121, 41));
        lbl_y = new QLabel(centralwidget);
        lbl_y->setObjectName(QString::fromUtf8("lbl_y"));
        lbl_y->setGeometry(QRect(80, 482, 201, 20));
        lbl_x = new QLabel(centralwidget);
        lbl_x->setObjectName(QString::fromUtf8("lbl_x"));
        lbl_x->setGeometry(QRect(930, 770, 63, 20));
        lbl_graf = new QLabel(centralwidget);
        lbl_graf->setObjectName(QString::fromUtf8("lbl_graf"));
        lbl_graf->setGeometry(QRect(30, 500, 971, 321));
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
        lbl_region->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\204\320\270\320\273\321\214\321\202\321\200 \320\264\320\273\321\217 \320\277\320\276\320\270\321\201\320\272\320\260:", nullptr));
        lbl_column->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\272\320\276\320\273\320\276\320\275\320\272\320\270:", nullptr));
        btn_column_count->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        lbl_txt_main->setText(QCoreApplication::translate("MainWindow", "Max:", nullptr));
        lbl_max->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        lbl_txt_min->setText(QCoreApplication::translate("MainWindow", "Min:", nullptr));
        lbl_min->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        lbl_med->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        lbl_txt_med->setText(QCoreApplication::translate("MainWindow", "Med:", nullptr));
        btn_connect_file->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        lbl_file->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \321\204\320\260\320\271\320\273: ", nullptr));
        lbl_file_name->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        cb_region->setItemText(0, QCoreApplication::translate("MainWindow", "Choose region", nullptr));
        cb_region->setItemText(1, QCoreApplication::translate("MainWindow", "All Regions", nullptr));

        cb_colunm->setItemText(0, QCoreApplication::translate("MainWindow", "Choose column", nullptr));

        lbl_y->setText(QString());
        lbl_x->setText(QString());
        lbl_graf->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
