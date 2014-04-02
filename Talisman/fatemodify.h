#ifndef FATEMODIFY_H
#define FATEMODIFY_H

#include "command.h"
#include "character.h"

class FateModify : public Command
{
public:
    FateModify(Character*, int);
    virtual void redo();
    virtual void undo();

private:
    Character* character;
    int modifier;
};

#endif // FATEMODIFY_H
