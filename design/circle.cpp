#include <iostream>
#include "circle.h"

using namespace std;
void Circle::draw()
{
    Figure::draw();
    cout << "Circle draw" <<endl;
}