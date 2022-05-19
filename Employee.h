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
    virtual Employee *clone(string, int, int) = 0;
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
    Employee *clone(string name, int unit, int pay_per_unit)
    {
        return new DailyEmployee(name, unit, pay_per_unit);
    }

    DailyEmployee() : _working_days(0), _pay_per_day(0) { this->name = "Some Daily Employee"; }

    DailyEmployee(string name, int _working_days, int _pay_per_day)
        : _working_days(_working_days), _pay_per_day(_pay_per_day)
    {
        this->name = name;
    };

    void setDay(int _working_days) { this->_working_days = _working_days; }
    void setPayPerDay(int _pay_per_day) { this->_pay_per_day = _pay_per_day; }

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
    HourlyEmployee() : _working_hours(0), _pay_per_hours(0) { this->name = "Some Hourly Employee"; }

    Employee *clone(string name, int unit, int pay_per_unit)
    {
        return new HourlyEmployee(name, unit, pay_per_unit);
    }

    HourlyEmployee(string name, int _working_hours, int _pay_per_hours)
        : _working_hours(_working_hours), _pay_per_hours(_pay_per_hours)
    {
        this->name = name;
    };

    void setHour(int _working_hours) { this->_working_hours = _working_hours; }
    void setPayPerHour(int _pay_per_hours) { this->_pay_per_hours = _pay_per_hours; }

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
    ProductEmployee() : _working_products(0), _pay_per_products(0) { this->name = "Some Product Employee"; }

    Employee *clone(string name, int unit, int pay_per_unit)
    {
        return new ProductEmployee(name, unit, pay_per_unit);
    }

    ProductEmployee(string name, int _working_products, int _pay_per_products)
        : _working_products(_working_products), _pay_per_products(_pay_per_products)
    {
        this->name = name;
    };

    void setProduct(int _working_products) { this->_working_products = _working_products; }
    void setPayPerProduct(int _pay_per_products) { this->_pay_per_products = _pay_per_products; }

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
    Employee *clone(string name, int unit, int pay_per_unit)
    {
        return new Manager(name, unit, pay_per_unit);
    }

    Manager() : _managed_employees(0), _pay_per_employee(0) { this->name = "Some Manager"; }

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

    void setManagedEmployees(int _managed_employees) { this->_managed_employees = _managed_employees; }
    void setPayPerEmployee(int _pay_per_employee) { this->_pay_per_employee = _pay_per_employee; }

    string info()
    {
        stringstream builder;

        builder << EmployeeType::Manager << ": " << name << " - "
                << "Salary: " << this->salary();

        string result = builder.str();

        return result;
    }
};

class EmployeeFactory
{
private:
    static vector<Employee *> prototype;

public:
    static Employee *createEmployee(string employeeType, string name, int unit, int pay_per_unit);
};

class StringUtils
{
public:
    static vector<string> split(const string &source, string delim);
};

class Parser
{
public:
    static vector<Employee *> parse(string filename);
};