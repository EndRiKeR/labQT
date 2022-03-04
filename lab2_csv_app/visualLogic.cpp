#include "visualLogic.h"
#include "BLogic.h"
#include <QFile>

void MainWindow::setSizeColumToDefault()
{
    ui->tbl_main->setColumnWidth(0, 50);
    ui->tbl_main->setColumnWidth(1, 260);
    ui->tbl_main->setColumnWidth(2, 120);
    ui->tbl_main->setColumnWidth(3, 120);
    ui->tbl_main->setColumnWidth(4, 120);
    ui->tbl_main->setColumnWidth(5, 120);
    ui->tbl_main->setColumnWidth(6, 120);
}

//подключение файла
void openFileAndTakeName(struct dataFromFile& data)
{
    data.filePath = QFileDialog::getOpenFileName(0,
                                                    "Open File",
                                                    "D://progectsForCpp/labQT/lab2_csv_app/",
                                                    "Excel Files (*.csv)").toStdString();
    data.fileName = QString::fromStdString(splitStrToWords(data.filePath, '/'));
    if (data.filePath == "") {
        data.error = ErFileOpen;
    }
    //QMessageBox::information(0, "File Path", QString::fromStdString(data.filePath));
    //QMessageBox::information(0, "File Path", data.fileName);
}

//Визуальная логика для таблицы
void MainWindow::outputTable()
{
    QTableWidgetItem* item;
    QString qstr;
    ui->tbl_main->setRowCount(data.table.row - 1);
    auto it = data.wordsFromFile->begin();
    for (size_t i = 0; i < ui->tbl_main->rowCount(); ++i) {
        for (size_t j = 0; j < ui->tbl_main->columnCount(); ++j) {
            qstr = QString::fromStdString(*it);
            if (qstr == "") {
                qstr = "-";
            }
            item = new QTableWidgetItem(qstr);
            ui->tbl_main->setItem(i, j, item);
            it++;
            if (it  == data.wordsFromFile->end()) {
                break;
            }
        }
    }
    QMessageBox::information(0, "Все ок!", "Ваша таблица была успешно загружена)");
}
