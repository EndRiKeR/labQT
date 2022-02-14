#include "calculatorMath.h"

//default operations
void doPlus(struct mathData* md)
{
    md->valueRes += md->valueNow;
}

void doMinus(struct mathData* md)
{
    md->valueRes -= md->valueNow;
}

void doMult(struct mathData* md)
{
    md->valueRes *= md->valueNow;
}

void doDiv(struct mathData* md)
{
    if (md->valueNow != 0) {
        md->valueRes = md->valueRes / md->valueNow;
    } else {
        md->error = true;
    }
}

//instrument operations
void doAdd(struct mathData* md)
{
    if (!md->pointDeep) {
        md->valueNow = md->valueNow * 10 + md->valueUser;
    } else {
        md->valueNow = md->valueNow + (md->valueUser / pow(10, md->pointDeep));
        md->pointDeep += 1;
    }
}

void doDel(struct mathData* md)
{
    if (!md->pointDeep) {
        md->valueNow = md->valueNow / 10;
    } else {
        md->valueNow = md->valueNow - (md->valueUser / pow(10, md->pointDeep));
        md->pointDeep -= 1;
    }
}

void doPoint(struct mathData* md)
{
    if (!md->pointDeep) {
        md->pointDeep = 1;
    }
}

void doRes(struct mathData* md)
{
    //do result
}

void doClear(struct mathData* md)
{
    md->valueUser = 0;
    md->valueNow = 0.0;
    md->valueRes = 0.0;
    md->operationType = None;
    md->error = false;
    md->pointDeep = 0;
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
    md->valueNow = pow(md->valueNow, 2);
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
