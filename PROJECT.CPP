#include <iostream>
#include <string>
#include <fstream>
#include <cctype>  // convert in upper
#include <iomanip> // for specifying the space
using namespace std;
class account
{
    long int accno;
    char name[50];
    long int amount;
    int deposit;
    int withdrawal;
    char type;

public:
    void create_aacount();
    void show_account() const;
    void modify();
    void dep(long int);
    void draw(long int);
    void report() const;
    int retacno() const;
    int retdeposit() const;
    char rettype() const;
};
void account::create_aacount()
{
    cout << "\n\t\t\tEnter the Account No. : ";
    cin >> accno;
    cout << "\n\t\t\tEnter the Name of the Account Holder Here : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n\t\t\tEnter the Type of the Account(C/S) : ";
    cin >> type;
    type = toupper(type);
    cout << "\n\t\t\tEnter the Initial amount : ";
    cin >> deposit;
    cout << "\n\t\t\tAccount is Creating....";
    cout << "\n\t\t\tAccount Created";
}
void account::show_account() const
{ // not able to ulter it
    cout << "\n\t\t\tAccount No. :" << accno;
    cout << "\n\t\t\tAccount Holder Name : ";
    cout << name;
    cout << "\n\t\t\tType of Acoount : " << type;
    cout << "\n\t\t\tBalance Amount : " << deposit;
}
void account::modify()
{
    cout << "\n\t\t\tAccount No. :" << accno;
    cout << "\n\t\t\tModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n\t\t\tModify Type of Account : ";
    cin >> type;
    type = toupper(type);
    cout << "\n\t\t\tModify Balance amount : ";
    cin >> deposit;
}
void account::dep(long int x)
{
    deposit += x;
}
void account::draw(long int x)
{
    deposit -= x;
}
void account::report() const
{
    cout << accno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}
int account::retacno() const
{
    return accno;
}
int account::retdeposit() const
{
    return deposit;
}
char account::rettype() const
{
    return type;
}
// for file handling
void write_account();
void display_sp(long int);
void modify_account(long int);
void delete_account(long int);
void display_all();
void display_account(long int);
void deposit_withdraw(long int, long int);
int main()
{
    char ch;
    int num;
    do
    {
        cout << "\n\t\t\t==============================\n";
        cout << "\n\t\t\tBANK MANAGEMENT SYSTEM";
        cout << "\n\t\t\t==============================\n";

        cout << "\n\t\t\t  ::MAIN MENU::\n";
        cout << "\n\t\t\t1. NEW ACCOUNT";
        cout << "\n\t\t\t2. DEPOSIT AMOUNT";
        cout << "\n\t\t\t3. WITHDRAW AMOUNT";
        cout << "\n\t\t\t4. BALANCE ENQUIRY";
        cout << "\n\t\t\t5. ALL ACCOUNT HOLDER LIST";
        cout << "\n\t\t\t6. CLOSE AN ACCOUNT";
        cout << "\n\t\t\t7. MODIFY AN ACCOUNT";
        cout << "\n\t\t\t8. EXIT";
        cout << "\n\n\t\t\t\tSELECT YOUR OPTION (1-8): ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            write_account();
            break;
        case '2':
            cout << "\n\n\t\t\t\tEnter the Account No. : ";
            cin >> num;
            deposit_withdraw(num, 1); // 1 is flag
            break;
        case '3':
            cout << "\n\n\t\t\t\tEnter the Account No. : ";
            cin >> num;
            deposit_withdraw(num, 2); // 2 is flag
            break;
        case '4':
            cout << "\n\n\t\t\t\tEnter the Account No. : ";
            cin >> num;
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            cout << "\n\n\t\t\t\tEnter the Account No. : ";
            cin >> num;
            display_account(num);
            break;
        case '7':
            cout << "\n\n\t\t\t\tEnter the Account No. : ";
            cin >> num;
            modify_account(num);
            break;
        case '8':
            cout << "\n\n\t\t\tGood Bye";
            break;
        default:
            cout << "\a"; //'\a' is an escape sequence that represents the "alert" or "bell" character
        }
        cin.ignore();
        cin.get();
    } while (ch != '8');
    return 0;
}
void write_account()
{
    account ac;       // object (class object is always a binary data)
    ofstream outfile; // outputfile object
    // using file obj opening or creating new file ios(flag) is input ouput app is append .dat is used to store data in a binary format
    outfile.open("Account.dat", ios::binary | ios::app); // dat is data
    /*This is a flag that tells the file stream to treat the file in binary mode.
     By default, file streams open files in text mode, where special character conversions may happen (like converting \n to \r\n on Windows).
     Using ios::binary prevents these conversions, allowing raw binary data to be written or read exactly as it is.
     */
    ac.create_aacount();
    outfile.write(reinterpret_cast<char *>(&ac), sizeof(account));
    /*&ac address of the account object which have everything
    <*char> coverted in character
    reinterpret_cast is csating the values of ac in character pointer
    reinterpret_cast is type casting operator that allows u to convert,
    one pointer type to another, in this case from type of ac to char*
    sizeof(account) size of the memory of the account class
    give only one address and size of overall it will copy all own by own*/
    outfile.close();
}
void display_sp(int n)
{
    account ac;
    bool flag = false;
    ifstream infile;
    infile.open("Account.dat", ios::binary);
    if (!infile)
    {
        cout << "File could not be open!! press any key...";
        return;
    }
    cout << "\n\t\t\tBALANCE DETAILS\n";
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retacno() == n)
        {
            ac.show_account();
            flag = true;
        }
    }
    infile.close();
    if (flag == false)
    {
        cout << "\n\t\t\tACCOUNT NUMBER DOESNOT EXIST";
        return;
    }
}
void modify_account(long int n)
{
    bool found = false;
    account ac;
    fstream file;
    file.open("Account.dat", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "\n\t\t\tFile could not be opened! Press any key...";
        return;
    }

    while (!file.eof() && found == false)
    {
        file.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (ac.retacno() == n)
        {
            ac.show_account();
            cout << "\n\n\t\t\tEnter the new details of the account." << endl;
            ac.modify();
            int pos = (-1) * static_cast<int>(sizeof(account));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout << "\n\n\t\t\tRecord Updated";
            found = true;
        }
    }
    file.close();
    if (!found)
    {
        cout << "\n\n\t\t\tRecord Not Found!";
    }
}

