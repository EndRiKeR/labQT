#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table->setEditTriggers(QTableWidget::NoEditTriggers);
    block(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnChooseFile_clicked()
{
    data.fileName = QFileDialog::getOpenFileName(0," ", "/Users/ksenianedorezova/Desktop/Lab", "*.csv").toStdString();
    QString file = QString::fromStdString(data.fileName).section('/',-1);
    ui->lblOutputName->setText(file);
    ui->btnLoadData->setEnabled(true);
}

void MainWindow::block(bool value)
{
    ui->btnLoadData->setEnabled(value);
    ui->btnCalculateMetrix->setEnabled(value);
    ui->btnOutput->setEnabled(value);
    ui->comboBox->setEnabled(value);
}

void MainWindow::on_btnLoadData_clicked()
{
    ui->table->clearContents();
    output(0);
    ui->inputRegion->clear();
    ui->btnCalculateMetrix->setEnabled(false);
}

void MainWindow::on_btnOutput_clicked()
{
    ui->table->clearContents();
    output(1);
    ui->btnCalculateMetrix->setEnabled(true);
}

void MainWindow::on_btnCalculateMetrix_clicked()
{
    QString variable = ui->comboBox->currentText();
    switch(variable.toStdString()[0]){
    case 'N':
        n = 2;
        group(2);
        break;
    case 'B':
        n = 3;
        group(3);
        break;
    case 'D':
        n = 4;
        group(4);
        break;
    case 'G':
        n = 5;
        group(5);
        break;
    case 'U':
        n = 6;
        group(6);
        break;
    case 'C':
        ui->lblForMax->setText("0");
        ui->lblForMed->setText("0");
        ui->lblForMin->setText("0");
        break;
    default:
        break;
    }
}
