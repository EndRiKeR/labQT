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
    void infoForUser();

private slots:
    void setSizeColumToDefault();

    void on_btn_view_all_clicked();
    void on_btn_view_part_clicked();
    void on_btn_connect_file_clicked();
    void on_btn_column_count_clicked();

    void outputTable();

    void clearAllItem();
    void clearAll();


private:
    Ui::MainWindow *ui;
    struct dataFromFile data;

};
#endif // MAINWINDOW_H
