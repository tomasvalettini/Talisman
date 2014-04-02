#include "fatemodify.h"

FateModify::FateModify(Character* charObj, int inc)
{
    character = charObj;
    modifier = inc;
    this->redo();
}

void FateModify::redo()
{
    character->gainStrength(modifier);
}

void FateModify::undo()
{
    character->loseStrength(modifier);
}
