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

Employee *Employee::createEmployee(string employeeType, int unit, int pay_per_unit)
{
    if (employeeType == EmployeeType::HourlyEmployee)
    {
        return new HourlyEmployee(unit, pay_per_unit);
    }
    else if (employeeType == EmployeeType::DailyEmployee)
    {
        return new DailyEmployee(unit, pay_per_unit);
    }
    else if (employeeType == EmployeeType::ProductEmployee)
    {
        return new ProductEmployee(unit, pay_per_unit);
    }
    else if (employeeType == EmployeeType::Manager)
    {
        return new Manager(unit, pay_per_unit);
    }
}