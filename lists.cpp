#include <iostream>
#include "linkedlist.h"
#include "foreach.h"

const int nElem = 10;

template <typename T>
void print(T &x)
{  cout << x << "  "; }

// Object function
template <typename T>
class ClassX
{          int m_inc = 0;
    public:  ClassX(int n) : m_inc(n){}
    void operator()(T &n){  n += m_inc;     }
};

template <typename T>
void fx(T &n) {    n++;    }

template <typename Container>
void DemoLinkedList(Container &mylist){
    using T = typename Container::value_type;

    for(T x=0; x<nElem; x++)
       mylist.insert(x);
    // TODO: liberar os siguientes comentarios y hacerlos correr
    // Lambda function
    // foreach(myAscList, [x](TX &n){ n += x; x++; });
    // foreach(myAscList, ::print<TX>); cout << endl;
    // ClassX<TX> ope(5);
    // foreach(myAscList, ope);
    // foreach(myAscList, ::print<TX>); cout << endl;
    // foreach(myAscList, ClassX<TX>(8) );
    // foreach(myAscList, ::print<TX>); cout << endl;
    
    foreach(mylist, ::print<T>);  cout << endl;
}

void DemoLinkedListSorted(){
    cout << "Ascending list" << endl;
    LinkedList< LLTraitAsc<TX> > myAscList;
    DemoLinkedList(myAscList);
    // foreach(myAscList);

    // cout << "Descending list" << endl;
    // LinkedList< LLTraitDesc<TX> > myDescList;
    // demoLinkedList(myDescList);
    // foreach(myDescList);
}

// template <typename Container>
// void demoDoubleLinkedList(Container &mylist)
// {
//     cout << "Inserting:       ";
//     for(auto x=0; x<nElem; x++)
//     {   
//       cout << vect[x] << ", "; 
//       mylist.insert(vect[x]);
//       //mylist.push_back(vect[x]);
//     }
//     cout << endl;
//     cout << "Lista en orden : ";
//     using T = typename Container::value_type;
//     foreach(mylist, fx<T>);  cout << endl;
    
//     cout << "Lista invertida: ";
//     foreach_inverso(mylist, fx<T>);  cout << endl;
// }

// void demoDoubleLinkedListSorted()
// {
//     cout << "Ascending double list" << endl;
//     DoubleLinkedList< DLLAscTraits<TX> > myAscList;
//     demoDoubleLinkedList(myAscList);

//     cout << "Descending double list" << endl;
//     DoubleLinkedList< DLLDescTraits<TX> > myDescList;
//     demoDoubleLinkedList(myDescList); 
// }