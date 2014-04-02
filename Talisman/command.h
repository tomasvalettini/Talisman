#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    virtual void redo() = 0;
    virtual void undo() = 0;
};

#endif // COMMAND_H
