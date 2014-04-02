#ifndef TALISMAN_H
#define TALISMAN_H

#include <QWidget>
#include "mapeditor.h"

class Talisman : public QWidget
{
    Q_OBJECT
public:
    explicit Talisman(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

private:
    void loadMap();
    void resizeWindow();
    void paintMap(QPainter);
    MapEditor* map;
};

#endif // TALISMAN_H
