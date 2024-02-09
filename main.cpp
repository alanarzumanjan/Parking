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
        int choice;
        do{
            cout << "Whitch ticket do you need?" << endl;
            cout << "1. VipTicket" << endl;
            cout << "2. Default Ticket" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch(choice){
                case 1:
                    return_choice(choice);
                    break;
                case 2:
                    return_choice(choice);
                    break;
                default:
                    cout << "Incorrect answer, repeat please" << endl;
            }
        }while(choice != 1 | choice != 2);
            
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
                this_thread::sleep_for(chrono::seconds(5));
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
        } else {
            cout << "All parking lots are filled." << endl;
        }
    }
};

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
            
            while(choice!=4);
            switch (choice) {
                case 1:
                    cout << "Enter price for Default ticket (between 1 and 1000 dollars): ";
                    cin >> price;
                    if (price >= 1 && price <= 1000) {
                        ticket_cost = price;
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
                        ticket_cost = price;
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
                    this_thread::sleep_for(chrono::seconds(2));
                    break;
            }
            cout << endl;
        } while(choice != 4);
    }
};


class Ticket {
    private:
        vector<Ticket> tickets;
        static int next_ticket_id;
    protected:
        int ticket_id;
    public:
        int cost_hour = 20;
        Parking parking;
        int place_number;
        float total_cost = 10;
        Ticket() : ticket_id(next_ticket_id++), place_number(parking.notfilled_lots[ticket_id - 1]) {}
        
        void printTicket() {
            cout << "Ticket ID: " << ticket_id <<
            "\nPlace number: " << place_number <<
            "\nCost per hour: " << cost_hour << endl;
            this_thread::sleep_for(chrono::seconds(10));
        }
};

class VipTicket: public Ticket {
    private:
        vector<Ticket> viptickets;
        static int next_vip_ticket_id;
    protected:
        int vip_ticket_id;
    public:
        Parking parking;
        int place_number;
        int cost_hour = 40;
        float total_cost = 15;
        VipTicket() : vip_ticket_id(next_vip_ticket_id++), place_number(parking.notfilled_lots[ticket_id - 1]){};

        void printVipTicket() {
            // every next ticket id += 1
            // place_number должен выбираться из свободных мест
            cout << "VIP ticket ID: " << ticket_id <<
            "\nPlace number: " << place_number <<
            "\nCost per hour: " << cost_hour << endl;
            this_thread::sleep_for(chrono::seconds(10));
        }
};

int Ticket::next_ticket_id = 1;
int VipTicket::next_vip_ticket_id = 1;

void main_menu(){
    cout << endl << "--->Parking<---" << endl;
    cout << "1. Parking Authorization" << endl;
    cout << "2. Admin" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main(){
    Car car(0,"");
    Admin admin(0);
    Parking parking;
    Ticket ticket;
    VipTicket vipticket;
    int choice;

    do{
        main_menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            car.car_autorization();
            parking.fill_random_lots();
            ticket.printTicket();
            car.car_end();
            break;
        case 2:
            admin.admin_functions();
            break;
        case 3:
            cout << "Exiting program.." << endl;
            // need time sleep 2-3s
            this_thread::sleep_for(chrono::seconds(2));
            break;
        default:
            cout << "Incorrect answer, please repeat." << endl;
            this_thread::sleep_for(chrono::seconds(2));
        } 
    }while(choice != 3);
    
    return 0;
}
