#include "mapregion.h"
#include <iostream>
#include <string>
#include <QMessageBox>
#include <QFile>
#include <QXmlStreamReader>
using namespace std;

//Initializing a region
MapRegion::MapRegion(int area, int initX, int initY)
{
    head = new Node;
    tail = head;
    string layer;

    //using an int to differentiate between regions.
    switch (area)
    {
    case 0:
        layer = "outter";
        init(layer, initX, initY);
        break;
    case 1:
        layer = "middle";
        init(layer, initX, initY);
        break;
    case 2:
        layer = "inner";
        init(layer, initX, initY);
        break;
    default:
        break;
    }
}

//Building doubly linke list
void MapRegion::init(string cLayer, int initX, int initY)
{
    string layer;
    QString url;
    string location;
    string direction;
    bool first = true;
    bool square = false;
    bool layerFound = false;

    QFile* xmlFile = new QFile("../data/map.xml");

    if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //QMessageBox::critical(this, "Load XML File Problem", "Couldn't open xmlfile.xml to load settings for download", QMessageBox::Ok);
        return;
    }

    QXmlStreamReader* xmlReader = new QXmlStreamReader(xmlFile);

    //Parse the XML until we reach end of it
    while(!xmlReader->atEnd() && !xmlReader->hasError())
    {
        // Read next element
        QXmlStreamReader::TokenType token = xmlReader->readNext();
        //If token is just StartDocument - go to next
        if (token == QXmlStreamReader::StartDocument)
        {
            continue;
        }
        //If token is StartElement - read it
        if (token == QXmlStreamReader::StartElement)
        {
            if (xmlReader->name() == "map")
            {
                continue;
            }
            else if (xmlReader->name() == "layer")
            {
                layer = xmlReader->attributes().value("name").toString().toStdString();

                if (layer == cLayer)
                    layerFound = true;
                else
                    layerFound = false;
            }
            else if (xmlReader->name() == "url" && layerFound)
            {
                url = xmlReader->readElementText();
            }
            else if (xmlReader->name() == "location" && layerFound)
            {
                location = xmlReader->readElementText().toStdString();
            }
            else if (xmlReader->name() == "dir" && layerFound)
            {
                direction = xmlReader->readElementText().toStdString();
                square = true;
            }

            if (layerFound && square)
            {
                square = false;

                if (!first)
                {
                    MapSquare *ms = new MapSquare(url, location, layer);
                    Node *nNode = new Node;

                    nNode->data = ms;
                    nNode->prev = tail;
                    nNode->next = head;
                    tail->next = nNode;
                    tail = nNode;
                    head->prev = tail;

                    if (direction == "right")
                    {
                        tail->data->setPosition(tail->prev->data->getRectangle().x() + tail->prev->data->getRectangle().width(), tail->prev->data->getRectangle().y());
                    }
                    else if (direction == "down")
                    {
                        tail->data->setPosition(tail->prev->data->getRectangle().x() + tail->prev->data->getRectangle().width() - tail->data->getRectangle().width(), tail->prev->data->getRectangle().y() + tail->prev->data->getRectangle().height());
                    }
                    else if (direction == "left")
                    {
                        tail->data->setPosition(tail->prev->data->getRectangle().x() - tail->data->getRectangle().width(), tail->prev->data->getRectangle().y());
                    }
                    else
                    {
                        tail->data->setPosition(tail->prev->data->getRectangle().x(), tail->prev->data->getRectangle().y() - tail->data->getRectangle().height());
                    }
                }
                else
                {
                    first = false;

                    MapSquare *ms = new MapSquare(url, location, layer);
                    head->data = ms;
                    head->next = head;
                    head->prev = head;

                    head->data->setPosition(initX, initY);
                }
            }
        }
    }
    /*
    for (int i = 0; i < size; i++)
    {
        /*
            Handling the "head" of the doubly linked list seperately since
            it's a special case
         *

    }
    */
}

//Returning a node based on the location given
Node* MapRegion::getMapSquare(string loc)
{
    Node *it = head;
    bool headChecked = false;

    while (it != head || !headChecked)
    {
        //handles the first element in the iteration or it will not check all nodes
        if (it == head)
        {
            headChecked = true;
        }

        if (it->data->getName() == loc)
        {
            return it;
        }
        else
        {
            it = it->next;
        }
    }
}

//Return the head of the region
Node* MapRegion::getHead()
{
    return head;
}

//Detructing the region
MapRegion::~MapRegion()
{
    // breaking the circle of map region (not sure if this is necessary)
    head->prev->next = NULL;
    head->prev = NULL;

    while (head)
    {
        Node *del = head;
        head = head->next;

        del->prev = NULL;
        del->next = NULL;
        delete del;
    }
}
