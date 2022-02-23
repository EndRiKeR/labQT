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
    input_file();
}

void MainWindow::input_file()
{
    list = new std::list<std::string>;
    input_data_from_file(*list, "E:/myProgects/labQT/lab2_csv_app/russian_demography.csv");
    listOfWords = new std::vector<std::string>;
    for (auto & str : *list) {
        split_str_to_words(*listOfWords, str, ',');
    }
}

MainWindow::~MainWindow()
{
    clearAllItem();
    delete ui;
}

void MainWindow::on_btn_add_row_clicked()
{
    ex.row = list->size();
    ui->tbl_main->setRowCount(++ex.row);
    std::string str = listOfWords[0];
    QString qstr = QString::fromStdString(str);
    for (size_t i = 0; i < ui->tbl_main->rowCount(); ++i) {
        for (size_t j = 0; j < ui->tbl_main->columnCount(); ++j) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(listOfWords[j]));
            ui->tbl_main->setItem(i, j, item);
        }
    }
}

void MainWindow::clearAllItem()
{
    for (int i = 0; i < ui->tbl_main->rowCount(); ++i) {
        for (int j = 0; j < ui->tbl_main->columnCount(); ++ j) {
            delete ui->tbl_main->item(i, j);
        }
    }
    delete list;
    delete listOfWords;
}
