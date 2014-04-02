#include "characterinvoker.h"
#include "character.h"
#include "strengthmodify.h"
#include "craftmodify.h"
#include "lifemodify.h"
#include "goldmodify.h"
#include "fatemodify.h"
#include <iostream>

using namespace std;

CharacterInvoker::CharacterInvoker(Character* c)
{
    character = c;
    cmdPos = -1;
}

void CharacterInvoker::redo()
{
    if (cmdPos >= cmdArr.size())
    {
        cout << "Nothing happened...(in redo) \n";
        return;
    }

    cout << "Redoing command #" << cmdPos << endl;
    cmdArr[cmdPos]->redo();
    cmdPos++;
}

void CharacterInvoker::undo()
{
    if (cmdPos <= -1)
    {
        cout << "Nothing happened...(in undo) \n";
        return;
    }

    cout << "Undoing command #" << (cmdPos + 1) << endl;
    cmdArr[cmdPos - 1]->undo();
    cmdPos--;
}

void CharacterInvoker::increaseStrength(int mod)
{
    StrengthModify* sm = new StrengthModify(character, mod);
    cmdArr.push_back(sm);
    cmdPos++;
}

void CharacterInvoker::increaseCraft(int mod)
{
    CraftModify* cm = new CraftModify(character, mod);
    cmdArr.push_back(cm);
    cmdPos++;
}

void CharacterInvoker::increaseLife(int mod)
{
    LifeModify* lm = new LifeModify(character, mod);
    cmdArr.push_back(lm);
    cmdPos++;
}

void CharacterInvoker::increaseGold(int mod)
{
    GoldModify* gm = new GoldModify(character, mod);
    cmdArr.push_back(gm);
    cmdPos++;
}

void CharacterInvoker::increaseFate(int mod)
{
    FateModify* fm = new FateModify(character, mod);
    cmdArr.push_back(fm);
    cmdPos++;
}

void CharacterInvoker::showStats()
{
    cout << "Character class: " << character->getClassName() << endl;
    cout << "Strength: " << character->getStrength() << endl;
    cout << "Craft: " << character->getCraft() << endl;
    cout << "Life: " << character->getLife() << endl;
    cout << "Gold: " << character->getGold() << endl;
    cout << "Fate: " << character->getFate() << endl;
}
