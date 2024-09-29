#include<iostream>
using namespace std;
int main(){
    //VARIBALE WHO HOLDS OTHER'S VARIABLE
    int *p; //pointer p with integer value;
    int a=100;
    p=&a; // The & operator is the address-of operator. It returns the memory address of the variable a
    //p = &a: This assigns the memory address of a to the pointer p, so p now points to a
    cout<<a<<endl;//VALUE
    cout<<p<<endl;//ADDRESS
    cout<<&a<<endl;//ADDRESS
    cout<<*p<<endl;//VALUE
}   
