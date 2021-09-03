#include <iostream>
#include <string>
#include <iomanip>
sing namespace std;

void loginPage();
void customerLoginChoice();
void customerMenu();
void adminMenu();
void movieList()

bool floatCheck(string a)
{ // Checks whether a given string contains a float or not

 void customerLoginChoice()
{
    string choice;
    cout << "1. Registered Customer" << endl
         << "2. New Customer" << endl
         << "3. Back" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                customerLogin();
                break;
            }
            else if (choice == "2")
            {
                //registerCustomer();
                break;
            }
            else if (choice == "3")
            {
                loginPage();
                break;
            }
            else
                cout << "Please Enter a Valid Number" << endl;
            continue;
        }
        else
        {
            cout << "Please Enter a Number" << endl;
            continue;
        }
    }
}

   oid customerLogin()
{
    string uName, pass;
    system("cls");
    cout << "Enter Credentials" << endl;
    while (true)
    {
        cout << "0. Back" << endl
             << endl;
        cout << "Enter your Username: ";
        cin >> uName;
        if (uName == "0")
        {
            customerLoginChoice();
        }
        cout << "Enter your Password: ";
        cin >> pass;
        if (pass == "0")
        {
            customerLoginChoice();
        }

        if (uName == custUname && pass == custPass)
        {
            customerMenu();
            break;
        }
        else
        {
            cout << "Invalid Credentials, Try Again";
            continue;
        }
    }
}
 void loginPage()
{
    string choice;
    system("cls");
    cout << "Welcome to this Cinema" << endl
         << "1.Customer" << endl
         << "2.Admin" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                customerLoginChoice();
                break;
            }
            else if (choice == "2")
            {
                //adminLogin();
                break;
            }
            else
                cout << "Please Enter a Valid Number" << endl;
            continue;
        }
        else
        {
            cout << "Please Enter a Number" << endl;
            continue;
        }
    }
}

    int main()
{
    loginPage();
    return 0;
}

    int len = 0;

    for (int j = 0; a[j]; j++)
    {
        len++;
    }

    for (int i = 0; a[i]; i++)
    {

        if ((int(a[i]) > 58 || int(a[i]) < 48) && int(a[i]) != 46)
        {
            return false;
        }
        if (i == len - 1)
        {
            if ((int(a[i]) < 58 && int(a[i]) >= 48))
            {
                return true;
            }
        }
    }
    return true;
}
