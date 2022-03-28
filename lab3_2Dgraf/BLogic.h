#ifndef BLOGIC_H
#define BLOGIC_H

#include <fstream>
#include <iostream>
#include <vector>
#include <QMessageBox>
#include <QFileDialog>
#include "newDataType.h"

void doData(struct dataFromFile& data);
void openFileAndTakeName(struct dataFromFile& data);
void inputFile(struct dataFromFile& data);
void inputDataFromFile(struct dataFromFile& data);
void sortWordsByColumn(struct dataFromFile& data, const std::vector<std::string>& vec);
void splitStrToWords(std::vector<std::string>& vector, const std::string& str, char sep);
std::vector<std::string> splitStrToVector(const std::string& str, char sep);
std::string splitStrToWords(const std::string& str, char sep);
void outputVectorOfStr(const std::vector<std::string>& vector);
void countMaxMinMed(struct dataFromFile& data);
double med(std::vector<double>& vec);
std::pair<double, double> maxAndMin(const std::vector<double>& vec);
std::vector<double> catchNumbers(struct dataFromFile& data);
bool isDigit(std::string& str);
bool isDigit(QString& qstr);
bool contain(const std::vector<std::string>& vec, std::string str);
void clearAllNew(struct dataFromFile& data);

#endif // BLOGIC_H
