#include "Employee.h"

int main()
{

    string filename = "November2021.txt";
    vector<Employee *> employees = Parser::parse(filename);

    for (auto &employee : employees)
    {
        cout << employee->info() << endl;
    }

    return 0;
}