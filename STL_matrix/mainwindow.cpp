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

void iNeedMatrix(MyMatrix<int>& mat)
{
    std::cout << "I stole matrix" << std::endl << mat << std::endl << std::endl;
}

void constructTest()
{
    MyMatrix<int> matDefault;
    MyMatrix<int> matZero(0, 0);
    MyMatrix<int> matCopyZero(matZero);
    MyMatrix<int> matSizeConstruct(3, 3);
    MyMatrix<int> matCopy(matSizeConstruct);

    outputFCKMatrix(matDefault, "MatDefault");
    outputFCKMatrix(matZero, "MatZero(0, 0)");
    outputFCKMatrix(matCopyZero, "MatCopyZero from MatZero");
    outputFCKMatrix(matSizeConstruct, "MatSizeConstruct(3, 3)");
    outputFCKMatrix(matCopy, "MatCopy from MatSizeConstruct");

    try {
        iNeedMatrix(matZero);
    } catch (std::string str) {
        std::cout << "Error! " << str << std::endl;
    }

    try {
        iNeedMatrix(matCopy);
    } catch (std::string str) {
        std::cout << "Error! " << str << std::endl;
    }

    try {
        MyMatrix<int> matIt({{1, 2, 3},{1, 2, 3},{1, 2, 3}});
        outputFCKMatrix(matIt, "MatIt: {{1, 2, 3},{1, 2, 3},{1, 2, 3}}");
    } catch (std::string str) {
        std::cout << "Error! " << str << std::endl;
    }

    std::cout << "matIt2{{1},{1, 2, 3},{1, 2, 3}}" << std::endl;
    try {
        MyMatrix<int> matIt2({{1},{1, 2, 3},{1, 2, 3}});
    } catch (std::string str) {
        std::cout << "Error! " << str << std::endl << std::endl;
    }

    std::cout << "matIt3{}" << std::endl;

    try {
        MyMatrix<int> matIt3({});
    } catch (std::string str) {
        std::cout << "Error! " << str << std::endl << std::endl;
    }
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

    matCopy += matBroke;
    outputFCKMatrix(matCopy, "matCopy += matBroke");

    matCopy -= matBroke;
    outputFCKMatrix(matCopy, "matCopy -= matBroke");

    matCopy += matZero;
    outputFCKMatrix(matCopy, "matCopy += matZero");

    try {
        std::cout << "Mult test" << std::endl;
        outputFCKMatrix(matCopy, "matCopy");
        outputFCKMatrix(matDefault, "matDefault");
        matCopy * matDefault;
        outputFCKMatrix(matCopy, "matCopy * matDefault");
    } catch(std::string str) {
        std::cout << str << std::endl;
    }
}

void banditMathTest()
{
    MyMatrix<int> mat1(2, 4);
    MyMatrix<int> mat2(4, 3);
    MyMatrix<int> mat3(1, 1);
    fillMatrix(mat1);
    fillMatrix(mat2);
    fillMatrix(mat3);
    try {
        outputFCKMatrix(mat1, "mat1");
        outputFCKMatrix(mat2, "mat2");
        mat1 * mat2;
        outputFCKMatrix(mat1, "mat1 * mat2");
    } catch(std::string str) {
        std::cout << str << std::endl;
    }

    try {
        std::cout << "Bandit Mult test" << std::endl;
        outputFCKMatrix(mat1, "mat1");
        outputFCKMatrix(mat3, "mat3");
        mat1 * mat3;
        outputFCKMatrix(mat3, "mat1 * mat3");
    } catch(std::string str) {
        std::cout << str << std::endl << std::endl;
    }

    try {
        std::cout << "Dived by Zero! MUHaHaHaHa!" << std::endl;
        mat1 / 0;
        outputFCKMatrix(mat1, "mat1 / 0");
    }  catch (std::string str) {
        std::cout << str << std::endl << std::endl;
    }
}

void iteratorTest()
{
    MyMatrix<int> mat(5, 3);
    fillMatrix(mat);
    outputFCKMatrix(mat);
    auto it = mat.begin();
    auto startIt = mat.begin();
    auto endIt = mat.end();

    std::cout << it.value() << std::endl;
    ++it;
    std::cout << it.value() << std::endl;
    it++;
    std::cout << *it++ << std::endl;
    it.next();
    std::cout << *it << std::endl;

    while (startIt != endIt) {
        std::cout << "[" << *startIt++ << "]" << std::endl;
    }

    if (startIt == endIt) {
        std::cout << "Itearator" << std::endl;
    }
    std::cout << std::endl;
}

void doULoveSpongeBob()
{
    MyMatrix<int> spongeBob(1, 1);
    std::cout << "1 * 1 matrix: " << spongeBob.is_square() << std::endl;

    MyMatrix<int> patric(1, 2);
    std::cout << "1 * 2 matrix: " << patric.is_square() << std::endl;

    MyMatrix<int> squidward(1, 0);
    std::cout << "1 * 0 matrix: " << squidward.is_square() << std::endl;

    MyMatrix<int> misterCrabs;
    std::cout << "Zero matrix: " << misterCrabs.is_square() << std::endl << std::endl;
}

void banditAccess()
{
    MyMatrix<int> mat(3, 3);
    fillMatrix(mat);

    try {
        std::cout << "mat[-1][-1]" << std::endl;
        std::cout << mat[-1][-1] << std::endl;
    }  catch (std::string str) {
        std::cout << str << std::endl << std::endl;
    }

    try {
        std::cout << "mat[123][987]" << std::endl;
        std::cout << mat[123][987] << std::endl;
    }  catch (std::string str) {
        std::cout << str << std::endl << std::endl;
    }

    try {
        std::cout << "mat(-1, -1)" << std::endl;
        std::cout << mat(-1, -1) << std::endl;
    }  catch (std::string str) {
        std::cout << str << std::endl << std::endl;
    }

    try {
        std::cout << "mat(123, 987)" << std::endl;
        std::cout << mat(123, 987) << std::endl;
    }  catch (std::string str) {
        std::cout << str << std::endl << std::endl;
    }

    try {
        std::cout << "mat.get_elem(-1, -1)" << std::endl;
        std::cout << mat.get_elem(-1, -1) << std::endl;
    }  catch (std::string str) {
        std::cout << str << std::endl << std::endl;
    }
    try {
        std::cout << "mat.get_elem(123, 987)" << std::endl;
        std::cout << mat.get_elem(123, 987) << std::endl;
    }  catch (std::string str) {
        std::cout << str << std::endl << std::endl;
    }

    try {
        std::cout << "mat.set_elem(123, 987, 1)" << std::endl;
        int i = 1;
        mat.set_elem(123, 987, i);
    }  catch (std::string str) {
        std::cout << str << std::endl << std::endl;
    }
}

void matrixTest()
{
    std::cout << std::endl << std::endl;
    std::cout << "~~~Construct~Test~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    constructTest();
    std::cout << "~~~Fill~Test~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    fillTest();
    std::cout << "~~~Equale~Test~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    equaleTest();
    std::cout << "~~~Math~Test~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    mathTest();
    std::cout << "~~~Bandit~Math~Test~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    banditMathTest();
    std::cout << "~~~Iterator~Test~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    iteratorTest();
    std::cout << "~~~Square~Test~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    doULoveSpongeBob();
    std::cout << "~~~Bandit~Access~Test~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    banditAccess();
}

void outputFCKMatrix(class MyMatrix<int>& matrix, const std::string& str)
{
    std::cout << str << std::endl;
    try {
    std::cout << matrix << std::endl;
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

