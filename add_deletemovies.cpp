#include <iostream>
#include <string>
#include <iomanip>
#include <istream>

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

struct Movie
{
    string name, genre, director;
    float rating, price;
    int showtime[3];
};

int movieCount = 5;
Movie *movies = new Movie[movieCount];
Movie *n_movies = new Movie[movieCount];

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

void addMovies()
{
    static int count = 0;

    cout << "How many inputs: ";
    if (count++ == 0)
    {
        //initializeMovies();
    }
    else
    {
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
void displaynewMovies()
{/*

    cout << left << setw(3) << "No"
         << setw(30) << "Name"
         << setw(15) << "Genre"
         << setw(30) << "Director"
         << setw(10) << "Price"
         << setw(10) << "Price"
         << setw(20) << "Showtimes" << endl;
    for (int i = 0; i < movieCount; i++)
    {
        cout << setw(3) << left << i + 1
             << setw(30) << n_movies[i].name
             << setw(15) << n_movies[i].genre
             << setw(30) << n_movies[i].director
             << setw(10) << n_movies[i].rating
             << setw(10) << n_movies[i].price
             << setw(6) << n_movies[i].showtime[0] << "|"
             << setw(6) << n_movies[i].showtime[1] << "|"
             << setw(6) << n_movies[i].showtime[2] << endl;
    }
}
*/
}
void editMovies()
{
    system("cls");
    string choice;
    cout << "VELCOME" << endl
         << "1. Add movie" << endl
         << "2. Delete movie" << endl
         << "3. Show Movies" << endl
         << "4. Exit" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                addMovies();
                system("cls");
                editMovies();
                break;
            }
            else if (choice == "2")
            {
                system("cls");
                deleteMovies();
                displayMovies();
                Sleep(10000);
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


    return 0;
}
