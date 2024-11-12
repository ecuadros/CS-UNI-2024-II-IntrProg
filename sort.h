#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__
#include <iostream>
#include <algorithm> 
using namespace std;

template <typename T>
int partition(T arr[], int low, int high, bool (*compare)(T, T, bool), bool ascending) {
    T pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && compare(arr[i], pivot, ascending)) i++;
        while (i <= j && !compare(arr[j], pivot, ascending)) j--;
        if (i > j) break;
        swap(arr[i], arr[j]);
        i++; j--;
    }
    swap(arr[low], arr[j]);
    return j;
}

template <typename T>
void QuickSort(T arr[], int low, int high, bool (*compare)(T, T, bool), bool ascending = true) {
    if (low < high) {
        int pi = partition(arr, low, high, compare, ascending);
        QuickSort(arr, low, pi - 1, compare, ascending);
        QuickSort(arr, pi + 1, high, compare, ascending);
    }
}

template <typename T>
void Print(ostream &os, T arr[], int size) {
    for (int i = 0; i < size; i++) {
        os << arr[i] << " ";
    }
    os << endl;
}

template <typename T>
bool compare(T a, T b, bool ascending) {
    return ascending ? a < b : a > b;
}

void SortDemo();

#endif
