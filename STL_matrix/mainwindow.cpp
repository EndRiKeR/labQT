#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    matrixTest();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void matrixTest()
{
    MyMatrix<int> matDefault;
    outputFCKMatrix(matDefault);
    MyMatrix<int> matSizeConstruct(3, 3);
    outputFCKMatrix(matSizeConstruct);
    MyMatrix<int> matCopy(matSizeConstruct);
    outputFCKMatrix(matCopy);


}

void outputFCKMatrix(class MyMatrix<int>& matrix)
{
    if (matrix.get_pointer_on_data() != nullptr) {
        std::cout << "Output Matrix" << std::endl;
        for (size_t i = 0; i < matrix.get_count_of_rows(); ++i) {
            for (size_t j = 0; j < matrix.get_count_of_columns(); ++j) {
                std::cout << "[" << matrix[i][j] << "]\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

