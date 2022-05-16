#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

    static Employee *createEmployee(string, int unit, int pay_per_unit);
    void setName(string name) { this->name = name; }
    string getName() { return name; }
};

class DailyEmployee : public Employee
{
private:
    int _working_days;
    int _pay_per_day;

public:
    DailyEmployee(int _working_days, int _pay_per_day)
        : _working_days(_working_days), _pay_per_day(_pay_per_day){};

    int salary()
    {
        return _pay_per_day * _working_days;
    }
};

class HourlyEmployee : public Employee
{
private:
    int _working_hours;
    int _pay_per_hours;

public:
    HourlyEmployee(int _working_hours, int _pay_per_hours)
        : _working_hours(_working_hours), _pay_per_hours(_pay_per_hours){};

    int salary()
    {
        return _pay_per_hours * _working_hours;
    }
};

class ProductEmployee : public Employee
{
private:
    int _working_products;
    int _pay_per_products;

public:
    ProductEmployee(int _working_products, int _pay_per_products)
        : _working_products(_working_products), _pay_per_products(_pay_per_products){};

    int salary()
    {
        return _pay_per_products * _working_products;
    }
};

class Manager : public Employee
{
private:
    int _managed_employees;
    int _pay_per_employee;
    int fix_salary = 500;

public:
    Manager(int _managed_employees, int _pay_per_employee)
    {
        this->_managed_employees = _managed_employees;
        this->_pay_per_employee = _pay_per_employee;
    }

    int salary()
    {
        return fix_salary + _pay_per_employee * _managed_employees;
    }
};

class MockEmployeeData
{
public:
    // parse data from file to an array
    static vector<Employee*> parse(string filename);


};

class StringUtils
{
public:
    static vector<string> split(const string &source, string delim);
};

