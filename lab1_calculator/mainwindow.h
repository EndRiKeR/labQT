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
    bool afterMove = false;
};

bool myContainChInStr(std::string str, const char ch);
void outputStatisticData(struct calcMath* mathInstrument, const std::string fName); //вспомогательные функци

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
    void on_btn_numeric_clicked();

    void on_btn_move_clicked();

    void clear_clicked();

    void on_btn_point_clicked();

    void result_clicked();

    void delete_clicked();

    void enableMoves(int i);

    void whatINeedToDo(struct calcMath* mathInstrument);

    void enableDelete(int i);

    void enableResult(int i);

    void enablePoint(int i);

    void enableNum(int i);

    void enableSwap(int i);
    void enableWerewolf(int i);

    void enableAllBtn(int i);

    void on_btn_swap_clicked();

    void on_btn_werewolf_clicked();

private:
    Ui::MainWindow *ui;
    calcMath mathInstrument = {0.0, 0.0, false, 1, "None", true};

};
#endif // MAINWINDOW_H
