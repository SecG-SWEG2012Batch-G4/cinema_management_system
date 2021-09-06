#include <iostream>
#include <string>
#include <iomanip>
#include <istream>
#include <windows.h>

using namespace std;

//
//Declaring Structures and Pointers
//

struct Movie
{
    string name, genre, director;
    float rating, price;
    string time_cinema[3];
    int seats;
};

int movieCount = 5;
Movie *movies{new Movie[movieCount]{{"The Avengers", "Action", "Russo Brothers", 9.9, 55.00, {"9:00 C1", "10:00 C3", "11:00 C2"}, 100},
                                    {"A Quiet Place", "Horror", "Russo Brothers", 9.9, 60.00, {"9:00 C1", "10:00 C3", "11:00 C2"}, 1},
                                    {"Fast 9", "Action", "Russo Brothers", 9.9, 70.00, {"9:00 C1", "10:00 C3", "11:00 C2"}, 75},
                                    {"Den of Thieves", "Adventure", "Russo Brothers", 9.9, 40.00, {"9:00 C1", "10:00 C3", "11:00 C2"}, 120},
                                    {"What Happedned", "Drama", "Russo Brothers", 9.9, 90.00, {"9:00 C1", "10:00 C3", "11:00 C2"}, 100}}};
Movie *n_movies = new Movie[movieCount];

struct Customer
{
    string name;
    int age;
    string phone, address, username, password;
};

int customerCount = 2;
Customer *customers{new Customer[customerCount]{{"Yohannes", 20, "09121212", "Bole", "yohannesakd", "yohannesakd"}, {"Abe", 22, "0912122522", "Be", "abe", "abe"}}};
Customer *n_customers = new Customer[customerCount];

struct Ticket
{
    string cust_name, mov_name, timeandcinema;
    int seat_no[10];
    int age, ticketCount;
    float totalCost;
};

int bookedTickets = 2;
Ticket *tickets{new Ticket[bookedTickets]{{"Wesagn", "The Avengers", "10:00 C2", {56, 57}, 21, 2, 200}, {"Fantish", "The Mnamn", "19:00 C3", {11, 23, 24}, 21, 3, 250}}};
Ticket *n_tickets = new Ticket[bookedTickets];

Ticket *newOrder = new Ticket;

string currentSession;
int loginIndex, ticketIndex;

string adminUname = "admin", adminPass = "admin";

//
//prototyping Functions
//
bool floatCheck(string);
void adminMenu();
void adminLogin();
void loginPage();
void customerMenu();
void customerLoginChoice();
void customerLogin();
void addBooked();
void displayMovies();
void inputTicket(Ticket, int);
void bookMovie();
void displayTicket();
void makeSeats(int);
void inputMovie(Movie, int);
void addMovie();
void deleteMovie();
void modMovies();
void displaycustomers();
void inputCustomer(Customer, int);
void addCustomer();
void deleteCustomer();
void deleteCustChoice();
void modCustomers();
void nullifyCustomerList();
void displayTicketList();
void deleteMovChoice();
void deleteAllMovie();
void displaySingleCustomer(int);
void displaySingleMovie();

int main()
{
    loginPage();
    return 0;
}
void displayTicketList()
{
    cout << left << setw(3) << "No"
         << setw(25) << "Customer Name"
         << setw(5) << "Age"
         << setw(25) << "Movie Name"
         << setw(10) << "Time and Cinema"
         << setw(5) << "Tickets Purchased"
         << setw(30) << "Seat No"
         << setw(2) << " " << setw(10) << "Total Cost" << endl;
    for (int i = 0; i < bookedTickets; i++)
    {
        cout << setw(3) << left << i + 1;
        cout << setw(25) << tickets[i].cust_name;
        cout << setw(5) << tickets[i].age;
        cout << setw(25) << tickets[i].mov_name;
        cout << setw(10) << tickets[i].timeandcinema;
        cout << setw(5) << tickets[i].ticketCount;
        for (int k = 0; k < tickets[i].ticketCount; k++)
        {

            cout << setw(5) << tickets[i].seat_no[k] << " | ";
        }
        cout << setw(12) << tickets[i].totalCost;
        cout << endl;
    }
}

