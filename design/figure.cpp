#include <iostream>
#include "figure.h"

using namespace std;

Figure::Figure(string _name)
      : m_name(_name)
{
    cout << "Figure: " << GetName() << " Construido ..." << endl;
}

Figure::~Figure(){
    SetName(m_name+" Destruido ...");
    cout << "Figure: " << GetName() << " Destruido ..." << endl;
}

void Figure::draw()
{
    cout << "Figure draw" << endl;
}

void Figure::SetName(string _name){
    m_name = _name;
}

string Figure::GetName(){
    return m_name;
}