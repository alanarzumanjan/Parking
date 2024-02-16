#include <iostream>
#include <string>
#include <vector>
#include <ctime> // for time()
#include <cstdlib> // for srand() and rand()
#include <chrono> // for using chrono
#include <thread> // for using sleep_for
#include <algorithm>
#include <cmath> // for math
#include <iomanip> // Для fixed и setprecision

using namespace std;

class Car
{
public:
    string car_number;
    string parking_time;
    int parking_seconds = 100 + rand() % 3000;
    int hours = parking_seconds / 3600;
    int minutes = (parking_seconds % 3600) / 60;

    Car(string car_number, string parking_time): car_number(car_number), parking_time(parking_time) {}
    Car() : car_number(""), parking_time("") {}


    int return_choice(int choice){
        return choice;
    }

    string calculate_time(){
        parking_time = to_string(hours) + "h " + to_string(minutes) + "m";
        return parking_time;
    }

    void car_autorization(){
        cout << "Enter your car number. Dont't use spaces please. \nExample: LV442, EX-8083" << endl;
        cout << "Your car number: ";
        cin >> car_number; 
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void car_end(){
        int choice;
        
        do{
            cout << endl << "Are you leaving already?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            if(choice == 1){
                cout << endl << "Malacis)" << endl << endl;
            }
            else{
                cout << endl << "Think again)" << endl;
                this_thread::sleep_for(chrono::seconds(5));
            }

        }while(choice!=1);
    }

    void updateCarNumber(string number) {
        car_number = number;
    }

};

class Parking {
public:
    static const int max_lots = 50;  // Number of parking lots
    int filled_lots;
    vector<int> occupied_lots;
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
            cout << "Not filled lots: ";
            for (int lot : notfilled_lots) {
                cout << lot << " ";
            }
            cout << endl;
        } 
        else {
            cout << "All parking lots are filled." << endl;
        }
    }

    bool takeParkingSpot(int spot) {
        auto it = find(notfilled_lots.begin(), notfilled_lots.end(), spot);

        if (it != notfilled_lots.end()) {
            notfilled_lots.erase(it);
            filled_lots++;
            cout << "Car parked at spot " << spot << endl;
            return true;
        }
        else {
            cout << "Spot " << spot << " is already taken. Please choose another spot." << endl;
            return false;
        }
    }
};

class Ticket: public Car, public Parking {
    private:
        vector<Ticket> tickets;
    protected:
        static int ticket_id;
        float seconds = parking_seconds;
    public:
        static int cost_hour;
        Parking parking;
        int place_number;
        float total_cost;
        Ticket() : place_number(notfilled_lots[ticket_id - 1]), total_cost((seconds / 3600) * cost_hour) {}
        
        static void setCostHour(int price) {
            cost_hour = price;
        }
        
        void printTicket() {
            ticket_id++;
            cout << "Ticket ID: " << ticket_id <<
            "\nCost per hour: " << cost_hour << endl;
        }

        void printCheck(int chosenSpot, int type) {
            cout << "Your Check:" << endl;
            if (type == 1){
                cout << "---VIP---" << endl; 
            }
            else{
                cout << "---Default---" << endl;
            }
            cout << "Car number: " << car_number <<
            "\nTicket ID: " << ticket_id <<
            "\nPlace number: " << chosenSpot <<
            "\nCost per hour: " << cost_hour <<
            "\nTotal time: " << calculate_time() <<
            "\nTotal cost: " << fixed << setprecision(2) << total_cost << "$" << endl;
        }
};

class VipTicket: public Ticket {
    private:
        vector<Ticket> viptickets;
    public:
        Parking parking;
        int place_number;
        static int cost_hour;
        float total_cost;
        VipTicket() : place_number(notfilled_lots[ticket_id - 1]), total_cost((seconds / 3600) * cost_hour) {};
        
        static void setCostHour(int price) {
            cost_hour = price;
        }

        void printVipTicket() {
            ticket_id++;
            cout << "VIP ticket ID: " << ticket_id <<
            "\nCost per hour: " << cost_hour << endl;
        }

        void printCheck(int chosenSpot, int type) {
            cout << "Your Check:" << endl;
            if (type == 1){
                cout << "---VIP---" << endl; 
            }
            else{
                cout << "---Default---" << endl;
            }
            cout << "Car number: " << car_number <<
            "\nTicket ID: " << ticket_id <<
            "\nPlace number: " << chosenSpot <<
            "\nCost per hour: " << cost_hour <<
            "\nTotal time: " << calculate_time() <<
            "\n\033[1;1mTotal cost: " << fixed << setprecision(2) << total_cost << "$\033[0m" << endl;
        }
};

