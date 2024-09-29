#include<iostream>
using namespace std;
int main(){
    int y;
    cout<<"enter the number: "<<"\n";
    cin>>y;
    if(y%2==0){
        cout<<y<<" "<<"is even number."<<"\n";//% remainder
    }
    else{
        cout<<y<<" "<<"is  odd number."<<"\n";
    }
    return 0;
}