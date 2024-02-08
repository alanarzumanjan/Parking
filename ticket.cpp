#include <iostream>
#include <vector>

using namespace std;

class Ticket {
    private:
        vector<Ticket> tickets;
    public:
        int ticket_id;
        int cost_hour = 20;
        int place_number;
        float total_cost = 10;
        Ticket(int id, int pn) : 
            ticket_id(id), place_number(pn){}
        
        void printVipTicket() {
            cout << "Ticket ID: " << ticket_id <<
            "\nPlace number: " << place_number <<
            "\nCost per hour: " << cost_hour <<
            "\nTotal cost: " << total_cost << endl;
        }
};

class VipTicket: public Ticket {
    int cost_hour = 40;
    float total_cost = 15;
    VipTicket(int ip, int pn) : Ticket(ip, pn){}

    void printVipTicket() {
        cout << "VIP ticket ID: " << ticket_id <<
        "\nPlace number: " << place_number <<
        "\nCost per hour: " << cost_hour <<
        "\nTotal cost: " << total_cost << endl;
    }
};