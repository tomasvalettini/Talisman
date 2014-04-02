#ifndef STRENGTHMODIFY_H
#define STRENGTHMODIFY_H

#include "command.h"
#include "character.h"

class StrengthModify : public Command
{
public:
    StrengthModify(Character*, int);
    virtual void redo();
    virtual void undo();

private:
    Character* character;
    int modifier;
};

#endif // INCREASESTRENGTH_H
