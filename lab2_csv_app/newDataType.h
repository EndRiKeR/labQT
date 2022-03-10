#ifndef NEWDATATYPE_H
#define NEWDATATYPE_H

#include <QString>
#include <list>
#include <string>

enum
{
  NoError = 0,
  ErFileOpen,
  ErFileRead,
  ErUncorrectColumn,
  DoNone,
  DoDefault,
  ErRowZero,
  ErFileQuality
};

enum
{
  None = 0,
  OpenFile,
  ViewAll,
  ViewPart,
  CountStatistic
};

//Эта структура пока нигде не используется. Я хочу немного переделать ввод и хранение данных.
//Ну как "немного")
struct rowData
{
    std::string age = "";
    std::string region = "";
    std::string natPopGrow = "";
    std::string birthRate = "";
    std::string deathRate = "";
    std::string genDemRate = "";
    std::string urbanisation = "";
};

//банальная структура, которую можно заменить на std::pair
struct excel
{
    const size_t column = 7;
    size_t row = 0;
    std::list<struct rowData> items;
};

struct statisticData
{
    int columnNum = 0;
    double max = 0.0;
    double min = 0.0;
    double med = 0.0;
};

struct dataFromFile
{
    QString fileName = "";
    std::string filePath = "";
    std::string filter = "";
    std::list<struct rowData>* sortedData = nullptr;
    struct excel table;
    struct statisticData statistic;
    int nextMove = None;
    int error = NoError; //добавить еще пояснение ошибок
};

#endif // NEWDATATYPE_H
