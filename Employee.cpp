#include "Employee.h"
#include <string>

vector<string> StringUtils::split(string source, string delimiter)
{
    vector<string> result;
    int start = 0;
    int end = source.find(delimiter);

    while (end != string::npos)
    {
        string token = source.substr(start, end - start);
        result.push_back(token);
        start = end + delimiter.length();
        end = source.find(delimiter, start);
    }

    result.push_back(source.substr(start, end - start));

    return result;
}

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

// mock up data method implementation
vector<Employee*> MockEmployeeData::parse(string filename)
{
    int type = 0;
    vector<Employee*> employees = {};

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
          
            // get Name
            vector<string> token = StringUtils::split(temp_str, ": ");
            temp_str = "";

            Employee* employee = Employee::createEmployee(token[0]);
            employee->setName(token[1]);

            // get Payment
            getline(file, temp_str);
            token = StringUtils::split(temp_str, "$; ");
            temp_str = "";

            token = StringUtils::split(token[1], ", ");

            

            
        }
    }

    file.close();

    return employees;
}