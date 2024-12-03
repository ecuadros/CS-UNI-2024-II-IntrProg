#include <iostream>
#include "rectangle.h"
#include "funcion.h"
using namespace std;

Rectangle::Rectangle(string _name)
          :Figure(_name)
{
    cout << "Rectangle: " << GetName() << " Construido ..." << endl;
}

Rectangle::~Rectangle()
{
    cout << "Rectangle: " << GetName() << " Destruido ..." << endl;
}

void Rectangle::draw()
{
    Figure::draw();
    cout << "Rectangle draw" << endl;
    ::draw();
}
