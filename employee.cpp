#include <iostream>
#include "employee.h"

void Employee::SetSalary(double _salary){
    m_salary = _salary;
}

void ClassDemo(){
    X     s1;
    s1.var1 = 20;

    Employee a1;
    a1.SetSalary(20);
    auto sal = a1.GetSalary();
    cout << a1 << endl;
}