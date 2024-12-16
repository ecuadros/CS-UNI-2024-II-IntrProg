#ifndef __VARIADIC_TEMPLATES_H__
#define __VARIADIC_TEMPLATES_H__
#include <iostream>
#include <string>
#include <sstream> // stringstream
using namespace std;

template<typename T>
string to_str(const T &value) {
    ostringstream oss;
    oss << value;
    return oss.str();
}

template<typename T>
auto suma(const T& value) { // conversión
    return to_str(value);
}


template<typename T, typename ...Args> // variadic template
auto suma(const T& value, const Args&... args) { // versión "recursiva" de suma
    return to_str(value) + suma(args...); 
}

void DemoVarTemplates();

#endif //
