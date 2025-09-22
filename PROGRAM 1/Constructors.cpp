
#include <iostream>
using namespace std;
class Complex
{
private:
    float real;
    float imag;
public:
    Complex()
    {
        real = 0;
        imag = 0;
        cout << "Default constructor called" << endl;
    }
    Complex(float r, float i)
    {
        real = r;
        imag = i;
        cout << "Parameterized constructor called" << endl;
    }

    Complex(const Complex &c)
    {
        real = c.real;
        imag = c.imag;
        cout << "Copy constructor called" << endl;
    }

    ~Complex()
    {
        cout << "Destructor called for Complex(" << real << ", " << imag << ")" << endl;
    }

    void getdata()
    {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }
    void showdata()
    {
        cout << real << " + " << imag << "i" << endl;
    }
    Complex add_complex(Complex c1, Complex c2)
    {
        Complex temp;
        temp.real = c1.real + c2.real;
        temp.imag = c1.imag + c2.imag;
        return temp;
    }
};
int main()
{
    Complex c1, c2, c3;
    cout << "\nEnter first complex number:" << endl;
    c1.getdata();
    cout << "\nEnter second complex number:" << endl;
    c2.getdata();
    cout << "\nFirst Complex number: ";
    c1.showdata();
    cout << "Second Complex number: ";
    c2.showdata();
    c3 = c3.add_complex(c1, c2);
    cout << "\nResult of addition: ";
    c3.showdata();
    Complex c4 = c3;
    cout << "Copied Complex number: ";
    c4.showdata();
    return 0;
}

