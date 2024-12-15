#include "templates.h"

void DemoVarTemplates(){
    int    i = 2;
    double d = 3.5;
    long   l = 5;

    auto rpta1 = suma(i, d, l); // Imprime: 10.5
    cout << rpta1 << endl;

    auto rpta2 = suma(5, d, 3, l, 4.3, i);
    cout << rpta2 << endl;      // Imprime: 17.8

    string text1 = "Hola",
           text2 = "C++",
           text3 = "UNI:",
           text4 = "llego Navidad";
    auto rpta3 = suma(text1, text2, text3, text4);  
    cout << rpta3 << endl;    // Imprime: HolaC++UNI:llego Navidad

    auto rpta4 = suma(text3, text2, text1);  
    cout << rpta4 << endl;    // Imprime: HolaC++UNI:llego Navidad

    auto rpta5 = suma(5, text1, 10.3, text2);  
    cout << rpta5 << endl; // Imprime: 5Hola10.3C++
}
