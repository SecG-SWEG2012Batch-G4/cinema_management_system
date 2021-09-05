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

//
//Declaring Structures and Pointers
//

struct Movie
{
    string name, genre, director;
    float rating, price;
    int showtime[3];
};

int movieCount = 5;
Movie *movies = new Movie[movieCount];
Movie *n_movies = new Movie[movieCount];

struct Customer
{
    string name;
    int age;
    string phone, address, username, password;
};

int customerCount = 2;
Customer *customers = new Customer[customerCount];
Customer *n_customers = new Customer[customerCount];

struct Ticket
{
    string cust_name, mov_name, time, seat_no;
    int ticketCount;
    float totalCost;
};

int bookedTickets = 1;
Ticket *tickets = new Ticket[bookedTickets];
Ticket *n_tickets = new Ticket[bookedTickets];

Ticket *newOrder = new Ticket;

string currentSession;

//
//Prototyping Functions
//
void adminMenu();
void loginPage();
void customerMenu();
void loginPage();
void customerLoginChoice();

//
// ////////////////////
//
void displayMovies()
{

    cout << left << setw(3) << "No"
         << setw(30) << "Name"
         << setw(15) << "Genre"
         << setw(30) << "Director"
         << setw(10) << "Rating4"
         << setw(10) << "Price"
         << setw(20) << "Showtimes" << endl;
    for (int i = 0; i < movieCount; i++)
    {
        cout << setw(3) << left << i + 1
             << setw(30) << movies[i].name
             << setw(15) << movies[i].genre
             << setw(30) << movies[i].director
             << setw(10) << movies[i].rating
             << setw(10) << movies[i].price
             << setw(6) << movies[i].showtime[0] << "|"
             << setw(6) << movies[i].showtime[1] << "|"
             << setw(6) << movies[i].showtime[2] << endl;
    }
}

void bookMovie()
{
    cout << "incomplete";
    Sleep(2000);
    customerMenu;
}

// void displaynewMovies()
// {
//     cout << left << setw(3) << "No"
//          << setw(30) << "Name"
//          << setw(15) << "Genre"
//          << setw(30) << "Director"
//          << setw(10) << "Price"
//          << setw(10) << "Price"
//          << setw(20) << "Showtimes" << endl;
//     for (int i = 0; i < movieCount; i++)
//     {
//         cout << setw(3) << left << i + 1
//              << setw(30) << n_movies[i].name
//              << setw(15) << n_movies[i].genre
//              << setw(30) << n_movies[i].director
//              << setw(10) << n_movies[i].rating
//              << setw(10) << n_movies[i].price
//              << setw(6) << n_movies[i].showtime[0] << "|"
//              << setw(6) << n_movies[i].showtime[1] << "|"
//              << setw(6) << n_movies[i].showtime[2] << endl;
//     }
// }

void inputMovie(Movie movies[], int i = 0)
{
    cout << "Input Movie Info" << endl;
    cout << "------------------------" << endl;
    cout << "ENTER MOVIE NAME: ";
    getline(cin >> ws, movies[i].name);

    cout << "ENTER MOVIE GENRE: ";
    getline(cin >> ws, movies[i].genre);

    cout << "ENTER MOVIE DIRECTOR: ";
    getline(cin >> ws, movies[i].director);

    cout << "ENTER MOVIE RATING: ";
    cin >> movies[i].rating;

    cout << "ENTER MOVIE PRICE: ";
    cin >> movies[i].price;

    for (int k = 0; k < 3; k++)
    {
        cout << "ENTER SHOWTIME " << k << " : ";
        cin >>
            movies[i].showtime[k];
    }
}

//
//Default input of Movies
//

Movie initialMov[5] = {{"The Avengers", "Action", "Russo Brothers", 9.9, 55.00, {900, 1000, 1100}}, {"A Quiet Place", "Horror", "Russo Brothers", 9.9, 60.00, {1200, 1300, 1400}}, {"Fast and Furious", "Action", "Russo Brothers", 9.9, 70.00, {1500, 1600, 1700}}, {"Den of Thieves", "Adventure", "Russo Brothers", 9.9, 40.00, {1800, 1900, 2000}}, {"What Happedned to Monday", "Drama", "Russo Brothers", 9.9, 90.00, {2100, 2200, 2300}}};

