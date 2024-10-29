## Principales algoritmos

### 1. Buble Sort:

```cpp
void buble_sort(int array[], int n) {
    //Iteramos sobre todo el arreglo
    for (int i = 0; i < n - 1; i++) {
        //En cada paso los elementos mayores burbujean hacia el final
        for (int j = 0; j < n - i -1; j++) {
            // Si el elemento actual es mayor que el siguiente, intercambiamos
            if (array[j] > array[j + 1]) {
                int temporal = array[j];
                array[j] = array[j+1];
                array[j+1] = temporal;
            }
        }
    }
}
```

### 2. Binary Search:

```cpp
int binary_search(int array[], int n, int a) {
    int left = 0;
    int right = n - 1;

    // Mientras la sección donde estamos buscando no se haya reducido a 0,
    // podemos seguir buscando
    while (left <= right) {
        int middle = ( left + right ) / 2;
        // Si el valor está en la mitad, lo hemos encontrado
        if (array[middle] == a) {
            return middle;
        }

        // Si el valor es mayor que array[middle], buscamos en la mitad derecha
        if (array[middle] < a) {
            left = middle + 1;
        }

        // Si el valor es menor que array[middle], buscamos en la mitad izquierda
        else {
            right = middle - 1;
        }
    }

    // Si no encontramos el valor, devolvemos -1
    return -1;
}
```

### 3. Selection Sort:

```cpp
void selection_sort(int array[], int n) {
    // Iteramos sobre todo el arreglo
    for (int i = 0; i < n - 1; i++) {
        //  Tomamos como supuesto que el mínimo es array[i]
        int indice_minimo = i;

        //  Encontramos el mínimo en todo el arreglo mediante comparaciones
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[indice_minimo]) {
                indice_minimo = j;
            }
        }
        
        //  Intercambiar el elemento mínimo con el primer elemento no ordenado
        int temporal = array[indice_minimo];
        array[indice_minimo] = array[i];
        array[i] = temporal;
    }
}
```

### 4. Insertion Sort:

```cpp
void insertion_sort(int array[], int n) {
    //  Recorremos todo el array
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;

        //  Se moveran los elementos que son mayores a la key, una posición adelante
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        //  Se coloca la key en la posición correcta
        array[j + 1] = key;
    }        
}
```

### 5. Merge Sort:
```cpp
#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Function to print a vector
void printVector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Given vector is \n";
    printVector(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    printVector(arr);
    return 0;
}
```

### 6. Quick Sort:
```cpp
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
  
    // Choose the pivot
    int pivot = arr[high];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[;ow..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}