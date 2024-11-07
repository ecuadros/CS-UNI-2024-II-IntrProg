#ifndef __SORT2_H__
#define __SORT2_H__
#include <iostream>
#include <algorithm>    // std::swap
using namespace std;

template<typename T>
void entradaDATOS(T v[], size_t n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"\nElemento "<<i+1<<": ";
        cin>>v[i];
    }
}

template <typename T, typename S>
void qs(T v[], int inicio, int fin, S &cmp)
{
    T piv;
    int izq, der, mitad;

    izq = inicio;
    der = fin;
    mitad = (izq+der)/2;
    piv = v[mitad];

    do
    {
        while ( (cmp(v[izq], piv)) && (izq < fin) )
        {
            izq++;
        }

        while ( !(cmp(v[der],piv)) && v[der]!=piv && (der > inicio) )
        {
            der--;
        }

        if (izq <= der)
        {
            swap(v[izq],v[der]);
            izq++;
            der--;
        }
        
    } while (izq < der);
    
    if (izq < fin)
    {
        qs(v, inicio, izq, cmp);
    }
    if (der > inicio)
    {
        qs(v, der, fin, cmp);
    }

}

template<typename T>
void mostrarvectorconsola(T v[], size_t n)
{
    cout<<"\n{";
    for (int i = 0; i < n; i++)
    {
        if (i == n-1)
        {
            cout<<v[i]<<"}"<<endl;
        }else{
            cout<<v[i]<<" ";
        }   
    }
}

template <typename T>
bool ascendente(const T& a, const T& b) {
    return a < b;
}
template <typename T>
bool descendente(const T& a, const T& b) {
    return a > b;
}

#endif //__SORT2_H__