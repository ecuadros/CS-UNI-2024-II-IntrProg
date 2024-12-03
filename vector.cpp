#include <iostream>
using namespace std;

void crearVector(int *&p,int n){
    p = new int [n];
}

void ingresaVector(int *p,int n){
    for(auto i=0;i<n;i++){
        cout<<"Ingrese el elemento "<<i<<": ";
        cin>>p[i];
        // cin>>*(p+i);
        // cin>>*(i+p);
        // cin>>i[p];
    }
}

void mostrarVector(int *p, int n){
    for(auto i=0; i<n ; i++){
        cout<<p[i]<<"\n";
    }
}

void borrarVector(int *&p){
    delete [] p;
    p=nullptr;
}

void VectorDemo(){
    int *pV=nullptr;
    int n=5;
    crearVector  (pV, n);
    ingresaVector(pV, n);
    mostrarVector(pV, n);
    borrarVector (pV);
}