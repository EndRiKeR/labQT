#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "newDataType.h"
#include "ui_mainwindow.h"
#include "calculatorLogic.h"
#include <iostream>
#include <cmath>
#include <string>
#include <QMessageBox>
#include <fstream>

bool myContainCharItStr(std::string str, const char& ch);

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT     

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Функция говорит сама за себя
    void infoForUser();

private slots:
    //вспомогательные функции
    void outputMD();
    bool checkBigText();
    void textErrorsChecker();
    void logicErrors(QString str, QPushButton* btn);

    //подключение кнопок
    void houstonConnectButtonPLS();

    //Функции по нажатию
    void on_btn_numeric_clicked();
    void on_btn_move_clicked();
    void on_btn_point_clicked();
    void clear_clicked();
    void result_clicked();
    void delete_clicked();
    void on_btn_swap_clicked();
    void on_btn_werewolf_clicked();
    void on_btn_sqrt_clicked();
    void on_btn_pow2_clicked();
    void on_btn_m_plus_clicked();
    void on_btn_m_minus_clicked();
    void on_btn_mr_clicked();
    void on_btn_mc_clicked();

    //Визуализация
    void updateLabel(QPushButton* btn);
    void doVisualInstrumentalOperation(QPushButton* btn);
    void doVisualAdd(QPushButton* btn);
    void doVisualDel();
    void doVisualPoint(QPushButton* btn);
    void doVisualRes();
    void doVisualClear();

    //тоже вспомогательные + простая запись больших
    void enableMoves(int i);
    void enableDelete(int i);
    void enableResult(int i);
    void enablePoint(int i);
    void enableNum(int i);
    void enableFunctions(int i);
    void enableMFunctions(int i);
    void enableAllBtn(int i);
private:
    Ui::MainWindow *ui;
    struct mathData md;
};
#endif // MAINWINDOW_H
