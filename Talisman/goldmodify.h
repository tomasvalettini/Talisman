#ifndef GOLDMODIFY_H
#define GOLDMODIFY_H

#include "command.h"
#include "character.h"

class GoldModify : public Command
{
public:
    GoldModify(Character*, int);
    virtual void redo();
    virtual void undo();

private:
    Character* character;
    int modifier;
};

#endif // GOLDMODIFY_H
