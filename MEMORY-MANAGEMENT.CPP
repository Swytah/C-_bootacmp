#include <iostream>
#include <stack>
// stack
/*you can say dynamic when you don;t the number of elements
the size of the memory to be allocated is known to the compiler
the allocation happens in  on continguous blocks of memory
 de-allocation happens after the function is called*/
// heap
/*in heap we have to create memory
and we have to relase the memory.
the memory is allocated during the execution of
instruction written by programmers.
if a programmer does not handle this memory well, a memory leak
can happen in the program
*/
using namespace std;
int main()
{
    int n;
    cout << "enter the number you want in heap:";
    cin >> n;
    int *p;
    float *q;
    p = new int[n];
    q = new float[n];
    // assigning value
    for (int i = 0; i < n; i++)
    {
        
       
       cin>> p[i]; // p[i]=*(p+i)
        /**p[i]: You're now trying to dereference the value, which is
         * incorrect
         * because p[i] is not a pointer; it's an integer (or whatever data type
         *  you're using).*/
        /*You don't use * in p[i] because the [] operator automatically dereferences the pointer to access the array element at that index.
        Using *p[i] would cause an error because p[i] gives a value, not a pointer, and you cannot dereference a non-pointer value.*/
        
       cin>> q[i];
    }

    cout << "\nValues in the int array: ";
    for (int i = 0; i < n; i++) {
        cout << p[i] << " "; // Print all elements of p
    }

    cout << "\nValues in the float array: ";
    for (int i = 0; i < n; i++) {
        cout << q[i] << " "; // Print all elements of q
    }

    // Deallocating the dynamically allocated memory
    delete[] p; // Correct deallocation of int array
    delete[] q; // Correct deallocation of float array

    return 0;
}
