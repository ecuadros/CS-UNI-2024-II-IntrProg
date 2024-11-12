#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_
#include <iostream>
#include <algorithm>    // swap
#include <cstddef>      // size_t
using namespace std;

// Función de comparación para decidir si se ordenará de manera ascendente o descendente
template <typename T>
bool compare(T a, T b) {
    return a > b;  // "<": Ascendente -- ">": Descendente
}

template <typename T>
size_t partition(T arr[], size_t low, size_t high) {
    T pivot = arr[low]; // Pivote como el primer elemento
    size_t i = low + 1;
    size_t j = high;

    while (true) {
        // Por la izquierda deben estar los menores
        while (i <= j && compare(arr[i], pivot))   i++;
        // Por la derecha deben estar los mayores
        while (i <= j && !compare(arr[j], pivot))  j--;
        // Se cruzaron los índices, salir del bucle
        if (i > j)  break; 
        swap(arr[i], arr[j]);  // Intercambiar elementos
        i++;    j--;
    }
    swap(arr[low], arr[j]);    // Colocar el pivote en su lugar
    return j; // Retornar la posición del pivote
}

template <typename T>
void QuickSort(T arr[], size_t low, size_t high) {
    if (low < high) {
        size_t pi = partition(arr, low, high);
        // Llamadas recursivas
        if (pi > 0) QuickSort(arr, low, pi - 1);  // Verifica que pi > 0 para evitar underflow
        QuickSort(arr, pi + 1, high);
    }
}

template <typename T>
void Print(ostream &os, T arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        os << arr[i] << " ";
    }
    os << endl;
}

void SortDemo();

#endif  // _QUICK_SORT_H_