int Ticket::ticket_id = 0;
int Ticket::cost_hour = 20;
int VipTicket::cost_hour = 40;

class Admin: public Parking
{
public:
    int ticket_cost;
    vector<int> occupied_lots;
    vector<int> free_lots;

    Admin(int tc) : ticket_cost(tc) {}

    void admin_functions() {
        int choice;
        do {
            int price;            
            cout << "Enter your ticket price:\n";
            cout << "Press 1 to set price for Default ticket\n";
            cout << "Press 2 to set price for Vip ticket\n";
            cout << "Press 3 to see Free/filling Lots.\n";
            cout << "Press 4 to exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    cout << "Enter price for Default ticket (between 0 and 10 000 dollars): ";
                    cin >> price;
                    if (price >= 0 && price <= 10000) {
                        Ticket::setCostHour(price);
                    } 
                    else {
                        cout << "Invalid price! Please enter a value between 0 and 10 000 dollars.\n";
                    }
                    break;
                case 2:
                    cout << "Enter price for Vip ticket (between 0 and 100 000 dollars): ";
                    cin >> price;
                    if (price >= 0 && price <= 100000) {
                        VipTicket::setCostHour(price);
                    } 
                    else {
                        cout << "Invalid price! Please enter a value between 0 and 100 000 dollars.\n";
                    }
                    break;
                case 3:
                    cout << endl;
                    if (notfilled_lots.empty()) {
                        cout << "No free lots available.\n";
                    } 
                    else {
                        int notfilled_lots_size = notfilled_lots.size();
                        cout << "Free Lots: " << notfilled_lots_size << endl;
                        print_notfilled_lots();
                    }
                    cout << endl;
                    break;
                case 4:
                    cout << "Exit.." << endl;
                    break;
                default:
                    cout << "Invalid choice!\n";
                    this_thread::sleep_for(chrono::seconds(1));
                    break;
            }
            cout << endl;
        } while(choice != 4);
    }
};

void main_menu(){
    cout << endl << "--->Parking<---" << endl;
    cout << "1. Parking Authorization" << endl;
    cout << "2. Admin" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

void choice_ticket(Ticket& ticket, VipTicket& vipticket, Car& car, int& type) {
    int choice;
    cout << "Which ticket do you need?" << endl;
    cout << "1. VipTicket" << endl;
    cout << "2. Default Ticket" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << endl;
        vipticket.printVipTicket();
        cout << "We will provide security for your car and promise not to hit it ourselves" << endl;
        type = 1; // VIP ticket
    } 
    else if (choice == 2) {
        cout << endl;
        ticket.printTicket();
        type = 2; // Default ticket
    } 
    else {
        cout << "Incorrect answer" << endl;
    }
}

void print_check(int type, Ticket& ticket, VipTicket& vipticket, int chosenSpot) {
    if (type == 1) {
        vipticket.printCheck(chosenSpot, type);
    }
    else {
        ticket.printCheck(chosenSpot, type);
    }
}

int main(){
    Car car("","");
    Admin admin(0);
    Parking parking;
    Parking parkingLot;
    Ticket ticket;
    VipTicket vipticket;

    int choice;
    int type;
    int chosenSpot;

    parking.fill_random_lots();

    do{
        main_menu();
        cin >> choice;
        int spot;
        switch (choice)
        {
        case 1:
            car.car_autorization();
            ticket.updateCarNumber(car.car_number);
            vipticket.updateCarNumber(car.car_number);
            this_thread::sleep_for(chrono::seconds(2));
                choice_ticket(ticket, vipticket, car, type); // Pass 'type' by reference
                cout << endl;
                this_thread::sleep_for(chrono::seconds(2));
                parkingLot.print_notfilled_lots();
                cout << "Enter a spot to park: ";
                cin >> chosenSpot;

                while (!parkingLot.takeParkingSpot(chosenSpot)) {
                cout << "Please choose another spot: ";
                cin >> chosenSpot;
                } 
                this_thread::sleep_for(chrono::seconds(2));
            car.car_end();
                
                print_check(type, ticket, vipticket, chosenSpot);
            break;
        case 2:
            admin.admin_functions();
            break;
        case 3:
            cout << "Exiting program.." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            break;
        default:
            cout << "Incorrect answer, please repeat." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        } 
    }while(choice != 3);
    
    return 0;
}