void displayMovies()
{

    cout << left << setw(3) << "No"
         << setw(25) << "Name"
         << setw(10) << "Genre"
         << setw(20) << "Director"
         << setw(7) << "Rating"
         << setw(7) << "Price"
         << setw(30) << "Time and Cinema"
         << setw(2) << " " << setw(10) << "Available Seats" << endl;
    for (int i = 0; i < movieCount; i++)
    {
        cout << setw(3) << left << i + 1
             << setw(25) << movies[i].name
             << setw(10) << movies[i].genre
             << setw(20) << movies[i].director
             << setw(7) << movies[i].rating
             << setw(7) << movies[i].price
             << setw(8) << movies[i].time_cinema[0] << " | "
             << setw(8) << movies[i].time_cinema[1] << " | "
             << setw(8) << movies[i].time_cinema[2]
             << setw(2) << " " << setw(10) << movies[i].seats << endl;
    }
}

void displaySingleMovie(int i)
{
    cout << left << setw(3) << "No"
         << setw(25) << "Name"
         << setw(10) << "Genre"
         << setw(20) << "Director"
         << setw(7) << "Rating"
         << setw(7) << "Price"
         << setw(30) << "Time and Cinema"
         << setw(2) << " " << setw(10) << "Available Seats" << endl;

    cout << setw(3) << left << 1
         << setw(25) << movies[i].name
         << setw(10) << movies[i].genre
         << setw(20) << movies[i].director
         << setw(7) << movies[i].rating
         << setw(7) << movies[i].price
         << setw(8) << movies[i].time_cinema[0] << " | "
         << setw(8) << movies[i].time_cinema[1] << " | "
         << setw(8) << movies[i].time_cinema[2]
         << setw(2) << " " << setw(10) << movies[i].seats << endl;
    cout << endl;
}

void inputTicket(Ticket tickets[], int i)
{
    int mov, time, tcount, seatID[tcount];

    n_tickets[i].cust_name = customers[loginIndex].name;
    cout << endl
         << "Select a Movie: ";
    cin >> mov;
    mov--;

    n_tickets[i].mov_name = movies[mov].name;
    cout
        << setw(39) << "Time and Cinema" << endl
        << "1. " << setw(8) << movies[mov].time_cinema[0] << " | "
        << "2. " << setw(8) << movies[mov].time_cinema[1] << " | "
        << "3. " << setw(8) << movies[mov].time_cinema[2] << endl;
    cout << "Choose a time to Watch: ";
    cin >> time;
    time--;

    n_tickets[i].timeandcinema = movies[mov].time_cinema[time];
    cout << "How many Tickets would you like to purchase: ";
    cin >> tcount;

    n_tickets[i].ticketCount = tcount;
    n_tickets[i].age = customers[loginIndex].age;
    n_tickets[i].totalCost = movies[mov].price * tcount;

    for (int l = 0; l < tcount; l++)
    {
        cout << "Choose a seat";
        cin >> seatID[l];
        movies[mov].seats--;
    }

    for (int k = 0; (k < n_tickets[i].ticketCount); k++)
    {
        n_tickets[i].seat_no[k] = seatID[k];
    }
}

