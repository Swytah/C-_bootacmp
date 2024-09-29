#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    // Creating a file using ofstream (o stands for output, and it will overwrite)
    ofstream xyz_out("MY_first.txt");
    xyz_out << "Welcome to my GitHub! I hope you like my GitHub_id. "<<endl;
    xyz_out << "I am Sweta, a third-year student.";
    xyz_out.close(); // Closing the file after writing

    // Writing into another file
    ofstream abc("test.txt");
    if(abc.is_open()){
        abc << "Hello" << "\n";
        abc << "Lucky";
        abc.close(); // Closing the file after writing
    }
    else{
        cout << "Sorry" << "\n";
    }

    // Reading from the file "MY_first.txt"
    string s;
    ifstream xyz_in("MY_first.txt");
    while(getline(xyz_in, s)){
        cout << s << endl;
    }
    xyz_in.close(); // Closing the file after reading

    return 0;
}
