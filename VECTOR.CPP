#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
    vector<int> elements; // Vector to hold stack elements

public:
    // Push an element onto the stack
    void push(int value)
    {
        elements.push_back(value);
    }

    // Pop an element from the stack
    void pop()
    {
        if (!elements.empty())
        {
            elements.pop_back(); // Remove the last element
        }
        else
        {
            cout << "Stack is empty! Cannot pop.\n";
        }
    }

    // Peek at the top element of the stack
    int top()
    {
        if (!elements.empty())
        {
            return elements.back(); // Return the last element
        }
        else
        {
            cout << "Stack is empty! No top element.\n";
            return -1; // Return -1 as an indication of an empty stack
        }
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return elements.empty();
    }

    // Get the size of the stack
    int size()
    {
        return elements.size();
    }
};

int main()
{
    Stack stack;
    char t;
    do
    {
        cout << "1. Enter the element\n";
        cout << "2. Remove the element\n";
        cout << "3. Top element\n";
        cout << "4. Is empty\n";
        cout << "5. Size\n";
        int ch;
        cout << "Enter the choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int d; // Declare d inside the case block
            cout << "Enter the element: ";
            cin >> d;
            stack.push(d);
            break;
        }
        case 2:
            stack.pop();
            break;
        case 3:
        {
            int h;
            h = stack.top();
            cout << h << endl;
            break;
        }
        case 4:
        {
            bool r = stack.isEmpty();                                      // Use bool instead of int for isEmpty
            cout << (r ? "Stack is empty" : "Stack is not empty") << endl; // condition ? value_if_true : value_if_false;

            break;
        }
        case 5:
        {
            int w = stack.size();
            cout << "Size of stack: " << w << endl;
            break;
        }
        default:
            cout << "Sorry\n";
        }
        cout << "Enter 'y' to continue or 'n' to exit: ";
        cin >> t;
    } while (t == 'y' || t == 'Y');

    return 0;
}
