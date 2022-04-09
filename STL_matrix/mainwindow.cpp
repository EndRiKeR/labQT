#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    std::cout << "TEST";
    ui->setupUi(this);
    matrixTest();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void matrixTest()
{
    std::cout << "TEST";
    MyMatrix<int> matDefault;
    MyMatrix<int> matSizeConstruct(3, 3);
    std::cout << matSizeConstruct;
    //MyMatrix<int> matInitList({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    //std::cout << matInitList;
    MyMatrix<int> matCopy(matDefault);
    //std::cout << matCopy;
    //matDefault = matSizeConstruct;
    //std::cout << matDefault;
}

