#include <iostream>
using namespace std;
#include "ConstructorDestructorHerencia.h"
#include "design/herencia.h"
#include "design/rectangle.h"
#include "design/circle.h"
#include "design/point.h"

void ConstructorDestructorHerenciaDemo(){
    Figure *vFig[3] = {new Rectangle, 
                       new Circle, 
                       new Point("Point 8")};
    cout << "Final de los 3 objetos construidos ...\n\n";

    for (auto i = 0; i < 3; i++)
        vFig[i]->draw();
    cout << "Draw llamado por polimorfismo ok ...\n\n";
    for (auto i = 0; i < 3; i++)
        px(vFig[i]);
    cout << "Draw llamado desde una funcion que recibe un Figure * ...\n\n";
    for (auto i = 0; i < 3; i++)
        px(*vFig[i]);
    cout << "Draw llamado desde una funcion que recibe un Figure & ...\n\n";
    
    for (auto i = 0; i < 3; i++){
        delete vFig[i];
        vFig[i] = nullptr;
    }
    cout << "Destructores terminaron ok ...\n\n";
}

void MemoryAllocatedObjectsDemo(){
    // Crear objetos en una memoria que ya existe
    void* pMem = new char[sizeof(Rectangle)+sizeof(Circle)+sizeof(Point)];
    Rectangle *pRect   = new (pMem) Rectangle();
    Circle    *pCircle = new ((char *)pMem + sizeof(Rectangle)) Circle();
    Point     *pPoint  = new ((char *)pMem + sizeof(Rectangle)+sizeof(Circle)) Point("Point 50");
    Figure *pvFig[3] = {pRect, pCircle, pPoint};
    for (auto i = 0; i < 3; i++)
        px(pvFig[i]);

    (static_cast<Rectangle*>(pvFig[0]))->~Rectangle();       //formas recomendadas por Gemini
    (static_cast<Circle*>(pvFig[1]))->~Circle();
    (static_cast<Point*>(pvFig[2]))->~Point();

    delete (char *)pMem;
}
