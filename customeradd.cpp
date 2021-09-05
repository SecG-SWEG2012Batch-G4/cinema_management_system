#include <iostream>
#include <string>
#include <iomanip>
#include <istream>
#include <windows.h>

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

struct Customer
{
    string name;
    int age;
    string phone, address, username, password;
};

int customerCount = 1;
Customer *customers = new Customer[customerCount];
Customer *n_customers = new Customer[customerCount];

void displaycustomers()
{

    cout << left << setw(3) << "No"
         << setw(30) << "Name"
         << setw(15) << "Age"
         << setw(30) << "Phone"
         << setw(10) << "Address"
         << endl;
    for (int i = 0; i < customerCount; i++)
    {
        cout << setw(3) << left << i + 1
             << setw(30) << customers[i].name
             << setw(15) << customers[i].age
             << setw(30) << customers[i].phone
             << setw(10) << customers[i].address
             << endl;
    }
}

void inputCustomer(Customer customers[], int i = 0)
{
    cout << "Input Customer Info" << endl;
    cout << "------------------------" << endl;
    cout << "Enter name: ";
    getline(cin >> ws, customers[i].name);

    cout << "Enter Age: ";
    cin >> customers[i].age;

    cout << "Enter Phone: ";
    cin >> customers[i].phone;

    cout << "Enter Address: ";
    cin >> customers[i].address;

    cout << "Enter Username: ";
    getline(cin >> ws, customers[i].username);

    cout << "Enter Password: ";
    getline(cin >> ws, customers[i].password);
}

Customer initial[1] = {{"Yohannes", 20, "09121212", "Bole", "yohannesakd", "yohannesakd"}};

void initializeCustomers()
{
    for (int i = 0; i < customerCount; i++)
    {
        customers[i].name = initial[i].name;
        customers[i].age = initial[i].age;
        customers[i].phone = initial[i].phone;
        customers[i].address = initial[i].address;
        customers[i].username = initial[i].username;
        customers[i].password = initial[i].password;
    }
}

void addCustomers()
{
    static int count = 0;

    if (count++ == 0)
    {
        initializeCustomers();
    }
    else
    {
        int j = 1;

        customerCount += j;
        delete[] n_customers;
        n_customers = new Customer[customerCount];
        for (int i = 0; i < (customerCount - j); i++)
        {
            n_customers[i].name = customers[i].name;
            n_customers[i].age = customers[i].age;
            n_customers[i].phone = customers[i].phone;
            n_customers[i].address = customers[i].address;
            n_customers[i].username = customers[i].username;
            n_customers[i].password = customers[i].password;
        }

        for (int i = 0; i < j; i++)
        {
            cout << endl
                 << "Taking new Inputs at index " << customerCount - j + i << endl;

            inputCustomer(n_customers, customerCount - j + i);
        }
        delete[] customers;
        customers = new Customer[customerCount];

        for (int i = 0; i < customerCount; i++)
        {
            customers[i].name = n_customers[i].name;
            customers[i].age = n_customers[i].age;
            customers[i].phone = n_customers[i].phone;
            customers[i].address = n_customers[i].address;
            customers[i].username = n_customers[i].username;
            customers[i].password = n_customers[i].password;
        }

        delete[] n_customers;
    }
}

void deletecustomers()
{
    displaycustomers();
    int m, temp, n = 0;
    cout << endl
         << "Which Customer would you like to remove: ";
    cin >> m;
    m--;
    temp = customerCount;
    customerCount--;
    delete[] n_customers;
    n_customers = new Customer[customerCount];

    cout << endl
         << "first step pass"
         << endl;

    for (int z = 0; z < temp; z++)
    {
        if (z != m)
        {
            n_customers[n].name = customers[z].name;
            n_customers[n].age = customers[z].age;
            n_customers[n].phone = customers[z].phone;
            n_customers[n].address = customers[z].address;
            n_customers[n].username = customers[z].username;
            n_customers[n].password = customers[z].password;
            n++;
        }
    }

    cout << "second step pass"
         << endl;

    delete[] customers;
    customers = new Customer[customerCount];
    for (int p = 0; p < customerCount; p++)
    {
        customers[p].name = n_customers[p].name;
        customers[p].age = n_customers[p].age;
        customers[p].phone = n_customers[p].phone;
        customers[p].address = n_customers[p].address;
        customers[p].username = n_customers[p].username;
        customers[p].password = n_customers[p].password;
    }

    cout << "completed"
         << endl;

    cout << "Customer Successfully Removed, Going Back to Menu" << endl;
    Sleep(2000);
}
void editCustomers()
{
    system("cls");
    string choice;
    cout << "VELCOME" << endl
         << "1. Add customer" << endl
         << "2. Delete customer" << endl
         << "3. Show customers" << endl
         << "4. Exit" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                addCustomers();
                system("cls");
                editCustomers();
                break;
            }
            else if (choice == "2")
            {
                system("cls");
                deletecustomers();
                displaycustomers();
                Sleep(10000);
                editCustomers();
                break;
            }
            else if (choice == "3")
            {
                displaycustomers();
                system("pause");
                editCustomers();
                break;
            }
            else if (choice == "4")
            {
                exit(0);
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
    editCustomers();

    return 0;
}
