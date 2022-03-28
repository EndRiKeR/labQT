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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *lblDraw;
    QPushButton *btnCalculateMetrix;
    QLabel *lblMin;
    QLabel *lblForMax;
    QComboBox *comboBox;
    QLabel *lblMax;
    QPushButton *btnChooseFile;
    QTableWidget *table;
    QPushButton *btnOutput;
    QLabel *lblForMed;
    QPushButton *btnLoadData;
    QLabel *lblOutputName;
    QLineEdit *inputRegion;
    QLabel *lblMed;
    QLabel *lblForMin;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 850);
        MainWindow->setMinimumSize(QSize(1000, 850));
        MainWindow->setMaximumSize(QSize(1000, 850));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 30, 921, 784));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lblDraw = new QLabel(gridLayoutWidget);
        lblDraw->setObjectName(QString::fromUtf8("lblDraw"));
        lblDraw->setMinimumSize(QSize(450, 550));
        lblDraw->setMaximumSize(QSize(450, 550));
        lblDraw->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(lblDraw, 10, 11, 1, 1);

        btnCalculateMetrix = new QPushButton(gridLayoutWidget);
        btnCalculateMetrix->setObjectName(QString::fromUtf8("btnCalculateMetrix"));
        btnCalculateMetrix->setMinimumSize(QSize(0, 60));
        btnCalculateMetrix->setMaximumSize(QSize(16777215, 60));
        btnCalculateMetrix->setStyleSheet(QString::fromUtf8("background-color: rgb(124, 133, 57);"));

        gridLayout->addWidget(btnCalculateMetrix, 3, 11, 1, 1);

        lblMin = new QLabel(gridLayoutWidget);
        lblMin->setObjectName(QString::fromUtf8("lblMin"));

        gridLayout->addWidget(lblMin, 3, 2, 1, 1);

        lblForMax = new QLabel(gridLayoutWidget);
        lblForMax->setObjectName(QString::fromUtf8("lblForMax"));

        gridLayout->addWidget(lblForMax, 3, 9, 1, 2);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 3, 0, 1, 1);

        lblMax = new QLabel(gridLayoutWidget);
        lblMax->setObjectName(QString::fromUtf8("lblMax"));

        gridLayout->addWidget(lblMax, 3, 8, 1, 1);

        btnChooseFile = new QPushButton(gridLayoutWidget);
        btnChooseFile->setObjectName(QString::fromUtf8("btnChooseFile"));
        btnChooseFile->setStyleSheet(QString::fromUtf8("background-color: rgb(124, 133, 57);"));

        gridLayout->addWidget(btnChooseFile, 0, 0, 1, 1);

        table = new QTableWidget(gridLayoutWidget);
        if (table->columnCount() < 7)
            table->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        table->setObjectName(QString::fromUtf8("table"));
        table->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 43, 62);\n"
""));

        gridLayout->addWidget(table, 10, 0, 1, 11);

        btnOutput = new QPushButton(gridLayoutWidget);
        btnOutput->setObjectName(QString::fromUtf8("btnOutput"));
        btnOutput->setStyleSheet(QString::fromUtf8("background-color: rgb(124, 133, 57);\n"
""));

        gridLayout->addWidget(btnOutput, 1, 11, 2, 1);

        lblForMed = new QLabel(gridLayoutWidget);
        lblForMed->setObjectName(QString::fromUtf8("lblForMed"));

        gridLayout->addWidget(lblForMed, 3, 6, 1, 2);

        btnLoadData = new QPushButton(gridLayoutWidget);
        btnLoadData->setObjectName(QString::fromUtf8("btnLoadData"));
        btnLoadData->setStyleSheet(QString::fromUtf8("background-color: rgb(124, 133, 57);"));

        gridLayout->addWidget(btnLoadData, 0, 11, 1, 1);

        lblOutputName = new QLabel(gridLayoutWidget);
        lblOutputName->setObjectName(QString::fromUtf8("lblOutputName"));
        lblOutputName->setStyleSheet(QString::fromUtf8("background-color:rgb(123, 133, 142);"));

        gridLayout->addWidget(lblOutputName, 0, 1, 1, 10);

        inputRegion = new QLineEdit(gridLayoutWidget);
        inputRegion->setObjectName(QString::fromUtf8("inputRegion"));
        inputRegion->setStyleSheet(QString::fromUtf8("background-color: rgb(118, 112, 126);\n"
""));

        gridLayout->addWidget(inputRegion, 1, 1, 1, 10);

        lblMed = new QLabel(gridLayoutWidget);
        lblMed->setObjectName(QString::fromUtf8("lblMed"));

        gridLayout->addWidget(lblMed, 3, 5, 1, 1);

        lblForMin = new QLabel(gridLayoutWidget);
        lblForMin->setObjectName(QString::fromUtf8("lblForMin"));

        gridLayout->addWidget(lblForMin, 3, 3, 1, 2);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lblDraw->setText(QString());
        btnCalculateMetrix->setText(QCoreApplication::translate("MainWindow", "Calculate and Draw", nullptr));
        lblMin->setText(QCoreApplication::translate("MainWindow", "Min:", nullptr));
        lblForMax->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Choose", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Npg", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "BirthRate", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "DeathRate", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Gdw", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Urbanization", nullptr));

        lblMax->setText(QCoreApplication::translate("MainWindow", "Max:", nullptr));
        btnChooseFile->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\204\320\260\320\271\320\273\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Year", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Region", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Npg", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Birth rate", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Death rate", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Gdw", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Urbanization", nullptr));
        btnOutput->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270", nullptr));
        lblForMed->setText(QString());
        btnLoadData->setText(QCoreApplication::translate("MainWindow", "Load data", nullptr));
        lblOutputName->setText(QString());
        lblMed->setText(QCoreApplication::translate("MainWindow", "Med:", nullptr));
        lblForMin->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Region 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
