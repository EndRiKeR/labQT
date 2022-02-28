#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QWidget>
#include "BLogic.h"
#include <QFileDialog>
#include <QMessageBox>

void securityBreach(struct dataFromFile& data);

//конструктор
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btn_column_count->setEnabled(0);
    ui->btn_view_all->setEnabled(0);
    ui->btn_view_part->setEnabled(0);
    setSizeColumToDefault();
}

//деструктор
MainWindow::~MainWindow()
{
    clearAll();
    delete ui;
}

//Подключение файла
void MainWindow::on_btn_connect_file_clicked()
{
    data.nextMove = OpenFile;
    doData(data);
    if (data.error) {
        securityBreach(data);
    } else {
        ui->lbl_file_name->setText(data.fileName);
        ui->btn_view_all->setEnabled(1);
    }
}

//Показ всей таблицы
void MainWindow::on_btn_view_all_clicked()
{
    data.nextMove = ViewAll;
    ui->txt_region->clear();
    data.filter = "";
    doData(data);
    if (data.error) {
        securityBreach(data);
    } else {
        clearAllItem();
        outputTable();
        ui->btn_column_count->setEnabled(1);
        ui->btn_view_part->setEnabled(1);
    }
}

//Показ части таблицы по заданной строке
void MainWindow::on_btn_view_part_clicked()
{
    data.nextMove = ViewPart;
    data.filter = ui->txt_region->toPlainText().toStdString();
    doData(data);
    if (data.error) {
        securityBreach(data);
    } else {
        clearAllItem();
        outputTable();
    }
}

//Просчет по столбцу
void MainWindow::on_btn_column_count_clicked()
{
    data.nextMove = CountStatistic;
    data.statistic.columnNum = ui->txt_column->toPlainText().toInt();
    doData(data);
    if (data.error) {
        ui->txt_column->clear();
        securityBreach(data);
    } else {
        ui->lbl_max->setText(QString::number(data.statistic.max));
        ui->lbl_min->setText(QString::number(data.statistic.min));
        ui->lbl_med->setText(QString::number(data.statistic.med));
    }
}

void securityBreach(struct dataFromFile& data)
{
    QString errorInfo;
    switch(data.error) {
    case ErFileOpen:
        errorInfo = "Не удалось открыть файл!\nПрезапустите прграмму и попробуйте снова!";
        break;
    case ErFileRead:
        errorInfo = "Не удалось считать файл!\nПрезапустите прграмму и попробуйте снова!";
        break;
    case ErUncorrectColumn:
        errorInfo = "Неверно введена колонка (от 4 до 7)!\nПрезапустите прграмму и попробуйте снова!";
        break;
    case DoNone:
        errorInfo = "Я не знаю, как вы попали сюда, но это плохо!\nПрезапустите прграмму и попробуйте снова!";
        break;
    case DoDefault:
        errorInfo = "Я не знаю, как вы попали сюда, но это плохо!\nПрезапустите прграмму и попробуйте снова!";
        break;
    default:
        errorInfo = "Я не знаю, как вы сюда умудрились попасть, но это ужасно!\nПрезапустите прграмму и попробуйте снова!";
        break;
    }
    QMessageBox::information(0, "ERROR", errorInfo);
    data.error = NoError;
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
    delete data.stringsFromFile;
    delete data.wordsFromFile;
}
