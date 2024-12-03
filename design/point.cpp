#include <iostream>
#include "point.h"

using namespace std;

Point::Point(string _name) : Figure(_name)
{
    cout << "Point: " << GetName() << " Construido ..." << endl;
}

Point::~Point()
{
    cout << "Point: " << GetName() << " Destruido ..." << endl;
}

void Point::draw(){
    Figure::draw();
    cout << "point draw" << endl;
}