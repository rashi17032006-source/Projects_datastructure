#include <iostream>
#include <string>
using namespace std;

// Node structure for Linked List
struct Passenger {
    int ticketNo;
    string name;
    string trainName;
    string source;
    string destination;
    Passenger* next;
};

// Head pointer to start of the linked list
Passenger* head = NULL;

// Function to add (book) a passenger
void bookTicket() {
    Passenger* newPassenger = new Passenger;
    cout << "\nEnter Ticket Number: ";
    cin >> newPassenger->ticketNo;
    cout << "Enter Passenger Name: ";
    cin.ignore();
    getline(cin, newPassenger->name);
    cout << "Enter Train Name: ";
    getline(cin, newPassenger->trainName);
    cout << "Enter Source Station: ";
    getline(cin, newPassenger->source);
    cout << "Enter Destination Station: ";
    getline(cin, newPassenger->destination);
    newPassenger->next = NULL;

    // Insert at end of linked list
    if (head == NULL) {
        head = newPassenger;
    } else {
        Passenger* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newPassenger;
    }

    cout << "\n✅ Ticket Booked Successfully!\n";
}

// Function to display all booked passengers
void displayPassengers() {
    if (head == NULL) {
        cout << "\n❌ No bookings found!\n";
        return;
    }

    Passenger* temp = head;
    cout << "\n---- List of Booked Passengers ----\n";
    while (temp != NULL) {
        cout << "Ticket No: " << temp->ticketNo << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Train: " << temp->trainName << endl;
        cout << "From: " << temp->source << "  To: " << temp->destination << endl;
        cout << "---------------------------------\n";
        temp = temp->next;
    }
}

// Function to cancel (delete) a ticket
void cancelTicket() {
    if (head == NULL) {
        cout << "\n❌ No bookings to cancel!\n";
        return;
    }

    int tNo;
    cout << "\nEnter Ticket Number to Cancel: ";
    cin >> tNo;

    Passenger* temp = head;
    Passenger* prev = NULL;

    // Search for the ticket number
    while (temp != NULL && temp->ticketNo != tNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\n❌ Ticket not found!\n";
        return;
    }

    // If the ticket is the first node
    if (temp == head)
        head = head->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "\n🗑️ Ticket Cancelled Successfully!\n";
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n===== Railway Reservation System =====";
        cout << "\n1. Book Ticket";
        cout << "\n2. Display All Passengers";
        cout << "\n3. Cancel Ticket";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bookTicket(); break;
            case 2: displayPassengers(); break;
            case 3: cancelTicket(); break;
            case 4: cout << "\nThank you for using Railway Reservation System!\n"; break;
            default: cout << "\nInvalid Choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
