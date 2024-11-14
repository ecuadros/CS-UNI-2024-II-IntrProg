#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include <iostream>
#include <string>
using namespace std;

struct X{ 
    int var1;   // public by default
private:
    int y;
};

using TSal = double;
class Employee{
    int var1;   // private by default
                // variable is now an "Attribute"
private:
    TSal m_salary;
public:
    // Functions are now called "Methods"
    TSal GetSalary() {    return m_salary;  }
    void SetSalary(TSal _salary);
public:
    float more;
};

ostream &operator<<(ostream &os, Employee &e);

void ClassDemo();

#endif // __EMPLOYEE_H__