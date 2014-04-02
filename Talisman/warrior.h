#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include "character.h"

using namespace std;

class Warrior : public Character
{
public:
    //Comments on methods in warrior.cpp
    Warrior(MapEditor*);
    ~Warrior();

protected:
    //Static constants representing a concrete character
    static const int STRENGTH = 4;
    static const int CRAFT = 2;
    static const int FATE = 1;
    static const int LIVES = 5;
    static const int NUM_OF_SPELLS = 0;

    static const string LOCATION;
    static const string ALIGNMENT;
};

#endif // WARRIOR_H
