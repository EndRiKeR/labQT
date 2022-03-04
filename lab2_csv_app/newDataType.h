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
  ErRowZero
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
    double age = 0.0;
    QString region = "";
    double natPopGrow = 0.0;
    double birthRate = 0.0;
    double deathRate = 0.0;
    double genDemRate = 0.0;
    double urbanisation = 0.0;
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
    std::list<std::string>* stringsFromFile = nullptr;
    std::list<std::string>* wordsFromFile = nullptr;
    struct excel table;
    struct statisticData statistic;
    int nextMove = None;
    int error = NoError; //добавить еще пояснение ошибок
};

#endif // NEWDATATYPE_H