void bookMovie()
{
    cout << "started Booking " << endl;
    int y = 1;

    bookedTickets += y;
    delete[] n_tickets;
    n_tickets = new Ticket[bookedTickets];
    for (int i = 0; (i < bookedTickets - y); i++)
    {
        n_tickets[i].cust_name = tickets[i].cust_name;
        n_tickets[i].mov_name = tickets[i].mov_name;
        n_tickets[i].timeandcinema = tickets[i].timeandcinema;
        n_tickets[i].ticketCount = tickets[i].ticketCount;
        n_tickets[i].age = tickets[i].age;
        n_tickets[i].totalCost = tickets[i].totalCost;
        for (int k = 0; k < tickets[i].ticketCount; k++)
        {
            n_tickets[i].seat_no[k] = tickets[i].seat_no[k];
        }
    }
    cout << "Finished Copy" << endl;

    // for (int z = 0; z < (bookedTickets - y); z++)
    // {
    //     cout << n_tickets[z].cust_name << endl;
    //     cout << n_tickets[z].mov_name << endl;
    //     cout << n_tickets[z].timeandcinema << endl;
    //     cout << n_tickets[z].ticketCount << endl;
    //     cout << n_tickets[z].age << endl;
    //     cout << n_tickets[z].totalCost << endl;
    //     for (int k = 0; k < tickets[z].ticketCount; k++)
    //     {
    //         cout << n_tickets[z].seat_no[k] << ", ";
    //     }
    //     cout << endl;
    // }

    cout << "Taking new Inputs at index " << bookedTickets - y << endl;

    for (int i = 0; i < y; i++)
    {
        inputTicket(n_tickets, bookedTickets - y + i);
    }

    delete[] tickets;
    tickets = new Ticket[bookedTickets];

    for (int i = 0; i < bookedTickets; i++)
    {
        tickets[i].cust_name = n_tickets[i].cust_name;
        tickets[i].mov_name = n_tickets[i].mov_name;
        tickets[i].timeandcinema = n_tickets[i].timeandcinema;
        tickets[i].ticketCount = n_tickets[i].ticketCount;
        tickets[i].age = n_tickets[i].age;
        tickets[i].totalCost = n_tickets[i].totalCost;
        for (int k = 0; (k < n_tickets[i].ticketCount); k++)
        {
            tickets[i].seat_no[k] = n_tickets[i].seat_no[k];
        }
    }
    cout << "Successfully Added Ticket" << endl;
    for (int z = 0; z < (bookedTickets); z++)
    {
        cout << tickets[z].cust_name << endl;
        cout << tickets[z].mov_name << endl;
        cout << tickets[z].timeandcinema << endl;
        cout << tickets[z].ticketCount << endl;
        cout << tickets[z].age << endl;
        cout << tickets[z].totalCost << endl;
        for (int k = 0; k < tickets[z].ticketCount; k++)
        {

            cout << tickets[z].seat_no[k] << ", ";
        }
        cout << endl;
    }
    system("pause");
    customerMenu();
}

void displayTicket()
{
    for (int i = 0; i < bookedTickets; i++)
    {
        if (customers[loginIndex].name == tickets[i].cust_name)
        {
            cout << tickets[i].cust_name << endl;
            cout << tickets[i].mov_name << endl;
            cout << tickets[i].timeandcinema << endl;
            cout << tickets[i].ticketCount << endl;
            cout << tickets[i].age << endl;
            cout << tickets[i].totalCost << endl;
            for (int k = 0; k < tickets[i].ticketCount; k++)
            {

                cout << tickets[i].seat_no[k] << ", ";
            }
            cout << endl;
        }
        else
        {
            continue;
        }
    }

    system("pause");
    customerMenu();
}

// void displaynewMovies()
// {
//     cout << left << setw(3) << "No"
//          << setw(30) << "Name"
//          << setw(15) << "Genre"
//          << setw(30) << "Director"
//          << setw(10) << "Price"
//          << setw(10) << "Price"
//          << setw(20) << "time_cinemas" << endl;
//     for (int i = 0; i < movieCount; i++)
//     {
//         cout << setw(3) << left << i + 1
//              << setw(30) << n_movies[i].name
//              << setw(15) << n_movies[i].genre
//              << setw(30) << n_movies[i].director
//              << setw(10) << n_movies[i].rating
//              << setw(10) << n_movies[i].price
//              << setw(6) << n_movies[i].time_cinema[0] << "|"
//              << setw(6) << n_movies[i].time_cinema[1] << "|"
//              << setw(6) << n_movies[i].time_cinema[2] << endl;
//     }
// }
// int seats[100];

