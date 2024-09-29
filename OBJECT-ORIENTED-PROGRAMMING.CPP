#include <iostream>

using namespace std;

class Metrix
{
private:
    int height;
    int age;
    char sex;
    long int phone;

public:
    Metrix(int h, int a, char s, int ph)
    {
        height = h;
        age = a;
        sex = s;
        phone = ph;
    }

    void display()
    {
        cout << "  AGE:  " << age << "  GENDER:  " << sex
             << "  HEIGHT:  " << height << "  PHONE-NUMBER:  " << phone << endl;
    }
};

int main()
{
    int ht, ag, pn;
    char sx;

    cout << "Enter the height, age, sex, phone, and name:\n";
    cin >> ht >> ag >> sx >> pn;

    Metrix m(ht, ag, sx, pn);
    m.display();

    return 0;
}
