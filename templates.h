#ifndef __VARIADIC_TEMPLATES_H__
#define __VARIADIC_TEMPLATES_H__
#include <iostream>
#include <string>
using namespace std;

template<typename T>
string toString(const T& value) {
    return std::to_string(value); // Convierte numéricos a texto
}

template<>
string toString(const string& value) {
    return value; // Ya es un texto
}

template<typename T>
auto suma(const T& value) {
    return toString(value); // Convierte a string si es necesario
}

template<typename T, typename ...Args>
auto suma(const T& value, const Args&... args) {
    return toString(value) + suma(args...); 
}

void DemoVarTemplates();

#endif // __VARIADIC_TEMPLATES_H__
