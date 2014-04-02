#ifndef THIEF_H
#define THIEF_H

#include "character.h"
#include <string>

class Thief : public Character
{
public:
    //Comments on methods in thief.cpp
    Thief(MapEditor*);

protected:
    //Static constants representing a concrete character
    static const int STRENGTH = 3;
    static const int CRAFT = 3;
    static const int FATE = 2;
    static const int LIVES = 4;
    static const int NUM_OF_SPELLS = 0;

    static const string LOCATION;
    static const string ALIGNMENT;
};

#endif // THIEF_H
