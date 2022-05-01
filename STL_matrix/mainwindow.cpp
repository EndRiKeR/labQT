#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"
#include <stdexcept>

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

void constructTest()
{
    MyMatrix<int> matDefault;
    MyMatrix<int> matZero(0, 0);
    MyMatrix<int> matCopyZero(matZero);
    MyMatrix<int> matSizeConstruct(3, 3);
    MyMatrix<int> matCopy(matSizeConstruct);

    try { //Как брать ссылку на функцию?
        outputFCKMatrix(matDefault, "MatDefault");
    } catch (std::string str) {
        std::cout << str << std::endl;
    }
    //testThis(matDefault, "MatDefault", outputFCKMatrix);
    try {
        outputFCKMatrix(matZero, "MatZero(0, 0)");
    } catch (std::string str) {
        std::cout << str << std::endl;
    }
    try {
        outputFCKMatrix(matCopyZero, "MatCopyZero from MatZero");
    } catch (std::string str) {
        std::cout << str << std::endl;
    }

    outputFCKMatrix(matSizeConstruct, "MatSizeConstruct(3, 3)");
    outputFCKMatrix(matCopy, "MatCopy from MatSizeConstruct");

//    try {
//        MyMatrix<int> matIt({{1, 2, 3},{1, 2, 3},{1, 2, 3}});
//        outputFCKMatrix(matIt, "MatIt: {{1, 2, 3},{1, 2, 3},{1, 2, 3}}");
//    } catch (const std::string str) {
//        std::cout << "Error! " << str << std::endl;
//    }

//    try {
//        MyMatrix<int> matIt2({{1},{1, 2, 3},{1, 2, 3}});
//    } catch (...) {
//        std::cout << "Error! " << std::endl;
//    }

//    try {
//        MyMatrix<int> matIt3({});
//    } catch (const std::string str) {
//        std::cout << "Error! " << str << std::endl;
//    }

}

void fillTest()
{
    MyMatrix<int> matCopy(3, 3);

    outputFCKMatrix(matCopy, "Create");

    for (size_t i = 0; i < matCopy.get_count_of_rows(); ++i) {
        for (size_t j = 0; j < matCopy.get_count_of_columns(); ++j) {
            int a = i + j;
            matCopy.set_elem(i, j, a);
        }
    }

    outputFCKMatrix(matCopy, "set_elem");

    for (size_t i = 0; i < matCopy.get_count_of_rows(); ++i) {
        for (size_t j = 0; j < matCopy.get_count_of_columns(); ++j) {
            int a = i + i;
            matCopy[i][j] = a;
        }
    }

    outputFCKMatrix(matCopy, "[]");

    for (size_t i = 0; i < matCopy.get_count_of_rows(); ++i) {
        for (size_t j = 0; j < matCopy.get_count_of_columns(); ++j) {
            int a = i + j + j + i;
            matCopy(i, j) = a;
        }
    }

    outputFCKMatrix(matCopy, "()");

}

void equaleTest()
{
    MyMatrix<int> testMat;
    MyMatrix<int> mat1(3, 3);
    MyMatrix<int> mat2(3, 3);
    MyMatrix<int> mat3(5, 5);
    fillMatrix(testMat);
    fillMatrix(mat1);
    fillMatrix(mat2);
    fillMatrix(mat3);

    outputFCKMatrix(mat1, "mat1");

    mat1 = testMat;
    outputFCKMatrix(mat1, "mat1 = testMat");

    mat2 = mat3;
    outputFCKMatrix(mat2, "mat2 = mat3");

    mat1 = mat3;
    outputFCKMatrix(mat1, "mat1 = mat3");
}

