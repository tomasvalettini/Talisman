#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "mapeditor.h"
using namespace std;

class Character
{
public:
    //Comments on methods in character.cpp
    Character(int, int, int, int, int, string, string, MapEditor*, string);
    void gainStrength(int);
    void loseStrength(int);
    void gainCraft(int);
    void loseCraft(int);
    void gainLife(int);
    void replenishLife(int);
    void loseLife(int);
    void gainGold(int);
    void loseGold(int);
    void gainFate(int);
    void replenishFate(int);
    void loseFate(int);
    void updateLocation(Node*);
    void updateAlignment(string);
    void updateMule();
    void updateToad();
    Node* getLocation();
    string getClassName();
    int getStrength();
    int getCraft();
    int getLife();
    int getGold();
    int getFate();

protected:
    int base_strength;			// Base attack power attribute for the character
    int counter_strength;		// Additional attack power
    int base_craft;				// Magic power attribute for the character
    int counter_craft;			// Additional magic power
    int max_health;				// The max health of a character
    int current_health;			// The current health of a character
    int gold;					// Amount of gold
    int max_fate;				// Max amount of fate tokens
    int current_fate;			// Current amount of fate tokens
    int trophies;				// Amount of trophies
    int num_of_spells;			// Number of spells a character can hold

    Node *location;             // Location of the character on the board
    string alignment;			// To check if he is good or bad
    string class_name;

    bool is_alive;              // To check if the character is alive or not
    bool has_mule;				// To check if the character has a mule
    bool is_toad;				// To check if the character is a toad

    //TalismanObject object[4];			// Array of objects a character has
    //Spell spells[3];                  // Array to hold the spells a character has
    //LinkedList<Follower> followers;	// Linked list to hold all followers

};

#endif // CHARACTER_H
