#include "visualLogic.h"

void MainWindow::updateLabel(QPushButton* btn)
{
    if (md.operationType >= DO && md.operationType <= endDO) {
        ui->lbl_main->setText(QString::number(md.valueRes, 'g', 15));
    } else if (md.operationType >= IO && md.operationType <= endIO) {
        doVisualInstrumentalOperation(btn);
    } else if (md.operationType >= AO && md.operationType <= endAO) {
        ui->lbl_main->setText(QString::number(md.valueNow, 'g', 15));
    } else if (md.operationType > MO && md.operationType <= endMO) {
        ui->lbl_main->setText(QString::number(md.valueNow, 'g', 15));
    }
}

void MainWindow::doVisualInstrumentalOperation(QPushButton* btn)
{
    switch(md.operationType) {
    case Add:
        doVisualAdd(btn);
        break;
    case Del:
        doVisualDel();
        break;
    case Point:
        doVisualPoint(btn);
        break;
    case Res:
        doVisualRes();
        break;
    case Clear:
        doVisualClear();
        break;
    default:
        md.error = true;
        break;
    }
}

void MainWindow::doVisualAdd(QPushButton* btn)
{
    //if ((ui->lbl_main->text() == "0" || md.MoveNext != None) && md.valueNow == 0.0) {
    if (ui->lbl_main->text() == "0" || md.afterMove) {
        ui->lbl_main->setText(btn->text());
        md.afterMove = false;
    } else {
        ui->lbl_main->setText(ui->lbl_main->text() + btn->text());
    }
}

void MainWindow::doVisualDel()
{
    if (ui->lbl_main->text().size() > 1) {
        ui->lbl_main->setText(QString::fromStdString(ui->lbl_main->text().toStdString().substr(0, ui->lbl_main->text().size() - 1)));
    } else {
        ui->lbl_main->setText("0");
    }
}

void MainWindow::doVisualPoint(QPushButton* btn)
{
    ui->lbl_main->setText(ui->lbl_main->text() + btn->text());
}

void MainWindow::doVisualRes()
{
    ui->lbl_main->setText(QString::number(md.valueRes, 'g', 15));
}

void MainWindow::doVisualClear()
{
    ui->lbl_main->setText(QString::number(md.valueNow, 'g', 15));
}
