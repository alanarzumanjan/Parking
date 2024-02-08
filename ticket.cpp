#include <iostream>
#include <vector>

using namespace std;

class Ticket {
    private:
        vector<Ticket> tickets;
    public:
        int ticket_id;
        int place_number;
        float total_cost = 10;
        Ticket(int id, int pn) : 
            ticket_id(id), place_number(pn){}
};

class VipTicket: public Ticket {
    float total_cost = 15;
    VipTicket(int ip, int pn) : Ticket(ip, pn){}
};