#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>
#include <string>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_numeric_clicked() //Эта функция отслеживает нажатие на циферки и текущее число
{
    QPushButton *button = (QPushButton *)sender(); // Can I use C-style ((QPushButton *))?
    if (mathInstrument.point) {
        mathInstrument.numberNow = mathInstrument.numberNow + ((button->text()).toDouble() / pow(10.0, mathInstrument.pointDeep++));
    } else {
        mathInstrument.numberNow = mathInstrument.numberNow * 10 + (button->text()).toDouble();
    }

    if (QString::number(mathInstrument.numberNow, 'g', 15).size() < 15) {
        if (ui->lbl_main->text() == "0") {
            ui->lbl_main->setText("");
        }
        ui->lbl_main->setText(ui->lbl_main->text() + button->text());
    } else {
        ui->centralwidget->setEnabled(0);
        ui->lbl_main->setText("Only Restart");
        QMessageBox::information(0, "ERROR", "Вы переполнили память калькулятора. Покайтесь и перезапустите калькулятор.");
    }
    outputStatisticData(&mathInstrument);
}

void MainWindow::on_btn_move_clicked() //Общая функция для всех действий
{
    QPushButton *button = (QPushButton *)sender();
    whatINeedToDo(&mathInstrument);
    mathInstrument.numberNow = 0.0;
    mathInstrument.point = false;
    ui->btn_point->setEnabled(1);
    mathInstrument.nextMove = button->text();
    mathInstrument.pointDeep = 1;
    ui->lbl_main->setText("0");
    outputStatisticData(&mathInstrument);
}

void MainWindow::on_btn_clear_clicked() //Очистка
{
    mathInstrument = {0.0, 0.0, false, 1, "None", true};
    ui->lbl_main->setText("0");
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
    } else {
        QMessageBox::information(0, "ERROR", "Вы переполнили память калькулятора. Покайтесь и перезапустите калькулятор.");
    }
    outputStatisticData(&mathInstrument);
}

void MainWindow::on_btn_result_clicked() //Вывод результата
{
    if (mathInstrument.nextMove.toStdString() != "None") {
        whatINeedToDo(&mathInstrument);
        ui->btn_point->setEnabled(1);
        ui->lbl_main->setText(QString::number(mathInstrument.result, 'g', 15));
        outputStatisticData(&mathInstrument);
        mathInstrument = {0.0, 0.0, false, 1, "None", true};
    }
}

bool myContainChInStr(std::string str, const char ch)
{
    bool result = false;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == ch) {
            result = true;
        }
    }
    return result;
}

void MainWindow::on_btn_delete_clicked() // Удаление
{
    std::string str = ui->lbl_main->text().toStdString();
    std::cout << str.size() << std::endl;
    size_t pos = str.size() - 1;
    if (str.size() <= 1) { // Нулевой символ + цифра
        ui->lbl_main->setText("0");
    } else {
        std::cout << str << " ";
        for (size_t i = str.size() - 1; i >= 0; --i) {
            if (str[i] != '\0') {
                str[i] = '\0';
                break;
            }
            pos -= 1;
        }
        ui->lbl_main->setText(QString::fromStdString(str.substr(0, pos)));
        mathInstrument.numberNow = atof(str.substr(0, pos).c_str());
        if (!myContainChInStr(ui->lbl_main->text().toStdString(), '.')) {
            ui->btn_point->setEnabled(1);
        }
    }
    std::cout << str << " " << mathInstrument.numberNow << std::endl;
}

void MainWindow::whatINeedToDo(struct calcMath* mathInstrument) // большая часть кода со switch для действий со знаками
{
    if (mathInstrument->firstTimeRes) {
        mathInstrument->result = mathInstrument->numberNow;
        mathInstrument->firstTimeRes = false;

    } else {
        switch(mathInstrument->nextMove.toStdString()[0]) {
            case '+':
                mathInstrument->result += mathInstrument->numberNow;
                break;
            case '-':
                mathInstrument->result -= mathInstrument->numberNow;
                break;
            case '/':
                if (mathInstrument->numberNow != 0) {
                    mathInstrument->result = mathInstrument->result / mathInstrument->numberNow;
                } else {
                   QMessageBox::information(0, "ERROR", "Вы решили поделить на ноль. Покайтесь и перезапустите калькулятор.");
                }
                break;
            case '*':
                mathInstrument->result *= mathInstrument->numberNow;
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
