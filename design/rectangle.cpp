#include <iostream>
#include "rectangle.h"
#include "funcion.h"
using namespace std;
Rectangle::Rectangle(const std::string &name) : Figure(name)
{
    cout << "Rectangle: " << GetName() << " Constructor llamado ..." << endl;
}
void Rectangle::draw()
{
    Figure::draw();
    cout << "Rectangle draw" << endl;
    ::draw();
}
