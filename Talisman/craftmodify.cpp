#include "craftmodify.h"

CraftModify::CraftModify(Character* charObj, int inc)
{
    character = charObj;
    modifier = inc;
    this->redo();
}

void CraftModify::redo()
{
    character->gainStrength(modifier);
}

void CraftModify::undo()
{
    character->loseStrength(modifier);
}

/*StrengthModify::StrengthModify(Character* charObj, int inc)
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
*/
