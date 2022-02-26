#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "newDataType.h"
#include "BLogic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    std::list<std::string>* list;
    std::list<std::string>* listOfWords;

private slots:
    void setSizeColumToDefault();
    void inputFile();
    void clearAllItem();

    void on_btn_view_all_clicked();

    void on_btn_view_part_clicked();

    void outputTable();

    void clearAll();

    void on_btn_column_count_clicked();

    std::vector<double> catchNumbers(std::list<std::string>& list, const int columnNum);


private:
    Ui::MainWindow *ui;
    struct excel ex;
    struct statisticData sd;

};
#endif // MAINWINDOW_H
