#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int shownum = 3;

struct Movie
{
    string name, genre, director;
    float rating, price;
    int showtime[3];
};



struct Customer
{
    string name;
    int age;
    string phone, address, username, password;
};

struct Ticket
{
    string cust_name, mov_name, time, seat_no;
    int ticketCount;
    float totalCost;
};

int showcount = 9;

Movie showingNow[9] = {
    {"The Avengers", "Action", 9.9, 55.00, {900, 1000, 1100}},
    {"A Quiet Place", "Horror", 9.9, 60.00, {1200, 1300, 1400}},
    {"Fast and Furious", "Action", 9.9, 70.00, {1500, 1600, 1700}},
    {"Den of Thieves", "Adventure", 9.9, 40.00, {1800, 1900, 2000}},
    {"What Happedned to Monday", "Drama", 9.9, 90.00, {2100, 2200, 2300}},
    {"Moana", "Animation", 9.9, 65.00, {100, 200, 300}},
    {"The Nun", "Horror", 9.9, 75.00, {400, 500, 600}},
    {"The Hundred", "Sci-Fi", 9.9, 85.00, {700, 800, 900}},
    {"Project X", "Drama", 9.9, 55.00, {1000, 1100, 1200}},
};

void listMovies()
{
    cout << left << setw(3) << "No" << setw(30) << "Name" << setw(15) << "Genre" << setw(10) << "Price" << setw(20) << "Showtimes" << endl;
    for (int i = 0; i < showcount; i++)
    {
        cout << setw(3) << left << i + 1 << setw(30) << showingNow[i].name << setw(15) << showingNow[i].genre << setw(10) << showingNow[i].price << setw(6) << showingNow[i].showtime[0] << "|" << setw(6) << showingNow[i].showtime[1] << "|" << setw(6) << showingNow[i].showtime[2] << endl;
    }
}
void bookMovie()
{
    int movieChoice;
    cout << "Select a Movie: ";
    cin >> movieChoice;
    movieChoice--;
}
void newOrder()
{
    int ticketAmount;
}
void customers()
{
}

int main()
{
    //loginPage();
    // mainMenu();
    return 0;
}
