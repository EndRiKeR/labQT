#include "BLogic.h"

void doData(struct dataFromFile& data)
{
    switch(data.nextMove) {
    case None:
        data.error = DoNone;
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

//Считывание данных из подключенного файла
void inputFile(struct dataFromFile& data)
{
    data.sortedData = new std::list<struct rowData>;
    inputDataFromFile(data);
    data.table.row = data.sortedData->size();
    if (data.table.row == 0){
        data.error = ErRowZero;
    }
}

void sortWordsByColumn(struct dataFromFile& data, const std::vector<std::string>& vec)
{
    auto it = vec.begin();
    struct rowData rowData;
    rowData.age = *it++;
    rowData.region = *it++;
    rowData.natPopGrow = *it++;
    rowData.birthRate = *it++;
    rowData.deathRate = *it++;
    rowData.genDemRate = *it++;
    rowData.urbanisation = *it++;
    data.sortedData->push_back(rowData);
}

//читает файл
void inputDataFromFile(struct dataFromFile& data)
{
    std::string str;
    std::vector<std::string> vec;
    std::ifstream fileForRead(data.filePath);
    if (fileForRead.is_open()) {
        getline(fileForRead, str);
        if (str == "year,region,npg,birth_rate,death_rate,gdw,urbanization") {
            while(getline(fileForRead, str)) {
                if (str.find(data.filter + ",") != -1) {//Гарантированно найдет запятую, но может не найти другого фильтра
                    //data.stringsFromFile->push_back(str);
                    vec = splitStrToVector(str, ',');
                    sortWordsByColumn(data, vec);
                }
            }
        } else {
            data.error = ErFileQuality;
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
    if (str[start] != sep) {
        list.emplace_back(str.substr(start, str.size() - start));
    }
}

std::vector<std::string> splitStrToVector(const std::string& str, char sep) // я убрал const перед str, тк на нее рагалась перегрузка
{
    int start = 0;
    int pos = str.find(sep, start);
    std::vector<std::string> vec;
    while (pos != -1) {
        vec.push_back(str.substr(start, pos - start));
        start = pos + 1;
        pos = str.find(sep, start);
    }
    if (str[start] != sep) {
        vec.push_back(str.substr(start, str.size() - start));//в чем разница push и emplace back
    }
    return vec;
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
    size_t pos = vec.size() / 2;
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
    std::string el = "";
    for (const auto& row : *(data.sortedData)) {
        switch (data.statistic.columnNum) {
        case 3:
            el = row.natPopGrow;
            break;
        case 4:
            el = row.birthRate;
            break;
        case 5:
            el = row.deathRate;
            break;
        case 6:
            el = row.genDemRate;
            break;
        case 7:
            el = row.urbanisation;
            break;
        default:
            break;
        }
        if (el != "" && isDigit(el)) {
            vec.push_back(atof(el.c_str()));
        }
    }
    return vec;
}

void clearAllNew(struct dataFromFile& data)
{
    delete data.sortedData;
}
