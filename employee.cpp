#include <iostream>
#include <memory>
#include "employee.h"

Employee::Employee(string name, TSal salary)
        : m_name(name), m_salary(salary), m_test(30)
{
    m_test = 20;
    cout << "Construyendo " << m_name << " salario: " << m_salary << endl;
}

Employee::Employee(Employee &other)
        : Employee(other.GetName(), other.GetSalary())
{
}

// Employee::Employee(Employee &other){
//     m_name   = other.GetName();
//     m_salary = other.GetSalary();
// }

Employee::~Employee(){
    cout << "Destruyendo: " << GetName() << " salario: " << GetSalary() << endl;
}

void Employee::SetSalary(double _salary){
    m_salary = _salary;
}

ostream &operator<<(ostream &os, Employee &e){
    os << "NameY: " << e.GetName() << " SalarioY: " << e.GetSalary();
    return os;
}

ostream &operator<<(ostream &os, Employee *pE){
    return os << *pE;
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
    Employee* pEmp  = new Employee("Caleb", 700);
    Employee *vEmpl = new Employee[3]{
            Employee("Raul", 980),
            Employee("Pepe", 1111),
            Employee("Luis", 1600)
    };  
     {
        // https://en.cppreference.com/w/cpp/memory/unique_ptr
        unique_ptr<Employee> obj1(new Employee("Ernesto", 900));
        obj1->SetSalary(950);
        obj1->SetName("Julio Ernesto");
        // No me deja sacarle copias
        // unique_ptr<Employee> copia = obj1;
    }
    unique_ptr<Employee> obj2(new Employee("Juan Pablo", 800));
    obj2->SetSalary(990);
    Employee *jp = obj2.release(); // Retorna el puntero y obj2 ya no lo administra.
                                   // osea, apunta a nullptr
    delete jp;

    Employee* pTmp = pEmp;     // 2 referencias para este puntero
    Employee* vEmpl = new Employee[3]{
            {"Cristian", 700},  // Para el 1er objeto
            {"Ana", 600},       // Para el 2do objeto
            {"Juan", 800}       // Para el 3er objeto
    };
    
    for(auto i = 0 ; i < 3 ; ++i)
        cout << vEmpl[i] << endl;
    delete [] vEmpl;

    cout << a1 << endl
         << a2 << endl
         << a3 << endl
         << pEmp << endl;
    cout << "========================\n";
<<<<<<< HEAD
    delete pEmp;  // Caleb
=======
    delete pEmp;
    delete[] vEmpl;
    delete[] vEmpl;
    pEmp = nullptr;
>>>>>>> 08a2f8edc8fc396dfb3e3ab403a2af15e5f7ff49
    pEmp = nullptr;


} // a1, a2, a3 estan saliendo de las {} donde fueron creados