void makeSeats(int seats[])
{
    for (int i = 1; i < 101; i++)
    {
        seats[i] = i;
    }
}

void inputMovie(Movie movies[], int i = 0)
{
    cout << "Input Movie Info" << endl;
    cout << "------------------------" << endl;
    cout << "Enter Movie Name: ";
    getline(cin >> ws, movies[i].name);

    cout << "Enter Movie Genre: ";
    getline(cin >> ws, movies[i].genre);

    cout << "Enter Director: ";
    getline(cin >> ws, movies[i].director);

    cout << "Enter Movie Rating: ";
    cin >> movies[i].rating;

    cout << "Enter Price: ";
    cin >> movies[i].price;

    cout << "Enter Available Seats: ";
    cin >> movies[i].seats;

    for (int k = 0; k < 3; k++)
    {
        cout << "Enter Time and Cinema " << k + 1 << " : ";
        getline(cin >> ws, movies[i].time_cinema[k]);
    }
}

void addMovie()
{
    cout << "How many inputs: ";
    int j;
    cin >> j;

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
        n_movies[i].seats = movies[i].seats;
        for (int k = 0; k < 3; k++)
        {
            n_movies[i].time_cinema[k] = movies[i].time_cinema[k];
        }
    }

    for (int x = 0; x < j; x++)
    {
        inputMovie(n_movies, movieCount - j + x);
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
        movies[i].seats = n_movies[i].seats;
        for (int k = 0; k < 3; k++)
        {
            movies[i].time_cinema[k] = n_movies[i].time_cinema[k];
        }
    }
}

void deleteMovie()
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
            n_movies[n].seats = movies[z].seats;
            for (int l = 0; l < 3; l++)
            {
                n_movies[n].time_cinema[l] = movies[z].time_cinema[l];
            }
            n++;
        }
    }

    delete[] movies;
    movies = new Movie[movieCount];
    for (int p = 0; p < movieCount; p++)
    {
        movies[p].name = n_movies[p].name;
        movies[p].genre = n_movies[p].genre;
        movies[p].director = n_movies[p].director;
        movies[p].rating = n_movies[p].rating;
        movies[p].price = n_movies[p].price;
        movies[p].seats = n_movies[p].seats;
        for (int q = 0; q < 3; q++)
        {
            movies[p].time_cinema[q] = n_movies[p].time_cinema[q];
        }
    }

    cout << "Movie Successfully Deleted, Going Back to Menu" << endl;
    Sleep(2000);
}

void editMovie(int i)
{
    string choice;
    system("cls");
    displaySingleMovie(i);
    cout << "Which attribute would you like to modify: " << endl
         << "1. Name" << endl
         << "2. Genre" << endl
         << "3. Director" << endl
         << "4. Price" << endl
         << "5. Rating" << endl
         << "6. Time and Cinema" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                cout << "Enter the new value: ";
                getline(cin >> ws, movies[i].name);
                cout << "Value Successfully Changed, Going back to menu";
                Sleep(1000);
                modMovies();
            }
            else if (choice == "2")
            {
                cout << "Enter the new value: ";
                getline(cin >> ws, movies[i].genre);
                cout << "Value Successfully Changed, Going back to menu";
                Sleep(1000);
                modMovies();
            }
            else if (choice == "3")
            {
                cout << "Enter the new value: ";
                getline(cin >> ws, movies[i].director);
                cout << "Value Successfully Changed, Going back to menu";
                Sleep(1000);
                modMovies();
            }
            else if (choice == "4")
            {
                cout << "Enter the new value: ";
                cin >> movies[i].price;
                cout << "Value Successfully Changed, Going back to menu";
                Sleep(1000);
                modMovies();
            }
            else if (choice == "5")
            {
                cout << "Enter the new value: ";
                cin >> movies[i].rating;
                cout << "Value Successfully Changed, Going back to menu";
                Sleep(1000);
                modMovies();
            }
            else if (choice == "6")
            {
                cout << "Enter the new values: ";
                for (int j = 0; j < 3; j++)
                {
                    getline(cin >> ws, movies[i].time_cinema[j]);
                    cout << endl;
                }
                cout << "Value Successfully Changed, Going back to menu";
                Sleep(1000);
                modMovies();
            }
            else
                cout << "Please Enter a Valid Number" << endl;
            continue;
        }
    }
}

