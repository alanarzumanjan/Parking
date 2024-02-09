#include <iostream>
#include <vector>
#include "park.cpp"
#include "main.cpp"

using namespace std;

class Ticket {
    private:
        vector<Ticket> tickets;
        static int next_ticket_id;
    protected:
        int ticket_id;
    public:
        int cost_hour = 20;
        Parking parking;
        Car car;
        int place_number;
        float total_cost = 10;
        Ticket(int cn) : ticket_id(next_ticket_id++), place_number(parking.notfilled_lots[ticket_id - 1]) {}
        
        void printTicket() {
            // every next ticket id += 1
            // place_number должен выбираться из свободных мест
            // + спрос какой билет вы хотите
            cout << "Ticket ID: " << ticket_id <<
            "\nPlace number: " << place_number <<
            "\nCost per hour: " << cost_hour << endl;
        }

        void printCheck() {
            cout << "Car number: " << car.car_number <<
            "\nTicket ID: " << ticket_id <<
            "\nPlace number: " << place_number <<
            "\nCost per hour: " << cost_hour <<
            "\nTotal cost: " << total_cost << endl;
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
            "\nCost per hour: " << cost_hour <<
            "\nTotal cost: " << total_cost << endl;
        }
};

int Ticket::next_ticket_id = 1;
int VipTicket::next_vip_ticket_id = 1;

int main() {
    Ticket* ticket1 = new Ticket();
    VipTicket* ticket2 = new VipTicket();
    ticket1->printTicket();
    ticket2->printVipTicket();
}