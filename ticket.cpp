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
<<<<<<< HEAD
        Ticket(int id, int pn) : 
            ticket_id(id), place_number(pn){}
=======
        Ticket(int id, int pn) : ticket_id(id), place_number(pn){}

        void printTicket() {
            cout << "Ticket ID: " << ticket_id <<
            "\nPlace number: " << place_number <<
            "\nCost per hour: " << cost_hour <<
            "\nTotal cost: " << total_cost << endl;
        }
>>>>>>> 29cb243 (mama)
};

class VipTicket: public Ticket {
    int cost_hour = 40;
    float total_cost = 15;
    VipTicket(int ip, int pn) : Ticket(ip, pn){}

    void printVipTicket() {
        cout << "Ticket ID: " << ticket_id <<
        "\nPlace number: " << place_number <<
        "\nCost per hour: " << cost_hour <<
        "\nTotal cost: " << total_cost << endl;
    }
};