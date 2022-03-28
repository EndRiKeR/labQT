#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QWidget>
#include "BLogic.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>

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
    setupComboBox();

    setupGraf();
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
        QMessageBox::information(0, "ERROR", "Очень жаль.\nПодумайте еще раз!");
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
    if (data.error.erCode) {
        errorNotify();
    } else {
        ui->lbl_file_name->setText(data.fileName);
        ui->btn_view_all->setEnabled(1);
    }
}

//Показ всей таблицы
void MainWindow::on_btn_view_all_clicked()
{
    data.nextMove = ViewAll;
    data.filter = "";
    doData(data);
    if (data.error.erCode) {
        errorNotify();
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
    data.filter = ui->cb_region->currentText().toStdString();
    doData(data);
    if (data.error.erCode) {
        errorNotify();
    } else {
        ui->tbl_main->clearContents();
        outputTable();
    }
}

//Просчет по столбцу
void MainWindow::on_btn_column_count_clicked()
{
    on_btn_view_part_clicked();
    data.nextMove = CountStatistic;
    data.statistic.columnNum = ui->cb_colunm->currentText().toStdString();
    doData(data);
    if (data.error.erCode) {
         errorNotify();
    } else {
        ui->lbl_max->setText(QString::number(data.statistic.max));
        ui->lbl_min->setText(QString::number(data.statistic.min));
        ui->lbl_med->setText(QString::number(data.statistic.med));
    }
    drawGraf();
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

void MainWindow::errorNotify()
{
    QMessageBox::information(0, "ERROR", QString::fromStdString(data.error.erInfo));
    data.error.erCode = 0;
    data.error.erInfo = "";
}

//~~~~~~~~~~~~~~~~~~~~~~~~New Functions In Lab3~~~~~~~~~~~~~~~~~~~~~~~~~~~

void MainWindow::setupComboBox()
{
    ui->cb_colunm->addItem(QString::fromStdString("Nat Pop Grow"));
    ui->cb_colunm->addItem(QString::fromStdString("Birth Rate"));
    ui->cb_colunm->addItem(QString::fromStdString("Death Rate"));
    ui->cb_colunm->addItem(QString::fromStdString("Gen Dem Rate"));
    ui->cb_colunm->addItem(QString::fromStdString("Urbanization"));
}

void MainWindow::setupGraf()
{
    ui->lbl_graf->setPicture(picture);
}

void MainWindow::drawGraf()
{
    painter.begin(&picture);
    picture.setBoundingRect(QRect(QPoint(0, 0), QPoint(971, 321)));
    setupOXandOY();
    if (ui->cb_colunm->currentIndex() != 0 && ui->cb_region->currentIndex()) {
        setupMetrics();
    } else {
        data.error.erCode = ErColumnChoose;
        data.error.erInfo = "Вы не выбрали регион и/или столбец для построения графа.\nПроверьте корректность своего запроса!\n\nErCode = ErColumnChoose";
    }
    setupGraf();
    painter.end();
}

void MainWindow::setupOXandOY()
{

    QPen pen(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(40, 0, 40, 470); //OY
    painter.drawLine(40, 270, 930, 270); //OX
    painter.drawLine(40, 0, 35, 15);
    painter.drawLine(40, 0, 45, 15);
    painter.drawLine(930, 270, 930 - 15, 265);
    painter.drawLine(930, 270, 930 - 15, 275);
    ui->lbl_x->setText("Year");
    if (ui->cb_colunm->currentIndex() != 0) {
        ui->lbl_y->setText(ui->cb_colunm->currentText());
    }
    setupGraf();
}

void MainWindow::setupMetrics()
{
    QPen pen(Qt::blue);
    pen.setWidth(5);
    painter.setPen(pen);
    struct point startP = {0.0, 0.0};
    struct point endP = {0.0, 0.0};
    struct point moveMult = {930. / data.yearsData.size(), 250. / (data.statistic.max - data.statistic.min)};
    bool first = true;
    for (const auto& el : data.colData) {
        if (first) {
            startP = {40 + moveMult.x, 321 - abs(321 - el * moveMult.y)}; //продумать формулу
            std::cout << "first point: [" << startP.x << "] [" << startP.y << "]" << std::endl;
            first = false;
            continue;
        }
        endP = {startP.x + moveMult.x, 321 - abs(321 - el * moveMult.y)};
        std::cout << "first point: [" << startP.x << "] [" << startP.y << "]\t"
                  << "last point: [" << endP.x << "] [" << endP.y << "]" << std::endl;
        painter.drawLine(startP.x, startP.y, endP.x, endP.y);
        startP = {endP.x, endP.y};
    }

}

