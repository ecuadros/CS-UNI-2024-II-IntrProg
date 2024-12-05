#include <iostream>
#include "employee.h"

using namespace std;

void ClassDemo() {
    Employee a1;
    a1.SetSalary(20);

    Employee a2("Brad", 1000), a3(a2);
    a3.SetSalary(1500);

    Employee *pEmp = new Employee("Caleb", 700); //Se utilizó new para inicializar dinámicamente el rreglo de objetos Employee 
    Employee *vEmpl = new Employee[3]{
        {"Cristian", 800},
        {"Ana", 600},
        {"Juan", 950}
    };
    cout << "Employee List:" << endl;

    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;
    cout << pEmp << endl;

    for (int i = 0; i < 3; i++) {
        cout << vEmpl[i] << endl;
    }
    delete pEmp; 
    delete[] vEmpl;
}
