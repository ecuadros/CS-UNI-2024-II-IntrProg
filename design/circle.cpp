#include <iostream>
#include "circle.h"

using namespace std;
Circle::Circle(string _name)
       :Figure(_name)
{
    cout << "Circle: " << GetName() << " Construido ..." << endl;
}

Circle::~Circle()
{
    cout << "Circle: " << GetName() << " Destruido ..." << endl;
}
void Circle::draw()
{
    Figure::draw();
    cout << "Circle draw" <<endl;
}
