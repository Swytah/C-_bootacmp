#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the number in one array(int)" << "\n";
    cin >> n;
    int arry[n]; // list you can say
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element" << "\n";
        cin >> arry[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arry[i] << " ";
    }
    char arr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'h', 'i', 'j', 'k'};
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}