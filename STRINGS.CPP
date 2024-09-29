#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cout << "enter the number" << "\n";
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the string" << "\n";
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    string fname = "Sweta";
    string lname = "Nath";
    string name = fname + " " + lname;
    cout << name;
    for (int i = name.length(); i <= 0; i--)
    {
        cout << name[i] << " ";
    }
    cout << endl;
    // length is a in built function
    int l = 0;
    while (name[l] != '\0')
    { // '\0' null operator
        l++;
    }
    cout << l;
}