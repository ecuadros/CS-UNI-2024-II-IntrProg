#include "sort.h"
#include "alu.h"

void SortDemo(){
    int v[10] = {5,2,10,70,45, 8, 9, 7, 15, 23};
    QuickSort(v, 0, 9, &men<int>);
    Print(cout, v, 10);
    QuickSort(v, 0, 9, &may<int>);
    Print(cout, v, 10);

    float w[10] = {5.3, 2.1, 10.5, 70.4, 45.3, 8.7, 9.2, 1.5, 2.5, 2.3};
    QuickSort(w, 0, 9, &may<float>);
    Print(cout, w, 10);

    string names[] = {"Anthony", "Caleb", "Raymound", "Elmer", "Brad",
                      "Miguel", "Christian", "Gabriel", "Ernesto", "Ana"};
    QuickSort(names, 0, 9, 
              [](const string &a, const string &b){ return a < b; });
    Print(cout, names, 10);
    QuickSort(names, 0, 9, 
              [](const string &a, const string &b){ return a > b; });
    Print(cout, names, 10);

    Alu vAlu[] = {  {"Anthony", 13, 7},  {"Caleb", 4, 1}, 
                    {"Raymound", 21, 7}, {"Elmer", 24, 12}, 
                    {"Brad", 23, 12},    {"Miguel", 15, 4}, 
                    {"Christian", 18, 4},{"Gabriel", 11, 8}, 
                    {"Ernesto", 22, 2},  {"Ana", 19, 2} 
                 };
    cout << "Antes: " << vAlu[0] << " ... Despues\n\n";

    cout << "Descending Sort by Name:" << endl;
    QuickSort(vAlu, 0, 9, &CompAluByNameDesc);
    Print(cout, vAlu, 10, "\n");
    cout << "*******************************\n";

    cout << "Descending Sort by day:" << endl;
    QuickSort(vAlu, 0, 9, [](Alu &a, Alu &b){ return a.dd < b.dd;});
    Print(cout, vAlu, 10, "\n");
    cout << "*******************************\n";

    cout << "Ascending Sort by mm/dd:" << endl;
    QuickSort(vAlu, 0, 9, [](Alu &a, Alu &b){if(a.mm==b.mm) {return a.dd > b.dd; } return a.mm > b.mm; });
    Print(cout, vAlu, 10, "\n");
    cout << "*******************************\n";
}
