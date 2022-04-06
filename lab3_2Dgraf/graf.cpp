#include "graf.h"

//~~~~~~~~~~~~~~~~~~~~~~~~New Functions In Lab3~~~~~~~~~~~~~~~~~~~~~~~~~~~

void MainWindow::setupComboBox()
{
    ui->cb_colunm->addItem(QString::fromStdString("Nat Pop Grow"));
    ui->cb_colunm->addItem(QString::fromStdString("Birth Rate"));
    ui->cb_colunm->addItem(QString::fromStdString("Death Rate"));
    ui->cb_colunm->addItem(QString::fromStdString("Gen Dem Rate"));
    ui->cb_colunm->addItem(QString::fromStdString("Urbanization"));
}

void MainWindow::setupGraf()
{
    if (picture != nullptr) {
        ui->lbl_graf->setPicture(*picture);
    }
}

void MainWindow::drawGraf()
{
    picture = new QPicture;
    painter.begin(picture);
    //painter.rotate(-90);
    picture->setBoundingRect(QRect(QPoint(0, 0), QPoint(971, -321)));
    setupOXandOY();
    if (ui->cb_colunm->currentIndex() != 0 && ui->cb_region->currentIndex()) {
        setupMetrics();
    } else {
        data.error.erCode = ErColumnChoose;
        data.error.erInfo = "Вы не выбрали регион и/или столбец для построения графа.\nПроверьте корректность своего запроса!\n\nErCode = ErColumnChoose";
    }
    setupGraf();
    painter.end();
    delete picture;
}

void MainWindow::setupOXandOY()
{
    setPenForPainter(pen, 2, Qt::red);
    painter.drawLine(grafSize.offsetOX, grafSize.minY,
                        grafSize.offsetOX, grafSize.maxY); //OY
    painter.drawLine(grafSize.offsetOX, grafSize.maxY - grafSize.offsetOY,
                        grafSize.maxX, grafSize.maxY - grafSize.offsetOY); //OX
    painter.drawLine(grafSize.offsetOX, grafSize.minY,
                        grafSize.offsetOX + grafSize.offset5Pix, grafSize.minY + 3 * grafSize.offset5Pix);
    painter.drawLine(grafSize.offsetOX, grafSize.minY,
                        grafSize.offsetOX - grafSize.offset5Pix, grafSize.minY + 3 * grafSize.offset5Pix);
    painter.drawLine(grafSize.maxX, grafSize.maxY - grafSize.offsetOY,
                        grafSize.maxX - 3 * grafSize.offset5Pix,
                        grafSize.maxY - grafSize.offsetOY - grafSize.offset5Pix);
    painter.drawLine(grafSize.maxX, grafSize.maxY - grafSize.offsetOY,
                        grafSize.maxX - 3 * grafSize.offset5Pix,
                        grafSize.maxY - grafSize.offsetOY + grafSize.offset5Pix);
    ui->lbl_x->setText("Year");
    if (ui->cb_colunm->currentIndex() != 0) {
        ui->lbl_y->setText(ui->cb_colunm->currentText());
    }
    setupGraf();
}

void MainWindow::setupMetrics()
{
    double delta = abs(data.statistic.max - data.statistic.min);
    const double OY = grafSize.maxGrafY + grafSize.offsetUpY - grafSize.offset5Pix;
    struct point startP = {0.0, 0.0};
    struct point endP = {0.0, 0.0};
    struct point moveMult = {grafSize.maxGrafX / data.yearsData.size(), grafSize.maxGrafY / delta};
    bool first = true;
    drawMaxMinMed(moveMult, OY);
    for (size_t i = 0; i < data.colData.size(); ++i) {
        setPenForPainter(pen, 3, Qt::blue);
        if (first) {
            startP = {grafSize.offsetLeftX, OY - abs(data.colData[i] - data.statistic.min) * moveMult.y};
            std::cout << "first point: [" << startP.x << "] [" << startP.y << "]" << std::endl;
            first = false;
        } else {
            endP = {startP.x + moveMult.x, OY - abs(data.colData[i] - data.statistic.min) * moveMult.y};
            std::cout << "first point: [" << startP.x << "] [" << startP.y << "]\t"
                      << "last point: [" << endP.x << "] [" << endP.y << "]" << std::endl;
            painter.drawLine(startP.x, startP.y, endP.x, endP.y);
            startP = {endP.x, endP.y};
        }
        drawHelpLines(startP, i);
        drawLinesAndYears(startP, i);

    }
}

