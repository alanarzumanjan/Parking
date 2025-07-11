// Ilja Prihodko functions
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Parking {
public:
    static const int max_lots = 50;  // Number of parking lots
    int filled_lots;
    vector<int> notfilled_lots;

    Parking() : filled_lots(0) {
        fill_random_lots();
    }

    void fill_random_lots() {
        // Seed the random number generator with the current time
        srand(static_cast<unsigned>(time(nullptr)));

        // Reset filled and not filled lots
        filled_lots = 0;
        notfilled_lots.clear();

        // Fill all parking lots initially
        for (int i = 1; i <= max_lots; ++i) {
            notfilled_lots.push_back(i);
        }

        // Ensure at least 5 to 10 parking lots are not filled
        int minNotFilled = 5;
        int maxNotFilled = 10;
        int targetNotFilled = rand() % (maxNotFilled - minNotFilled + 1) + minNotFilled;

        while (filled_lots < (max_lots - targetNotFilled)) {
            int lotToRemove = rand() % notfilled_lots.size();
            notfilled_lots.erase(notfilled_lots.begin() + lotToRemove);
            filled_lots++;
        }
    }

    bool takeParkingSpot(int spot) {
        auto it = find(notfilled_lots.begin(), notfilled_lots.end(), spot);

        if (it != notfilled_lots.end()) {
            notfilled_lots.erase(it);
            filled_lots++;
            cout << "Car parked at spot " << spot << endl;
            return true;
        } else {
            cout << "Spot " << spot << " is already taken. Please choose another spot." << endl;
            return false;
        }
    }

    void print_notfilled_lots() const {
        cout << "Filled Lots: " << filled_lots << endl;
        if (filled_lots < max_lots) {
            cout << "Parking lots not filled: ";
            for (int lot : notfilled_lots) {
                cout << lot << " ";
            }
            cout << endl;
        }
        else {
            cout << "All parking lots are filled." << endl;
        }
    }
};

int main() {
    Parking parkingLot;

    // Access and display the information
    parkingLot.print_notfilled_lots();

    // Allow user to choose a spot
    int chosenSpot;
    cout << "Enter a spot to park: ";
    cin >> chosenSpot;

    // Simulate the user taking the chosen spot or prompt to choose another spot
    while (!parkingLot.takeParkingSpot(chosenSpot)) {
        cout << "Please choose another spot: ";
        cin >> chosenSpot;
    }

    // Access and display the final information
    parkingLot.print_notfilled_lots();

    return 0;
}