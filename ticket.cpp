#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>
//#include "park.cpp"
//#include "main.cpp"

using namespace std;

class Car
{
public:
    int car_number;
    string parking_time;
    int parking_seconds = 10 + rand() % 250;
    int hours = parking_seconds / 3600;
    int minutes = (parking_seconds % 3600) / 60;

    Car(int car_number, string parking_time): car_number(car_number), parking_time(parking_time) {}
    Car() : car_number(0), parking_time("") {}

    int return_choice(int choice){
        return choice;
    }

    string calculate_time(){
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
        }
        else {
            cout << "All parking lots are filled." << endl;
        }
    }
};


class Ticket: public Car {
    private:
        vector<Ticket> tickets;
        static int next_ticket_id;
    protected:
        static int ticket_id;
        float seconds = parking_seconds;
    public:
        static int cost_hour;
        Parking parking;
        int place_number;
        float total_cost;
        Ticket() : place_number(parking.notfilled_lots[ticket_id - 1]), total_cost((seconds / 3600) * cost_hour) {}
        static void setCostHour(int price) {
            cost_hour = price;
        }
        
        void printTicket() {
            // every next ticket id += 1
            // place_number должен выбираться из свободных мест
            // + спрос какой билет вы хотите
            cout << "Ticket ID: " << ticket_id <<
            "\nPlace number: " << place_number <<
            "\nCost per hour: " << cost_hour << endl;
        }

        void printCheck() {
            cout << "Car number: " << car_number <<
            "\nTicket ID: " << ticket_id <<
            "\nPlace number: " << place_number <<
            "\nCost per hour: " << cost_hour <<
            "\nTotal cost: " << total_cost <<
            "\nTotal time: " << calculate_time() << endl;
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
        static int cost_hour;
        float total_cost;
        VipTicket() : place_number(parking.notfilled_lots[ticket_id - 1]), total_cost((seconds / 3600) * cost_hour) {};
        
        static void setCostHour(int price) {
            cost_hour = price;
        }

        void printVipTicket() {
            // every next ticket id += 1
            // place_number должен выбираться из свободных мест
            cout << "VIP ticket ID: " << ticket_id <<
            "\nPlace number: " << place_number <<
            "\nCost per hour: " << cost_hour <<
            "\nTotal cost: " << total_cost << endl;
        }
};

int Ticket::ticket_id = 0;
int Ticket::cost_hour = 40;
int VipTicket::cost_hour = 60;

int main() {
    Ticket ticket1;
    VipTicket ticket2;
    ticket1.printTicket();
    ticket2.printVipTicket();
    ticket1.printCheck();
    ticket2.printCheck();
}