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

bool MyContainCharItStr(std::string str, const char& ch);

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT     

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void infoForUser();

private slots:
    void houstonConnectButtonPLS();

    void on_btn_numeric_clicked();
    void on_btn_move_clicked();
    void on_btn_point_clicked();
    void outputMD();
    void clear_clicked();
    void result_clicked();
    void delete_clicked();
    void on_btn_swap_clicked();
    void on_btn_werewolf_clicked();
    void on_btn_sqrt_clicked();

    void enableMoves(int i);
    void enableDelete(int i);
    void enableResult(int i);
    void enablePoint(int i);
    void enableNum(int i);
    void enableSwap(int i);
    void enableWerewolf(int i);
    void enableSQRT(int i);
    void enablePOW2(int i);
    void enableMPlus(int i);
    void enableMMinus(int i);
    void enableMClear(int i);
    void enableMResult(int i);
    void enableMFunctions(int i);
    void enableFunctions(int i);
    void enableAllBtn(int i);

    void on_btn_pow2_clicked();

    void on_btn_m_plus_clicked();
    void on_btn_m_minus_clicked();
    void on_btn_mr_clicked();
    void on_btn_mc_clicked();

    void updateLabel(QPushButton* btn = nullptr);
private:
    Ui::MainWindow *ui;
    struct mathData md;
};
#endif // MAINWINDOW_H
