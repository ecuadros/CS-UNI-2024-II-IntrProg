#ifndef MINIEXCEL_H
#define MINIEXCEL_H

#include "Cell.h"
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

class MiniExcel {
private:
    std::map<std::string, Cell> grid; // Mapa para almacenar celdas por ID

    double getValue(const std::string& cellId); // Obtiene el valor de una celda
    double evaluateFormula(const std::string& formula); // Evalúa fórmulas simples

public:
    void setCell(const std::string& cellId, const std::string& value); // Establece el contenido de una celda
    std::string getCell(const std::string& cellId); // Obtiene el contenido de una celda
    double evaluateCell(const std::string& cellId); // Evalúa el contenido de una celda
    void printGrid(); // Imprime la cuadrícula
};

#endif // MINIEXCEL_H
