#include "sort.h"

// Función de comparación para ordenar de manera ascendente
auto ascendente = [](auto a, auto b) {
    return a < b;
};

// Función de comparación para ordenar de manera descendente
auto descendente = [](auto a, auto b) {
    return a > b;
};

void SortDemo(){
    int v[10] = {5,2,10,70,45, 8, 9, 7, 15, 23};
    QuickSort(v, 0, 9, ascendente);
    Print(cout, v, 10);

    float w[10] = {5.3, 2.1, 10.5, 70.4, 45.3, 8.7, 9.2, 1.5, 2.5, 2.3};
    QuickSort(w, 0, 9, descendente);
    Print(cout, w, 10);
}