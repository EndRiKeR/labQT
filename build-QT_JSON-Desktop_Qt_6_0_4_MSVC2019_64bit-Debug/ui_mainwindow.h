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
#include <QtWidgets/QColumnView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QColumnView *colView;
    QPushButton *btnShowJson;
    QPushButton *btnReadJson;
    QLabel *resultLabel;
    QLabel *jsontext;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1009, 669);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        colView = new QColumnView(centralwidget);
        colView->setObjectName(QString::fromUtf8("colView"));
        colView->setGeometry(QRect(170, 70, 791, 241));
        QFont font;
        font.setPointSize(8);
        colView->setFont(font);
        colView->setEditTriggers(QAbstractItemView::DoubleClicked);
        colView->setResizeGripsVisible(true);
        btnShowJson = new QPushButton(centralwidget);
        btnShowJson->setObjectName(QString::fromUtf8("btnShowJson"));
        btnShowJson->setEnabled(false);
        btnShowJson->setGeometry(QRect(60, 200, 80, 41));
        btnReadJson = new QPushButton(centralwidget);
        btnReadJson->setObjectName(QString::fromUtf8("btnReadJson"));
        btnReadJson->setGeometry(QRect(60, 130, 80, 41));
        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));
        resultLabel->setGeometry(QRect(170, 10, 661, 41));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setStyleStrategy(QFont::PreferAntialias);
        resultLabel->setFont(font1);
        jsontext = new QLabel(centralwidget);
        jsontext->setObjectName(QString::fromUtf8("jsontext"));
        jsontext->setGeometry(QRect(170, 320, 781, 291));
        QFont font2;
        font2.setPointSize(10);
        jsontext->setFont(font2);
        jsontext->setCursor(QCursor(Qt::PointingHandCursor));
        jsontext->setFrameShape(QFrame::Box);
        jsontext->setMargin(20);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1009, 20));
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
        btnShowJson->setText(QCoreApplication::translate("MainWindow", "Show JSON", nullptr));
        btnReadJson->setText(QCoreApplication::translate("MainWindow", "Read JSON", nullptr));
        resultLabel->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270 \321\204\320\260\320\271\320\273\320\260", nullptr));
        jsontext->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \320\272\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