void delete_account(long int n)
{
    account ac;
    ifstream infile;
    ofstream outfile;
    infile.open("Account.dat", ios::binary);
    if (!infile)
    {
        cout << "\n\t\t\tFile could not be opened! Press any key...";
        return;
    }

    outfile.open("Temp.dat", ios::binary);
    infile.seekg(0, ios::beg);
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retacno() != n)
        {
            outfile.write(reinterpret_cast<char *>(&ac), sizeof(account));
        }
    }
    infile.close();
    outfile.close();
    remove("Account.dat");
    rename("Temp.dat", "Account.dat");
    cout << "\n\n\t\t\tRecord Deleted";
}

void display_all()
{
    account ac;
    ifstream infile;
    infile.open("Account.dat", ios::binary);
    if (!infile)
    {
        cout << "\n\t\t\tFile could not be opened! Press any key...";
        return;
    }

    cout << "\n\t\t\tACCOUNT HOLDER LIST\n";
    cout << "================================================================\n";
    cout << "A/c no.      NAME            Type    Balance\n";
    cout << "================================================================\n";
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        ac.report();
    }
    infile.close();
}

void deposit_withdraw(long int n, long int option)
{
    long int amt;
    bool found = false;
    account ac;
    fstream file;
    file.open("Account.dat", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "\n\t\t\tFile could not be opened! Press any key...";
        return;
    }

    while (!file.eof() && found == false)
    {
        file.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (ac.retacno() == n)
        {
            ac.show_account();
            if (option == 1)
            {
                cout << "\n\n\t\t\tTO DEPOSIT AMOUNT\n";
                cout << "\n\t\t\tEnter the amount to be deposited: ";
                cin >> amt;
                ac.dep(amt);
            }
            else if (option == 2)
            {
                cout << "\n\n\t\t\tTO WITHDRAW AMOUNT\n";
                cout << "\n\t\t\tEnter the amount to be withdrawn: ";
                cin >> amt;
                long int balance = ac.retdeposit() - amt;
                if (balance < 0)
                    cout << "\n\t\t\tInsufficient balance!";
                else
                    ac.draw(amt);
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout << "\n\n\t\t\tRecord Updated";
            found = true;
        }
    }
    file.close();
    if (!found)
        cout << "\n\n\t\t\tRecord Not Found!";
}

void display_account(long int n)
{
    account ac;
    ifstream infile;
    infile.open("Account.dat", ios::binary);
    if (!infile)
    {
        cout << "\n\t\t\tFile could not be opened! Press any key...";
        return;
    }

    bool flag = false;
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retacno() == n)
        {
            ac.show_account();
            flag = true;
        }
    }
    infile.close();
    if (!flag)
    {
        cout << "\n\n\t\t\tAccount number does not exist!";
    }
}
