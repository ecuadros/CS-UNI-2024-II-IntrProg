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

string toString(const string& value) {
    return value;
}
template<typename T>
string toString(const T& value) {
    ostringstream oss;
    oss << value;
    return oss.str();
}

template<typename T, typename ...Args>
auto suma(const T& value, const Args&... args) {
    return value + suma(args...); 
}

void DemoVarTemplates();

#endif //
