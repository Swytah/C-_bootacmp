/* ENCAPSULATION -> THAT BINDS DATA AND FUNCTIONS THAT MANIPULATE THE DATA AND KEEPS
BOTH SAFE FROM OUTSIDE INTERFERENCE AND MISUSE. DATA HIDING*/
#include<iostream>
#include<string>
using namespace std;
class employee{
    private:
    int empid;
    string name;
    int age;
    float salary;
    public:
    employee(string s, int a, int e, float sa){
        name=s;
        age=a;
        empid=e;
        salary=sa;
    }
    void display(){
        cout<<"Name: "<<name<<" Age: "<<age<<" Employee id: "<<empid<<" Salary: "<<salary<<"\n";
    }
    string getname(){
        return name;
    }
    float getsalary(){
        return salary;
    }
    int getage(){
        return age;
    }
    int getempid(){
        return empid;
    }
};
int main(){
    int n;
    cout<<"Enter the number of employees :"<<"\n";
    cin>>n;
    for(int i=0; i<n;i++){
        int ag,idt;
        string na;
        float sa;
        cout<<"Enter the empid, age, salary and name: "<<"\n";
        cin>>idt>>ag>>sa;
        cin.ignore();
        getline(cin,na);
        cout<<idt<<ag<<sa<<na;

    }
}