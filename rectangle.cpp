#include <iostream>
#include "rectangle.h"
using namespace std;

void rectangle::draw() {
    figure::draw();
    cout << "Rectangle draw" << endl;
}