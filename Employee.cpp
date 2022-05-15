#include "Employee.h"

Employee *Employee::createEmployee(string employeeType)
{
    if (employeeType == EmployeeType::HourlyEmployee)
    {
        return new HourlyEmployee();
    }
    else if (employeeType == EmployeeType::DailyEmployee)
    {
        return new DailyEmployee();
    }
    else if (employeeType == EmployeeType::ProductEmployee)
    {
        return new ProductEmployee();
    }
    else if (employeeType == EmployeeType::Manager)
    {
        return new Manager();
    }
}