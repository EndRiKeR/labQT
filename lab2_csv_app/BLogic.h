#ifndef BLOGIC_H
#define BLOGIC_H

#include <fstream>
#include <QList>
#include <iostream>
#include <list>
#include <vector>
#include <QMessageBox>
#include "newDataType.h"

void outputListOfStr(const std::list<std::string>& list);
void splitStrToWords(std::list<std::string>& vector, const std::string& str, char sep);
void inputDataFromFile(std::list<std::string>& list,
                            const std::string& filename,
                            const std::string& region);
std::vector<double> catchNumbers(const std::list<std::string>& list, const int columnNum);
std::pair<double, double> maxAndMin(const std::vector<double>& vec);
double med(std::vector<double>& vec);

#endif // BLOGIC_H