void MainWindow::drawMaxMinMed(struct point& moveMult, double OY)
{
    setPenForPainter(pen, 2, Qt::green);
    painter.drawLine(grafSize.offsetOX,
                         OY - (data.statistic.max - data.statistic.min) * moveMult.y,
                         grafSize.maxX,
                         OY - (data.statistic.max - data.statistic.min) * moveMult.y);
    setPenForPainter(pen, 2, Qt::black);
    painter.drawLine(grafSize.offsetOX - grafSize.offset5Pix,
                         OY - (data.statistic.max - data.statistic.min) * moveMult.y,
                         grafSize.offsetOX + grafSize.offset5Pix,
                         OY - (data.statistic.max - data.statistic.min) * moveMult.y);
    setPenForPainter(pen, 2, Qt::green);
    painter.drawLine(grafSize.offsetOX,
                         OY,
                         grafSize.maxX,
                         OY);
    painter.drawLine(grafSize.offsetOX,
                        OY - (data.statistic.med - data.statistic.min) * moveMult.y,
                        grafSize.maxX,
                        OY - (data.statistic.med - data.statistic.min) * moveMult.y);
    setPenForPainter(pen, 2, QColorConstants::Svg::purple);
    painter.drawText(grafSize.maxX - 4 * grafSize.offset5Pix,
                        OY - (data.statistic.max - data.statistic.min) * moveMult.y - 2 * grafSize.offset5Pix,
                        QString::number(data.statistic.max));
    painter.drawText(grafSize.maxX - 4 * grafSize.offset5Pix,
                        OY - (data.statistic.max - data.statistic.min) * moveMult.y - 4 * grafSize.offset5Pix,
                        "MAX");
    painter.drawText(grafSize.maxX - 4 * grafSize.offset5Pix,
                        OY - 2 * grafSize.offset5Pix,
                        QString::number(data.statistic.min));
    painter.drawText(grafSize.maxX - 4 * grafSize.offset5Pix,
                        OY - 4 * grafSize.offset5Pix,
                        "MIN");
    if (data.statistic.max != data.statistic.med && data.statistic.min != data.statistic.med) {
        painter.drawText(grafSize.maxX - 4 * grafSize.offset5Pix,
                            OY - (data.statistic.med - data.statistic.min) * moveMult.y - 2 * grafSize.offset5Pix,
                            QString::number(data.statistic.med));
        painter.drawText(grafSize.maxX - 4 * grafSize.offset5Pix,
                            OY - (data.statistic.med - data.statistic.min) * moveMult.y - 4 * grafSize.offset5Pix,
                            "MED");
    }
}

void MainWindow::drawLinesAndYears(struct point& startP, size_t i)
{
    setPenForPainter(pen, 3, Qt::black);
    painter.rotate(-90);
    painter.drawText(grafSize.offsetDownY - grafSize.maxY - 8 * grafSize.offset5Pix,
                        startP.x + 1.5 * grafSize.offset5Pix,
                        QString::fromStdString(data.yearsData[i]));
    painter.rotate(90);
    painter.drawLine(startP.x, grafSize.maxY - grafSize.offsetDownY + 2 * grafSize.offset5Pix,
                        startP.x, grafSize.maxY - grafSize.offsetDownY);
}

void MainWindow::drawHelpLines(struct point& moveMult, double OY)
{
    setPenForPainter(pen, 2, Qt::black);
    double k = 0.2;
    for (size_t i = 1; i <= 5; ++i) {
        painter.drawLine(grafSize.offsetOX - grafSize.offset5Pix,
                            grafSize.maxY * k + grafSize.offset5Pix,
                            grafSize.offsetOX + grafSize.offset5Pix,
                            grafSize.maxY * k + grafSize.offset5Pix);
        k += 0.2;
    }


}

void MainWindow::setPenForPainter(QPen& pen, int width, const QColor& color)
{
    pen.setWidth(width);
    pen.setColor(color);
    painter.setPen(pen);
}
