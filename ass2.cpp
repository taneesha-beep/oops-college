#include <iostream>
#include <string.h>

using namespace std;

class student
{

public:
    int prn;
    string name;
    char panel;

    void takeinput()
    {
        cout << "enter prn: ";
        cin >> prn;
        cout << "enter name: ";
        cin >> name;
        cout << "enter panel: ";
        cin >> panel;
    }

    void print()
    {
        cout << prn << "\t" << name << "\t" << panel << endl;
    }

    student()
    {
        cout << "default constructor !" << endl;
        name = "abcd";
        prn = 0;
        cout << "\n"
             << endl;
    }

    student(int n, string m, char s)
    {
        cout << "parameterized constructor !" << endl;
        prn = n;
        name = m;
        panel = s;
        print();
    }

    student(student &q)
    {
        prn = q.prn;
        name = q.name;
        panel = q.panel;
        print();
    }
};

int main()
{
    student st1, st2(24, "taneesha", 'F'), st3(st2);
}