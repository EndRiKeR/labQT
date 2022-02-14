#ifndef NEWDATATYPE_H
#define NEWDATATYPE_H

enum {
    None = 0,
    DO, Plus, Minus, Mult, Div, endDO,
    IO, Add, Del, Point, Res, Clear, endIO,
    AO, Swap, Werewolf, Sqrt, Pow, endAO,
    MO, MPlus, MMinus, MResult, MClear, endMO
};

struct memoryData {
    double valueNow;
};

struct mathData {
    double valueUser = 0;
    double valueNow = 0.0;
    double valueRes = 0.0;
    int operationType = None;
    bool error = false;
    int pointDeep = 0;
    struct memoryData memory = {0.0};
};

#endif // NEWDATATYPE_H
