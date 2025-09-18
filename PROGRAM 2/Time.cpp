#include <iostream>
using namespace std;
class Time 
{
private:
    int hr, min, sec;
public:
    Time() 
{
        hr = 0;
        min = 0;
        sec = 0;
        cout << "Default constructor called" << endl;
}
    Time(int h, int m, int s) 
{
        hr = h;
        min = m;
        sec = s;
        normalize();
        cout << "Parameterized constructor called" << endl;
}
    Time(const Time &t) 
{
        hr = t.hr;
        min = t.min;
        sec = t.sec;
        cout << "Copy constructor called" << endl;
}
    ~Time() 
{
        cout << "Destructor called for Time(" 
             << hr << ":" << min << ":" << sec << ")" << endl;
}
    void getdata() 
{
        cout << "Enter hours: ";
        cin >> hr;
        cout << "Enter minutes: ";
        cin >> min;
        cout << "Enter seconds: ";
        cin >> sec;
        normalize();
}
    void showdata() 
{
        cout << hr << " hr : " << min << " min : " << sec << " sec" << endl;
}
    void normalize() 
{
        if (sec >= 60) 
        {
            min += sec / 60;
            sec = sec % 60;
        }
        if (min >= 60) 
        {
            hr += min / 60;
            min = min % 60;
        }
}
    Time operator+(Time t) 
{
        Time temp;
        temp.hr = hr + t.hr;
        temp.min = min + t.min;
        temp.sec = sec + t.sec;
        temp.normalize();
        return temp;
}
    Time operator++(int) 
{
        Time temp = *this; 
        sec++;
        normalize();
        return temp; 
}
};
int main() 
{
    Time t1, t2, t3;
    cout << "\nEnter first time:" << endl;
    t1.getdata();
    cout << "\nEnter second time:" << endl;
    t2.getdata();
    t3 = t1 + t2;
    t1++;
    cout << "\nResult of addition (t3): ";
    t3.showdata();
    cout << "Time after increment (t1): ";
    t1.showdata();
    return 0;
}
