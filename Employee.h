#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;



class Employee
{
protected:
    string name;

public:
    virtual int salary() = 0;
    virtual int getUnit() = 0;
    virtual int getPayPerUnit() = 0;
    virtual string className() = 0;
    void setName(string name) { this->name = name; }
    string getName() { return name; }
};

class DailyEmployee : public Employee
{
private:
    int _working_days;
    int _pay_per_day;

public:
    DailyEmployee() {
        name = "";
        _working_days = 0;
        _pay_per_day = 0;
    };

    DailyEmployee(int _working_days, int _pay_per_day)
        : _working_days(_working_days), _pay_per_day(_pay_per_day){};

    int salary()
    {
        return _pay_per_day * _working_days;
    }

    int getUnit()
    {
        return _working_days;
    }

    int getPayPerUnit()
    {
        return _pay_per_day;
    }

    string className() { return "DailyEmployee"; }

};

class HourlyEmployee : public Employee
{
private:
    int _working_hours;
    int _pay_per_hours;

public:

    HourlyEmployee() {
        name = "";
        _working_hours = 0;
        _pay_per_hours = 0;
    };

    HourlyEmployee(int _working_hours, int _pay_per_hours)
        : _working_hours(_working_hours), _pay_per_hours(_pay_per_hours){};

    int salary()
    {
        return _pay_per_hours * _working_hours;
    }

    int getUnit()
    {
        return _working_hours;
    }

    int getPayPerUnit()
    {
        return _pay_per_hours;
    }

    string className() { return "HourlyEmployee"; }

};

class ProductEmployee : public Employee
{
private:
    int _working_products;
    int _pay_per_products;

public:
    ProductEmployee() {
        name = "";
        _working_products = 0;
        _pay_per_products = 0;
    };


    ProductEmployee(int _working_products, int _pay_per_products)
        : _working_products(_working_products), _pay_per_products(_pay_per_products){};

    int salary()
    {
        return _pay_per_products * _working_products;
    }

    int getUnit()
    {
        return _working_products;
    }

    int getPayPerUnit()
    {
        return _pay_per_products;
    }

    string className() { return "ProductEmployee"; }

};

class Manager : public Employee
{
private:
    int _managed_employees;
    int _pay_per_employee;
    int fix_salary = 500;

public:
    Manager() {
        name = "";
        _managed_employees = 0;
        _pay_per_employee = 0;
    };

    Manager(int _managed_employees, int _pay_per_employee)
    {
        this->_managed_employees = _managed_employees;
        this->_pay_per_employee = _pay_per_employee;
    }

    int salary()
    {
        return fix_salary + _pay_per_employee * _managed_employees;
    }

    int getUnit()
    {
        return _managed_employees;
    }

    int getPayPerUnit()
    {
        return _pay_per_employee;
    }

    int getFixSalary()
    {
        return fix_salary;
    }

    string className() { return "Manager"; }

};

class EmployeeFactory
{
public:
    static constexpr const char* DailyEmployeeStr = "DailyEmployee";
    static constexpr const char* HourlyEmployeeStr = "HourlyEmployee";
    static constexpr const char* ProductEmployeeStr = "ProductEmployee";
    static constexpr const char* ManagerStr = "Manager";

    static Employee* createEmployee(string, int, int);
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

class IConverter {
public:
    virtual string convert(void* shape) = 0;
    
};

class DailyEmployeeUIConverter : public IConverter {
public:
    string convert(void* employee) {
        DailyEmployee* dailyEmployee = (DailyEmployee*) employee;
        stringstream builder;
        builder << "DailyEmployee" << ": " << dailyEmployee->getName() << endl;
        builder << "   DailyPayment=" << dailyEmployee->getPayPerUnit() << "$; TotalDays=" << dailyEmployee->getUnit() << endl;
        builder << "   Salary=" << dailyEmployee->salary() << endl;

        string result = builder.str();
        return result;
    }

    
};

class HourlyEmployeeUIConverter : public IConverter {
public:
    string convert(void* employee) {
        HourlyEmployee* hourlyEmployee = (HourlyEmployee*)employee;
        stringstream builder;
        builder << "HourlyEmployee" << ": " << hourlyEmployee->getName() << endl;
        builder << "   HourlyPayment=" << hourlyEmployee->getPayPerUnit() << "$; TotalHours=" << hourlyEmployee->getUnit() << endl;
        builder << "   Salary=" << hourlyEmployee->salary() << endl;

        string result = builder.str();
        return result;
    }

    
};

class ProductEmployeeUIConverter : public IConverter {
public:
    string convert(void* employee) {
        ProductEmployee* productEmployee = (ProductEmployee*)employee;
        stringstream builder;
        builder << "ProductEmployee" << ": " << productEmployee->getName() << endl;
        builder << "   PaymentPerProduct=" << productEmployee->getPayPerUnit() << "$; TotalProducts=" << productEmployee->getUnit() << endl;
        builder << "   Salary=" << productEmployee->salary() << endl;
        string result = builder.str();
        return result;
    }

    
};

class ManagerUIConverter : public IConverter {
public:
    string convert(void* employee) {
        Manager* manager = (Manager*)employee;
        stringstream builder;
        builder << "Manager" << ": " << manager->getName() << endl;
        builder << "   FixedPayment=" << manager->getFixSalary() << "$; TotalEmployees=" << manager->getUnit() << "; PaymentPerProduct=" << manager->getPayPerUnit()<< "$" << endl;
        builder << "   Salary=" << manager->salary() << endl;
        string result = builder.str();
        return result;
    }

  
};