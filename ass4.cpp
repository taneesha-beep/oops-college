#include <iostream>
using namespace std;

class Complex
{
    float real;
    float imag;

public:
    // Default Constructor
    Complex()
    {
        real = 0;
        imag = 0;
    }

    // Function to set values
    void setComplex(float r, float i)
    {
        real = r;
        imag = i;
    }

    // Function to display complex number
    void printComplex()
    {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
        cout << endl;
    }

    // Friend function declarations
    friend Complex operator+(Complex, Complex);
    friend Complex operator-(Complex, Complex);
    friend Complex operator*(Complex, Complex);
    friend Complex operator/(Complex, Complex);
};

// Addition
Complex operator+(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

// Subtraction
Complex operator-(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = c1.real - c2.real;
    temp.imag = c1.imag - c2.imag;
    return temp;
}

// Multiplication
Complex operator*(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    temp.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    return temp;
}

// Division
Complex operator/(Complex c1, Complex c2)
{
    Complex temp;
    float denom = (c2.real * c2.real) + (c2.imag * c2.imag);

    temp.real = ((c1.real * c2.real) + (c1.imag * c2.imag)) / denom;
    temp.imag = ((c1.imag * c2.real) - (c1.real * c2.imag)) / denom;

    return temp;
}

int main()
{
    Complex c1, c2, c3;

    c1.setComplex(4, 5);
    c2.setComplex(2, 3);

    cout << "First Complex Number: ";
    c1.printComplex();

    cout << "Second Complex Number: ";
    c2.printComplex();

    c3 = c1 + c2;
    cout << "Addition: ";
    c3.printComplex();

    c3 = c1 - c2;
    cout << "Subtraction: ";
    c3.printComplex();

    c3 = c1 * c2;
    cout << "Multiplication: ";
    c3.printComplex();

    c3 = c1 / c2;
    cout << "Division: ";
    c3.printComplex();

    return 0;
}
