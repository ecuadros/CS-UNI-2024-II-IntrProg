#include<iostream>
#include<cstdlib>
#include"sort2.h"

using namespace std;

int main(){

    const int n = 10;
    float *v;

    v = new float[n];
    
    entradaDATOS(v, n);

    //qs(v, 0, n-1, ascendente<int>); //INSTANCIAMOS EL COMPARADOR
    //mostrarvectorconsola(v, n);
    //qs(v, 0, n-1, descendente<int>);
    //mostrarvectorconsola(v, n);

    qs(v, 0, n-1, ascendente<float>); //si queremos ordenar floats ascendentemente
    mostrarvectorconsola(v, n);
    qs(v, 0, n-1, descendente<float>); //si queremos ordenar floats descedentemente
    mostrarvectorconsola(v, n);

    //qs(v, 0, n-1, ascendente<double>); //si queremos ordenar doubles ascendentemente
    //mostrarvectorconsola(v, n);
    //qs(v, 0, n-1, descendente<double>); //si queremos ordenar doubles descedentemente
    //mostrarvectorconsola(v, n);




    //--------------------------------------------------------------------------------
    //qs(v, 0 ,n-1, ascendente); //Si introduzco esto (para arreglos de cualquier tipo), pide que instancie cada template
    //mostrarvectorconsola(v, n);
    //--------------------------------------------------------------------------------




    //FORMA ALTERNATIVA:

    //qs<int, decltype(ascendente<int>)>(v, 0, n-1, ascendente<int>); //gemini nos recomienda "instanciar" EXPLÍCITAMENTE al comparador para evitar ambiguedades
    //mostrarvectorconsola(v, n);
    //qs<int, decltype(descendente<int>)>(v, 0, n-1, descendente<int>);
    //mostrarvectorconsola(v, n);

    //qs<float, decltype(ascendente<float>)>(v, 0, n-1, ascendente<float>); //si queremos ordenar floats ascendentemente
    //mostrarvectorconsola(v, n);
    //qs<float, decltype(descendente<float>)>(v, 0, n-1, descendente<float>); //si queremos ordenar floats descedentemente
    //mostrarvectorconsola(v, n);

    //qs<double, decltype(ascendente<double>)>(v, 0, n-1, ascendente<double>); //si queremos ordenar doubles ascendentemente
    //mostrarvectorconsola(v, n);
    //qs<double, decltype(descendente<double>)>(v, 0, n-1, descendente<double>); //si queremos ordenar doubles descedentemente
    //mostrarvectorconsola(v, n);
    delete[] v;
    return 0;
}