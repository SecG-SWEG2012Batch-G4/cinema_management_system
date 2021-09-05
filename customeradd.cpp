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

int main()
{
    //editCustomers();

    return 0;
}
