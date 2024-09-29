#include <iostream>
using namespace std;
class animal
{
    // private is not accessible
    int height;
    int weight;
    // public can be accessible
public:
    animal(int h, int w)
    { // constructor it will call(bydefault) the class from here and assign value to the height and the weight
        height = h;
        weight = w;
    }
    void display()
    {
        cout << "Height" << height << " weight" << weight << "\n";
    }
    ~animal()
    { // destructor destruct the space which is created while making the cnstructor
        cout << "I am done" << "\n";
    }
};
int main()
{
    int he, we;
    cout << "Enter the height and weight" << "\n";
    cin >> he >> we;
    animal a1(he, we);
    a1.display();
    return 0;
}