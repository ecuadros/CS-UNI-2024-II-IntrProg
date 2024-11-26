#include <iostream>
#include "figure.h"

using namespace std;

Figure::Figure(const string &_name)
{
    m_name = _name;
    cout << "Figure: " << GetName() << " Construido ..." << endl;
}

Figure::~Figure(){
    SetName(m_name+" Destruido ...");
    cout << "Figure: " << GetName() << " Destruido ..." << endl;
}

void Figure::SetName(const string _name){
    m_name = _name;
}

string Figure::GetName() const{
    return m_name;
}

void Figure::draw(){
    cout << "Figure::draw() llamado ok\n";
}