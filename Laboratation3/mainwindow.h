#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPainter>
#include <QMessageBox>

#include "ui_mainwindow.h"
#include "struct.h"
#include "visual.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnChooseFile_clicked();
    void block(bool value);
    void on_btnLoadData_clicked();
    void on_btnOutput_clicked();
    void on_btnCalculateMetrix_clicked();
    void group(int col);
    QString writeRegion();
    void output(bool needCheck);
    std::vector<double> inputInMas(int col);
    void prepDraw();
    void inputYearsAndNumbers();
    void drawing();
    void graph (double serifsY);
    void draw();
    void serifs();
    void text(int i, int y_t);
    void serifsOnY();

private:
    struct Type data;
    int n;
    std::vector<double> mas;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
