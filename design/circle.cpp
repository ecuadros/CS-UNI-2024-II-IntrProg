#include <iostream>
#include "circle.h"

using namespace std;
Circle::Circle(const std::string &name) : Figure(name)
{
    cout << "Circle: " << GetName() << " Constructor llamado ..." << endl;
}
void Circle::draw()
{
    Figure::draw();
    cout << "Circle draw" <<endl;
}