void initializeMovies()
{
    for (int i = 0; i < movieCount; i++)
    {
        movies[i].name = initialMov[i].name;
        movies[i].genre = initialMov[i].genre;
        movies[i].director = initialMov[i].director;
        movies[i].rating = initialMov[i].rating;
        movies[i].price = initialMov[i].price;
        for (int k = 0; k < 3; k++)
        {
            movies[i].showtime[k] = initialMov[i].showtime[k];
        }
    }
}

void addMovie()
{
    // cout << "How many inputs: ";
    static int count = 0;

    if (count++ == 0)
    {
        initializeMovies();
    }
    else
    {
        cout << "How many inputs: ";
        int j;
        cin >> j;
        cout << endl
             << "Adding Amount " << j << "\n";

        movieCount += j;
        delete[] n_movies;
        n_movies = new Movie[movieCount];
        for (int i = 0; i < (movieCount - j); i++)
        {
            n_movies[i].name = movies[i].name;
            n_movies[i].genre = movies[i].genre;
            n_movies[i].director = movies[i].director;
            n_movies[i].rating = movies[i].rating;
            n_movies[i].price = movies[i].price;
            for (int k = 0; k < 3; k++)
            {
                n_movies[i].showtime[k] = movies[i].showtime[k];
            }
        }

        for (int i = 0; i < j; i++)
        {
            cout << endl
                 << "Taking new Inputs at index " << movieCount - j + i << endl;

            inputMovie(n_movies, movieCount - j + i);
        }
        delete[] movies;
        movies = new Movie[movieCount];

        for (int i = 0; i < movieCount; i++)
        {
            movies[i].name = n_movies[i].name;
            movies[i].genre = n_movies[i].genre;
            movies[i].director = n_movies[i].director;
            movies[i].rating = n_movies[i].rating;
            movies[i].price = n_movies[i].price;
            for (int k = 0; k < 3; k++)
            {
                movies[i].showtime[k] = n_movies[i].showtime[k];
            }
        }

        delete[] n_movies;
    }
}
void deleteMovies()
{
    displayMovies();
    int m, temp, n = 0;
    cout << endl
         << "Which Movie index would you like to delete: ";
    cin >> m;
    m--;
    temp = movieCount;
    movieCount--;
    delete[] n_movies;
    n_movies = new Movie[movieCount];

    cout << endl
         << "first step pass"
         << endl;

    for (int z = 0; z < temp; z++)
    {
        if (z != m)
        {
            n_movies[n].name = movies[z].name;
            n_movies[n].genre = movies[z].genre;
            n_movies[n].director = movies[z].director;
            n_movies[n].rating = movies[z].rating;
            n_movies[n].price = movies[z].price;
            for (int l = 0; l < 3; l++)
            {
                n_movies[n].showtime[l] = movies[z].showtime[l];
            }
            n++;
        }
    }

    cout << "second step pass"
         << endl;

    delete[] movies;
    movies = new Movie[movieCount];
    for (int p = 0; p < movieCount; p++)
    {
        movies[p].name = n_movies[p].name;
        movies[p].genre = n_movies[p].genre;
        movies[p].director = n_movies[p].director;
        movies[p].rating = n_movies[p].rating;
        movies[p].price = n_movies[p].price;
        for (int q = 0; q < 3; q++)
        {
            movies[p].showtime[q] = n_movies[p].showtime[q];
        }
    }

    cout << "completed"
         << endl;

    cout << "Movie Successfully Deleted, Going Back to Menu" << endl;
    Sleep(2000);
}

