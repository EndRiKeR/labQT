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
    ui->btn_graf->setEnabled(0);
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
        ui->btn_graf->setEnabled(1);
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
    ui->cb_colunm->addItem(QString::fromStdString("Deat Rate"));
    ui->cb_colunm->addItem(QString::fromStdString("Gen Dem Rate"));
    ui->cb_colunm->addItem(QString::fromStdString("Urbanization"));
}

void MainWindow::setupGraf()
{
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
}

void MainWindow::drawGraf()
{
    scene->clear();
    setupOXandOY();
    if (ui->cb_colunm->currentIndex() != 0 && ui->cb_region->currentIndex()) {
        //setupMetrics(); // установка значений + годов
        scene->update();
    } else {
        data.error.erCode = ErColumnChoose;
        data.error.erInfo = "Вы не выбрали регион и/или столбец для построения графа.\nПроверьте корректность своего запроса!\n\nErCode = ErColumnChoose";
    }
    ui->graphicsView->setScene(scene);
}

void MainWindow::setupOXandOY()
{
    QPen pen(Qt::red);
    pen.setWidth(2);
    scene->addLine(40, 0, 40, 470, pen);
    scene->addLine(40, 250, 470, 250, pen);
    scene->addLine(40, 0, 35, 15, pen);
    scene->addLine(40, 0, 45, 15, pen);
    scene->addLine(470, 250, 455, 240, pen);
    scene->addLine(470, 250, 455, 260, pen);
    ui->lbl_x->setText("year");
    if (ui->cb_colunm->currentIndex() != 0) {
        ui->lbl_y->setText(ui->cb_colunm->currentText());
    }
}


void MainWindow::on_btn_graf_clicked()
{
    drawGraf();
}

