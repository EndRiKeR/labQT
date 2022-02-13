#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>
#include <string>
#include <QMessageBox>
#include <fstream>
#include <locale>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    setlocale(LC_ALL, "Russian");
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
    connect(ui->btn_clear, &QPushButton::clicked, this, &MainWindow::clear_clicked);
    connect(ui->btn_delete, &QPushButton::clicked, this, &MainWindow::delete_clicked);
    connect(ui->btn_result, &QPushButton::clicked, this, &MainWindow::result_clicked);
    //Решение бага с двойным подключением: Qt автоматически подключает такие названия.
    //Например, есть кнопка ui->name и если просто создать слот с именем on_name_clicked(),
    //то Qt сам подключит сигнал clicked() к этому слоту внутри вызова ui->setupUi(this).
    //Поэтому, можно либо переименовать название слота, либо не подключать его вручную.
    //www.cyberforum.ru by Humanoid
    enableMoves(0);
    enableResult(0);
    enableDelete(0);
    enableSwap(0);
    std::cout << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::infoForUser() //Сообщение, в котором объясняется работа калькулятора
{
    std::ifstream readMeFile("E:/myProgects/labQT/lab1_calculator/READ_ME");
    std::string temp;
    std::string str;
    if (readMeFile.is_open()) {
        while (getline(readMeFile, temp)) {
            str += temp;
            str += '\n';
        }
    }
    QMessageBox msgBox;
    msgBox.setText("Используя этот калькулятор Вы соглашаетесь с условиями пользовательского соглашения.");
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

void MainWindow::on_btn_numeric_clicked() //Эта функция отслеживает нажатие на циферки и текущее число
{
    //Включение кнопок
    enableMoves(1);
    enableDelete(1);
    if (mathInstrument.nextMove != "None") {
        enableResult(1);
    }
    //Математика
    QPushButton *button = (QPushButton *)sender(); // Can I use C-style ((QPushButton *))?
    if (mathInstrument.point) {
        mathInstrument.numberNow = mathInstrument.numberNow + ((button->text()).toDouble() / pow(10.0, mathInstrument.pointDeep++));
    } else {
        mathInstrument.numberNow = mathInstrument.numberNow * 10 + (button->text()).toDouble();
    }
    //Вывод
    if (QString::number(mathInstrument.numberNow, 'g', 15).size() < 15) {
        if (ui->lbl_main->text() == "0" || mathInstrument.nextMove == "Res" || mathInstrument.afterMove) {
            ui->lbl_main->setText("");
            mathInstrument.afterMove = false;
        }
        ui->lbl_main->setText(ui->lbl_main->text() + button->text());
    } else {
        enableAllBtn(0);
        ui->lbl_main->setText("Only Restart");
        QMessageBox::information(0, "ERROR", "Вы переполнили память калькулятора. Покайтесь и перезапустите калькулятор.");
    }
    if (ui->lbl_main->text().toStdString() != "0") {
        enableSwap(1);
    }
    outputStatisticData(&mathInstrument, "Number (0 - 9)");
}

void MainWindow::on_btn_point_clicked() //Точка в числе
{
    mathInstrument.point = true;
    enableResult(0);
    enablePoint(0);
    if (QString::number(mathInstrument.numberNow, 'g', 15).size() < 15) {
        ui->lbl_main->setText(QString::number(mathInstrument.numberNow, 'g', 15) + '.');
    } else {
        QMessageBox::information(0, "ERROR", "Вы переполнили память калькулятора. Покайтесь и перезапустите калькулятор.");
    }
    outputStatisticData(&mathInstrument, "Point (.)");
}

void MainWindow::delete_clicked() // Удаление
{
    std::string str = ui->lbl_main->text().toStdString();
    std::cout << "str len: " << str.size();
    size_t pos = str.size() - 1;
    if (str.size() <= 1) {
        ui->lbl_main->setText("0");
        mathInstrument.numberNow = 0;
        enableDelete(0);
        enableSwap(0);
    } else {
        std::cout << "str before: " << str << " ";
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
            enablePoint(1);
        } else {
            mathInstrument.pointDeep -= 1;
        }
    }
    std::cout << " str after: "<< str << " number now: " << mathInstrument.numberNow << std::endl;
}

