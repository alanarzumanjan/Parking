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