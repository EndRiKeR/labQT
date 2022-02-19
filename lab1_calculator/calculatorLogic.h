#ifndef CALCULATORLOGIC_H
#define CALCULATORLOGIC_H

#include <cmath>
#include "newDataType.h"

//calcLogic - это просто деление. Вся работа в calcMath

void doMath(struct mathData* md);
void doDefaultOperation(struct mathData* md);
void doInstrumentalOperation(struct mathData* md);
void doAdditionalOperation(struct mathData* md);
void doMemoryOperation(struct mathData* md);

#endif // CALCULATORLOGIC_H
