#include "circle.h"

using namespace std;

Circle::Circle(string _name) : name(_name) {   //_name es una variable que almacena el valor que se le pase al crear el objeto de la clase Circle
    cout << "Circle: " << name << " construido..." << endl;
}

Circle::~Circle() {
    cout << "Circle: " << name << " destruido..." << endl;
}

void Circle::draw() {
    cout << "Dibujando Circle: " << name << endl;
}
