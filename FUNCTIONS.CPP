#include <iostream>
using namespace std;

void greet()
{
    cout << "Good morning sir" << "\n";
}

int total(int a, int b)
{
    return (a + b);
}

int sub(int a, int b)// INT A AND B ARE ARGUMENTS
{
    return (a - b);
}

int mul(int a, int b)
{
    return (a * b);
}

int ds(int a, int b)
{
    return (a / b);
}

int main()
{
    int c, d;
    int x; // Variable to track if the user wants to continue

    do
    {
        greet();
        cout << "Welcome to the basic calculator" << "\n";
        cout << "Enter two numbers: " << "\n";
        cin >> c >> d;

        cout << "1. Addition" << "\n";
        cout << "2. Subtraction" << "\n";
        cout << "3. Multiplication" << "\n";
        cout << "4. Division" << "\n";

        int mn;
        cout << "Enter your choice: " << "\n";
        cin >> mn;

        switch (mn)
        {
        case 1:
        {
            int r = total(c, d);
            cout << "Addition: " << r << "\n";
            break;
        }
        case 2:
        {
            // Subtraction with input validation using do-while
            do
            {
                if (c < d)
                {
                    cout << c << " should be greater than or equal to " << d << "\n";
                    cout << "Enter two new numbers: " << "\n";
                    cin >> c >> d;
                }
            } while (c < d);

            int u = sub(c, d);
            cout << "Subtraction: " << u << "\n";
            break;
        }
        case 3:
        {
            int t = mul(c, d);
            cout << "Multiplication: " << t << "\n";
            break;
        }
        case 4:
        {
            // Division with input validation using do-while
            do
            {
                if (d == 0)
                {
                    cout << "The second number should not be zero." << "\n";
                    cout << "Enter two new numbers: " << "\n";
                    cin >> c >> d;
                }
            } while (d == 0);

            int v = ds(c, d);
            cout << "Division: " << v << "\n";
            break;
        }
        }

        // Ask if the user wants to continue after performing an operation
        cout << "Do you want to continue? Enter 1 for yes or 0 to exit: ";
        cin >> x;

    } while (x != 0); // Exit when the user enters 0

    return 0;
}
