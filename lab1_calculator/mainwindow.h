#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

struct calcMath { //Доп структура для хранения нужных для мат логики данных
    double result;
    double numberNow;
    bool point;
    int pointDeep;
    QString nextMove = "None"; // None, Plus(+), Minus(-), Div(/), Mult(*)
    bool firstTimeRes;
};

bool myContainChInStr(std::string str, const char ch);
void outputStatisticData(struct calcMath* mathInstrument); //вспомогательные функци

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
    void on_btn_numeric_clicked();

    void on_btn_move_clicked();

    void on_btn_clear_clicked();

    void on_btn_point_clicked();

    void on_btn_result_clicked();

    void on_btn_delete_clicked();

    void whatINeedToDo(struct calcMath* mathInstrument);

private:
    Ui::MainWindow *ui;
    calcMath mathInstrument = {0.0, 0.0, false, 1, "None", true};

};
#endif // MAINWINDOW_H
