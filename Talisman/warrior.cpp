#include "warrior.h"

//Initializing the constants
const string Warrior::LOCATION = "TAVERN";
const string Warrior::ALIGNMENT = "Neutral";

//A pointer to the map is passed to retrieve the node corresponding to concrete character's starting location.
Warrior::Warrior(MapEditor *map) : Character(STRENGTH, CRAFT, LIVES, FATE, NUM_OF_SPELLS, LOCATION, ALIGNMENT, map, "Warrior")
{
}
