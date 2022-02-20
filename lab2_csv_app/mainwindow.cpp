#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setSizeColumToDefault();
}

MainWindow::~MainWindow()
{
    clearAllItem();
    delete ui;
}

void MainWindow::on_btn_add_row_clicked()
{
    ex.row += 1;
    ui->tbl_main->setRowCount(ex.row);
    QTableWidgetItem *newItem;
    QVariant var("Hello1");
    for (int i = 0; i < ex.column; ++i) {
        //newItem = ui->tbl_main->item(ex.row, i);
        newItem = new QTableWidgetItem;
        newItem->setData(Qt::DisplayRole, var.toString());
        newItem->setData(Qt::EditRole, var.toString());
        var = var.toString() + "Hello";
        ui->tbl_main->setItem(ex.row, i, newItem);
        std::cout << "After: " << newItem->text().toStdString() << std::endl;
    }
}

void MainWindow::clearAllItem()
{
    for (int i = 0; i < ex.row; ++i) {
        for (int j = 0; j < ex.column; ++ j) {
            delete ui->tbl_main->item(i, j);
        }
    }
}
