#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class EmployeeType
{
public:
    static constexpr const char *DailyEmployee = "DailyEmployee";
    static constexpr const char *HourlyEmployee = "HourlyEmployee";
    static constexpr const char *ProductEmployee = "ProductEmployee";
    static constexpr const char *Manager = "Manager";
};

class Employee
{
protected:
    string name;

public:
    virtual int salary() = 0;
    virtual string info() = 0;

    // static Employee *createEmployee(string, int unit, int pay_per_unit);

    void setName(string name) { this->name = name; }
};

class DailyEmployee : public Employee
{
private:
    int _working_days;
    int _pay_per_day;

public:
    DailyEmployee(string name, int _working_days, int _pay_per_day)
        : _working_days(_working_days), _pay_per_day(_pay_per_day)
    {
        this->name = name;
    };

    int salary()
    {
        return _pay_per_day * _working_days;
    }

    string info()
    {
        stringstream builder;

        builder << EmployeeType::DailyEmployee << ": " << name << " - "
                << "Salary: " << this->salary();

        string result = builder.str();

        return result;
    }
};

class HourlyEmployee : public Employee
{
private:
    int _working_hours;
    int _pay_per_hours;

public:
    HourlyEmployee(string name, int _working_hours, int _pay_per_hours)
        : _working_hours(_working_hours), _pay_per_hours(_pay_per_hours)
    {
        this->name = name;
    };

    int salary()
    {
        return _pay_per_hours * _working_hours;
    }

    string info()
    {
        stringstream builder;

        builder << EmployeeType::HourlyEmployee << ": " << name << " - "
                << "Salary: " << this->salary();

        string result = builder.str();

        return result;
    }
};

class ProductEmployee : public Employee
{
private:
    int _working_products;
    int _pay_per_products;

public:
    ProductEmployee(string name, int _working_products, int _pay_per_products)
        : _working_products(_working_products), _pay_per_products(_pay_per_products)
    {
        this->name = name;
    };

    int salary()
    {
        return _pay_per_products * _working_products;
    }

    string info()
    {
        stringstream builder;

        builder << EmployeeType::ProductEmployee << ": " << name << " - "
                << "Salary: " << this->salary();

        string result = builder.str();

        return result;
    }
};

class Manager : public Employee
{
private:
    int _managed_employees;
    int _pay_per_employee;
    int fix_salary = 500;

public:
    Manager(string name, int _managed_employees, int _pay_per_employee)
    {
        this->_managed_employees = _managed_employees;
        this->_pay_per_employee = _pay_per_employee;
        this->name = name;
    }

    int salary()
    {
        return fix_salary + _pay_per_employee * _managed_employees;
    }

    string info()
    {
        stringstream builder;

        builder << EmployeeType::Manager << ": " << name << " - "
                << "Salary: " << this->salary();

        string result = builder.str();

        return result;
    }
};

class StringUtils
{
    static vector<string> split(const string &source, string delim);
};

class EmployeeFactory
{
public:
    static Employee *createEmployee(string employeeType, string name, int unit, int pay_per_unit);
};