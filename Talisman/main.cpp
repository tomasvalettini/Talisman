#include <iostream>
#include "talisman.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Talisman w;
    w.show();

    return a.exec();
}
