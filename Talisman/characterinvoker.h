#ifndef CHARACTERINVOKER_H
#define CHARACTERINVOKER_H

#include "character.h"
#include "command.h"
#include <vector>

class CharacterInvoker
{
public:
    CharacterInvoker(Character*);
    void redo();
    void undo();
    void increaseStrength(int);
    void increaseCraft(int);
    void increaseLife(int);
    void increaseGold(int);
    void increaseFate(int);
    void showStats();

private:
    Character* character;
    vector<Command*> cmdArr;
    int cmdPos;
};

#endif // CHARACTERINVOKER_H
