#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Hotel
{
    string cust_name, city, room_type;
    int cust_id, age, income;

public:
    // Default constructor
    Hotel()
    {
        cust_name = "";
        city = "";
        room_type = "";
        cust_id = age = income = 0;
    }

    void accept()
    {
        cout << "\nEnter Customer Name: ";
        cin >> cust_name;

        cout << "Enter Customer ID: ";
        cin >> cust_id;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Income: ";
        cin >> income;

        cout << "Enter City: ";
        cin >> city;

        cout << "Enter Room Type: ";
        cin >> room_type;
    }

    void display()
    {
        cout << cust_name << "\t"
             << cust_id << "\t"
             << age << "\t"
             << income << "\t"
             << city << "\t"
             << room_type << endl;
    }

    void getage()
    {
        if (age < 18 || age > 55)
            throw age;
    }

    void getincome()
    {
        if (income < 50000 || income > 100000)
            throw income;
    }

    void getcity()
    {
        if (city != "Pune" && city != "Mumbai")
            throw city;
    }

    void getroom_type()
    {
        if (room_type != "delux" && room_type != "superdelux")
            throw room_type;
    }

    void store()
    {
        ofstream fout("hotel.txt", ios::app);
        fout << cust_name << "\t"
             << cust_id << "\t"
             << age << "\t"
             << income << "\t"
             << city << "\t"
             << room_type << endl;
        fout.close();
    }
};

int main()
{
    Hotel h;
    int count = 0;

    while (count < 5)
    {
        try
        {
            h.accept();
            h.getage();
            h.getincome();
            h.getcity();
            h.getroom_type();

            cout << "\nValid Customer Details:\n";
            h.display();

            h.store();
            count++;
        }
        catch (int)
        {
            cout << "Error: Age or Income is invalid\n";
        }
        catch (string)
        {
            cout << "Error: City or Room Type is invalid\n";
        }
    }

    cout << "\n5 Records Stored Successfully in File.\n";
    return 0;
}
