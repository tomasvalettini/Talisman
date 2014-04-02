#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "mapregion.h"

class MapEditor
{
public:
    //Comments on methods in mapeditor.cpp
    MapEditor();
    ~MapEditor();
    MapRegion* getOutterRegion();
    MapRegion* getMiddleRegion();
    MapRegion* getInnerRegion();

private:
    MapRegion *outter_region;   //represents the outter region
    MapRegion *middle_region;   //represents the middle region
    MapRegion *inner_region;    //represents the inner region
};

#endif // MAPEDITOR_H
