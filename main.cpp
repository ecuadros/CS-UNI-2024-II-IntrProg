#include "rectangle.h"
#include "circle.h"
#include "point.h"
#include <iostream>
using namespace std;

void fx(Figure *p){
  p->draw();
}
void fy(Figure &rObj){
  rObj.draw();
}

int main(){
  Figure *pf[3]={new Rectangle, new Circle, new Point};
  cout<<"Llamadas directas a draw(): " <<endl;
    for(auto i=0; i<3; i++){
        pf[i]->draw();
    }
    cout<<"\nLlamadas a través de fx(): "<<endl;
    for(auto i=0; i<3; i++){
        fx(pf[i]);
    }
    cout<<"\nLlamadas a través de fy(): "<<endl;
    for (auto i=0; i<3; i++){
        fy(*pf[i]);
    }
    for (auto i=0; i<3; i++){
        delete pf[i];
    }
    return 0;
}
