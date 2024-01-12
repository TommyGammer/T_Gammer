//Tommy Gammer
//Collects and stores updatable item records

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Structure to store inventory data
struct InventoryItem {
    string description;
    int quantity;
    float wholesaleCost;
    float retailCost;
    string dateAdded;
};

// Function prototypes
void addRecord(ofstream &file);
void displayRecord(ifstream &file);
void changeRecord(fstream &file);

int main() {
    ofstream outFile("inventory.txt", ios::app); // Create a file (or open if exists) for appending
    ifstream inFile("inventory.txt"); // Open file for reading
    fstream file("inventory.txt"); // Open file for reading and writing

    int choice;

    do {
        cout << "Inventory Management System\n";
        cout << "1. Add new record\n";
        cout << "2. Display a record\n";
        cout << "3. Change a record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord(outFile);
                break;
            case 2:
                displayRecord(inFile);
                break;
            case 3:
                changeRecord(file);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    outFile.close();
    inFile.close();
    file.close();

    return 0;
}

// Function to add a new record to the file
void addRecord(ofstream &file) {
    InventoryItem newItem;

    cout << "Enter item description: ";
    cin.ignore();
    getline(cin, newItem.description);

    cout << "Enter quantity on hand: ";
    cin >> newItem.quantity;
    while (newItem.quantity < 0) {
        cout << "Quantity cannot be less than 0. Enter a valid quantity: ";
        cin >> newItem.quantity;
    }

    cout << "Enter wholesale cost: ";
    cin >> newItem.wholesaleCost;
    while (newItem.wholesaleCost < 0) {
        cout << "Wholesale cost cannot be less than 0. Enter a valid cost: ";
        cin >> newItem.wholesaleCost;
    }

    cout << "Enter retail cost: ";
    cin >> newItem.retailCost;
    while (newItem.retailCost < 0) {
        cout << "Retail cost cannot be less than 0. Enter a valid cost: ";
        cin >> newItem.retailCost;
    }

    cout << "Enter date added to inventory (MM/DD/YYYY): ";
    cin >> newItem.dateAdded;

    file << newItem.description << " " << newItem.quantity << " " << newItem.wholesaleCost << " " << newItem.retailCost << " " << newItem.dateAdded << endl;
    cout << "Record added successfully!\n";
}

// Function to display a record from the file
void displayRecord(ifstream &file) {
    string searchDescription;
    bool found = false;
    InventoryItem item;

    cout << "Enter item description to display: ";
    cin.ignore();
    getline(cin, searchDescription);

    while (file >> item.description >> item.quantity >> item.wholesaleCost >> item.retailCost >> item.dateAdded) {
        if (item.description == searchDescription) {
            found = true;
            cout << "Record Found\n";
            cout << "Item Description: " << item.description << endl;
            cout << "Quantity on Hand: " << item.quantity << endl;
            cout << "Wholesale Cost: $" << fixed << setprecision(2) << item.wholesaleCost << endl;
            cout << "Retail Cost: $" << fixed << setprecision(2) << item.retailCost << endl;
            cout << "Date Added to Inventory: " << item.dateAdded << endl;
            break;
        }
    }

    if (!found) {
        cout << "Record not found.\n";
    }
}

// Function to change a record in the file
void changeRecord(fstream &file) {
    string searchDescription;
    bool found = false;
    InventoryItem item;

    cout << "Enter item description to change: ";
    cin.ignore();
    getline(cin, searchDescription);

    while (file >> item.description >> item.quantity >> item.wholesaleCost >> item.retailCost >> item.dateAdded) {
        if (item.description == searchDescription) {
            found = true;
            cout << "Existing Record\n";
            cout << "Item Description: " << item.description << endl;
            cout << "Quantity on Hand: " << item.quantity << endl;
            cout << "Wholesale Cost: $" << fixed << setprecision(2) << item.wholesaleCost << endl;
            cout << "Retail Cost: $" << fixed << setprecision(2) << item.retailCost << endl;
            cout << "Date Added to Inventory: " << item.dateAdded << endl;

            cout << "Enter new item description: ";
            getline(cin, item.description);

            cout << "Enter new quantity on hand: ";
            cin >> item.quantity;
            while (item.quantity < 0) {
                cout << "Quantity cannot be less than 0. Enter a valid quantity: ";
                cin >> item.quantity;
            }

            cout << "Enter new wholesale cost: ";
            cin >> item.wholesaleCost;
            while (item.wholesaleCost < 0) {
                cout << "Wholesale cost cannot be less than 0. Enter a valid cost: ";
                cin >> item.wholesaleCost;
            }

            cout << "Enter new retail cost: ";
            cin >> item.retailCost;
            while (item.retailCost < 0) {
                cout << "Retail cost cannot be less than 0. Enter a valid cost: ";
                cin >> item.retailCost;
            }

            cout << "Enter new date added to inventory (MM/DD/YYYY): ";
            cin >> item.dateAdded;

            // Move the file pointer to the beginning of the record to be modified
            file.seekp(-static_cast<int>(sizeof(item)), ios::cur);
            file << item.description << " " << item.quantity << " " << item.wholesaleCost << " " << item.retailCost << " " << item.dateAdded << endl;
            cout << "Record changed successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Record not found.\n";
    }
}