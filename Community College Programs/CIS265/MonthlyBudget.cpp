//Thomas Gammer
//Helps manage a monthly budget


#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

// Define the MonthlyBudget structure
struct MonthlyBudget {
    double housing;
    double utilities;
    double householdExpenses;
    double transportation;
    double food;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double miscellaneous;
};

// Function to input expenses
void inputExpenses(MonthlyBudget &budget) {
    cout << "Enter the amount spent in each budget category during the month:" << endl;
    cout << "Housing: ";
    cin >> budget.housing;
    cout << "Utilities: ";
    cin >> budget.utilities;
    cout << "Household Expenses: ";
    cin >> budget.householdExpenses;
    cout << "Transportation: ";
    cin >> budget.transportation;
    cout << "Food: ";
    cin >> budget.food;
    cout << "Medical: ";
    cin >> budget.medical;
    cout << "Insurance: ";
    cin >> budget.insurance;
    cout << "Entertainment: ";
    cin >> budget.entertainment;
    cout << "Clothing: ";
    cin >> budget.clothing;
    cout << "Miscellaneous: ";
    cin >> budget.miscellaneous;
}

// Function to display the budget report
void displayBudgetReport(const MonthlyBudget &budget) {
    double totalBudget = 500.00 + 150.00 + 65.00 + 50.00 + 250.00 + 30.00 + 100.00 + 150.00 + 75.00 + 50.00;
    double totalSpent = budget.housing + budget.utilities + budget.householdExpenses + budget.transportation + budget.food +
                        budget.medical + budget.insurance + budget.entertainment + budget.clothing + budget.miscellaneous;

    cout << "Budget Report:" << endl;

    // Calculate and display the amount over or under budget for each category
    cout << "Housing: $" << (budget.housing - 500.00) << " over/under budget" << endl;
    cout << "Utilities: $" << (budget.utilities - 150.00) << " over/under budget" << endl;
    cout << "Household Expenses: $" << (budget.householdExpenses - 65.00) << " over/under budget" << endl;
    cout << "Transportation: $" << (budget.transportation - 50.00) << " over/under budget" << endl;
    cout << "Food: $" << (budget.food - 250.00) << " over/under budget" << endl;
    cout << "Medical: $" << (budget.medical - 30.00) << " over/under budget" << endl;
    cout << "Insurance: $" << (budget.insurance - 100.00) << " over/under budget" << endl;
    cout << "Entertainment: $" << (budget.entertainment - 150.00) << " over/under budget" << endl;
    cout << "Clothing: $" << (budget.clothing - 75.00) << " over/under budget" << endl;
    cout << "Miscellaneous: $" << (budget.miscellaneous - 50.00) << " over/under budget" << endl;

    // Calculate and display the amount over or under for the entire monthly budget
    cout << "Total Budget: $" << totalBudget << endl;
    cout << "Total Spent: $" << totalSpent << endl;
    cout << "Overall Budget Difference: $" << (totalSpent - totalBudget) << endl;
}

int main() {
    MonthlyBudget budget;

    // Input expenses
    inputExpenses(budget);

    // Display the budget report
    displayBudgetReport(budget);

    return 0;
}