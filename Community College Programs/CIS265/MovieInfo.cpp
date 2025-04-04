//Thomas Gammer
//Displays given movie information

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

// Defines the MovieData structure
struct MovieData {
    string title;
    string director;
    int yearReleased;
    int runningTime;
};

// Function to display movie information
void displayMovieInfo(const MovieData& movie) {
    cout << "Movie Title: " << movie.title << endl;
    cout << "Director: " << movie.director << endl;
    cout << "Year Released: " << movie.yearReleased << endl;
    cout << "Running Time (minutes): " << movie.runningTime << endl;
    cout << endl;
}

int main() {
    // Creates two MovieData variables and initializes their members
    MovieData movie1;
    movie1.title = "Avengers Endgame";
    movie1.director = "Anthony and Joe Russo";
    movie1.yearReleased = 2019;
    movie1.runningTime = 182;

    MovieData movie2;
    movie2.title = "Whiplash";
    movie2.director = "Damien Chazelle";
    movie2.yearReleased = 2014;
    movie2.runningTime = 107;

    // Displays information about the movies using the displayMovieInfo function
    cout << "Movie 1 Information:" << endl;
    displayMovieInfo(movie1);

    cout << "Movie 2 Information:" << endl;
    displayMovieInfo(movie2);

    return 0;
}