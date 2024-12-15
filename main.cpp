#ifndef CELL_H
#define CELL_H

#include <string>

class Cell {
public:
    std::string content; // Contenido de la celda (texto, número o fórmula)

    Cell(const std::string& value = "");

    bool isNumber() const;    // Verifica si el contenido es un número
    double evaluate() const;  // Evalúa el contenido si es un número
};

#endif // CELL_H
