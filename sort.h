#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__
#include <iostream>
#include <algorithm>    // std::swap
using namespace std;

// Función para particion el arreglo
template <typename T>
size_t partition(T arr[], size_t low, size_t high) {
    T pivote = arr[(high+low)/2]; // Elegimos el elemento medio como pivote
    size_t i=low,j =high;
    while (i < j){
        // Se avanza el ínidce i mientras que el valor cumpla la comparación con el pivote
        while (arr[i]>pivote){
            i++;
        }
        // Se retrocede el ínidce j mientras que el valor cumpla la comparación con el pivote
        while (pivote > arr[j]){
            j--;
        }
        // si i está aún antes de j, se intercambian los valores
        if (i < j){
            swap(arr[i],arr[j]);
        }
    }
    return i; // Retornar el índice del pivote
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
