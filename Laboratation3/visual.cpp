#include "visual.h"
#include "buslog.h"
#include "struct.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QTableWidgetItem>
#include <QPainter>

void MainWindow::output(bool needCheck)
{
    data.userMove = Input;
    entry(data);
    int k = 0;
    for (int i = 0; i < data.vecTwo.size(); ++i){
        std::string exam = data.vecTwo[i];
        QString str = QString::fromStdString(exam);
        str.remove('\r');
        QStringList lst = str.split(",");
        QTableWidgetItem* item;
        QString var, check = lst.at(1);
        if (needCheck && (check != writeRegion()))
            continue;
        k++;
        ui->table->setRowCount(k);
        for (int j = 0; j < 7; j++){
            var = QString(lst.at(j));
            item = new QTableWidgetItem(var);
            ui->table->setItem(k - 1, j, item);
        }
    }
    data.vecTwo.clear();
    ui->table->resizeColumnsToContents();
    block(true);
}

QString MainWindow::writeRegion()
{
    QString reg = ui->inputRegion->text();
    return reg;
}

std::vector<double> MainWindow::inputInMas(int col)
{
    int amount =ui->table->rowCount();
    for (int i = 0; i < amount; i++){
        QString myData = ui->table->item(i,col)->text();
        std::string exam = myData.toUtf8().constData();
        data.str = exam;
        data.userMove = Check;
        entry(data);
        if (data.res == true){
            data.val = atof(data.str.c_str());
            data.userMove = Val;
            entry(data);
        }else{
            continue;
        }
    }
    return mas;
}

void MainWindow::group(int col)
{
    mas = inputInMas(col);
    data.userMove = Sort;
    entry(data);
    data.max = 0;
    data.userMove = Max;
    entry(data);
    data.min = 0;
    data.userMove = Min;
    entry(data);
    data.med = 0;
    data.userMove = Med;
    entry(data);
    ui->lblForMax->setText(QString::number(data.max));
    ui->lblForMed->setText(QString::number(data.med));
    ui->lblForMin->setText(QString::number(data.min));
    draw();
    data.vec.clear();
}
