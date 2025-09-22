
#include <iostream>
using namespace std;
class DB;
class DM
{
private:
    int meters;
    int centimeters;
public:
    DM()
    {
        meters = 0;
        centimeters = 0;
    }
    DM(int m, int cm)
    {
        meters = m;
        centimeters = cm;
        normalize();
    }
    void normalize()
    {
        if (centimeters >= 100)
        {
            meters += centimeters / 100;
            centimeters = centimeters % 100;
        }
    }
    void getdata()
    {
        cout << "Enter meters: ";
        cin >> meters;
        cout << "Enter centimeters: ";
        cin >> centimeters;
        normalize();
    }
    void showdata()
    {
        cout << meters << " meters " << centimeters << " centimeters" << endl;
    }
    friend DM add(DM d1, DB d2);
};
class DB
{
private:
    int feet;
    int inches;
public:
    DB()
    {
        feet = 0;
        inches = 0;
    }
    DB(int f, int in)
    {
        feet = f;
        inches = in;
        normalize();
    }
    void normalize()
    {
        if (inches >= 12)
        {
            feet += inches / 12;
            inches = inches % 12;
        }
    }
    void getdata()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
        normalize();
    }
    void showdata()
    {
        cout << feet << " feet " << inches << " inches" << endl;
    }
    friend DM add(DM d1, DB d2);
};
DM add(DM d1, DB d2)
{
    float total_inches = d2.feet * 12 + d2.inches;
    float total_cm = total_inches * 2.54;
    int dm_total_cm = d1.meters * 100 + d1.centimeters;
    int sum_cm = dm_total_cm + total_cm;
    DM result;
    result.meters = sum_cm / 100;
    result.centimeters = sum_cm % 100;
    result.normalize();
    return result;
}
int main()
{
    DM d1, d3;
    DB d2;
    cout << "Enter distance in meters and centimeters:" << endl;
    d1.getdata();
    cout << "\nEnter distance in feet and inches:" << endl;
    d2.getdata();
    d3 = add(d1, d2);
    cout << "\nFirst distance (DM): ";
    d1.showdata();
    cout << "Second distance (DB): ";
    d2.showdata();
    cout << "\nResultant distance after addition (in meters & cm): ";
    d3.showdata();
    return 0;
}
