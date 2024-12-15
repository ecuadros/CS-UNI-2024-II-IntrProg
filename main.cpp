#include "MiniExcel.h"
#include <sstream>

// Obtiene el valor de una celda o 0 si no existe
double MiniExcel::getValue(const std::string& cellId) {
    if (grid.find(cellId) != grid.end()) {
        return grid[cellId].evaluate();
    }
    return 0;
}

// Evalúa fórmulas simples del tipo "=A1+A2"
double MiniExcel::evaluateFormula(const std::string& formula) {
    if (formula[0] != '=') {
        throw std::invalid_argument("La fórmula debe comenzar con '='");
    }
    std::istringstream ss(formula.substr(1));
    std::string leftCell, op, rightCell;
    ss >> leftCell >> op >> rightCell;

    double leftValue = getValue(leftCell);
    double rightValue = getValue(rightCell);

    if (op == "+") return leftValue + rightValue;
    if (op == "-") return leftValue - rightValue;
    if (op == "*") return leftValue * rightValue;
    if (op == "/") {
        if (rightValue == 0) throw std::runtime_error("División por cero");
        return leftValue / rightValue;
    }

    throw std::invalid_argument("Operador no soportado");
}

// Establece el contenido de una celda
void MiniExcel::setCell(const std::string& cellId, const std::string& value) {
    grid[cellId] = Cell(value);
}

// Obtiene el contenido de una celda
std::string MiniExcel::getCell(const std::string& cellId) {
    if (grid.find(cellId) != grid.end()) {
        return grid[cellId].content;
    }
    return "";
}

// Evalúa el contenido de una celda
double MiniExcel::evaluateCell(const std::string& cellId) {
    if (grid.find(cellId) == grid.end()) return 0;

    const std::string& content = grid[cellId].content;
    if (content.empty()) return 0;

    if (content[0] == '=') {
        return evaluateFormula(content);
    }

    try {
        return std::stod(content);
    } catch (...) {
        return 0;
    }
}

// Imprime la cuadrícula
void MiniExcel::printGrid() {
    for (char row = 'A'; row <= 'C'; ++row) {
        for (int col = 1; col <= 3; ++col) {
            std::string cellId = std::string(1, row) + std::to_string(col);
            std::cout << getCell(cellId) << "\t";
        }
        std::cout << std::endl;
    }
}
