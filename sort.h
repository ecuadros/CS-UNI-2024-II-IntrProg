#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__
#include <iostream>
#include <algorithm>    // std::swap
using namespace std;

// Función para partition el arreglo
template <typename T>
size_t partition(T arr[], size_t low, size_t high, bool ascendente) {
    T pivote = arr[high]; // Elegimos el último elemento como pivote
    size_t i = low - 1; // Índice del elemento más pequeño

    for (size_t j = low; j < high; j++) {
        bool condicion = ascendente ? (arr[j] <= pivote) : (arr[j] >= pivote);
        if (condicion) {
            i++;
            swap(arr[i], arr[j]); // Intercambiar
        }
    }
    swap(arr[i + 1], arr[high]); // Colocar el pivote en la posición correcta
    return i + 1; // Retornar el índice del pivote
}

// Función recursiva para aplicar QuickSort
template <typename T>
void QuickSort(T arr[], size_t low, size_t high) {
    if (low < high) {
        size_t pi = partition(arr, low, high); // partition el arreglo

        // Ordenar recursivamente los elementos antes y después de la partición
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

// Función para mostrar el arreglo
template <typename T>
void Print(ostream &os, T arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        os << arr[i] << " ";
    }
    os << endl;
}

void SortDemo();

#endif  // __QUICK_SORT_H__
