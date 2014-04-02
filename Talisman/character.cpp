#include "character.h"
#include <iostream>

//Initial values reflecting concrete characters attributes
Character::Character(int init_base_strength, int init_base_craft, int init_max_health, int init_fate,
                     int init_num_of_spells, string init_location, string init_alignment, MapEditor *map, string name)
{
    //Initializing character values
    counter_strength = 0;
    counter_craft = 0;
    gold = 1;
    trophies = 0;

    is_alive = true;
    has_mule = false;
    is_toad = false;

    base_strength = init_base_strength;
    base_craft = init_base_craft;
    max_health = init_max_health;
    current_health = init_max_health;
    max_fate = init_fate;
    current_fate = init_fate;
    num_of_spells = init_num_of_spells;
    //a pointer to the map is needed to give the starting loation to the character
    updateLocation(map->getOutterRegion()->getMapSquare(init_location));
    alignment = init_alignment;
    class_name = name;
}

//Gain strength, possibly, above base strength
void Character::gainStrength(int inc)
{
    counter_strength += inc;
}

//Lose strength, but not below base strength
void Character::loseStrength(int dec)
{
    counter_strength -= dec;

    if (counter_strength < 0)
        counter_strength = 0;
}

//Gain craft, possibly, above base craft
void Character::gainCraft(int inc)
{
    counter_craft += inc;
}

//Lose craft, but not below base craft
void Character::loseCraft(int dec)
{
    counter_craft -= dec;

    if (counter_craft < 0)
        counter_craft = 0;
}

//Gain live, possibly, above base live
void Character::gainLife(int inc)
{
    current_health += inc;
}

//Heal lost live up to base health
void Character::replenishLife(int rep)
{
    current_health += rep;

    if (current_health > max_health)
        current_health = max_health;
}

//Lose live until you are dead
void Character::loseLife(int dec)
{
    current_health -= dec;

    if (current_health <= 0)
        is_alive = false;
}

void Character::gainGold(int inc)
{
    gold += inc;
}

void Character::loseGold(int dec)
{
    gold -= dec;

    if (gold <= 0)
        gold = 0;
}

//Gain a fate token, possibly, above base fate tokens
void Character::gainFate(int inc)
{
    current_fate += inc;
}

//Replenish fate up to base fate tokens
void Character::replenishFate(int rep)
{
    current_fate += rep;

    if (current_fate > max_fate)
        current_fate = max_fate;
}

//Lose fate token until none is left
void Character::loseFate(int dec)
{
    current_fate -= dec;

    if (current_fate < 0)
        current_fate = 0;
}

//Move character on map
void Character::updateLocation(Node *up_loc)
{
    location = up_loc;
}

//A character can change alignment
void Character::updateAlignment(string up_al)
{
    alignment = up_al;
}

//Update flag if the character has a mule or not
void Character::updateMule()
{
    if (has_mule)
        has_mule = false;
    else
        has_mule = true;
}

//Update flag if character is a toad
void Character::updateToad()
{
    if (is_toad)
        is_toad = false;
    else
        is_toad = true;
}

//Simply returns the location of the character
Node* Character::getLocation()
{
    return location;
}

//Return class name of the character
string Character::getClassName()
{
    return class_name;
}

int Character::getStrength()
{
    return (base_strength + counter_strength);
}

int Character::getCraft()
{
    return (base_craft + counter_craft);
}

int Character::getLife()
{
    return current_health;
}

int Character::getGold()
{
    return gold;
}

int Character::getFate()
{
    return current_fate;
}
