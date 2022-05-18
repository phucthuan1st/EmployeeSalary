#include "Employee.h"

int main()
{
    /*Employee *employee1 = EmployeeFactory::createEmployee(EmployeeFactory::ProductEmployeeStr, 50, 10);
    Employee *employee2 = EmployeeFactory::createEmployee(EmployeeFactory::DailyEmployeeStr, 40, 15);
    Employee *employee3 = EmployeeFactory::createEmployee(EmployeeFactory::HourlyEmployeeStr, 60, 25);
    Employee *employee4 = EmployeeFactory::createEmployee(EmployeeFactory::ManagerStr, 3, 100);*/

    vector<Employee*> employees = MockEmployeeData::parse("November2021.txt");
    

    map<string, IConverter*> ui = {
        {(new DailyEmployee())->className(), new DailyEmployeeUIConverter() },
        {(new HourlyEmployee())->className(), new HourlyEmployeeUIConverter() },
        {(new ProductEmployee())->className(), new ProductEmployeeUIConverter() },
        {(new Manager())->className(), new ManagerUIConverter() }

    };

    for (int i = 0; i < employees.size(); i++) {
        auto converter = ui[employees[i]->className()];
        string data = converter->convert((void*)employees[i]);
        
        cout << data << endl;
    }

    system("pause");
    /*cout << employee1->salary() << endl;
    cout << employee2->salary() << endl;
    cout << employee3->salary() << endl;
    cout << employee4->salary() << endl;*/

    /*delete employee4;
    delete employee3;
    delete employee2;
    delete employee1;*/
    return 0;
}