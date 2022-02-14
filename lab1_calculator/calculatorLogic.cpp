#include "calculatorLogic.h"
#include "calculatorMath.h"

void doMath(struct mathData* md)
{
    if (md->operationType == None) {
        doNone(md);
    } else if (md->operationType >= DO && md->operationType <= endDO) {
        doDefaultOperation(md);
    } else if (md->operationType >= IO && md->operationType <= endIO) {
        doInstrumentalOperation(md);
    } else if (md->operationType >= AO && md->operationType <= endAO) {
        doAdditionalOperation(md);
    } else if (md->operationType > MO && md->operationType <= endMO) {
        doMemoryOperation(md);
    }
}

void doNone(struct mathData* md)
{
    //do none :)
}

void doDefaultOperation(struct mathData* md)
{
    switch(md->operationType) { //Вопрос, Switch еще пригоден? (ООП - язык без выбора. Цитата препода по ООП)
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
}

void doInstrumentalOperation(struct mathData* md)
{
    switch(md->operationType) {
    case Add:
        doAdd(md);
        break;
    case Del:
        doDel(md);
        break;
    case Point:
        doPoint(md);
        break;
    case Res:
        doRes(md);
        break;
    case Clear:
        doClear(md);
        break;
    default:
        md->error = true;
        break;
    }
}

void doAdditionalOperation(struct mathData* md)
{
    switch(md->operationType) {
    case Swap:
        doSwap(md);
        break;
    case Werewolf:
        doWerewolf(md);
        break;
    case Sqrt:
        doSqrt(md);
        break;
    case Pow:
        doPow(md);
        break;
    default:
        md->error = true;
        break;
    }
}

void doMemoryOperation(struct mathData* md)
{
    switch(md->operationType) {
    case MPlus:
        doMPlus(md);
        break;
    case MMinus:
        doMMinus(md);
        break;
    case MResult:
        doMResult(md);
        break;
    case MClear:
        doMClear(md);
        break;
    default:
        md->error = true;
        break;
    }
}
