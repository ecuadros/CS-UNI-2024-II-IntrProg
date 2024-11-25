#include <iostream>
#include "pointers.h"
#include "sorting.h"
#include "sort.h"
#include "files.h"
#include "vector.h"
#include "bits.h"
#include "struct.h"
#include "employee.h"

#include "rectangle.h"
#include "circle.h"
#include "point.h"
using namespace std;

// g++ -std=c++17 main.cpp pointers.cpp sorting.cpp sort.cpp files.cpp vector.cpp bits.cpp struct.cpp employee.cpp rectangle.cpp circle.cpp point.cpp funcion.cpp figure.cpp -o main

void px (Figure *p)
{
    p->draw();
}
void py (Figure &rObj)
{
    rObj.draw();
}

int main(){
    cout << "Hello Introd Programacion CS-UNI\n";
    // Pointers();
    // Sorting();
    // SortDemo();
    // DemoFiles();
    // VectorDemo();
    // BitsPlayground();
    // BitsDemo();
    // DemoFunctionPointers();
    // DemoStruct();
    //ClassDemo();

    Figure *pf[3]={new Rectangle, new Circle, new Point};

    for(int i=0; i<3; i++)
    {
        pf[i]->draw();
    }
    //falta implementar el delete
    for(int i = 0; i < 3; i++)
    {
        delete pf[i]; // con esto voy a liberar cada objeto dinamico creado
        pf[i] = nullptr;
    }

    px(pf[1]);
    py(*pf[1]);



    // int x = 5, y;
    // if( x < 7)
    //     y = 10;
    // else
    //     y = 20;

    // y = 20;
    // if( x < 7 )
    //     y = 10;

    // y = x<7? 10 : 20 ;

	return 0;
}
