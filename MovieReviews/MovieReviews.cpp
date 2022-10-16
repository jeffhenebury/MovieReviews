/*
The problem :

Make a program to track what movies I’ve watched, what rating I give them, and automatically logs when I watched it(the day of entry)
The program :

Make a Movie class, which holds the movie’s title, the name of the director, my rating of the movie, and the time and date when the movie was added.
Make a vector called Movies that holds all of the created Movies.
Create a user input method to add the details in, create a new Movie, and add it into the vector

Biggest learning :

Automatically getting the current date in C++ felt really I remember that in Python, it’s quite simple, as seen in this article from programiz.com.In C++, there are a number of steps, and the solution that finally worked for me seems precarious; you basically have to turn off a security warning because of pointer risks.That does not seem like a good long - term solution!If anyone has used a better method, I’d love to hear it.
*/

#include <iostream>
#include <string>
#include <istream>
#include <ctime> // this lets you do date and time functions
#include <chrono> //// ...so does this one, didn't really work?
#include <string.h>
#include <vector>
//#pragma warning(disable : 4996)    //have to do this to get ctime to work... which doesn't seem great!
using namespace std;

class Movie {    //create a Movie class
public:
    string title;
    struct Director {
        string firstName;
        string lastName;
    };
    int rating;
    time_t dateFinished;    //recording when the movie was read

    //constructor
    Movie(string titl, string firstN, string lastN, int rtg) {
        title = titl; //could i just do both as title?
        Director director;
        director.firstName = firstN;
        director.lastName = lastN;
        rating = rtg;
        dateFinished = time(0); //should give the current time?
    };

    string getTimeString() {    //convert Time to a string?
        char* dt = ctime(&dateFinished);
        return dt;
    }
};

vector<Movie> movies; //make a vector to hold the movies watched

void userInput() {    //prompt the user to put in a movie, add to movies vector
    string t;
    string first;
    string last;
    cout << "Enter the Title: ";
    getline(cin, t);
    cout << "\nEnter director's first name: ";
    cin >> first;
    cout << "\nEnter director's last name: ";
    cin >> last;
    cout << "\nEnter your rating of the movie, on a scale from 1-10: ";
    int rtg;
    cin >> rtg;
    Movie newMovie(t, first, last, rtg);
    cout << "\nNew movie created! Date of add: " + newMovie.getTimeString() << endl;
    movies.push_back(newMovie);
    cout << "\nAdded to movies list!" << endl;

};



int main()
{
    cout << "First, adding 2 movies from the main function, and printing out a title and the time added..." << endl;
    Movie movie1("Dumb and Dumber", "Peter", "Farrelly", 4);
    Movie movie2("La Dolce Vita", "Federico", "Fellini", 3);
    movies.push_back(movie1);
    movies.push_back(movie2);
    cout << "Title of Movie 1: " << movie1.title << endl;
    cout << "Time and date that Movie 2 was added: " << movie2.getTimeString() << endl;
    userInput();

}