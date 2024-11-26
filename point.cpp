#include <iostream>
#include "point.h"

using namespace std;

void Point::draw()
{
    Figure::draw();
    cout << "point draw" << endl;
}