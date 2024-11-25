#include <iostream>
#include "figure.h"
#include "circle.h"
#include "point.h"
#include "rectangle.h"

using namespace std;

// g++ -std=c++17 main.cpp figure.cpp rectangle.cpp circle.cpp point.cpp -o main

void fx(Figure *p)
{
    p->draw();
}
void fy(Figure &rObj)
{
    rObj.draw();
}

int main(){
    Figure *pf[3]= {new Rectangle, 
                    new Circle,
                    new Point};
    
    for (auto i = 0; i < 3; i++)
    {
        pf[i]->draw();
    }
    
    /* for (auto i = 0; i < 3; i++)
    {
        fx(pf[i]);
    } */
    
    /* for (auto i = 0; i < 3; i++)
    {
        fy(*pf[i]);
    } */

   for (auto i = 0; i < 3; i++)
   {
        delete pf[i];
   }
   

}