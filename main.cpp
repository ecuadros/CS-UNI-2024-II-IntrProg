#include "MiniExcel.h"

int main() {
    MiniExcel excel;

    // Insertar números
    excel.setCell("A1", "10");
    excel.setCell("A2", "20");

    // Insertar palabras
    excel.setCell("B1", "Hola");
    excel.setCell("B2", "Mundo");

    // Insertar fórmulas
    excel.setCell("C1", "=A1+A2");
    excel.setCell("C2", "=A2-A1");

    // Imprimir cuadrícula
    std::cout << "Cuadrícula inicial:" << std::endl;
    excel.printGrid();

    // Evaluar celdas con fórmulas
    std::cout << "\nEvaluando fórmulas:" << std::endl;
    std::cout << "C1 (A1 + A2): " << excel.evaluateCell("C1") << std::endl;
    std::cout << "C2 (A2 - A1): " << excel.evaluateCell("C2") << std::endl;

    return 0;
}
