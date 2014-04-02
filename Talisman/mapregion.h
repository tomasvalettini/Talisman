#ifndef MAPREGION_H
#define MAPREGION_H

#include <string>
#include "mapsquare.h"
using std::string;

//Node structure holding a MapSquare and pointers to other nodes
struct Node
{
    MapSquare *data;
    Node *next;
    Node *prev;
};

class MapRegion
{
public:
    //Comments on methods in mapregion.cpp
    MapRegion(int, int, int);
    ~MapRegion();
    Node* getMapSquare(string);
    Node* getHead();

private:
    void init(string, int, int);
    Node *head; //Start of the doubly linked list
    Node *tail; //End of the doubly linked list
};

#endif // MAPREGION_H
