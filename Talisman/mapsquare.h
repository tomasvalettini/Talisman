#ifndef MAPSQUARE_H
#define MAPSQUARE_H

#include <string>
#include <QImage>
#include <QRect>
using std::string;

class MapSquare
{
public:
    //Comments on methods in mapsquare.cpp
    MapSquare(QString, string, string);
    string getName();
    string getRegion();
    QRect getRectangle();
    QImage & getImage();
    void setPosition(int, int);

private:
    string name;    //Holds the name of the map square
    string region;  //Holds the region where the map square resides
    QImage img;
    QRect rect;
};

#endif // MAPSQUARE_H
