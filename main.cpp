#include "Cell.h"
#include <stdexcept>

// Constructor
Cell::Cell(const std::string& value) : content(value) {}

// Verifica si el contenido es un número
bool Cell::isNumber() const {
    try {
        std::stod(content);
        return true;
    } catch (...) {
        return false;
    }
}

// Evalúa el contenido si es un número
double Cell::evaluate() const {
    if (isNumber()) {
        return std::stod(content);
    }
    return 0;
}