void editMovies()
{
    system("cls");
    string choice;
    cout << "VELCOME" << endl
         << "1. Add movie" << endl
         << "2. Delete movie" << endl
         << "3. Show Movies" << endl
         << "4. Back" << endl
         << "5. Exit" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                addMovie();
                system("cls");
                editMovies();
                break;
            }
            else if (choice == "2")
            {
                system("cls");
                deleteMovies();
                displayMovies();
                Sleep(3000);
                editMovies();
                break;
            }
            else if (choice == "3")
            {
                displayMovies();
                system("pause");
                editMovies();
                break;
            }
            else if (choice == "4")
            {
                adminMenu();
                break;
            }
            else if (choice == "5")
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

Customer initialCust[2] = {{"Yohannes", 20, "09121212", "Bole", "yohannesakd", "yohannesakd"}, {"Abe", 22, "0912122522", "Be", "abe", "abe"}};

void initializeCustomers()
{
    for (int i = 0; i < customerCount; i++)
    {
        customers[i].name = initialCust[i].name;
        customers[i].age = initialCust[i].age;
        customers[i].phone = initialCust[i].phone;
        customers[i].address = initialCust[i].address;
        customers[i].username = initialCust[i].username;
        customers[i].password = initialCust[i].password;
    }
}
/*
void addcustomers()
{
    // cout << "How many inputs: ";
    static int count = 0;

    if (count++ == 0)
    {
        initializeCustomers();
    }
    else
    {
        customerCount++;
        delete[] n_customers;
        n_customers = new Customer[customerCount];
        for (int i = 0; i < (customerCount - 1); i++)
        {
            n_customers[i].name = customers[i].name;
            n_customers[i].age = customers[i].age;
            n_customers[i].phone = customers[i].phone;
            n_customers[i].address = customers[i].address;
            n_customers[i].username = customers[i].username;
            n_customers[i].password = customers[i].password;
        }
        cout << endl
             << "Taking new Inputs at index " << customerCount << endl;

        inputCustomer(n_customers, customerCount);

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
*/
void addCustomer()
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
         << "4. Back" << endl
         << "5. Exit" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                addCustomer();
                system("cls");
                editCustomers();
                break;
            }
            else if (choice == "2")
            {
                system("cls");
                deletecustomers();
                displaycustomers();
                Sleep(3000);
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
                adminMenu();
                break;
            }
            else if (choice == "5")
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

string custUname = "user",
       custPass = "user";
string adminUname = "admin", adminPass = "admin";

void customerLogin()
{
    string uName, pass;
    int loginIndex;
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

        for (int i = 0; i < customerCount; i++)
        {
            if (uName == customers[i].username)
            {
                loginIndex = i;
                break;
            }
        }

        cout << "Enter your Password: ";
        cin >> pass;
        if (pass == "0")
        {
            customerLoginChoice();
        }
        if (pass == customers[loginIndex].password)
        {
            currentSession = uName;
            system("cls");
            cout << "Login Successful, Redirecting";
            Sleep(1000);
            customerMenu();
        }
        else
        {
            cout << "Invalid Credentials, Try Again";
            continue;
        }

        //     if (pass == customers[loginIndex].password)
        //     {
        //         {
        //             currentSession = uName;
        //             customerMenu();
        //             break;
        //         }
        //     }
        // else
        // {
        //     cout << "Wrong Credentials, Try Again!" << endl;
        //     break;
        // }

        system("pause");
        customerLogin();
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
    system("cls");
    cout
        << "1. Registered Customer" << endl
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
                addCustomer();
                cout << "Customer Successfully Registered, Please Login";
                Sleep(2000);
                system("cls");
                customerLogin();
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
         << "1. Customer List" << endl
         << "2. Movie List" << endl
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
                editCustomers();
                break;
            }
            else if (choice == "2")
            {
                editMovies();
                break;
            }
            else if (choice == "3")
            {
                //adminList();
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

    cout << "\t\t\t\t\t\t\t"
         << "User: " << currentSession << endl;

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
                displayMovies();
                break;
            }
            else if (choice == "3")
            {
                //custStatus();
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
    addMovie();
    addCustomer();
    loginPage();

    return 0;
}
