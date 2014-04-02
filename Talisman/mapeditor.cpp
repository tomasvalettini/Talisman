#include "mapeditor.h"

//Creating the 3 regions representing the Talisman map.
MapEditor::MapEditor()
{
    outter_region = new MapRegion(0, 0, 0);
    middle_region = new MapRegion(1, outter_region->getHead()->prev->data->getRectangle().x() + outter_region->getHead()->prev->data->getRectangle().width(), outter_region->getHead()->prev->data->getRectangle().y());
    inner_region = new MapRegion(2, middle_region->getHead()->prev->data->getRectangle().x() + middle_region->getHead()->prev->data->getRectangle().width(), middle_region->getHead()->prev->data->getRectangle().y());
}

//Deleting regions
MapEditor::~MapEditor()
{
    delete outter_region;
    delete middle_region;
    delete inner_region;
}

//The following 3 "getters" are returning the the corresponding region.
MapRegion* MapEditor::getOutterRegion()
{
    if (outter_region != NULL)
    {
        return outter_region;
    }
    return NULL;
}

MapRegion* MapEditor::getMiddleRegion()
{
    if (middle_region != NULL)
    {
        return middle_region;
    }
    return NULL;
}

MapRegion* MapEditor::getInnerRegion()
{
    if (inner_region != NULL)
    {
        return inner_region;
    }
    return NULL;
}
