#ifndef __STRUCT_H__
#define __STRUCT_H__
#include <iostream>
#include <string>

// #include <cstddef> // size_t
using namespace std;

struct ALU{
    int id;
    string name;
};

ostream &PrintAlu(ostream &os, ALU &alu);
ostream &PrintAlu(ostream &os, ALU *pAlu);

void DemoStruct();

#endif