#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matrix.h"

void matrixTest();
void outputFCKMatrix(class MyMatrix<int>& matrix, const std::string& str = "Output Matrix");
void fillMatrix(class MyMatrix<int>& matCopy);
void testThis(class MyMatrix<int>& matrix, std::string str, void (*F)(MyMatrix<int>&, const std::string&));

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
