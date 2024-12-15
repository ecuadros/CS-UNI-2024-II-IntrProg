#ifndef __VARIADIC_TEMPLATES_H__
#define __VARIADIC_TEMPLATES_H__
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <type_traits>

using namespace std;

//convertir los numeros en cadenas
template <typename T>
string Astring(T value) {
    if constexpr (is_arithmetic<T>::value) 
    {
        ostringstream os;

        if constexpr (is_floating_point<T>::value) 
        {
            os << value;           //guardandolo a string
        } else {
            os << value;           //si es entero simplememte comviertelos
        }

        return os.str();
    } else if constexpr (is_same<T, string>::value || is_same<T, const char*>::value) 
    {
        return string(value);       
    }
    return "";
}

template<typename T>
auto suma(const T& value) {
    return value;
}


template<typename T, typename ...Args>
auto suma(const T& value, const Args&... args)
 {
    if constexpr (std::is_arithmetic<T>::value && (... && std::is_arithmetic<Args>::value)) 
    {
        //si todos los argumentos son numeros, realizara la suma
        return value + suma(args...);
    } 
    else 
    {
        //si hay palabras o tipos mezclados, convierte todo a cadenas y concatenalas
        return Astring(value) + suma(args...);
    }
}

void DemoVarTemplates();

#endif //