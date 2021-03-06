#include "calculatorMath.h"

//help func
void prepareForNextMove(struct mathData* md)
{
    md->valueNow = 0.0;
    md->point = false;
    md->pointDeep = 0;
    md->MoveNext = md->operationType;
}

void doNone(struct mathData* md)
{
    if (md->operationType == Add) {
        doAdd(md);
    } else if (md->MoveNext == None) {
        md->MoveNext = md->operationType;
        md->valueRes = md->valueNow;
        md->valueNow = 0;
        prepareForNextMove(md);
    }
}

//default operations
void doPlus(struct mathData* md)
{
    md->valueRes += md->valueNow;
    prepareForNextMove(md);
}

void doMinus(struct mathData* md)
{
    md->valueRes -= md->valueNow;
    prepareForNextMove(md);
}

void doMult(struct mathData* md)
{
    md->valueRes *= md->valueNow;
    prepareForNextMove(md);
}

void doDiv(struct mathData* md)
{
    if (md->valueNow != 0) {
        md->valueRes = md->valueRes / md->valueNow;
    } else {
        md->error = true;
    }
    prepareForNextMove(md);
}

//instrument operations
void doAdd(struct mathData* md)
{
    if (md->valueNow >= 0) {
        if (!md->point) {
            md->valueNow = md->valueNow * 10 + md->valueUser;
        } else {
            md->valueNow = md->valueNow + (md->valueUser / pow(10, md->pointDeep));
            md->pointDeep += 1;
        }
    } else {
        if (!md->point) {
            md->valueNow = md->valueNow * 10 - md->valueUser;
        } else {
            md->valueNow = md->valueNow - (md->valueUser / pow(10, md->pointDeep));
            md->pointDeep += 1;
        }
    }

}

void doDel(struct mathData* md)
{
    if (md->point) {
        md->pointDeep -= 1;
    }
    md->valueNow = atof(md->visual.c_str());
}

void doPoint(struct mathData* md)
{
    md->point = true;
    md->pointDeep = 1;
}

void doRes(struct mathData* md)
{
    switch(md->MoveNext) {
    case Plus:
        doPlus(md);
        break;
    case Minus:
        doMinus(md);
        break;
    case Mult:
        doMult(md);
        break;
    case Div:
        doDiv(md);
        break;
    default:
        md->error = true;
        break;
    }
    md->afterMove = true;
}

void doClear(struct mathData* md)
{
    md->valueUser = 0;
    md->valueNow = 0.0;
    md->valueRes = 0.0;
    md->operationType = Clear;
    md->MoveNext = None;
    md->error = false;
    md->point = false;
    md->afterMove = false;
    md->pointDeep = 0;
    std::string visual = "0";
    md->memory = {0.0};
}

//additional operations
void doSwap(struct mathData* md)
{
    md->valueNow = -md->valueNow;
}

void doWerewolf(struct mathData* md)
{
    if (md->valueNow != 0) {
        md->valueNow = 1.0 / md->valueNow;
    } else {
        md->error = true;
    }
}

void doSqrt(struct mathData* md)
{
    if (md->valueNow >= 0) {
        md->valueNow = sqrt(md->valueNow);
    } else {
        md->error = true;
    }
}

void doPow(struct mathData* md)
{
    md->valueNow = md->valueNow * md->valueNow;
}

//memory operations
void doMPlus(struct mathData* md)
{
    md->memory.valueNow += md->valueNow;
}

void doMMinus(struct mathData* md)
{
    md->memory.valueNow -= md->valueNow;
}

void doMResult(struct mathData* md)
{
    md->valueNow = md->memory.valueNow;
}

void doMClear(struct mathData* md)
{
    md->memory = {0.0};
}
