
#include <fstream>
#include "struct.h"
using namespace std;

ostream &operator<<(ostream &os, ALU &alu){
    os << "id:" << alu.id << " name:" << alu.name << " ***" << endl;
    return os;
}

// ostream &PrintAlu(ostream &os, ALU &alu){
//     os << "id:" << alu.id << " name:" << alu.name << endl;
//     return os;
// }

// ostream &PrintAlu(ostream &os, ALU *pAlu){
//     return PrintAlu(os, *pAlu);
// }


void DemoStruct(){
    ALU a1, *pAlu1 = nullptr, 
            *pAlu2 = nullptr,
            *pAlu3 = nullptr,
        va[10], *pVa = nullptr;

    a1.id = 25;
    a1.name = "Antonio";
    // PrintAlu(cout, a1);
    cout << a1 << "hola de prueba despues de Antonio";
    cout << "Después de imprimir a1\n";

    pAlu1 = &a1;
    pAlu1->id = 20;
    pAlu1->name = "Jose";
    // PrintAlu(cout, pAlu1);
    cout << *pAlu1;
    cout << "Hola " << *pAlu1 << " Texto final" << endl;

    pAlu2 = new ALU;
    pAlu2->id   = 50;
    pAlu2->name = "Maria";
    // PrintAlu(cout, pAlu2);
    cout << *pAlu2;
    delete  pAlu2;

    const size_t N = 3;
    pAlu3 = new ALU[N];
    pAlu3[0].id = 40;
    pAlu3[1].id = 42;
    pAlu3[2].id = 43;
    
    pAlu3[0].name = "Enrique";
    pAlu3[1].name = "Juan";
    pAlu3[2].name = "Patricia";
    
    for(auto i = 0 ; i < N ; ++i )
        // PrintAlu(cout, pAlu3[i]);
        cout << pAlu3[i];

    ofstream archivo("Alumnos.txt");
    for(auto i = 0 ; i < N ; ++i )
        // PrintAlu(archivo, pAlu3[i]);
        archivo << pAlu3[i];

    delete [] pAlu3;
}