#include <iostream>
#include "rectangle.h"
using namespace std;
void draw(){
    cout << "Outside draw" << endl;
}
void Rectangle::draw(){
    Figure::draw();
    cout << "Rectangle draw" << endl;
    ::draw();
}
