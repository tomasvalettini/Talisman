#include "goldmodify.h"

GoldModify::GoldModify(Character* charObj, int inc)
{
    character = charObj;
    modifier = inc;
    this->redo();
}

void GoldModify::redo()
{
    character->gainGold(modifier);
}

void GoldModify::undo()
{
    character->loseGold(modifier);
}
