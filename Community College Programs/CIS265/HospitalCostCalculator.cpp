//Thomas Gammer
//Calculates the total cost of a hospital visit by gathering imformation about the expenses 

#include <iostream>
#include <string>
using namespace std;

// Function to calculate the total cost for an in-patient
double hospitalCost(double days, double rate, double medication, double services) {
    double total;
    total = (days*rate) + medication + services;
    return total;
}
// Function to calculate the total cost for an out-patient
double hospitalCost(double medication, double services) {
    double total;
    total = medication + services;
    return total;
}
// Function to get the number of days the patient stayed at the hospital
int getDays(string days) {
    int tempDays;
    do {
        cout << days;
        cin >> tempDays;

        if (tempDays < 0.0) {
            cout << "Days can't be less than or equal to 0.\n";
        }
    } while (tempDays < 0.0);

    return tempDays;
}
// Function to get the daily rate for the patient staying at the hospital
int getRate(string rate) {
    double tempRate;
    do {
        cout << rate;
        cin >> tempRate;

        if (tempRate < 0.0) {
            cout << "Rate can't be less than or equal to $0.00.\n";
        }
    } while (tempRate < 0.0);

    return tempRate;
}
// Function to get the total cost of medication that the patient got
int getMedication(string medication) {
    double tempMedication;
    do {
        cout << medication;
        cin >> tempMedication;

        if (tempMedication < 0.0) {
            cout << "Medication can't be less than or equal to $0.00.\n";
        }
    } while (tempMedication < 0.0);

    return tempMedication;
}
// Function to get the total cost for the services that the patient used
int getServices(string services) {
    double tempServices;
    do {
        cout << services;
        cin >> tempServices;

        if (tempServices < 0.0) {
            cout << "Services can't be less than or equal to $0.00.\n";
        }
    } while (tempServices < 0.0);

    return tempServices;
}
int main(){
    // Defines my variables
    string patientType;
    double varDays = 0;
    double varRate = 0;
    double varMedication = 0;
    double varServices = 0;

    // Gets from the user whether it is an in or out patient 
    cout << "Is the patient an in-patient or and out-patient? (type either in or out) ";
    cin >> patientType;

    // Gets, calculates, and displays the costs and total costs for an in-patient    
    if (patientType == "in"){

        varDays = getDays("How many days was the patient in the hospital? ");
        
        varRate = getRate("What was the daily rate of the hospital? $");

        varMedication = getMedication("What was the total cost of the medication the patient used? $");

        varServices = getServices("What was the total cost of the hospital services that the patient used? $");
        
        cout << "The total cost of this patients visit was $" << hospitalCost(varDays, varRate, varMedication, varServices);

    }
    // Gets, calculates, and displays the costs and total costs for an in-patient
    else if (patientType == "out"){

        varMedication = getMedication("What was the total cost of the medication the patient used? $");

        varServices = getServices("What was the total cost of the hospital services that the patient used? $");

        cout << "The total cost of this patients visit was $" << hospitalCost(varMedication, varServices);
    // Makes sure the user enters the correct thing
    }else{
        cout << "Please enter either in or out.";
    }

    return 0;
}