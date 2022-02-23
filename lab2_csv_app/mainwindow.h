#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "newDataType.h"

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
    void setSizeColumToDefault();
    void input_file();
    void on_btn_add_row_clicked();
    void clearAllItem();

private:
    Ui::MainWindow *ui;
    struct excel ex;
    std::list<std::string>* list;
    std::vector<std::string>* listOfWords;
};
#endif // MAINWINDOW_H
