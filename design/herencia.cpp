#include <iostream>
using namespace std;
#include "herencia.h"
#include "rectangle.h"
#include "circle.h"
#include "point.h"

void px(Figure *p)
{
    p->draw();
}
void px(Figure &rObj)
{
    rObj.draw();
}

void HerenciaDemo(){
Figure *pf[3]={new Rectangle, new Circle, new Point("Punto 5")};

    for(int i=0; i<3; i++){
        pf[i]->draw();
        cout << "************\n";
    }
    //falta implementar el delete
    for(int i = 0; i < 3; i++)
    {
        delete pf[i]; // con esto voy a liberar cada objeto dinamico creado
        pf[i] = nullptr;
    }

    px(pf[1]);
    px(*pf[1]);
}