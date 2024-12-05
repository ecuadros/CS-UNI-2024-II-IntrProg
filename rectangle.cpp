#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(string _name) : name(_name) {       //_name es una variable que almacena el valor que se le indique al crear el objeto de la clase Rectangle
    cout << "Rectangle: " << name << " construido..." << endl;
}

Rectangle::~Rectangle() {
    cout << "Rectangle: " << name << " destruido..." << endl;
}

void Rectangle::draw() {
    cout << "Dibujando Rectangle: " << name << endl;
}
