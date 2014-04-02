#ifndef LIFEMODIFY_H
#define LIFEMODIFY_H

#include "command.h"
#include "character.h"

class LifeModify : public Command
{
public:
    LifeModify(Character*, int);
    virtual void redo();
    virtual void undo();

private:
    Character* character;
    int modifier;
};

#endif // LIFEMODIFY_H
