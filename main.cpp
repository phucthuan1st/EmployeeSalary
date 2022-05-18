#include "Employee.h"

int main()
{
    Employee *employee1 = EmployeeFactory::createEmployee(EmployeeType::ProductEmployee, "David Louis", 50, 10);
    Employee *employee2 = EmployeeFactory::createEmployee(EmployeeType::DailyEmployee, "John Smith", 40, 15);
    Employee *employee3 = EmployeeFactory::createEmployee(EmployeeType::HourlyEmployee, "Jenny Oliver", 60, 25);
    Employee *employee4 = EmployeeFactory::createEmployee(EmployeeType::Manager, "Racoon Barterson", 3, 100);

    cout << employee1->info() << endl;
    cout << employee2->info() << endl;
    cout << employee3->info() << endl;
    cout << employee4->info() << endl;

    delete employee4;
    delete employee3;
    delete employee2;
    delete employee1;
    return 0;
}