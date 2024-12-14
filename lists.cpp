#include <iostream>
#include "linkedlist.h"
#include "foreach.h"

const int nElem = 10;

template <typename T>
void print(T &x)
{  
    std::cout << x << "  "; 
}

// Object function
template <typename T>
class ClassX
{          
    int m_inc = 0;
public:  
    ClassX(int n) : m_inc(n) {}
    void operator()(T &n) {  n += m_inc; }
};

template <typename T>
void fx(T &n) {    
    n++;    
}

template <typename Container>
void DemoLinkedList(Container &mylist){
    using T = typename Container::value_type;

    for(T x = 0; x < nElem; x++)
       mylist.insert(x);

    // Lambda function
    foreach(mylist, [x](T &n) mutable { n += x; x++; }); // Capturing x by value and mutably
    foreach(mylist, ::print<T>); 
    std::cout << std::endl;

    // Object function
    ClassX<T> ope(5);
    foreach(mylist, ope);
    foreach(mylist, ::print<T>);
    std::cout << std::endl;

    // Using the object function with a different increment
    foreach(mylist, ClassX<T>(8));
    foreach(mylist, ::print<T>);
    std::cout << std::endl;
}

void DemoLinkedListSorted(){
    std::cout << "Ascending list" << std::endl;
    LinkedList< LLTraitAsc<int> > myAscList; // Change `TX` to `int` or your container type
    DemoLinkedList(myAscList);

    // Uncomment and use for descending list
    std::cout << "Descending list" << std::endl;
    LinkedList< LLTraitDesc<int> > myDescList;
    DemoLinkedList(myDescList);
}

// template <typename Container>
// void demoDoubleLinkedList(Container &mylist)
// {
//     std::cout << "Inserting:       ";
//     for(auto x=0; x<nElem; x++)
//     {   
//       std::cout << vect[x] << ", "; 
//       mylist.insert(vect[x]);
//       //mylist.push_back(vect[x]);
//     }
//     std::cout << std::endl;
//     std::cout << "Lista en orden : ";
//     using T = typename Container::value_type;
//     foreach(mylist, fx<T>);  std::cout << std::endl;
    
//     std::cout << "Lista invertida: ";
//     foreach_inverso(mylist, fx<T>);  std::cout << std::endl;
// }

// void demoDoubleLinkedListSorted()
// {
//     std::cout << "Ascending double list" << std::endl;
//     DoubleLinkedList< DLLAscTraits<int> > myAscList;
//     demoDoubleLinkedList(myAscList);

//     std::cout << "Descending double list" << std::endl;
//     DoubleLinkedList< DLLDescTraits<int> > myDescList;
//     demoDoubleLinkedList(myDescList); 
// }
