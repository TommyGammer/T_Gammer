//Thomas Gammer
//Gets the number of rooms in a building as well as the number of rooms and unoccupied rooms on each floor
//Then determines total number of rooms, occupied rooms, unoccupied rooms, and percentage of occupied rooms 


#include <iostream>
using namespace std;

int main()
{
 //define a list of vars & input
    float floors, tempRooms, rooms = 0, tempOccupiedRooms, occupiedRooms = 0;


 //processing
    // gets user input for amount of floors
    cout << "How many floors are in the building? ";
    cin >> floors;
    // starts the loop that runs for the amount of floors
    for (int i = 1; i<= floors; ++i) {
        // skips the 13th floor
        if (i == 13)
            continue;
        // gets number of rooms on a floor and add it to the variable rooms
        cout << "How many rooms are on floor "<< i << ": ";
        cin >> tempRooms;
        rooms = rooms + tempRooms;
        // gets number of occupied rooms on a floor and adds it to variable 
        cout << "How many occupied rooms are on this floor "<< i << ": ";
        cin >> tempOccupiedRooms;
        occupiedRooms = occupiedRooms + tempOccupiedRooms;
        
    }
 //output
    // outputs total number of rooms
    cout << "The number of rooms is: " << rooms << endl;
    // outputs total number of occupied rooms
    cout << "The number of occupied rooms is: " << occupiedRooms << endl;
    // outputs total number of unoccupied rooms
    cout << "The number of unoccupied rooms is: " << rooms - occupiedRooms << endl;
    // outputs percent of total rooms that are occupied
    cout << "The percentage of occupied rooms is: " << (occupiedRooms/rooms)*100 << "%.";
 
    return 0;   

}
