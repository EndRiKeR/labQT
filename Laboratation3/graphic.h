#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <QPainter>
#include <QWidget>
#include <QStandardItemModel>

#include "struct.h"
#include "struct.h"
#include "buslog.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

QPicture picture;
QPainter painter;
QPen graph1;
QPen mett;
QPen oss;

const int xHigh = 550; // размер по х
const int yHigh = 505; // размер по у
const int offsetYDown = yHigh - 20; // отступ снизу
const int offsetXLeft = 30; // отступ от левого края
const int offsetXRight = 10; // отступ от правого края
const int numberForSerif = 2; // вверх/вниз или вправо/влево для засечек
const int littleOffset = 3; // сдвиг по х или по у для названия или стрелки
const int offsetForXArrowAndYArrow = 15;
const int coordinataForYandYArrow = 10;
const int offsetForXYear = 35;
const int offsetForYYear = 20;
const int offsetForText = 5;
const int offsetXForText = 30;
const int offsetForYears = 40;
const int offsetForYText = 15;
const int nach = 0;
const int beginY = 100;
double xNach = 40; //начало координат для х
int coorMaxY; // координата макисмума
int coorMinY; //координата минимума
int now = 40;

#endif // GRAPHIC_H
