#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>

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
    connect(ui->btn_delete, &QPushButton::clicked, this, &MainWindow::on_btn_delete_clicked, Qt::ConnectionType::SingleShotConnection);
    connect(ui->btn_result, &QPushButton::clicked, this, &MainWindow::on_btn_result_clicked); // double result  bug
    //ui->btn_delete->setEnabled(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

struct calcMath mathInstrument = {0.0, 0.0, false, 1, "None", true}; // Да, это глобальная переменная. Ну убейте, не знаю, как без нее

void MainWindow::on_btn_numeric_clicked() //Эта функция отслеживает нажатие на циферки и текущее число
{
    QPushButton *button = (QPushButton *)sender(); // Can I use C-style ((QPushButton *))?
    if (mathInstrument.point) {
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
    outputStatisticData(&mathInstrument);
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

void MainWindow::on_btn_clear_clicked() //Очистка
{
    mathInstrument = {0.0, 0.0, false, 1, "None", true};
    ui->lbl_main->setText(QString::number(mathInstrument.numberNow, 'g', 15));
    ui->btn_point->setEnabled(1);
    outputStatisticData(&mathInstrument);
}

void MainWindow::on_btn_point_clicked() //Точка в числе
{
    mathInstrument.point = true;
    QPushButton *button = (QPushButton *)sender();
    button->setEnabled(0);
    if (QString::number(mathInstrument.numberNow, 'g', 15).size() < 15) {
        ui->lbl_main->setText(QString::number(mathInstrument.numberNow, 'g', 15) + '.');
    }
    outputStatisticData(&mathInstrument);
}

void MainWindow::on_btn_result_clicked() //Вывод результата
{
    if (mathInstrument.nextMove.toStdString() != "None") {
        whatINeedToDo();
        ui->btn_point->setEnabled(1);
        ui->lbl_main->setText(QString::number(mathInstrument.result, 'g', 15));
        outputStatisticData(&mathInstrument);
        mathInstrument = {0.0, 0.0, false, 1, "None", true};
    }
}

void MainWindow::on_btn_delete_clicked() // Удаление
{
//    bool point = false;
    double temp = mathInstrument.numberNow;
    std::string str = std::to_string(temp);
    std::cout << str << " " << str.size() << " " << temp << "\t";
    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] != '0' & str[i] != '\0') { //Тут можно contain использовать
            str[i] = '\0';
//            if (point) {
//                ui->btn_delete->setEnabled(1);
//            }
            break;
        }
//        if (str[i] == '.') {
//            point = true;
//        }
    }
    temp = atof(str.c_str());
    mathInstrument.numberNow = temp;
    ui->lbl_main->setText(QString::number(temp, 'g', 15));
    std::cout << str << " " << str.size() << " " << temp << std::endl;
}

void whatINeedToDo() // большая часть кода со switch для действий со знаками
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

void outputStatisticData(calcMath* mathInstrument) //Вспомогательная функция для понимая, что лежит в структуре
{
    std::cout << mathInstrument->numberNow << " " << mathInstrument->result << " " << mathInstrument->nextMove.toStdString() << std::endl;
}