void MainWindow::on_btn_move_clicked() //Общая функция для всех действий
{
    QPushButton *button = (QPushButton *)sender();
    whatINeedToDo(&mathInstrument);
    //настройка структуры
    mathInstrument.numberNow = 0.0;
    mathInstrument.point = false;
    mathInstrument.nextMove = button->text();
    mathInstrument.pointDeep = 1;
    mathInstrument.afterMove = true;
    ui->lbl_main->setText(QString::number(mathInstrument.result, 'g', 15));
    outputStatisticData(&mathInstrument, "Move (+,-,*,/)");
    //включение кнопок
    enablePoint(1);
    enableMoves(0);
    enableResult(0);
}

void MainWindow::result_clicked() //Вывод результата
{
    if (mathInstrument.nextMove != "None" && mathInstrument.nextMove != "Res") {
        whatINeedToDo(&mathInstrument);
        if (mathInstrument.result < 1e+16) {
            ui->lbl_main->setText(QString::number(mathInstrument.result, 'g', 15));
        } else {
            QMessageBox::information(0, "ERROR", "Вы переполнили память калькулятора. Покайтесь и перезапустите калькулятор.");
            ui->lbl_main->setText("Only Restart");
        }

        mathInstrument = {0.0, 0.0, false, 1, "Res", true};
        enableAllBtn(0);
        outputStatisticData(&mathInstrument, "Equale (=)");
    }
}

void MainWindow::clear_clicked() //Очистка
{
    mathInstrument = {0.0, 0.0, false, 1, "None", true, false};
    ui->lbl_main->setText("0");
    enableAllBtn(1);
    enableMoves(0);
    enableResult(0);
    enableDelete(0);
    enableSwap(0);
    outputStatisticData(&mathInstrument, "Clear (C)");
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
                   ui->lbl_main->setText("Only Restart");
                }
                break;
            case '*':
                mathInstrument->result *= mathInstrument->numberNow;
                break;
            default:
                QMessageBox::information(0, "ERROR", "Если вы видите эту строчку, то проверьтесь на сверх способности. Экзорцист уже вызван.\nПерезапустите калькулятор.");
                break;
        }
    }
}

void outputStatisticData(calcMath* mathInstrument, const std::string str) //Вспомогательная функция для понимая, что лежит в структуре
{
    std::cout << "Function: " << str << std::endl
              << "Number now: " << mathInstrument->numberNow << std::endl
              << "Result now: " << mathInstrument->result << std::endl
              << "Next move: " << mathInstrument->nextMove.toStdString() << std::endl << std::endl;
}

bool myContainChInStr(std::string str, const char ch) //Contains только в С++23 :(
{
    bool result = false;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == ch) {
            result = true;
        }
    }
    return result;
}

//Далее идут функции для группого и не очень включения/выключения кнопок
void MainWindow::enableMoves(int i)
{
    ui->btn_minus->setEnabled(i);
    ui->btn_plus->setEnabled(i);
    ui->btn_mult->setEnabled(i);
    ui->btn_divide->setEnabled(i);
}

void MainWindow::enableDelete(int i)
{
    ui->btn_delete->setEnabled(i);
}

void MainWindow::enableResult(int i)
{
    ui->btn_result->setEnabled(i);
}

void MainWindow::enablePoint(int i)
{
    ui->btn_point->setEnabled(i);
}

void MainWindow::enableNum(int i)
{
    ui->btn_0->setEnabled(i);
    ui->btn_1->setEnabled(i);
    ui->btn_2->setEnabled(i);
    ui->btn_3->setEnabled(i);
    ui->btn_4->setEnabled(i);
    ui->btn_5->setEnabled(i);
    ui->btn_6->setEnabled(i);
    ui->btn_7->setEnabled(i);
    ui->btn_8->setEnabled(i);
    ui->btn_9->setEnabled(i);
}

void MainWindow::enableSwap(int i)
{
    ui->btn_swap->setEnabled(i);
}

void MainWindow::enableAllBtn(int i)
{
    enableDelete(i);
    enableMoves(i);
    enableNum(i);
    enablePoint(i);
    enableResult(i);
    enableSwap(i);
    enableWerewolf(i);
}

void MainWindow::enableWerewolf(int i)
{
    ui->btn_werewolf->setEnabled(i);
}

void MainWindow::on_btn_swap_clicked()
{
    mathInstrument.numberNow = -mathInstrument.numberNow;
    ui->lbl_main->setText(QString::number(mathInstrument.numberNow, 'g', 15));
    outputStatisticData(&mathInstrument, "swap");
}

void MainWindow::on_btn_werewolf_clicked()
{

}

