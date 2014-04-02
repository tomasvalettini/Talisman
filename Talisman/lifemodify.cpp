#include "lifemodify.h"

LifeModify::LifeModify(Character* charObj, int inc)
{
    character = charObj;
    modifier = inc;
    this->redo();
}

void LifeModify::redo()
{
    character->gainLife(modifier);
}

void LifeModify::undo()
{
    character->loseLife(modifier);
}
