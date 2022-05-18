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

Employee* EmployeeFactory::createEmployee(string employeeType, int unit, int pay_per_unit)
{
    if (employeeType == HourlyEmployeeStr)
    {
        return new HourlyEmployee(unit, pay_per_unit);
    }
    else if (employeeType == DailyEmployeeStr)
    {
        return new DailyEmployee(unit, pay_per_unit);
    }
    else if (employeeType == ProductEmployeeStr)
    {
        return new ProductEmployee(unit, pay_per_unit);
    }
    else if (employeeType == ManagerStr)
    {
        return new Manager(unit, pay_per_unit);
    }
}

// mock up data method implementation
vector<Employee*> MockEmployeeData::parse(string filename)
{
    int type = 0;
    vector<Employee*> employees = {};
    string unit = "";
    string pay_per_unit = "";
    fstream file(filename, ios::in);

    if (!file.is_open())
    {
        cout << "Read failed: cannot open " + string(filename) << endl;
    }
    else
    {
        string temp_str = "";
        while (getline(file, temp_str))
        {

            vector<string> token = StringUtils::split(temp_str, ": ");
            temp_str = "";

            // get Employee Type
            string employeeType = token[0];

            // get Name
            string name = token[1];

            
            getline(file, temp_str);
            token = StringUtils::split(temp_str, "$; ");
            temp_str = "";

            if (token.size() == 3) {
                // get Pay Per Unit
                vector<string>token1 = StringUtils::split(token[2], "=");
                pay_per_unit = token1[1];

                // get Unit
                token1 = StringUtils::split(token[1], "=");
                unit = token1[1];
            }
            else {
                // get Pay Per Unit
                vector<string>token1 = StringUtils::split(token[0], "=");
                pay_per_unit = token1[1];

                // get Unit
                token1 = StringUtils::split(token[1], "=");
                unit = token1[1];
            }
            

            Employee* employee = EmployeeFactory::createEmployee(employeeType, stoi(unit), stoi(pay_per_unit));
            employee->setName(name);
            employees.push_back(employee);
        }
    }

    file.close();

    return employees;
}