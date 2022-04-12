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

    for (size_t i = 0; i < matCopy.get_count_of_rows(); ++i) {
        for (size_t j = 0; j < matCopy.get_count_of_columns(); ++j) {
            int a = i + j;
            matCopy.set_elem(i, j, a); //Можно прописать T const& для упрощения жизни?
        }
    }

    outputFCKMatrix(matCopy);

    matDefault = matCopy;
    outputFCKMatrix(matDefault, "matDefault = matCopy");

    matCopy += matCopy;
    outputFCKMatrix(matCopy, "matCopy += matCopy");

    matCopy -= matCopy;
    outputFCKMatrix(matCopy, "matCopy -= matCopy");

    //matCopy = matCopy + matDefault;
    //outputFCKMatrix(matCopy, "matCopy = matCopy + matDefault");


    auto it = matCopy.begin();

    std::cout << matDefault.get_elem(1, 1) << std::endl;
    std::cout << matDefault(1, 1) << std::endl;
    std::cout << matDefault[1][1] << std::endl;

    std::cout << matDefault.is_square() << std::endl;



}

void outputFCKMatrix(class MyMatrix<int>& matrix, const std::string& str)
{
    if (matrix.get_pointer_on_data() != nullptr) {
        std::cout << str << std::endl;
        for (size_t i = 0; i < matrix.get_count_of_rows(); ++i) {
            for (size_t j = 0; j < matrix.get_count_of_columns(); ++j) {
                std::cout << "[" << matrix[i][j] << "]\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

