#include <iostream>
#include "circle.h"
using namespace std;

void circle::draw() {
    figure::draw();
    cout << "Circle draw" << endl;
}