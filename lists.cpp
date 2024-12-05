#include <iostream>
#include "linkedlist.h"
#include "foreach.h"

using namespace std;

const int nElem = 10;

template <typename T>
void print(T &x)
{  cout << x << "  "; }

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
    
    foreach(mylist, [&x](TX &n){ n += x; x++; });
    foreach(mylist, ::print<TX>); cout << endl;
    ClassX<TX> ope(5);
    foreach(mylist, ope);
    foreach(mylist, ::print<TX>); cout << endl;
    foreach(mylist, ClassX<TX>(8) );
    foreach(mylist, ::print<TX>); cout << endl;
    
    foreach(mylist, ::print<T>);  cout << endl;
}

void DemoLinkedListSorted(){
    cout << "Ascending list" << endl;
    LinkedList< LLTraitAsc<TX> > mylist;
    DemoLinkedList(mylist);
    foreach(mylist, ::print<TX>); cout << endl;

    cout << "Descending list" << endl;
    LinkedList< LLTraitDesc<TX> > myDescList;
    demoLinkedList(myDescList);
    foreach(myDescList, ::print<TX>); cout << endl;
}

template <typename Container>
void demoDoubleLinkedList(Container &mylist)
{
    cout << "Inserting:       ";
    for(auto x=0; x<nElem; x++)
    {   
       cout << vect[x] << ", "; 
       mylist.insert(vect[x]);
       mylist.push_back(vect[x]);
    }
     cout << endl;
     cout << "Lista en orden : ";
     using T = typename Container::value_type;
     foreach(mylist, fx<T>);  cout << endl;
    
     cout << "Lista invertida: ";
     foreach_inverso(mylist, fx<T>);  cout << endl;
     }

void demoDoubleLinkedListSorted()
{
     cout << "Ascending double list" << endl;
     DoubleLinkedList< DLLAscTraits<TX> > mylist;
     demoDoubleLinkedList(mylist);

     cout << "Descending double list" << endl;
     DoubleLinkedList< DLLDescTraits<TX> > myDescList;
     demoDoubleLinkedList(myDescList); 
    }
