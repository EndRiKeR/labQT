#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPicture>
#include <QPainter>
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

    void createItem(std::string str, int row, int column);
    void outputTable();

    void errorNotify();

    //New F for Lab3
    void setupComboBox();
    void setupGraf();
    void drawGraf();
    void setupOXandOY();
    void setupMetrics();
    void setPenForPainter(QPen& pen, int width, const QColor& color);

private:
    Ui::MainWindow *ui;
    struct dataFromFile data;

    QPicture* picture = nullptr;
    QPainter painter;
    QPen pen;
    struct grafConst grafSize;

};
#endif // MAINWINDOW_H
