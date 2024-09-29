#include <iostream>
using namespace std;
float divide(int x, int y)
{
    return x / y;
}
int main()
{
    /*
     arises during the execution of a program
    try(suspect) allows you to define a block if code to be tested for
    errors while it is being executed.
    throw an exception when a problem deteced which lets us to create a custom error
    catch allows you to define a block of code to be executed, if an error occurs in the try block
    numerator/0=infinity */
    int n;
    cout << "enetr the age";
    cin >> n;
    try
    {
        if (n >= 18)
        {
            cout << "Access granted";
        }
        else
        {
            throw(n);
        }
    }
    catch (int a)
    {
        cout << "Access denied: you must be 18 years old\n";
        cout << "Age is:" << a;
    }

    int y, u;
    cout << "enter the number\n";
    cin >> y >> u;
    try
    {
        if (u != 0)
        {
            int k = divide(y, u);
        }
        else
        {
            throw(u);
        }
    }
    catch (int h)
    {

        cout << "The denominator should not be 0\n";
    }
    return 0;
}
