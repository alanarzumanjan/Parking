#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread> // for using his_thread::sleep_for
#include <chrono> // usingseconds 

using namespace std;

// please don't change this file
// here comes the connection code of each

class Car
{
public:
    int car_number;
    string parking_time;

    Car(int car_number, string parking_time): car_number(car_number), parking_time(parking_time) {}
    
    void car_autorization(){
        cout << "Enter your car number: ";
        cin >> car_number;
        cout << endl;
        // need time sleep 2-3s
    }

    string calculate_time(){
        int parking_seconds = 10 + rand() % 250;
        int hours = parking_seconds / 3600; // 1 h = 3600 sec
        int minutes = (parking_seconds % 3600) / 60; // 1 min = 60 sec
        parking_time = to_string(hours) + "h " + to_string(minutes) + "m";
        return parking_time;
    }

};

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

    void print_notfilled_lots() const {
        cout << "Filled Lots: " << filled_lots << endl;
        if (filled_lots < max_lots) {
            cout << "Parking lots not filled: ";
            for (int lot : notfilled_lots) {
                cout << lot << " ";
            }
            cout << endl;
        } else {
            cout << "All parking lots are filled." << endl;
        }
    }
};



void main_menu(){
    cout << "--->Parking<---" << endl;
    cout << "1. Parking Autorization" << endl;
    cout << "2. Admin" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main(){
    Car car(0,"");
    
    int choice;
    do{
        main_menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            car.car_autorization();
            
            break;
        case 2:

            break;
        case 3:
            cout << "Exiting program.." << endl;
            // need time sleep 2-3s
            break;
        default:
            cout << "Incorrect answer, repeat please" << endl;
    
        } 
    }while(choice!=3);
    

    return 0;
}