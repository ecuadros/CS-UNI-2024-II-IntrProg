#ifndef __ALU_H__
#define __ALU_H__
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Alu
{   string  name;
    int     dd;
    int     mm;
};

auto CompAluByNameDesc(Alu &a, Alu &b)
{   return a.name < b.name;     }

auto CompAluByNameAsc(Alu &a, Alu &b)
{   return a.name > b.name;     }

ostream &operator<<(ostream &os, Alu &a)
{   os << "Name: " << setw(10) << left  << a.name 
       << " mm: "  << setw(2)  << right << a.mm
       << " dd: "  << setw(2)  << right << a.dd;
    return os;   
}

struct MyComp
{
    auto operator()(Alu &a, Alu &b) {
        return a.mm < b.mm || (a.mm == b.mm && a.dd < b.dd);
    }
};

#endif