#include <iostream>
#include "employee.h"

Employee::Employee(string name, TSal salary)
        : m_name(name), m_salary(salary), m_test(30)
{
    m_test = 20;
    cout << "Construyendo " << m_name << " salario: " << m_salary << endl;
}
//Constructor de copia corregido
Employee::Employee(Employee &other)
        : m_name(other.GetName()), m_salary(other.GetSalary())  // Cambio: uso directo de los getters
{
    cout << "Copia de " << other.GetName() << endl;
}

// Destructor
Employee::~Employee(){
    cout << "Destruyendo: " << GetName() << " salario: " << GetSalary() << endl;
}

void Employee::SetSalary(double _salary){
    m_salary = _salary;
}

ostream &operator<<(ostream &os, Employee &e){
    os << "Name: " << e.GetName() << " Salario: " << e.GetSalary();
    return os;
}

void ClassDemo(){
    X     s1;
    s1.var1 = 20;

    Employee a1;
    a1.SetSalary(20);
    auto sal = a1.GetSalary();

    Employee a2("Brad", 1000),
             a3(a2);
    a3.SetSalary(1500);
    cout << "------------------------\n";
    Employee *pEmp = new Employee("Caleb", 700);

    cout << a1 << endl
         << a2 << endl
         << a3 << endl;
    cout << "========================\n";
    delete pEmp;
    pEmp = nullptr;
} // a1, a2, a3 estan saliendo de las {} donde fueron creados
