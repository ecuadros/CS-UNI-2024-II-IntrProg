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
               // private by default
private:
    string m_name;   // Name    // variable is now an "Attribute"
    TSal   m_salary; // Salary
    float  m_test;
public:
    Employee(string name = "SinNombre", TSal salary = 0);
    Employee( Employee &other );
                        // 1. Mismo nombre de la clase
                        // 2. No tiene tipo de devolucion.
                        // 3. Puede haber mas de uno (distintos parametros)
                        // 4a. Se llama al declarar el objeto o
                        //     Se llama al crear con new un objeto
                        // 5. Se llama solo 1 de los constructores
                        // 6. Se pueden llamar entre constructores (C++11)
    
    virtual ~Employee();// 1. Mismo nombre de la clase pero con ~
                        // 2. No tiene tipo de devolucion.
                        // 3. Solo puede haber uno
                        // 4a. Se llama cuando el objeto sale de las {} done fue declarado
                        // 4b. Se llama cuando lo borras con delete (obj dinamico)
                        // 5. Recomendable que sea siempre virtual
    // Set & Get for m_name
    string GetName()   {    return m_name;  }
    void   SetName(string name){ m_name = name;    }
    
    // Set & Get for m_salary
    TSal GetSalary() {    return m_salary;  }
    void SetSalary(TSal _salary);
};

ostream &operator<<(ostream &os, Employee &e);
ostream &operator<<(ostream &os, Employee *pE);

void delArrEmp(Employee *);

void ClassDemo();

#endif // __EMPLOYEE_H__