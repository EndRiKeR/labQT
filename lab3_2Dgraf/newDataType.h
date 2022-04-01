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
  ErFileQuality,
    ErColumnChoose,
    ErRegionFilterChoose

};

enum
{
  None = 0,
  OpenFile,
  ViewAll,
  ViewPart,
  CountStatistic,
    creatGraf
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
    std::string columnNum = "";//Вот тут было написано std::string columnNum = 0;
    double max = 0.0;
    double min = 0.0;
    double med = 0.0;
};

struct error
{
    int erCode = NoError;
    std::string erInfo = "";
};

struct point
{
    double x = 0;
    double y = 0;
};

struct grafConst
{
    //Размеры главной плоскости
    const double maxX = 970.0;
    const double maxY = 320.0;
    const double minX = 0.0;
    const double minY = 0.0;

    //Размеры области графика
    const double maxGrafX = 885.0;
    const double maxGrafY = 225.0;

    //Отступы от краев для осей (по нормальным координатам)
    const double offsetOX = 40.0;
    const double offsetOY = 50.0;

    //Отступы от краев для области графика (по нормальным координатам)
    const double offsetLeftX = 45.0;
    const double offsetRightX = 40.0;
    const double offsetUpY = 40.0;
    const double offsetDownY = 55.0;

    //Стандартные отступы для корректировки
    const double offset5Pix = 5.0;
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

    //New Data for Lab3
    std::vector<double> colData;
    std::vector<std::string> yearsData;
};

#endif // NEWDATATYPE_H
