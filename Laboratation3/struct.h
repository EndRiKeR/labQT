#ifndef STRUCT_H
#define STRUCT_H
#include <vector>
#include <string>
#include <QString>

enum
{
    None,
    Max,
    Min,
    Med,
    Check,
    Sort,
    Val,
    Input
};

struct Type
{
    int userMove = 0;

    std::string fileName;
    const std::string firstStr = "year,region,npg,birth_rate,death_rate,gdw,urbanization\r";

    std::vector<double> vec;
    std::vector<std::string> vecTwo;
    std::string str;
    std::vector<QString> years;
    std::vector<double> number;

    double val;
    double min = 0;
    double max = 0;
    double med = 0;
    bool res = true;
    int check;
};

#endif // STRUCT_H
