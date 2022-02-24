#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QWidget>
#include "BLogic.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setSizeColumToDefault();
}

MainWindow::~MainWindow()
{
    clearAll();
    delete ui;
}

void MainWindow::on_btn_view_all_clicked()
{
    ui->txt_region->clear();
    inputFile();
    clearAllItem();
    outputTable();
}

void MainWindow::on_btn_view_part_clicked()
{
    inputFile();
    clearAllItem();
    outputTable();
}

void MainWindow::outputTable()
{
    QTableWidgetItem* item;
    QString qstr;
    ui->tbl_main->setRowCount(ex.row - 1);
    auto it = listOfWords->begin();
    for (size_t i = 0; i < ui->tbl_main->rowCount(); ++i) {
        for (size_t j = 0; j < ui->tbl_main->columnCount(); ++j) {
            qstr = QString::fromStdString(*it);
            if (qstr == "") {
                qstr = "-";
            }
            item = new QTableWidgetItem(qstr);
            ui->tbl_main->setItem(i, j, item);
            it++;
            if (it  == listOfWords->end()) {
                break;
            }
        }
    }
    QMessageBox::information(0, "Все ок!", "Ваша таблица была успешно загружена)");
}

void MainWindow::inputFile()
{
    list = new std::list<std::string>;
    std::string region = ui->txt_region->toPlainText().toStdString();
    if (ui->txt_region->toPlainText() == "") {
        region = ",";
    }
    inputDataFromFile(*list,
                            "E:/myProgects/labQT/lab2_csv_app/russian_demography.csv",
                            region);
    ex.row = list->size();
    listOfWords = new std::list<std::string>;
    for (auto & str : *list) {
        splitStrToWords(*listOfWords, str, ',');
    }
    delete list;
}

void MainWindow::clearAllItem()
{
    for (int i = 0; i < ui->tbl_main->rowCount(); ++i) {
        for (int j = 0; j < ui->tbl_main->columnCount(); ++ j) {
            delete ui->tbl_main->item(i, j);
        }
    }
}

void MainWindow::clearAll()
{
    clearAllItem();
    delete list;
    delete listOfWords;
}
