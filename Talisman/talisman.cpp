#include "talisman.h"
#include <QPainter>
#include <QImage>
#include <QRect>
#include "mapeditor.h"
#include <iostream>

using namespace std;

Talisman::Talisman(QWidget *parent) : QWidget(parent)
{
    loadMap();
    resizeWindow();
}

void Talisman::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // paint map
    Node *cursor = map->getOutterRegion()->getHead();
    bool first = false;

    while (cursor != map->getOutterRegion()->getHead() || !first)
    {
        first = true;
        painter.drawImage(cursor->data->getRectangle(), cursor->data->getImage());
        cursor = cursor->next;
    }

    cursor = map->getMiddleRegion()->getHead();
    first = false;

    while (cursor != map->getMiddleRegion()->getHead() || !first)
    {
        first = true;
        painter.drawImage(cursor->data->getRectangle(), cursor->data->getImage());
        cursor = cursor->next;
    }

    cursor = map->getInnerRegion()->getHead();
    first = false;

    while (cursor != map->getInnerRegion()->getHead() || !first)
    {
        first = true;
        painter.drawImage(cursor->data->getRectangle(), cursor->data->getImage());
        cursor = cursor->next;
    }
}

void Talisman::loadMap()
{
    map = new MapEditor();
}

void Talisman::resizeWindow()
{
    Node *n1 = map->getOutterRegion()->getHead();
    Node *n2 = map->getOutterRegion()->getHead()->next;
    int w = n1->data->getRectangle().width();
    int h = n1->data->getRectangle().height();

    while (n1->data->getRectangle().y() == n2->data->getRectangle().y())
    {
        w += n2->data->getRectangle().width();
        n1 = n1->next;
        n2 = n2->next;
    }

    n1 = map->getOutterRegion()->getHead();
    n2 = map->getOutterRegion()->getHead()->prev;

    while (n1->data->getRectangle().x() == n2->data->getRectangle().x())
    {
        h += n2->data->getRectangle().height();
        n1 = n1->prev;
        n2 = n2->prev;
    }

    resize(w, h);
}
