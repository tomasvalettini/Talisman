#include "thief.h"

//Initializing the constants
const string Thief::LOCATION = "CITY";
const string Thief::ALIGNMENT = "Neutral";

//A pointer to the map is passed to retrieve the node corresponding to concrete character's starting location.
Thief::Thief(MapEditor *map) : Character(STRENGTH, CRAFT, LIVES, FATE, NUM_OF_SPELLS, LOCATION, ALIGNMENT, map, "Thief")
{
}
