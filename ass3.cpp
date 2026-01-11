#include <iostream>
using namespace std;

class Employee
{
    string Ename;
    string Empid;

public:
    Employee() : Ename(""), Empid(0) {}
    Employee(string name, int id) : Ename(name), Empid(id) {}
    virtual void accept()
    {
        cout << "Enter employee name: ";
        cin >> Ename;
        cout << "Enter employee id: ";
        cin >> Empid;
    }
    virtual void display() const
    {
        cout << "Employee Name: " << Ename << endl;
        cout << "Employee ID: " << Empid << endl;
    }
    virtual double earnings() const = 0;
};
class SalariedEmployee : public Employee
{
    double weeklysalary;

public:
    SalariedEmployee() : weeklysalary(0) {}
    SalariedEmployee(string name, int id, double salary) : Employee(name, id), weeklysalary(salary) {}
    virtual void accept() override
    {
        Employee::accept();
        cout << "Enter weekly salary: ";
        cin >> weeklysalary;
    }
    virtual void display() const override
    {
        Employee::display();
        cout << "Weekly Salary: " << weeklysalary << endl;
    }
    double earnings() const override
    {
        return weeklysalary;
    }
};
class HourlyEmployee : public Employee
{
    double wage;
    double hours;
    double Houerlysalary;

public:
    HouerlyEmployee() : wage(0.0), hours(0.0) {}
    HourlyEmployee(string name, int id, double w, double hour) : Employee(name, id), wage(w), hour(hours) {}
    virtual void accept() override
    {
        Employee::accept();
        cout << "hourly wages:";
        cin >> wage;
        cout << "hours worked:";
        cin >> hours;
    }
    virtual void display() const override
    {
        Employee::display();
        cout << "Hourly wage: " << wage << endl;
        cout << "Hours worked: " << hours << endl;

        cout << "Hourly Salary: " << earnings() << endl;
    }
    double earnings() const override
    {
        if (hours < 40)
        {
            return hours * wage;
        }
        else
        {
            return 40 * wage + (hours - 40) * wage * 1.5;
        }
    }
};
class CommisionEmployee : public Employee
{
    double grossSales;
    double commissionRate;
    double commissionSalary;

public:
    CommisionEmployee() : grossSales(0.0), commissionRate(0.0), commissionSalary(0.0) {}
    CommisionEmployee(string name, int id, double g, double rate) : Employee(name, id), grossSales(g), commissionRate(rate) {}
    virtual void accept() override
    {
        Employee::accept();
        cout << "Enter gross sales: ";
        cin >> grossSales;
        cout << "Enter commission rate: ";
        cin >> commissionRate;
    }
    virtual void display() const override
    {
        Employee::display();
        cout << "Gross Sales: " << grossSales << endl;
        cout << "Commission Rate: " << commissionRate << endl;
        cout << "Commission Salary: " << earnings() << endl;
    }
    double earnings() const override
    {
        return grossSales * commissionRate;
    }
};
int main()
{
    SalariedEmployee s("John", 101, 5000);
    HourlyEmployee h("Jane", 102, 20, 40);
    CommisionEmployee c("Tom", 103, 10000, 0.08);

    cout << "salaried employee details: " << endl;
    s.accept();
    s.display();
    cout << "earnings:" << s.earnings() << endl;
    cout << "Hourly employee details: " << endl;
    h.accept();
    h.display();
    cout << "earnings:" << h.earnings() << endl;
    cout << "Commission employee details: " << endl;
    c.accept();
    c.display();
    cout << "earnings:" << c.earnings() << endl;
    return 0;
}
