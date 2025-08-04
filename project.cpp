#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Bus {
private:
    string busNumber;
    string driverName;
    string arrivalTime;
    string departureTime;
    string from;
    string to;
    string seats[32];

public:
    void createRoute();
    void reserveSeat();
    void showSeats();
    void showBusDetails();
    string getBusNumber();
};

Bus buses[10]; // Max 10 buses
int totalBuses = 0;

// Create a new bus route
void Bus::createRoute() {
    cout << "Enter Bus Number: ";
    cin >> busNumber;
    cin.ignore();

    cout << "Enter Driver Name: ";
    getline(cin, driverName);

    cout << "Enter Arrival Time: ";
    getline(cin, arrivalTime);

    cout << "Enter Departure Time: ";
    getline(cin, departureTime);

    cout << "Enter From Location: ";
    getline(cin, from);

    cout << "Enter To Location: ";
    getline(cin, to);

    // Initialize all seats as empty
    for (int i = 0; i < 32; ++i) {
        seats[i] = "Empty";
    }

    cout << "Bus route created successfully!\n";
}

// Reserve a seat in a specific bus
void Bus::reserveSeat() {
    int seatNum;
    string name;

    cout << "Enter Seat Number to Reserve (1-32): ";
    cin >> seatNum;
    cin.ignore();

    if (seatNum < 1 || seatNum > 32) {
        cout << "Invalid seat number!\n";
        return;
    }

    if (seats[seatNum - 1] != "Empty") {
        cout << "Seat already reserved by " << seats[seatNum - 1] << endl;
    } else {
        cout << "Enter Passenger Name: ";
        getline(cin, name);
        seats[seatNum - 1] = name;
        cout << "Seat reserved successfully.\n";
    }
}

// Display seats of a specific bus
void Bus::showSeats() {
    cout << "\nBus Number: " << busNumber << " | Driver: " << driverName << "\n";
    cout << "Route: " << from << " to " << to << "\n";
    cout << "Arrival: " << arrivalTime << " | Departure: " << departureTime << "\n\n";

    for (int i = 0; i < 32; ++i) {
        cout << "Seat " << setw(2) << (i + 1) << ": " << seats[i] << endl;
    }
}

// Display bus info in a table format
void Bus::showBusDetails() {
    cout << left << setw(12) << busNumber << setw(20) << driverName
         << setw(12) << arrivalTime << setw(12) << departureTime
         << setw(15) << from << setw(15) << to << endl;
}

string Bus::getBusNumber() {
    return busNumber;
}

// Find bus index by number
int findBus(string number) {
    for (int i = 0; i < totalBuses; ++i) {
        if (buses[i].getBusNumber() == number) {
            return i;
        }
    }
    return -1;
}

// Display all available buses
void showAllBuses() {
    if (totalBuses == 0) {
        cout << "No buses available.\n";
        return;
    }

    cout << "\nAvailable Buses:\n";
    cout << left << setw(12) << "Bus Number" << setw(20) << "Driver"
         << setw(12) << "Arrival" << setw(12) << "Departure"
         << setw(15) << "From" << setw(15) << "To" << endl;

    for (int i = 0; i < totalBuses; ++i) {
        buses[i].showBusDetails();
    }
}

// Main program menu
int main() {
    int choice;
    string busNum;

    do {
        cout << "\n=== Bus Reservation System ===\n";
        cout << "1. Create Bus Route\n";
        cout << "2. Reserve a Seat\n";
        cout << "3. Display Seats of a Bus\n";
        cout << "4. Show Available Buses\n";
        cout << "5. Exit\n";
        cout << "Choose an option (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (totalBuses < 10) {
                    buses[totalBuses].createRoute();
                    totalBuses++;
                } else {
                    cout << "Maximum bus limit reached.\n";
                }
                break;

            case 2:
                cout << "Enter Bus Number: ";
                cin >> busNum;
                {
                    int index = findBus(busNum);
                    if (index != -1) {
                        buses[index].reserveSeat();
                    } else {
                        cout << "Bus not found.\n";
                    }
                }
                break;

            case 3:
                cout << "Enter Bus Number: ";
                cin >> busNum;
                {
                    int index = findBus(busNum);
                    if (index != -1) {
                        buses[index].showSeats();
                    } else {
                        cout << "Bus not found.\n";
                    }
                }
                break;

            case 4:
                showAllBuses();
                break;

            case 5:
                cout << "Exiting... Thank you!\n";
                break;

            default:
                cout << "Invalid option. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
