#include "BLogic.h"

void inputDataFromFile(std::list<std::string>& list,
                            const std::string& filename,
                            const std::string& region)
{
    std::string str;
    std::ifstream fileForRead(filename);
    getline(fileForRead, str); //убираю вспомогат. строку
    if (fileForRead.is_open()) {
        while(getline(fileForRead, str)) {
            if (str.find(region) != -1) {
                list.push_back(str);
            }
        }
    } else {
        //error here
    }
    fileForRead.close();
}

void outputListOfStr(const std::list<std::string>& list)
{
    for (auto& str : list) {
        std::cout << str << std::endl;
    }
}

void splitStrToWords(std::list<std::string>& list, const std::string& str, char sep)
{
    int start = 0;
    int pos = str.find(sep, start);
    while (pos != -1) {
        //if (start != pos) {
       list.emplace_back(str.substr(start, pos - start));
        //}
        start = pos + 1;
        pos = str.find(sep, start);
    }
    if (str[start] != sep ) {
        list.emplace_back(str.substr(start, str.size() - start));
    }
}

void countMaxMinMed(struct statisticData& sd,
                        std::list<std::string>& list,
                        int columnNum)
{
    std::vector<double> vec = catchNumbers(list, columnNum);
    auto pair = maxAndMin(vec);
    sd.max = pair.first;
    sd.min = pair.second;
    sd.med = med(vec);
}

double med(std::vector<double>& vec)
{
    std::sort(vec.begin(), vec.end());
    int pos = vec.size() / 2;
    return vec[pos];
}

std::pair<double, double> maxAndMin(const std::vector<double>& vec)
{
    double max = vec[0];
    double min = vec[0];
    for (const auto& el : vec) {
        if (el > max) {
            max = el;
        }
        if (el < min) {
            min = el;
        }
    }
    return std::make_pair(max, min);
}

std::vector<double> catchNumbers(const std::list<std::string>& list, const int columnNum)
{
    std::vector<double> vec;
    auto it = list.begin();
    for (int i = 1; i < columnNum; ++i) {
        it++;
    }
    vec.push_back(atof(it->c_str()));
    for (int i = columnNum; i <= 7; ++i) {
        it++;
    }
    return vec;
}
