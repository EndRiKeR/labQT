#ifndef NEWDATATYPE_H
#define NEWDATATYPE_H

#include <QString>
#include <vector>
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

struct excel
{
    const size_t column = 7;
    size_t row = 0;
    std::vector<struct rowData> items;
};

struct statisticData
{
    std::string columnNum = 0;
    double max = 0.0;
    double min = 0.0;
    double med = 0.0;
};

struct error
{
    int erCode = NoError;
    std::string erInfo;
};

struct dataFromFile
{
    QString fileName = "";
    std::string filePath = "";
    std::string filter = "";
    std::vector<struct rowData>* sortedData = nullptr;
    struct excel table;
    struct statisticData statistic;
    int nextMove = None;
    struct error error;
};

#endif // NEWDATATYPE_H