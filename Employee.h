#pragma once

#include <iostream>
#include <fstream>
#include <vector>

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
    int _salary;

public:
    virtual int salary() = 0;
    static Employee *createEmployee(string);
};

class DailyEmployee : public Employee
{
private:
    int _working_days;
    int _pay_per_day;

public:
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
    int salary()
    {
        return fix_salary + _pay_per_employee * _managed_employees;
    }
};