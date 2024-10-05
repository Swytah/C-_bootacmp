#include <iostream>
#include <tuple>
using namespace std;

class animal
{
    int height;
    int weight;

public:
    // Constructor accepting a tuple
    animal(tuple<int, int> info)
    {
        // Unpacking tuple into height and weight
        height = get<0>(info); // The get function in C++ is used with tuples to access specific elements by their index
        weight = get<1>(info);
    }

    void display()
    {
        cout << "Height: " << height << " Weight: " << weight << "\n";
    }

    // Destructor
    ~animal()
    {
        cout << "I am done" << "\n";
    }
};

int main()
{
    int he, we;
    cout << "Enter the height and weight: " << "\n";
    cin >> he >> we;

    // Creating a tuple to hold height and weight
    tuple<int, int> info = make_tuple(he, we);
    // used to create a tuple by bundling multiple values of potentially different types into a single object.
    // a variable with auto, the compiler automatically infers the type of the variable based on the value assigned to it
    // auto keyword can only be used to deduce the types of variables but not within class member variables or function parameter types
    //  Passing the tuple to the animal constructor
    animal a1(info);
    a1.display();

    return 0;
}
