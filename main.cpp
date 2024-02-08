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
    float parking_time;

    Car(int car_number, float parking_time): car_number(car_number), parking_time(parking_time) {}
    
    void car_autorization(){
        cout << "Enter your car number:";
        cin >> car_number;
    }
    
};

void main_menu(){
    cout << "====>Parking<====" << endl;
    cout << "1. Parking Autorization" << endl;
    cout << "2. Admin" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main(){
    Car car;

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