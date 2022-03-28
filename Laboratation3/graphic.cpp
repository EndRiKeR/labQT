#include "graphic.h"

void MainWindow::prepDraw()
{
    picture.setBoundingRect(QRect(QPoint(0, 0), QPoint(xHigh, yHigh)));
    painter.begin(&picture);
    serifs();
    graph1 = painter.pen();
    graph1.setWidth(5);
    graph1.setColor(QColor("light green"));
    mett = painter.pen();
    mett.setColor("white");
    mett.setStyle(Qt::DotLine);
    painter.drawLine(offsetXLeft, offsetYDown, xHigh - offsetXRight, offsetYDown); // x
    painter.drawLine(xHigh - offsetXRight, offsetYDown, xHigh - offsetForXArrowAndYArrow, offsetYDown - littleOffset); // arrow
    painter.drawLine(xHigh - offsetXRight, offsetYDown, xHigh - offsetForXArrowAndYArrow, offsetYDown + littleOffset);
    painter.drawText(xHigh - offsetForXYear, offsetYDown + offsetForYYear, "Year");
    painter.drawLine(offsetXLeft, offsetYDown, offsetXLeft, coordinataForYandYArrow); // y
    painter.drawLine(offsetXLeft, coordinataForYandYArrow, offsetXLeft - littleOffset, offsetForXArrowAndYArrow);//arrow
    painter.drawLine(offsetXLeft, coordinataForYandYArrow, offsetXLeft + littleOffset, offsetForXArrowAndYArrow);
    QString column = ui->comboBox->currentText();
    painter.drawText(offsetXLeft + littleOffset, offsetForYText, column);
    oss = painter.pen();
    oss.setWidth(2);
    oss.setColor("white");
    painter.setPen(oss);
    ui->lblDraw->setPicture(picture);
}

void MainWindow::inputYearsAndNumbers()
{
    int rows = ui->table->rowCount();
    for (int i = 0; i < rows; i++) {
        QString curYear = ui->table->item(i,0)->text();
        QString temp = ui->table->item(i,n)->text();
        std::string exam = temp.toUtf8().constData();
        data.str = exam;
        data.userMove = Check;
        entry(data);
        if (data.res == true){
           data.years.push_back(curYear);
           data.number.push_back(atof(data.str.c_str()));
        }else
            continue;
    }
}

void MainWindow::drawing()
{
    painter.begin(&picture);
    prepDraw();
    double serifsY;
    serifsY = data.max - data.min;
    graph (serifsY);
    painter.end();
}

void MainWindow::graph (double serifsY)
{
    double step = (xHigh - offsetXLeft) / data.years.size();
    int yNach = (offsetYDown - beginY) / serifsY;
    for(int i = 0; i < data.years.size(); i++)
    {
        int coordinataOnY = 50 - (data.number.at(i) - data.max) * yNach;
        if (data.number.at(i) == data.med || data.number.at(i) == data.max || data.number.at(i) == data.min)
        {
            painter.setPen(oss);
            painter.drawLine(offsetXLeft + numberForSerif, coordinataOnY, offsetXLeft - numberForSerif, coordinataOnY);
            painter.setPen(graph1);
            painter.drawText(nach, coordinataOnY, QString::number(data.number.at(i), 'g', 5));
            painter.setPen(mett);
            painter.drawLine(offsetXLeft, coordinataOnY, xNach, coordinataOnY);
            text(i, coordinataOnY);
            if (data.number.at(i) == data.min)
                painter.setPen(mett);
                painter.drawLine(offsetXLeft, coordinataOnY, xNach, coordinataOnY);
        }
        painter.setPen(graph1);
        painter.drawPoint(xNach - littleOffset - 3, coordinataOnY);
        xNach += step;
    }
    xNach -= (step * data.years.size());
    serifsOnY();
    painter.end();
}

void MainWindow::draw()
{
    drawing();
    data.years.clear();
    data.number.clear();
}

void MainWindow::serifs()
{
    inputYearsAndNumbers();
    int step = (xHigh - now)  / data.years.size();
    for (int i = 0; i < data.years.size(); i++){
        painter.drawLine(now, offsetYDown + littleOffset, now, offsetYDown - littleOffset);
        painter.rotate (-90);
        painter.drawText(- offsetYDown - offsetForYears, now + offsetForText, data.years.at(i));
        painter.rotate (90);
        now += step;
    }
    now -= step * data.years.size();
}

void MainWindow::text(int i,int coordinataOnY)
{
    if (data.max == data.number.at(i)){
        painter.drawText(offsetXLeft + offsetForText, coordinataOnY, "max");
        coorMaxY = coordinataOnY;
    }
    else if (data.med == data.number.at(i)){
        painter.drawText(offsetXLeft + offsetForText, coordinataOnY, "med");
    }
    else if (data.min == data.number.at(i)){
        painter.drawText(offsetXLeft + offsetForText, coordinataOnY, "min");
        coorMinY = coordinataOnY;
    }
}

void MainWindow:: serifsOnY()
{
    int stepY = (coorMinY - coorMaxY) / 4;
    double stepNumbers = (data.max - data.min) / 4;
    int ser = coorMaxY;
    for (int i = 1; i < 4; i++){
        ser += stepY;
        painter.setPen(oss);
        painter.drawLine(offsetXLeft + numberForSerif, ser, offsetXLeft - numberForSerif, ser);
        QString text = QString::number(data.max - stepNumbers * i);
        painter.drawText(offsetXLeft - offsetXForText, ser, text);
    }
}
