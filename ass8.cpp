#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class Item
{
public:
    int code;
    string name;
    int quantity;
    float price;

    void accept()
    {
        cout << "Enter Item Code: ";
        cin >> code;
        cout << "Enter Item Name: ";
        cin >> name;
        cout << "Enter Item Quantity: ";
        cin >> quantity;
        cout << "Enter Item Price: ";
        cin >> price;
    }

    void display()
    {
        cout << "Code: " << code
             << " | Name: " << name
             << " | Quantity: " << quantity
             << " | Price: " << price << endl;
    }
};

// Function to search item
list<Item>::iterator searchItem(list<Item> &items, int code, string name)
{
    for (auto it = items.begin(); it != items.end(); it++)
    {
        if (it->code == code || it->name == name)
            return it;
    }
    return items.end();
}

int main()
{
    list<Item> items;
    int choice;

    do
    {
        cout << "\n----- INVENTORY MENU -----\n";
        cout << "1. Add Item\n";
        cout << "2. Display Items\n";
        cout << "3. Search Item\n";
        cout << "4. Purchase Item\n";
        cout << "5. Delete Item\n";
        cout << "6. Sort by Item Code\n";
        cout << "7. Sort by Item Name\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Item i;
            i.accept();
            items.push_back(i);
            break;
        }

        case 2:
        {
            for (auto i : items)
                i.display();
            break;
        }

        case 3:
        {
            int code;
            string name;
            cout << "Enter Item Code (or 0): ";
            cin >> code;
            cout << "Enter Item Name (or NA): ";
            cin >> name;

            auto it = searchItem(items, code, name);
            if (it != items.end())
                it->display();
            else
                cout << "Requested Item is not available\n";
            break;
        }

        case 4:
        {
            int code, qty;
            cout << "Enter Item Code to Purchase: ";
            cin >> code;

            auto it = searchItem(items, code, "");
            if (it != items.end())
            {
                cout << "Enter Quantity Required: ";
                cin >> qty;

                if (qty <= it->quantity)
                {
                    float bill = qty * it->price;
                    it->quantity -= qty;
                    cout << "Total Bill Amount: Rs. " << bill << endl;
                }
                else
                {
                    cout << "Required item's Quantity is not in stock\n";
                }
            }
            else
            {
                cout << "Requested Item is not available\n";
            }
            break;
        }

        case 5:
        {
            int code;
            cout << "Enter Item Code to Delete: ";
            cin >> code;

            auto it = searchItem(items, code, "");
            if (it != items.end())
            {
                items.erase(it);
                cout << "Item Deleted Successfully\n";
            }
            else
            {
                cout << "Item not found\n";
            }
            break;
        }

        case 6:
        {
            items.sort([](Item a, Item b)
                       { return a.code < b.code; });
            cout << "Items sorted by Item Code\n";
            break;
        }

        case 7:
        {
            items.sort([](Item a, Item b)
                       { return a.name < b.name; });
            cout << "Items sorted by Item Name\n";
            break;
        }

        case 0:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 0);

    return 0;
}
