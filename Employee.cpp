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
    if (employeeType == EmployeeType::DailyEmployee)
    {
        return prototype[0]->clone(name, unit, pay_per_unit);
    }
    else if (employeeType == EmployeeType::HourlyEmployee)
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

vector<Employee *> Parser::parse(string filename)
{
    vector<Employee *> employees = {};

    string type;
    string name;
    int unit = 0;
    int pay_per_unit = 0;

    fstream file(filename, ios::in);

    if (!file.is_open())
    {
        cout << "Read failed: cannot open " + string(filename) << endl;
    }
    else
    {
        string line = "";
        while (getline(file, line))
        {
            vector<string> token = StringUtils::split(line, ": ");
            type = token[0];
            name = token[1];

            getline(file, line);
            token = StringUtils::split(line, "$; ");
            string work = token[0];
            string pay = token[1];
            unit = stoi(StringUtils::split(work, "=")[1]);
            pay_per_unit = stoi(StringUtils::split(pay, "=")[1]);

            employees.push_back(EmployeeFactory::createEmployee(type, name, unit, pay_per_unit));
        }
    }

    file.close();

    return employees;
}
