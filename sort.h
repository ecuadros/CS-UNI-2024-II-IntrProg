#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__
#include <iostream>
#include <algorithm>    // std::swap
using namespace std;

template <typename T>
int partition(T arr[], size_t low, size_t high) {
    T pivot = arr[low]; // Pivote como el primer elemento
    auto i = low + 1;
    auto j = high;

    while (true) {
        // Por la izq deben estar los menores 
        while (i <= j && arr[i] <= pivot)   i++;
        // Por la der deben estar los mayores
        while (i <= j && arr[j] > pivot)    j--;
        // Se cruzaron los índices, salir del bucle
        if (i > j)  break; 
        std::swap(arr[i], arr[j]);  // Intercambiar elementos
        i++;    j--;
    }
    std::swap(arr[low], arr[j]);    // Colocar el pivote en su lugar
    return j; // Retornar la posición del pivote
}

template <typename T>
void QuickSort(T arr[], size_t low, size_t high) {
    if (low < high) {
        auto pi = partition(arr, low, high);
        QuickSort(arr, low, pi -1);
        QuickSort(arr, pi + 1, high);
    }
}

template <typename T>
void Print(ostream &os, T arr[], size_t size) {
    for (auto i = 0; i < size; i++) {
        os << arr[i] << " ";
    }
    os << endl;
}

void SortDemo();

#endif  // __QUICK_SORT_H__