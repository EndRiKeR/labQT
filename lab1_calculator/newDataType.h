#ifndef NEWDATATYPE_H
#define NEWDATATYPE_H

#include <string>

//Суть этого заголовочного - создать структуры для работы и подключать их куда-угодно

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
    double valueUser = 0; //цифра, на которую нажал пользователь
    double valueNow = 0.0; //число, которое сейчас видит и вводит пользователь
    double valueRes = 0.0; //текущий результат
    int operationType = None; //Тип операции, которая сейчас производится(произвелась)
    int MoveNext = None; //Тип операции стандартных действий (разраб пояснит)
    bool error = false; //Была ли получена ошибка в результате действий
    bool point = false; //стоит ли точка в числе
    bool afterMove = false; //Произошло ли действие или нет (это для визуала)
    int pointDeep = 0; //Насколько глубоко лежит число относительно точки
    std::string visual = "0"; //То, что видит пользователь
    struct memoryData memory = {0.0}; //память для функций памяти
};

#endif // NEWDATATYPE_H
