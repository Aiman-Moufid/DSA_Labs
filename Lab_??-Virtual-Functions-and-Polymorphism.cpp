//
//  main.cpp
//  tbd
//
//  Created by Aiman Moufid on 10/23/25.
//

#include <iostream>
#include <vector>
using namespace std;
class Employee{
public:
    string name;
    double salary;
    
    Employee(string n, double s)
    {
        name=n;
        salary=s;
    }
    void showInfo()
    {
        cout << name << " " << salary << endl;
    }
    virtual void calculateBonus()
    {
        cout << "Bonus = " << "No bonus"<<endl;
    }
};

class Manager:public Employee
{
public:
    Manager(string n, double s):Employee(n, s){};
    
    
    void calculateBonus() //override
    {
        cout <<"Bonus = " << salary*0.2 << endl;
    }
    
};

class Developer:public Employee
{
public:
    Developer(string n, double s):Employee(n, s){};
    void calculateBonus() //override
    {
        cout <<"Bonus = " << salary*0.1 << endl;
    }
    
};

class Intern:public Manager
{
public:
    Intern(string n, double s):Manager(n, s){};
    
    
    void calculateBonus() override
    {
        cout <<"Bonus = " << salary*0 << endl;
    }
    
};

int main()
{
    Employee g("beans", 56);
    g.showInfo();
    g.calculateBonus();
    Manager f("mr.manager", 98);
    f.showInfo();
    f.calculateBonus();
    Developer b("ui", 76);
    b.showInfo();
    b.calculateBonus();
    
    Employee* employees;
    employees = new Manager("more beans", 20000);
    employees->calculateBonus();
    Employee* employees2;
    employees2 = new Developer("capped out on beans", 1);
    employees2->calculateBonus();
    
    Employee* employeelist[3];
    employeelist[0] = new Manager("Mr.Manager", 99999);
    employeelist[1] = new Developer("E", 89);
    employeelist[2] = new Intern("Coffee Bringer", 1000);
    cout << endl<< endl << "Part 3" << endl << endl;
    for(int i = 0;i<3;i++)
    {
        employeelist[i]->showInfo();
        employeelist[i]->calculateBonus();
    }
               
               
}
