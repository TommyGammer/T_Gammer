//Thomas Gammer
//Recieves the quarterly sales for 4 different divisions and outputs the highest

#include <iostream>
#include <string>
using namespace std;

// Function to get the sales for any division that is put into it.
double getSales(string divisionName) {
    double sales;
    do {
        cout << "Enter quarterly sales for " << divisionName << ": $";
        cin >> sales;

        if (sales < 0.0) {
            cout << "Sales can't be less than $0.00.\n";
        }
    } while (sales < 0.0);

    return sales;
}
// Function to find and print the division with the highest sales.
void findHighest(double northeastSales, double southeastSales, double northwestSales, double southwestSales) {
    double highestSales = northeastSales;
    string highestDivision = "Northeast";

    if (southeastSales > highestSales) {
        highestSales = southeastSales;
        highestDivision = "Southeast";
    }

    else if (northwestSales > highestSales) {
        highestSales = northwestSales;
        highestDivision = "Northwest";
    }

    else if (southwestSales > highestSales) {
        highestSales = southwestSales;
        highestDivision = "Southwest";
    }

    cout << "The division with the highest sales is " << highestDivision << " with sales of $" << highestSales << endl;
}

int main() {
    // Sets variables named after each region equal to the getSales function for that region.
    double northeastSales = getSales("Northeast");
    double southeastSales = getSales("Southeast");
    double northwestSales = getSales("Northwest");
    double southwestSales = getSales("Southwest");

    // Prints the highest number out of the 4 sales variables.
    findHighest(northeastSales, southeastSales, northwestSales, southwestSales);

    return 0;
}