void modMovies()
{
    system("cls");
    displayMovies();
    string choice;
    cout << "Select an action" << endl
         << "1. Add movie" << endl
         << "2. Delete movie" << endl
         << "3. Edit Movies" << endl
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
                modMovies();
                break;
            }
            else if (choice == "2")
            {
                system("cls");
                deleteMovChoice();
                break;
            }
            else if (choice == "3")
            {
                int i;
                cout << "Choose a Movie: ";
                cin >> i;
                i--;
                editMovie(i);
                modMovies();
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

void displaySingleCustomer(int i)
{
    cout << left << setw(3) << "No"
         << setw(30) << "Name"
         << setw(15) << "Age"
         << setw(30) << "Phone"
         << setw(10) << "Address"
         << endl;
    cout << setw(3) << left << i + 1
         << setw(30) << customers[i].name
         << setw(15) << customers[i].age
         << setw(30) << customers[i].phone
         << setw(10) << customers[i].address
         << endl
         << endl;
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
    getline(cin >> ws, customers[i].address);

    cout << "Enter Username: ";
    getline(cin >> ws, customers[i].username);

    cout << "Enter Password: ";
    getline(cin >> ws, customers[i].password);
}

void addCustomer()
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
}

void deleteCustomer()
{
    system("cls");
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

    cout << "Customer Successfully Removed, Going Back to Menu" << endl;
    Sleep(2000);
}

void nullifyCustomerlist()
{
    delete[] customers;
    customerCount = 0;
    customers = new Customer[customerCount];

    cout << "Successfully Deleted all Entries, Going back to menu" << endl;
    Sleep(2000);
    modCustomers();
}

void nullifyMovieList()
{
    delete[] movies;
    movieCount = 0;
    movies = new Movie[movieCount];

    cout << "Successfully Deleted all Entries, Going back to menu" << endl;
    Sleep(2000);
    modMovies();
}

