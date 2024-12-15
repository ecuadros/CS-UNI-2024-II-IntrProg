#ifndef __VARIADIC_TEMPLATES_H__
#define __VARIADIC_TEMPLATES_H__
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<typename T>
auto suma(const T& value) {
    return value;
}

template<typename T>
auto suma2(const T& value) {
    stringstream cadena;
    cadena << value;
    return cadena.str();
}


template<typename T, typename ...Args>
auto suma(const T& value, const Args&... args) {
    return value + suma(args...); 
}

template<typename T, typename ...Args>
auto suma2(const T& value, const Args&... args) {
    stringstream cadena;
    cadena << value;
    cadena << suma2(args...);
    return cadena.str();
}

void DemoVarTemplates();

#endif //