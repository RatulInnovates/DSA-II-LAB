#include <bits/stdc++.h>
using namespace std;
class Employee
{

    string name;
    double salary;

public:
    int id;
    Employee(string name, double salary, int id) : name(name), salary(salary), id(id) {}

    string getName()
    {
        return name;
    }
    double getSalary()
    {
        return salary;
    }

    void display()
    {
        cout << "name: " << name << " salary: " << salary << " id: " << id << endl;
    }
    void Increment(double percentage)
    {
        salary += salary * percentage / 100;
    }
};
bool compareById(Employee &e1, Employee &e2)
{
    return e1.id < e2.id;
}
bool compareBySalary(Employee &e1, Employee &e2)
{
    return e1.getSalary() > e2.getSalary();
}

int main()
{
    vector<Employee> emp;
    emp.push_back(Employee("rahim", 8000, 2));
    emp.push_back(Employee("karim", 15000, 1));
    emp.push_back(Employee("Abir", 9000, 4));
    emp.push_back(Employee("Roni", 18000, 3));
    // emp.front().display();

    // cout << "Employees with salary more than 10000: " << endl;
    // for (auto e : emp)
    // {
    //     if (e.getSalary() >= 10000)
    //         cout << e.getName() << endl;
    // }
    // for (auto &e : emp)
    // {
    //     if (e.getSalary() >= 15000)
    //         e.Increment(15);
    //     else
    //         e.Increment(10);
    // }

    sort(emp.begin(), emp.end(), compareById);
    sort(emp.begin(), emp.end(), compareBySalary);

    emp.front().display();

    return 0;
}