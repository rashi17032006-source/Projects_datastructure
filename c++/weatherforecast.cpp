#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

class Weather {
private:
    string city;
    string conditions[6] = {"Sunny", "Cloudy", "Rainy", "Stormy", "Snowy", "Windy"};

    int getRandomTemperature() {
        return rand() % 45 - 5;
    }

    int getRandomHumidity() {
        return rand() % 101;
    }

    string getRandomCondition() {
        return conditions[rand() % 6];
    }

public:
    Weather(string c) {
        city = c;
    }

    void setCity(string c) {
        city = c;
    }

    void displayForecast(int days = 3) {
        cout << CYAN << "\nWeather Forecast for " << BOLD << city << RESET << ":\n";
        cout << "------------------------------\n";
        for (int i = 1; i <= days; i++) {
            cout << BOLD << YELLOW << "Day " << i << ":" << RESET << "\n";
            cout << "Temperature: " << RED << getRandomTemperature() << "°C" << RESET << "\n";
            cout << "Humidity: " << BLUE << getRandomHumidity() << "%" << RESET << "\n";
            cout << "Condition: " << GREEN << getRandomCondition() << RESET << "\n\n";
        }
    }
};

int main() {
    srand(time(0));
    string city;
    int choice;

    cout << BOLD << GREEN;
    cout << "==============================\n";
    cout << "  Welcome to Weather Forecast\n";
    cout << "==============================\n" << RESET;

    cout << "Enter your city: ";
    getline(cin, city);

    Weather weather(city);

    do {
        cout << BOLD << "\n----- Menu -----\n" << RESET;
        cout << "1. " << CYAN << "View Weather Forecast" << RESET << "\n";
        cout << "2. " << CYAN << "Change City" << RESET << "\n";
        cout << "3. " << CYAN << "Exit" << RESET << "\n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << RED << "Invalid input! Please enter a number (1-3).\n" << RESET;
            continue;
        }

        cin.ignore();

        switch (choice) {
            case 1:
                weather.displayForecast();
                break;
            case 2:
                cout << "Enter new city: ";
                getline(cin, city);
                weather.setCity(city);
                break;
            case 3:
                cout << GREEN << "Exiting... Thank you for using Weather Forecast!\n" << RESET;
                break;
            default:
                cout << RED << "Invalid choice! Please enter 1, 2, or 3.\n" << RESET;
        }

    } while (choice != 3);

    return 0;
}
