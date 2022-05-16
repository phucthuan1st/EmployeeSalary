#include "Employee.h"

int main()
{
    Employee *employee1 = Employee::createEmployee(EmployeeType::ProductEmployee, 50, 10);
    Employee *employee2 = Employee::createEmployee(EmployeeType::DailyEmployee, 40, 15);
    Employee *employee3 = Employee::createEmployee(EmployeeType::HourlyEmployee, 60, 25);
    Employee *employee4 = Employee::createEmployee(EmployeeType::Manager, 3, 100);

    cout << employee1->salary() << endl;
    cout << employee2->salary() << endl;
    cout << employee3->salary() << endl;
    cout << employee4->salary() << endl;

    delete employee4;
    delete employee3;
    delete employee2;
    delete employee1;
    return 0;
}