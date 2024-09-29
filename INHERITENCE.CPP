#include <iostream>
using namespace std;
class pro
{
public:
    int length;
    pro(int l)
    {
        length = l;
    }
    void display()
    {
        cout << "the length is " << length << "\n";
    }
};
class rectangle : public pro
{
public:
    int breadth;
    rectangle(int l,int b):pro(l)
    {
        breadth = b;
    }
    void display()
    {
        display();
        cout << "the breadth is " << breadth << "\n";
    }
};
int main()
{
    int r;
    int t;
    cout << "enter the length and the breadth" << "\n";
    cin >> r >> t;
    rectangle r1(r,t);
    r1.display();
    return 0;
}
// function with same name and different purpose is called polymorphism