void mathTest()
{
    MyMatrix<int> matCopy(3, 3);
    MyMatrix<int> matDefault(3, 3);
    MyMatrix<int> matBroke(3, 4);
    MyMatrix<int> matZero;

    fillMatrix(matCopy);
    fillMatrix(matDefault);
    fillMatrix(matBroke);

    matCopy += matDefault;
    outputFCKMatrix(matCopy, "matCopy += matCopy");

    matCopy -= matCopy;
    outputFCKMatrix(matCopy, "matCopy -= matCopy");

    matCopy = matCopy + matDefault;
    outputFCKMatrix(matCopy, "matCopy = matCopy + matDefault");

    matCopy = matCopy - matDefault;
    outputFCKMatrix(matCopy, "matCopy = matCopy - matDefault");

    matCopy = matCopy + 5;
    outputFCKMatrix(matCopy, "matCopy = matCopy + 5");

    matCopy = matCopy - 3;
    outputFCKMatrix(matCopy, "matCopy = matCopy - 3");

    matCopy = matCopy * 2;
    outputFCKMatrix(matCopy, "matCopy = matCopy * 2");

    matCopy = matCopy / 2;
    outputFCKMatrix(matCopy, "matCopy = matCopy / 2");

    matCopy = matCopy / 0;
    outputFCKMatrix(matCopy, "matCopy = matCopy / 0");

    matCopy += matBroke;
    outputFCKMatrix(matCopy, "matCopy += matBroke");

    matCopy -= matBroke;
    outputFCKMatrix(matCopy, "matCopy -= matBroke");

    matCopy += matZero;
    outputFCKMatrix(matCopy, "matCopy += matZero");

}

void test()
{
    MyMatrix<int> a(2, 3);
}

void matrixTest()
{
    test();
    std::cout << "~~~Construct Test~~~" << std::endl;
    constructTest();
    std::cout << "~~~Fill Test~~~" << std::endl;
    fillTest();
    std::cout << "~~~Equale Test~~~" << std::endl;
    equaleTest();
    std::cout << "~~~Math Test~~~" << std::endl;
    mathTest();


//    //некорректные матрицы добавить
//    //некорректное умножить
//    //Деление на 0
//    matCopy += matDefault;
//    outputFCKMatrix(matCopy, "matCopy += matCopy");

//    matCopy -= matCopy;
//    outputFCKMatrix(matCopy, "matCopy -= matCopy");

//    matCopy = matCopy + matDefault;
//    outputFCKMatrix(matCopy, "matCopy = matCopy + matDefault");

//    matCopy = matCopy - matDefault;
//    outputFCKMatrix(matCopy, "matCopy = matCopy - matDefault");

//    matCopy = matCopy + 5;
//    outputFCKMatrix(matCopy, "matCopy = matCopy + 5");

//    matCopy = matCopy - 3;
//    outputFCKMatrix(matCopy, "matCopy = matCopy - 3");

//    matCopy = matCopy * 2;
//    outputFCKMatrix(matCopy, "matCopy = matCopy * 2");

//    matCopy = matCopy / 2;
//    outputFCKMatrix(matCopy, "matCopy = matCopy / 2");



//    auto it = matCopy.begin();

//    std::cout << "checkpoint1" << std::endl;
//    ++it;
//    std::cout << "checkpoint2" << std::endl;
//    std::cout << it.value() << std::endl;
//    std::cout << "checkpoint3" << std::endl;
//    it.next();
//    std::cout << "checkpoint4" << std::endl;
//    std::cout << *it << std::endl;

//    //Итератор из енд
//    //Равно не равно

//    std::cout << matDefault.get_elem(1, 1) << std::endl;
//    std::cout << matDefault(1, 1) << std::endl;
//    std::cout << matDefault[1][1] << std::endl;
//    //ыСет и гет на выъодящие за край матрицы

//    std::cout << matDefault.is_square() << std::endl;
}

void outputFCKMatrix(class MyMatrix<int>& matrix, const std::string& str)
{
    try {
    std::cout << str << std::endl << matrix << std::endl;
    } catch (std::string str) {
        std::cout  << str << std::endl << std::endl;
    }
}

void fillMatrix(class MyMatrix<int>& matCopy)
{
    for (size_t i = 0; i < matCopy.get_count_of_rows(); ++i) {
        for (size_t j = 0; j < matCopy.get_count_of_columns(); ++j) {
            int a = i + j;
            matCopy.set_elem(i, j, a);
        }
    }
}

void testThis(class MyMatrix<int>& matrix, std::string str, void (*F)(MyMatrix<int>&, const std::string&))
{
    if (str != "") {
        try {
            F(matrix, str);
        } catch (std::string str) {
            std::cout << str << std::endl;
        }

    }
}

