//Thomas Gammer
//Changes the format of the entered date to 3 different formats

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

class Date {
private:
    int month, day, year;

public:
    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    void printDate1() const {
        cout << month << "/" << day << "/" << (year) << endl;
    }

    void printDate2() const {
        string monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        cout << monthNames[month - 1] << " " << day << ", " << year << endl;
    }

    void printDate3() const {
        string monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        cout << day << " " << monthNames[month - 1] << " " << year << endl;
    }

    // Function to validate the date
    bool validateDate() const {
        if (month < 1 || month > 12)
            return false;
        if (day < 1 || day > 31)
            return false;
        return true;
    }
};

int main() {
    int m, d, y;

    cout << "Enter month, day, and year (MM DD YYYY): ";
    cin >> m >> d >> y;

    Date date(m, d, y);
    // checks if it is a valid date and then prints it in the 3 different forms
    if (date.validateDate()) {
        cout << "Date in the format 1: ";
        date.printDate1();

        cout << "Date in the format 2: ";
        date.printDate2();

        cout << "Date in the format 3: ";
        date.printDate3();
    } else {
        cout << "Invalid date entered." << endl;
    }

    return 0;
}