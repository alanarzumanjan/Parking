#include <iostream>
#include <string> // data type - string 
#include <vector> // vectors
#include <fstream> // work ar file 
#include <ctime> // for time()
#include <cstdlib> // for srand() and rand()
#include <chrono> // for using chrono
#include <thread> // for using sleep_for

using namespace std;

class Car
{
public:
    int car_number;
    string parking_time;

    Car(int car_number, string parking_time): car_number(car_number), parking_time(parking_time) {}
    Car() : car_number(0), parking_time("") {}

    int return_choice(int choice){
        return choice;
    }

    string calculate_time(){
        int parking_seconds = 10 + rand() % 250;
        int hours = parking_seconds / 3600; // 1 h = 3600 sec
        int minutes = (parking_seconds % 3600) / 60; // 1 min = 60 sec
        parking_time = to_string(hours) + "h " + to_string(minutes) + "m";

        return parking_time;
    }

    void car_autorization(){
        cout << "Enter your car number: ";
        cin >> car_number; 
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
                cout << endl << "Malacis)" << endl;
            }
            else{
                cout << endl << "Think again)" << endl;
                this_thread::sleep_for(chrono::seconds(3));
            }

        }while(choice!=1);
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
};

class Ticket: public Car {
    private:
        vector<Ticket> tickets;
        
    protected:
        static int next_ticket_id;
        int ticket_id;
    public:
        static int cost_hour;
        Parking parking;
        Car car;
        int place_number;
        float total_cost;
        Ticket() : ticket_id(next_ticket_id++), place_number(parking.notfilled_lots[ticket_id - 1]) {}
        static void setCostHour(int price) {
            cost_hour = price;
        }
        
        void printTicket() {
            cout << "Ticket ID: " << ticket_id <<
            "\nPlace number: " << place_number <<
            "\nCost per hour: " << cost_hour << endl;
        }

        void printCheck() {
            cout << "Car number: " << car.car_number <<
            "\nTicket ID: " << ticket_id <<
            "\nPlace number: " << place_number <<
            "\nCost per hour: " << cost_hour <<
            "\nTotal cost: " << total_cost <<
            "\nTotal time: " << car.calculate_time() << endl;
        }
};

class VipTicket: public Ticket {
    private:
        vector<Ticket> viptickets;
    protected:
        int vip_ticket_id;
    public:
        Parking parking;
        int place_number;
        static int cost_hour;
        float total_cost;
        VipTicket() : vip_ticket_id(next_ticket_id++), place_number(parking.notfilled_lots[vip_ticket_id - 1]){};
        
        static void setCostHour(int price) {
            cost_hour = price;
        }

        void printVipTicket() {
            cout << "VIP ticket ID: " << vip_ticket_id <<
            "\nPlace number: " << place_number <<
            "\nCost per hour: " << cost_hour << endl;
        }
};

int Ticket::next_ticket_id = 0;
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
                    cout << "Enter price for Default ticket (between 1 and 1000 dollars): ";
                    cin >> price;
                    if (price >= 1 && price <= 1000) {
                        Ticket::setCostHour(price);
                        cout << "Price for Default ticket: $" << ticket_cost << endl;
                    } 
                    else {
                        cout << "Invalid price! Please enter a value between 1 and 1000 dollars.\n";
                    }
                    break;
                case 2:
                    cout << "Enter price for Vip ticket (between 5 and 1000 dollars): ";
                    cin >> price;
                    if (price >= 5 && price <= 1000) {
                        VipTicket::setCostHour(price);
                        cout << "Price for Vip ticket: $" << ticket_cost << endl;
                    } 
                    else {
                        cout << "Invalid price! Please enter a value between 5 and 1000 dollars.\n";
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

void choice_ticket(){
    VipTicket vipticket;
    Ticket ticket;
    int choice;
    cout << "Whitch ticket do you need?" << endl;
    cout << "1. VipTicket" << endl;
    cout << "2. Default Ticket" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    do{
        switch (choice)
        {
            case 1:
                cout << endl;
                vipticket.printVipTicket();
                break;
            case 2:
                cout << endl;
                ticket.printTicket();
                break;
            default:
                cout << "Incorrect answer" << endl;
                break;
        }

    }while(choice != 1 && choice != 2); 
}

int main(){
    Car car(0,"");
    Admin admin(0);
    Parking parking;
    Ticket ticket;
    VipTicket vipticket;
    int choice;
    parking.fill_random_lots();

    do{
        main_menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            car.car_autorization();
            choice_ticket();
            car.car_end();
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
