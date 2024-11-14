#include "sort.h"

void SortDemo(){
    int v[10] = {5,2,10,70,45, 8, 9, 7, 15, 23};
    bool ascendente = true; //false = descendente
    QuickSort(v, 0, 9, ascendente);
    Print(cout, v, 10);

    float w[10] = {5.3, 2.1, 10.5, 70.4, 45.3, 8.7, 9.2, 1.5, 2.5, 2.3};
    QuickSort(w, 0, 9, ascendente);
    Print(cout, w, 10);
}