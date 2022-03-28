#ifndef BUSLOG_H
#define BUSLOG_H

#include <fstream>
#include "struct.h"
#include "mainwindow.h"

void entry (struct Type& type);
void openReadWriteFile(struct Type& data);
void mySort(std::vector<double>& mas);
double searchMin(std::vector<double>& mas);
double searchMax(std::vector<double>& mas);
double searchMed(std::vector<double>& mas);
bool check(std::string str);
void inputValInVector(std::vector<double>& mas, double val);
void inputStructForDraw(QStringList lst, struct Draw& draw, int i);

#endif // BUSLOG_H
