#include <iostream>
#include <string>
#include <iomanip>
#include <istream>

using namespace std;

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