void deleteAllCustomer()
{
    string choice;
    cout
        << "Are you sure you want to remove all entries?" << endl
        << "1. Yes" << endl
        << "2. No" << endl;
    while (true)
    {
        cout << "Enter your Choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                nullifyCustomerlist();
                break;
            }
            else if (choice == "2")
            {
                deleteCustChoice();
                system("pause");
                modCustomers();
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

void deleteAllMovie()
{
    string choice;
    cout
        << "Are you sure you want to remove all entries?" << endl
        << "1. Yes" << endl
        << "2. No" << endl;
    while (true)
    {
        cout << "Enter your Choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                nullifyMovieList();
                break;
            }
            else if (choice == "2")
            {
                deleteMovChoice();
                system("pause");
                modMovies();
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

void deleteCustChoice()
{
    system("cls");
    string choice;
    cout << "Select a Delete Option" << endl;
    cout << "1. Single Entry" << endl
         << "2. All Entries" << endl
         << "3. Back" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                deleteCustomer();
                modCustomers();
                break;
            }
            else if (choice == "2")
            {
                deleteAllCustomer();
                cout << "All Entries Successfully deleted";
                Sleep(2000);
                modCustomers();
                break;
            }
            else if (choice == "3")
            {
                modCustomers();
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

void deleteMovChoice()
{
    system("cls");
    string choice;
    cout << "Select a Delete Option" << endl;
    cout << "1. Single Entry" << endl
         << "2. All Entries" << endl
         << "3. Back" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                deleteMovie();
                modMovies();
                break;
            }
            else if (choice == "2")
            {
                deleteAllMovie();
                cout << "All Entries Successfully deleted";
                Sleep(2000);
                modMovies();
                break;
            }
            else if (choice == "3")
            {
                modMovies();
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

void editCustomer(int i)
{
    string choice;
    system("cls");
    displaySingleCustomer(i);
    cout << "Which attribute would you like to modify: " << endl
         << "1. Name" << endl
         << "2. Age" << endl
         << "3. Address" << endl
         << "4. Phone Number" << endl
         << "5. Username" << endl
         << "6. Password" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                cout << "Enter the new value: ";
                getline(cin >> ws, customers[i].name);
                cout << "Value Successfully Changed, Going back to menu";
                Sleep(1000);
                modCustomers();
            }
            else if (choice == "2")
            {
                cout << "Enter the new value: ";
                cin >> customers[i].age;
                cout << "Value Successfully Changed, Going back to menu";
                Sleep(1000);
                modCustomers();
            }
            else if (choice == "3")
            {
                cout << "Enter the new value: ";
                getline(cin >> ws, customers[i].address);
                cout << "Value Successfully Changed, Going back to menu";
                Sleep(1000);
                modCustomers();
            }
            else if (choice == "4")
            {
                cout << "Enter the new value: ";
                cin >> customers[i].phone;
                cout << "Value Successfully Changed, Going back to menu";
                Sleep(1000);
                modCustomers();
            }
            else if (choice == "5")
            {
                cout << "Enter the new value: ";
                getline(cin >> ws, customers[i].username);
                cout << "Value Successfully Changed, Going back to menu";
                Sleep(1000);
                modCustomers();
            }
            else if (choice == "6")
            {
                cout << "Enter the new value: ";
                getline(cin >> ws, customers[i].password);
                cout << "Value Successfully Changed, Going back to menu";
                Sleep(1000);
                modCustomers();
            }
            else
                cout << "Please Enter a Valid Number" << endl;
            continue;
        }
    }
}

void modCustomers()
{
    system("cls");
    displaycustomers();
    string choice;
    cout << "Select an Action" << endl
         << "1. Add customer" << endl
         << "2. Delete customer" << endl
         << "3. Edit customers" << endl
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
                modCustomers();
                break;
            }
            else if (choice == "2")
            {
                system("cls");
                deleteCustChoice();
                break;
            }
            else if (choice == "3")
            {
                int i;
                cout << "Choose a Customer: ";
                cin >> i;
                i--;
                editCustomer(i);
                modCustomers();
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
            cout << "Login Successful, Redirecting" << endl;
            cout << "| # - - - - - - - - |";
            Sleep(500);
            system("cls");
            cout << "Login Successful, Redirecting" << endl;
            cout << "| # # # # # # # # # |";
            Sleep(250);
            customerMenu();
        }
        else
        {
            cout << "Invalid Credentials, Try Again" << endl;
            continue;
        }

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
            cout << "Invalid Credentials, Try Again" << endl;
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
         << "3. Ticket List" << endl
         << "4. Logout" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                modCustomers();
                break;
            }
            else if (choice == "2")
            {
                modMovies();
                break;
            }
            else if (choice == "3")
            {
                displayTicketList();
                system("pause");
                adminMenu();
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
                displayMovies();
                bookMovie();
                system("pause");
                customerMenu();
                break;
            }
            else if (choice == "2")
            {
                displayMovies();
                system("pause");
                customerMenu();
                break;
            }
            else if (choice == "3")
            {
                displayTicket();
                system("pause");
                customerMenu();
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