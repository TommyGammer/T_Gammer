//Thomas Gammer
//Gathers data from numbers in a file

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

int main() {
    // Gets the user input for a file name
    string file_name;
    cout << "Enter the name of the file containing numbers: ";
    cin >> file_name;

    ifstream file(file_name);

    // If the file fails to get read it will display a fail message
    if (file.fail())
    {
        cout << "File input error";
    }

    const int max_numbers = 1000;  // Defines a maximum number of elements in the array
    double numbers[max_numbers];
    int num_elements = 0;
    double sum = 0.0;

    double number;

    // Adds up all of the numbers from the file and creates an array of the numbers in the file
    while (num_elements < max_numbers && file >> number) {
        numbers[num_elements] = number;
        sum += number;
        num_elements++;
    }

    // If the file is empty it displays a message
    if (num_elements == 0) {
        cout << "The file is empty." << endl;
        return 0;
    }

    double min_number = numbers[0];
    double max_number = numbers[0];

    // Gets the min and max numbers in the array
    for (int i = 0; i < num_elements; i++) {
        if (numbers[i] < min_number) {
            min_number = numbers[i];
        }
        if (numbers[i] > max_number) {
            max_number = numbers[i];
        }
    }

    // calculates the average of all the numbers in the array
    double average = sum / num_elements;

    // Gives the required outputs for the array
    cout << "Lowest number: " << min_number << endl;
    cout << "Highest number: " << max_number << endl;
    cout << "Total of the numbers: " << sum << endl;
    cout << "Average of the numbers: " << fixed << setprecision(2) << average << endl;

    return 0;
}