#ifndef BLOGIC_H
#define BLOGIC_H

#include <fstream>
#include <QList>
#include <iostream>
#include <list>
#include <vector>
#include <QMessageBox>
#include "newDataType.h"

void inputDataFromFile(std::list<std::string>& list,
                            const std::string& filename,
                            const std::string& region);
void outputListOfStr(const std::list<std::string>& list);
void splitStrToWords(std::list<std::string>& list, const std::string& str, char sep);
void countMaxMinMed(struct statisticData& sd,
                        std::list<std::string>& list,
                        int columnNum);
double med(std::vector<double>& vec);
std::pair<double, double> maxAndMin(const std::vector<double>& vec);
std::vector<double> catchNumbers(std::list<std::string>& list, int columnNum);

#endif // BLOGIC_H
