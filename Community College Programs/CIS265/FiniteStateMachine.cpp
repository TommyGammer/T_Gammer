//Thomas Gammer
//Finite State Machine

#include <iostream>
#include <string>
using namespace std;

// Enum to represent the states of the FSM
enum State {
    q0,
    q1,
    q2,
    q3,
    q4
};

// Function to transition between states based on the input character
State transition(State current_state, char input) {
    switch (current_state) {
        case q0:
            if (input == '0')
                return q0;
            else if (input == '1')
                return q1;
            break;
        case q1:
            if (input == '0')
                return q0;
            else if (input == '1')
                return q2;
            break;
        case q2:
            if (input == '0')
                return q3;
            else if (input == '1')
                return q1;
            break;
        case q3:
            if (input == '0')
                return q0;
            else if (input == '1')
                return q4;
            break;
        case q4:
            if (input == '0' || input == '1')
                return q4;
            break;
    }
    // If an invalid character is encountered, return q0
    return q0;
}

int main() {
    State current_state = q0;
    string input;

    while (true) {
        cout << "Enter a string (0s and 1s only, enter 'q' to quit): ";
        cin >> input;

        if (input == "q")
            break;

        bool foundSubstring = false;
        for (char& c : input) {
            if (c != '0' && c != '1') {
                // If the user enters a character that is not a 1 or a 0, it will just be removed from the input.
                cout << "Ignoring character " << c << " not in the input alphabet" << endl;
                continue;
            }

            current_state = transition(current_state, c);
            if (current_state == q4) {
                foundSubstring = true;
                current_state = q0; // Resetting the state
                break;
            }
        }

        if (foundSubstring) {
            cout << "String is ACCEPTED" << endl;
        } else {
            cout << "String is NOT ACCEPTED" << endl;
        }
    }

    return 0;
}