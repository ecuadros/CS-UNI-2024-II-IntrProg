#include <iostream>
#include "rectangle.h"
#include "funcion.h"
using namespace std;

void Rectangle::draw()
{
    Figure::draw();
    cout << "Rectangle draw" << endl;
    ::draw();
}