#ifndef CALCULATORMATH_H
#define CALCULATORMATH_H

#include <string>
#include "newDataType.h"

//default operations
void doPlus(struct mathData* md);
void doMinus(struct mathData* md);
void doMult(struct mathData* md);
void doDiv(struct mathData* md);

//instrument operations
void doAdd(struct mathData* md);
void doDel(struct mathData* md);
void doPoint(struct mathData* md);
void doRes(struct mathData* md);
void doClear(struct mathData* md);

//additional operations
void doSwap(struct mathData* md);
void doWerewolf(struct mathData* md);
void doSqrt(struct mathData* md);
void doPow(struct mathData* md);

//memory operations
void doMPlus(struct mathData* md);
void doMMinus(struct mathData* md);
void doMResult(struct mathData* md);
void doMClear(struct mathData* md);

#endif // CALCULATORMATH_H
