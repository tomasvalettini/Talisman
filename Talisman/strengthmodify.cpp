#include "strengthmodify.h"

StrengthModify::StrengthModify(Character* charObj, int inc)
{
    character = charObj;
    modifier = inc;
    this->redo();
}

void StrengthModify::redo()
{
    character->gainStrength(modifier);
}

void StrengthModify::undo()
{
    character->loseStrength(modifier);
}
