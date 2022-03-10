#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QWidget>
#include "BLogic.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>

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
    ui->tbl_main->clearContents();
    clearAllNew(data);
    delete ui;
}

//Окна вне таблички
void MainWindow::infoForUser()
{
    std::ifstream readMeFile("D:/progectsForCPP/labQT/lab2_csv_app/READ_ME");
    std::string temp;
    std::string str;
    if (readMeFile.is_open()) {
        while (getline(readMeFile, temp)) {
            str += temp;
            str += '\n';
        }
    }
    QMessageBox msgBox;
    msgBox.setText("Используя данную программу, Вы соглашаетесь с условиями пользовательского соглашения.");
    msgBox.setInformativeText("Вы согласны?");
    msgBox.setDetailedText(str.c_str());
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int answer = msgBox.exec();
    switch (answer) {
    case QMessageBox::Yes:
        break;
    case QMessageBox::No:
        QMessageBox::information(0, "ERROR", "Очень жаль.");
        MainWindow::~MainWindow();
        break;
    default:
        MainWindow::~MainWindow();
        break;
    }
}

//Подключение файла
void MainWindow::on_btn_connect_file_clicked()
{
    openFileAndTakeName(data);
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
        ui->tbl_main->clearContents();
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
        ui->tbl_main->clearContents();
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
        errorInfo = "Не удалось открыть файл!\nПрезапустите прграмму и попробуйте снова!\n\nErCode = ErFileOpen";
        break;
    case ErFileRead:
        errorInfo = "Не удалось считать файл!\nПрезапустите прграмму и попробуйте снова!\n\nErCode = ErFileRead";
        break;
    case ErUncorrectColumn:
        errorInfo = "Неверно введена колонка (от 3 до 7)!\nПрезапустите прграмму и попробуйте снова!\n\nErCode = ErUncorrectColumn";
        break;
    case DoNone:
        errorInfo = "Я не знаю, как вы попали сюда, но это плохо!\nПрезапустите прграмму и попробуйте снова!\n\nErCode = DoNone";
        break;
    case DoDefault:
        errorInfo = "Я не знаю, как вы попали сюда, но это плохо!\nПрезапустите прграмму и попробуйте снова!\n\nErCode = DoDefault";
        break;
    case ErRowZero:
        errorInfo = "По вашему запросу ничего не найдено.\nПроверьте корректность своего запроса!\n\nErCode = ErRowZero";
        break;
    case ErFileQuality:
        errorInfo = "Ваш файл не соответствует стандарту.\nПокайтесь и проверьте файл!\n\nErCode = ErFileQuality";
        break;
    default:
        errorInfo = "Я не знаю, как вы сюда умудрились попасть, но это ужасно!\nПрезапустите прграмму и попробуйте снова!\n\nErCode = DoSwitchDefault";
        break;
    }
    QMessageBox::information(0, "ERROR", errorInfo);
    data.error = NoError;
}

bool isDigit(std::string& str)
{
    bool digit = true;
    if (str == ".") {
        digit = false;
    } else {
        bool justPoint = false;
        QString qstr = QString::fromStdString(str);
        for (size_t i = 0; i < str.size(); ++i) {
            if (i == 0 && qstr[0] == '-') {
                continue;
            }
            if ((!qstr[i].isDigit() && qstr[i] != '.')
                    || (qstr == '.' && justPoint)) {
                digit = false;
                break;
            } else if (qstr[i] == '.' && !justPoint) {
                justPoint = true;
            }
        }
    }
    return digit;
}

bool isDigit(QString& qstr)
{
    bool digit = true;
    if (qstr == ".") {
        digit = false;
    } else {
        bool justPoint = false;
        for (size_t i = 0; i < qstr.size(); ++i) {
            if ((!qstr[i].isDigit() && qstr[i] != '.')
                    || (qstr == '.' && justPoint)) {
                digit = false;
                break;
            } else if (qstr[i] == '.' && !justPoint) {
                justPoint = true;
            }
        }
    }
    return digit;
}
