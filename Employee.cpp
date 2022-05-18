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

Employee *EmployeeFactory::createEmployee(string employeeType, string name, int unit, int pay_per_unit)
{
    if (employeeType == EmployeeType::HourlyEmployee)
    {
        return new HourlyEmployee(name, unit, pay_per_unit);
    }
    else if (employeeType == EmployeeType::DailyEmployee)
    {
        return new DailyEmployee(name, unit, pay_per_unit);
    }
    else if (employeeType == EmployeeType::ProductEmployee)
    {
        return new ProductEmployee(name, unit, pay_per_unit);
    }
    else if (employeeType == EmployeeType::Manager)
    {
        return new Manager(name, unit, pay_per_unit);
    }
}
