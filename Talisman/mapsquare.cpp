#include "mapsquare.h"
#include <iostream>

using namespace std;

//Initialize name and region
MapSquare::MapSquare(QString url, string name, string region)
{
    img.load(url);
    rect = img.rect();
    this->name = name;
    this->region = region;
}

//Return name
string MapSquare::getName()
{
    return this->name;
}

//Return region
string MapSquare::getRegion()
{
    return this->region;
}

QRect MapSquare::getRectangle()
{
    return this->rect;
}

QImage& MapSquare::getImage()
{
    return this->img;
}

void MapSquare::setPosition(int x, int y)
{
    this->rect.moveTo(x, y);
}
