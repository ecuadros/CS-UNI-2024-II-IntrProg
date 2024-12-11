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
{          
    int m_inc = 0;
    public:  
        ClassX(int n) : m_inc(n){}
        void operator()(T &n){  n += m_inc; }
};

template <typename T>
void fx(T &n) {    n++;    }

template <typename Container>
void DemoLinkedList(Container &mylist){
    using T = typename Container::value_type;

    for(T x=0; x<nElem; x++)
       mylist.insert(x);
    // Lambda function
    foreach(mylist, [x](T &n){ n += x; x++; });
    foreach(mylist, ::print<T>); cout << endl;
    
    ClassX<T> ope(5);
    foreach(mylist, ope);
    foreach(mylist, ::print<T>); cout << endl;

    foreach(mylist, ClassX<T>(8) );
    foreach(mylist, ::print<T>); cout << endl;
    
    foreach(mylist, ::print<T>);  cout << endl;
}

void DemoLinkedListSorted(){
    cout << "Ascending list" << endl;
    LinkedList< LLTraitAsc<int> > myAscList;
    DemoLinkedList(myAscList);
    foreach(myAscList, ::print<int>); cout << endl;

    cout << "Descending list" << endl;
    LinkedList< LLTraitDesc<int> > myDescList;
    DemoLinkedList(myDescList);
    foreach(myDescList, ::print<int>); cout << endl;
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
//     DoubleLinkedList< DLLAscTraits<int> > myAscList;
//     demoDoubleLinkedList(myAscList);

//     cout << "Descending double list" << endl;
//     DoubleLinkedList< DLLDescTraits<int> > myDescList;
//     demoDoubleLinkedList(myDescList); 
// }
