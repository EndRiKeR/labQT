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
    std::string filePath = QFileDialog::getOpenFileName(0,
                                                        "Open File",
                                                        "D:\progectsForCPP\labQT\lab3_2Dgraf",
                                                        "Excel Files (*.csv)").toStdString();
    if (filePath != "") {
        data.filePath = filePath;
        data.fileName = QString::fromStdString(splitStrToWords(data.filePath, '/'));
    } else {
        data.error.erCode = ErFileOpen;
        data.error.erInfo = "Не удалось открыть файл!\nПрезапустите прграмму и попробуйте снова!\n\nErCode = ErFileOpen";
    }
}

void MainWindow::createItem(std::string str, int row, int column)
{
    QTableWidgetItem* item;
    QString qstr = QString::fromStdString(str);
    if (qstr == "") {
        qstr = "-";
    }
    item = new QTableWidgetItem(qstr);
    ui->tbl_main->setItem(row, column, item);
}

//Визуальная логика для таблицы
void MainWindow::outputTable()
{
    ui->tbl_main->setRowCount(data.table.row);
    auto it = data.sortedData->begin();
    std::vector<std::string> vec;
    for (size_t i = 0; i < ui->tbl_main->rowCount() || it != data.sortedData->end(); ++i) {
        struct rowData row = *it++;
        createItem(row.age, i, 0);
        createItem(row.region, i, 1);
        createItem(row.natPopGrow, i, 2);
        createItem(row.birthRate, i, 3);
        createItem(row.deathRate, i, 4);
        createItem(row.genDemRate, i, 5);
        createItem(row.urbanisation, i, 6);
        if (!contain(vec, row.region)) {
            vec.push_back(row.region);
            ui->cb_region->addItem(QString::fromStdString(row.region));
        }
    }

    QMessageBox::information(0, "Все ок!", "Ваша таблица была успешно загружена)");
}
