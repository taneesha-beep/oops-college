#include <iostream>
#include <string.h>
using namespace std;
class student
{
public:
    string name;
    int roll_no, Class, div;
    string dob;
    string aadh_no;
    string blood_grp;
    string address;
    int ph_no;
    static int count;
    void store()
    {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student's Roll no: ";
        cin >> roll_no;
        cout << "Enter student's class and div: ";
        cin >> Class >> div;
        cout << "Enter student's date of birth: ";
        cin >> dob;
        cout << "Enter student's aadhar card no: ";
        cin >> aadh_no;
        cout << "Enter student's blood group: ";
        cin >> blood_grp;
        cout << "Enter student's address: ";
        cin >> address;
        cout << "Enter student's phone number: ";
        cin >> ph_no;
    }
    void show()
    {
        cout << "Student name: " << name << "\n";
        cout << "Student's Roll no: " << roll_no << "\n";
        cout << "Student's class and div: " << Class << div << "\n";
        cout << "Student's date of birth: " << dob << "\n";
        cout << "Student's aadhar card no and blood group " << aadh_no << "\n"
             << blood_grp << "\n";
        cout << "Student's address: " << address << "\n";
        cout << "Student's phone number: " << ph_no << "\n";
    }
};
int main()
{
    student a, b;
    a.store();
    a.show();
    b.store();
    b.show();
}
