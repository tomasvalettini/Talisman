#ifndef CRAFTMODIFY_H
#define CRAFTMODIFY_H

#include "command.h"
#include "character.h"

class CraftModify : public Command
{
public:
    CraftModify(Character*, int);
    virtual void redo();
    virtual void undo();

private:
    Character* character;
    int modifier;
};

#endif // CRAFTMODIFY_H
