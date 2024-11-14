#include <iostream>
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string_view>

#include "sorting.h"
using namespace std;
// int z = 8;
void printX(int vect[], int n){
    for (int i = 0 ; i < n ; ++i)
        cout << vect[i] << ' ';
    // v[3] = 8;
    // z = 9;
}

void AdvancedSorting(){
    cout << "Advanced Sorting Demo\n";
    int v[5] = {4, 2, 8, 1, 6};
    sort(v, v+5);
    printX(v, 5);
    cout << "*****************\n";

    array<float, 10> sf{5.3f, 7.2f, 4.8f, 2.1f, 8.7f, 6.2f, 1.5f, 9.9f, 0.7f, 3.14f};
    array<int  , 10>  s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    
    auto printY = [&s](string_view const rem)
    {
        for (auto a : s)
            cout << a << ' ';
        cout << ": " << rem << '\n';
    };
 
    sort(s.begin(), s.end());
    printY("sorted with the default operator<");
 
    greater<int> CompMayor;
    sort(s.begin(), s.end(), CompMayor);
    printY("sorted with the standard library compare function object");
 
    struct
    {
        bool operator()(int a, int b) const { return a < b; }
    }
    customLess;

    sort(s.begin(), s.end(), customLess);
    printY("sorted with a custom function object");
 
    sort(s.begin(), s.end(), [](int a, int b)
                                  {
                                      return a > b;
                                  });
    printY("sorted with a lambda expression");
}

void Sorting(){
    AdvancedSorting();
}


