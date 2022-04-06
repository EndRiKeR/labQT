#include "BLogic.h"

void doData(struct dataFromFile& data)
{
    switch(data.nextMove) {
    case None:
        data.error.erCode = DoNone;
        data.error.erInfo = "Я не знаю, как вы попали сюда, но это плохо!\nПрезапустите прграмму и попробуйте снова!\n\nErCode = DoNone";
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
        data.error.erCode = DoDefault;
        data.error.erInfo = "Я не знаю, как вы попали сюда, но это плохо!\nПрезапустите прграмму и попробуйте снова!\n\nErCode = DoDefault";
        break;
    }
}

//Считывание данных из подключенного файла
void inputFile(struct dataFromFile& data)
{
    data.sortedData = new std::vector<struct rowData>;
    inputDataFromFile(data);
    data.table.row = data.sortedData->size();
    if (data.table.row == 0){
        data.error.erCode = ErRowZero;
        data.error.erInfo = "По вашему запросу ничего не найдено.\nПроверьте корректность своего запроса!\n\nErCode = ErRowZero";
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
    if (data.filter == "All Regions") {
        data.filter = "";
    }
    if (data.filter == "Choose region") {
        data.error.erCode = ErRegionFilterChoose;
        data.error.erInfo = "Упс, Вы не выбрали регион для поиска!\nВыберете в выдающем списке нужный пункт и попробуйте снова!\n\nErCode = ErRegionFilterChoose";
    } else if (fileForRead.is_open()) {
        getline(fileForRead, str);
        if (str == "year,region,npg,birth_rate,death_rate,gdw,urbanization") {
            while(getline(fileForRead, str)) {
                if (str.find(data.filter + ",") != -1) {
                    vec = splitStrToVector(str, ',');
                    sortWordsByColumn(data, vec);
                }
            }
        } else {
            data.error.erCode = ErFileQuality;
            data.error.erInfo = "Ваш файл не соответствует стандарту.\nПокайтесь и проверьте файл!\n\nErCode = ErFileQuality";
        }
        fileForRead.close();
    } else {
        data.error.erCode = ErFileRead;
        data.error.erInfo = "Не удалось считать файл!\nПрезапустите прграмму и попробуйте снова!\n\nErCode = ErFileRead";
    }
}

//Делит строку на слова по делителю
void splitStrToWords(std::vector<std::string>& vec, const std::string& str, char sep)
{
    int start = 0;
    int pos = str.find(sep, start);
    while (pos != -1) {
        vec.emplace_back(str.substr(start, pos - start));
        start = pos + 1;
        pos = str.find(sep, start);
    }
    if (str[start] != sep) {
        vec.emplace_back(str.substr(start, str.size() - start));
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
        vec.push_back(str.substr(start, str.size() - start));
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
void outputVectorOfStr(const std::vector<std::string>& vec)
{
    for (auto& str : vec) {
        std::cout << str << std::endl;
    }
}

//Вычисление статистики
void countMaxMinMed(struct dataFromFile& data)
{
    if (data.statistic.columnNum != "Choose column") {
        std::vector<double> vec = catchNumbers(data);
        auto pair = maxAndMin(vec);
        data.statistic.max = pair.first;
        data.statistic.min = pair.second;
        data.statistic.med = med(vec);
    } else {
        data.error.erCode = ErRegionFilterChoose;
        data.error.erInfo = "Неверно выбран регион!\nПроверьте правильность своег овыбора!\n\nErCode = ErRegionFilterChoose";
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
    std::vector<std::string> years;
    std::string el = "";
    for (const auto& row : *(data.sortedData)) {
        switch (data.statistic.columnNum[0]) {
        case 'N':
            el = row.natPopGrow;
            break;
        case 'B':
            el = row.birthRate;
            break;
        case 'D':
            el = row.deathRate;
            break;
        case 'G':
            el = row.genDemRate;
            break;
        case 'U':
            el = row.urbanisation;
            break;
        default:
            data.error.erCode = ErColumnChoose;
            data.error.erInfo = "Упс, Вы не выбрали столбец для нахождения данных!\nВыберете в выдающем списке нужный пункт и попробуйте снова!\n\nErCode = ErColumnChoose";
            break;
        }
        if (data.error.erCode) {
            break;
        }
        if (el != "" && isDigit(el)) {
            vec.push_back(std::stod(el.c_str()));
        }
        if (!contain(years, row.age) && el != "") {
            years.push_back(row.age);
        }
    }
    data.colData = vec;
    data.yearsData = years;
    return vec;
}

bool contain(const std::vector<std::string>& vec, std::string str)
{
    bool result = false;
    for (const auto& region : vec) {
        if (region == str) {
            result = true;
            break;
        }
    }
    return result;
}

void clearAllNew(struct dataFromFile& data)
{
    delete data.sortedData;
}
