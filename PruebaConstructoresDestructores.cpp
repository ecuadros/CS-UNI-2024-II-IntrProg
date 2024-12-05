#include <iostream>
#include "circle.h"
#include "rectangle.h"

using namespace std;

void ConstructorDestructorHerenciaDemo() {
    const int N = 2;
    Circle *vFig[N] = {new Circle("Circle 1"), new Rectangle("Rectangle 1")};
    
    for (int i = 0; i < N; i++) {
        vFig[i]->draw();
    }


  
    for (int i = 0; i < N; i++) {
        delete vFig[i];
    }
}

int main() {
    ConstructorDestructorHerenciaDemo();
    return 0;
}
