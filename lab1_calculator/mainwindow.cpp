#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>

void numberNowCheck(QPushButton* button);
void whatINeedToDo();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_0, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_1, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_2, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_3, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_4, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_5, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_6, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_7, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_8, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_9, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_plus, &QPushButton::clicked, this, &MainWindow::on_btn_move_clicked);
    connect(ui->btn_minus, &QPushButton::clicked, this, &MainWindow::on_btn_move_clicked);
    connect(ui->btn_mult, &QPushButton::clicked, this, &MainWindow::on_btn_move_clicked);
    connect(ui->btn_divide, &QPushButton::clicked, this, &MainWindow::on_btn_move_clicked);
    connect(ui->btn_clear, &QPushButton::clicked, this, &MainWindow::on_btn_clear_clicked);
    connect(ui->btn_delete, &QPushButton::clicked, this, &MainWindow::on_btn_delete_clicked);
    connect(ui->btn_result, &QPushButton::clicked, this, &MainWindow::on_btn_result_clicked); // double result  bug
    ui->btn_delete->setEnabled(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

struct calcMath mathInstrument = {0.0, 0.0, false, 1, "None", true}; // Да, это глобальная переменная. Ну убейте, не знаю, как без нее

void MainWindow::on_btn_numeric_clicked() //Эта функция отслеживает нажатие на циферки и текущее число
{
    QPushButton *button = (QPushButton *)sender(); // Can I use C-style ((QPushButton *))?
    if (mathInstrument.point) { // bug with unenabled buttons
        mathInstrument.numberNow = mathInstrument.numberNow + ((button->text()).toDouble() / pow(10.0, mathInstrument.pointDeep++));
    } else {
        mathInstrument.numberNow = mathInstrument.numberNow * 10 + (button->text()).toDouble();
    }

    if (QString::number(mathInstrument.numberNow, 'g', 15).size() < 15) {
        ui->lbl_main->setText(QString::number(mathInstrument.numberNow, 'g', 15));
    } else {
        ui->centralwidget->setEnabled(0);
        ui->lbl_main->setText("Only Restart");
        //Here new window with error
    }
    outputStatisticData(&mathInstrument); //Вспомогательная функция для понимая, что лежит в структуре
}

void MainWindow::on_btn_move_clicked() //Общая функция для всех действий
{
    QPushButton *button = (QPushButton *)sender();
    whatINeedToDo();
    mathInstrument.numberNow = 0.0;
    mathInstrument.point = false;
    ui->btn_point->setEnabled(1);
    mathInstrument.nextMove = button->text();
    mathInstrument.pointDeep = 1;
    ui->lbl_main->setText(QString::number(mathInstrument.result, 'g', 15));
    outputStatisticData(&mathInstrument);
}

void MainWindow::on_btn_clear_clicked()
{
    mathInstrument = {0.0, 0.0, false, 1, "None", true};
    ui->lbl_main->setText(QString::number(mathInstrument.numberNow, 'g', 15));
    ui->btn_point->setEnabled(1);
    outputStatisticData(&mathInstrument);
}

void outputStatisticData(calcMath* mathInstrument)
{
    std::cout << mathInstrument->numberNow << " " << mathInstrument->result << " " << mathInstrument->nextMove.toStdString() << std::endl;
}



void MainWindow::on_btn_point_clicked()
{
    mathInstrument.point = true;
    QPushButton *button = (QPushButton *)sender();
    button->setEnabled(0);
    if (QString::number(mathInstrument.numberNow, 'g', 15).size() < 15) {
        ui->lbl_main->setText(QString::number(mathInstrument.numberNow, 'g', 15) + '.');
    }
    outputStatisticData(&mathInstrument); //Вспомогательная функция для понимая, что лежит в структуре
}


void MainWindow::on_btn_result_clicked()
{
    if (mathInstrument.nextMove.toStdString() != "None") {
        whatINeedToDo();
        ui->btn_point->setEnabled(1);
        ui->lbl_main->setText(QString::number(mathInstrument.result, 'g', 15));
        outputStatisticData(&mathInstrument);
        mathInstrument = {0.0, 0.0, false, 1, "None", true};
    }
}

void whatINeedToDo()
{
    if (mathInstrument.firstTimeRes) {
        mathInstrument.result = mathInstrument.numberNow;
        mathInstrument.firstTimeRes = false;
    } else {
        switch(mathInstrument.nextMove.toStdString()[0]) {
            case '+':
                mathInstrument.result += mathInstrument.numberNow;
                break;
            case '-':
                mathInstrument.result -= mathInstrument.numberNow;
                break;
            case '/':
                if (mathInstrument.numberNow != 0) {
                    mathInstrument.result = mathInstrument.result / mathInstrument.numberNow;
                } else {
                    //new error window
                }
                break;
            case '*':
                mathInstrument.result *= mathInstrument.numberNow;
                break;
            default:
                //new error window
                break;
        }
    }
}

void MainWindow::on_btn_delete_clicked()
{
    //пока не реализовано
    ui->btn_delete->setEnabled(0);
}

