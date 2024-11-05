#include <iostream>
#include <algorithm>    // std::swap
#include "sort.h"

using namespace std;

// Función para particionar el arreglo
int particionar(int arr[], int bajo, int alto) {
    int pivote = arr[alto]; // Elegimos el último elemento como pivote
    int i = bajo - 1; // Índice del elemento más pequeño

    for (int j = bajo; j < alto; j++) {
        if (arr[j] <= pivote) {
            i++; // Incrementar el índice del elemento más pequeño
            swap(arr[i], arr[j]); // Intercambiar
        }
    }
    swap(arr[i + 1], arr[alto]); // Colocar el pivote en la posición correcta
    return i + 1; // Retornar el índice del pivote
}

// Función recursiva para aplicar QuickSort
void QuickSort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particionar(arr, bajo, alto); // Particionar el arreglo

        // Ordenar recursivamente los elementos antes y después de la partición
        QuickSort(arr, bajo, pi - 1);
        QuickSort(arr, pi + 1, alto);
    }
}

// Función para mostrar el arreglo
void Print(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SortDemo(){
    int v[10] = {5,2,10,70,45, 8, 9, 7, 15, 23};
    QuickSort(v, 0, 9);  //se asigna valor alto al indice del ultimo elemento
    Print(v, 10);
}