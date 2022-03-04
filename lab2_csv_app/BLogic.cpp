#include "BLogic.h"
#include <QFile>

void doData(struct dataFromFile& data)
{
    switch(data.nextMove) {
    case None:
        data.error = DoNone;
        break;
    case OpenFile:
        openFileAndTakeName(data);
        break;
    case ViewAll:
        inputFile(data);
        break;
    case ViewPart:
        inputFile(data);
        break;
    case CountStatistic:
        countMaxMinMed(data);
        break;
    default:
        data.error = DoDefault;
        break;
    }
}

//подключение файла
void openFileAndTakeName(struct dataFromFile& data)
{
    data.filePath = QFileDialog::getOpenFileName(0,
                                                    "Open File",
                                                    "D://progectsForCpp/labQT/lab2_csv_app/",
                                                    "Excel Files (*.csv)").toStdString();
    data.fileName = QString::fromStdString(splitStrToWords(data.filePath, '/'));
    if (data.filePath == "") {
        data.error = ErFileOpen;
    }
    //QMessageBox::information(0, "File Path", QString::fromStdString(data.filePath));
    //QMessageBox::information(0, "File Path", data.fileName);
}


//Считывание данных из подключенного файла
void inputFile(struct dataFromFile& data)
{
    data.stringsFromFile = new std::list<std::string>;
    if (data.filter == "") {
        data.filter = ",";
    }
    inputDataFromFile(data);
    data.table.row = data.stringsFromFile->size();
    if (data.table.row == 0){
        data.error = ErRowZero;
    } else {
        data.wordsFromFile = new std::list<std::string>;
        for (auto & str : *(data.stringsFromFile)) {
            splitStrToWords(*(data.wordsFromFile), str, ',');
        }

    }
    delete data.stringsFromFile;
}

//читает файл
void inputDataFromFile(struct dataFromFile& data)
{
    std::string str;
    std::ifstream fileForRead(data.filePath);
    if (fileForRead.is_open()) {
        getline(fileForRead, str); //убираю вспомогат. строку
        while(getline(fileForRead, str)) {
            if (str.find(data.filter) != -1) {
                data.stringsFromFile->push_back(str);
            }
        }
        fileForRead.close();
    } else {
        data.error = ErFileRead;
    }
}

//Делит строку на слова по делителю
void splitStrToWords(std::list<std::string>& list, const std::string& str, char sep)
{
    int start = 0;
    int pos = str.find(sep, start);
    while (pos != -1) {
        list.emplace_back(str.substr(start, pos - start));
        start = pos + 1;
        pos = str.find(sep, start);
    }
    if (str[start] != sep ) {
        list.emplace_back(str.substr(start, str.size() - start));
    }
}

std::string splitStrToWords(const std::string& str, char sep)
{
    std::string newStr;
    int start = 0;
    int pos = str.find(sep, start);
    while (pos != -1) {
        newStr = str.substr(start, pos - start);
        start = pos + 1;
        pos = str.find(sep, start);
    }
    if (str[start] != sep ) {
        newStr = str.substr(start, str.size() - start);
    }
    return newStr;
}

//дебаг
void outputListOfStr(const std::list<std::string>& list)
{
    for (auto& str : list) {
        std::cout << str << std::endl;
    }
}

//Вычисление статистики
void countMaxMinMed(struct dataFromFile& data)
{
    if (data.statistic.columnNum >= 3 && data.statistic.columnNum <= 7) {
        std::vector<double> vec = catchNumbers(data);
        auto pair = maxAndMin(vec);
        data.statistic.max = pair.first;
        data.statistic.min = pair.second;
        data.statistic.med = med(vec);
    } else {
        data.error = ErUncorrectColumn;
    }
}

double med(std::vector<double>& vec)
{
    std::sort(vec.begin(), vec.end());
    int pos = vec.size() / 2;
    std::cout << vec[pos] << std::endl;
    return vec[pos];
}

std::pair<double, double> maxAndMin(const std::vector<double>& vec)
{
    double max = vec[0];
    double min = vec[0];
    std::cout << "max: " << max << " min: " << min << std::endl;
    for (const auto& el : vec) {
        if (el > max) {
            max = el;
        }
        if (el < min) {
            min = el;
        }
        std::cout << "max: " << max << " min: " << min << std::endl;
    }
    return std::make_pair(max, min);
}

std::vector<double> catchNumbers(struct dataFromFile& data)
{
    std::vector<double> vec;
    double num = 0.0;
    auto it = data.wordsFromFile->begin();
    int count = 1;
    while (it != data.wordsFromFile->end()) {
        if (count == data.statistic.columnNum && *it != "" && isDigit(*it)) {
            num = atof(it->c_str());
            vec.push_back(num);
        }
        it++;
        if (count == 7) {
            count = 1;
        } else {
            count++;
        }
    }
    return vec;
}

bool isDigit(std::string& str)
{
    bool digit = true;
    bool justPoint = false;
    QString qstr = QString::fromStdString(str);
    for (size_t i = 0; i < str.size(); ++i) {
        if ((!qstr[i].isDigit() && qstr[i] != '.')
                || (qstr == '.' && justPoint)) {
            digit = false;
            break;
        } else if (qstr[i] == '.' && !justPoint) {
            justPoint = true;
        }
    }
    return digit;
}
