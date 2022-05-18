#include "Employee.h"

vector<string> StringUtils::split(const string &source, string delim)
{
    int start = 0;
    int end = source.find(delim);

    vector<string> result;

    string token;

    while (end != string::npos)
    {
        token = source.substr(start, end);
        result.push_back(token);
        start = end + delim.length();
        end = source.find(delim, start);
    }

    token = source.substr(start, end);
    result.push_back(token);

    return result;
}

vector<Employee *> EmployeeFactory::prototype{new DailyEmployee, new HourlyEmployee, new ProductEmployee, new Manager};

Employee *EmployeeFactory::createEmployee(string employeeType, string name, int unit, int pay_per_unit)
{
    if (employeeType == EmployeeType::HourlyEmployee)
    {
        return prototype[0]->clone(name, unit, pay_per_unit);
    }
    else if (employeeType == EmployeeType::DailyEmployee)
    {
        return prototype[1]->clone(name, unit, pay_per_unit);
    }
    else if (employeeType == EmployeeType::ProductEmployee)
    {
        return prototype[2]->clone(name, unit, pay_per_unit);
    }
    else if (employeeType == EmployeeType::Manager)
    {
        return prototype[3]->clone(name, unit, pay_per_unit);
    }

    return new DailyEmployee(name, unit, pay_per_unit);
}