#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool floatCheck(string a)
{ // Checks whether a given string contains a float or not

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
void loginPage();
void customerLoginChoice();
void customerMenu();
void adminMenu();
void movieList()
{
    cout << "Incomplete";
}
void customerList()
{
    string choice;
    cout << "Incomplete" << endl;
    cout << "Enter Information" << endl
         << "0. Back" << endl;
    cin >> choice;
    if (choice == "0")
    {
        adminMenu();
    }
} //Incomplete
void adminList()
{
    string choice;
    cout << "Incomplete" << endl;
    cout << "Enter Information" << endl
         << "0. Back" << endl;
    cin >> choice;
    if (choice == "0")
    {
        adminMenu();
    }
} //Incomplete
void bookMovie()
{
    cout << "Incomplete";
} //Incomplete
void adminMovieList()
{
    string choice;
    cout << "Incomplete" << endl;
    cout << "Enter Information" << endl
         << "0. Back" << endl;
    cin >> choice;
    if (choice == "0")
    {
        adminMenu();
    }
} //Incomplete
void custStatus()
{
    cout << "Incomplete";
} //Incomplete

string custUname = "user",
       custPass = "user";
string adminUname = "admin", adminPass = "admin";

void customerLogin()
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
void registerCustomer() //Incomplete
{
    string choice;
    system("cls");
    cout << "Enter Information" << endl
         << "0. Back" << endl;
    cin >> choice;
    if (choice == "0")
    {
        customerLoginChoice();
    }
}
void adminLogin()
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
            loginPage();
        }
        cout << "Enter your Password: ";
        cin >> pass;
        if (pass == "0")
        {
            loginPage();
        }

        if (uName == adminUname && pass == adminPass)
        {
            adminMenu();
            break;
        }
        else
        {
            cout << "Invalid Credentials, Try Again";
            continue;
        }
    }
}
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
                registerCustomer();
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

void adminMenu()
{
    string choice;
    system("cls");
    cout << "Welcome to the Admin Page" << endl
         << "1. Movie List" << endl
         << "2. Customer List" << endl
         << "3. Admin List" << endl
         << "4. Logout" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                adminMovieList();
                break;
            }
            else if (choice == "2")
            {
                customerList();
                break;
            }
            else if (choice == "3")
            {
                adminList();
                break;
            }
            else if (choice == "4")
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
void customerMenu()
{
    string choice;
    system("cls");
    cout << "Welcome to the Customer Page" << endl
         << "1. Book a Movie" << endl
         << "2. Show Movies List" << endl
         << "3. Show My Status" << endl
         << "4. Logout" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                bookMovie();
                break;
            }
            else if (choice == "2")
            {
                movieList();
                break;
            }
            else if (choice == "3")
            {
                custStatus();
                break;
            }
            else if (choice == "4")
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
                adminLogin();
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

/*

    #include <iostream>
    #include <string>

    using namespace std;
    void askForSecretPassword(void){
    	string password;
    	cout<<"Enter your password: ";
    	cin>>password;
    	int len=password.length();
    	system("cls");
    	cout<<"Enter numeric password: ";
    	for(int i=0;i<len;i++){
    		cout<<"*";
    	}cout<<endl;
    };
    void main(){

    	askForSecretPassword();
    	system("pause");

    }

*/
