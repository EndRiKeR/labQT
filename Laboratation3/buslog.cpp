#include "buslog.h"
#include <iostream>

void entry (struct Type& type)
{
    switch(type.userMove) {
    case None:
        break;
    case Input:
        openReadWriteFile(type);
        break;
    case Max:
        type.max = searchMax(type.vec);
        break;
    case Min:
        type.min = searchMin(type.vec);
        break;
    case Med:
        type.med = searchMed(type.vec);
        break;
    case Check:
        type.res = check(type.str);
        break;
    case Sort:
        mySort(type.vec);
        break;
    case Val:
        inputValInVector(type.vec, type.val);
        break;
    default:
        break;
    }
}

void openReadWriteFile(struct Type& data)
{
    std::ifstream file(data.fileName);
    if (file.is_open()){
        std::string prep;
        getline(file, prep);
        if (prep == data.firstStr){
            while (getline(file, prep)){
                data.vecTwo.push_back(prep);
            }
        }
        data.check = 1;
    }else
        data.check = 0;
    file.close();
}

void mySort(std::vector<double>& mas)
{
    std::sort(mas.begin(),mas.end());
}

double searchMin(std::vector<double>& mas)
{
    return mas.front();
}

double searchMax(std::vector<double>& mas)
{
    return mas.back();
}

double searchMed(std::vector<double>& mas)
{
    return mas[mas.size() / 2];
}

void inputValInVector(std::vector<double>& mas, double val)
{
    mas.push_back(val);
}

bool check(std::string str)
{
    bool res;
    if (str != "" && str != "\r"){
        int len = str.size();
        str.erase(len-1, len);
        len = str.size();
        for (int i = 0; i < len; i++){
            if (str[i] == '.'){
                continue;
            }if (str[i] == '-'){
                continue;
            }if ('0' <= str[i] && str[i] <= '9'){
                res = true;
            }else {
                res = false;
                break;
            }
        }
    }else
        res = false;
    return res;
}
