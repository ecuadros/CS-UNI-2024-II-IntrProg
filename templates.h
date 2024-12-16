#ifndef __VARIADIC_TEMPLATES_H__
#define __VARIADIC_TEMPLATES_H__

#include <iostream>
#include <sstream>
#include <string>

// Función base: convierte cualquier valor a std::string
template<typename T>
std::string to_string(const T& value) {
    std::ostringstream oss;
    oss << value; // Convierte el valor a texto
    return oss.str();
}

// Función base para <<suma>>: caso único (cuando queda un solo argumento)
template<typename T>
std::string suma(const T& value) {
    return to_string(value); // Convierte el valor restante a cadena
}

// Función recursiva para <<suma>>: combina valores usando concatenación
template<typename T, typename... Args>
std::string suma(const T& value, const Args&... args) {
    return to_string(value) + suma(args...); // Concatena el valor actual con el resto
}

// Función de demostración
void DemoVarTemplates() {
    std::cout << "Concatenar cadenas y números:" << std::endl;
    std::cout << suma("La suma de ", 5, " y ", 10, " es ", 15) << std::endl;
    std::cout << suma("Mi edad es ", 25, ".") << std::endl;
    std::cout << suma("Pi es aproximadamente ", 3.14159) << std::endl;
}

#endif // __VARIADIC_TEMPLATES_H__
