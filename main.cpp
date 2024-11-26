#include <iostream>
#include "pointers.h"
#include "sorting.h"
#include "sort.h"
#include "files.h"
#include "vector.h"
#include "bits.h"
#include "struct.h"
#include "employee.h"
#include "design/herencia.h"

#include "design/rectangle.h"
#include "design/circle.h"
#include "design/point.h"
using namespace std;

// g++ -std=c++17 main.cpp pointers.cpp sorting.cpp sort.cpp files.cpp vector.cpp bits.cpp struct.cpp employee.cpp design/herencia.cpp design/figure.cpp design/rectangle.cpp design/circle.cpp design/point.cpp design/funcion.cpp -o main

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

    HerenciaDemo();



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
