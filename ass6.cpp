#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

int countSpaces(const char input[])
{
    int num = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            num++;
        }
    }
    return num;
}

int main()
{
    ifstream fin("abc.txt");
    if (!fin)
    {
        cout << "Error opening file abc.txt" << endl;
        return 1;
    }

    char ch[50];
    fin.getline(ch, sizeof(ch)); // Use getline to read a full line

    ofstream fout("xyz.txt");
    if (!fout)
    {
        cout << "Error opening file xyz.txt" << endl;
        return 1;
    }

    fout << ch;

    int l = 0; // Count of lowercase letters
    int u = 0; // Count of uppercase letters
    for (int i = 0; i < strlen(ch); i++)
    {
        if (islower(ch[i]))
        {
            l++;
        }
        else if (isupper(ch[i]))
        { // Only count uppercase if it's an uppercase letter
            u++;
        }
    }

    cout << "Lowercase: " << l << endl;
    cout << "Uppercase: " << u << endl;

    int spaces = countSpaces(ch);
    cout << "Number of spaces: " << spaces << endl;

    fin.close();
    fout.close();

    return 0;
}
