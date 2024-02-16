#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   

using namespace std;

class Admin {
public:
    static const int max_lots = 50;  
    int ticket_cost;
    vector<int> occupied_lots; 
    vector<int> free_lots; 

    Admin(int tc) : ticket_cost(tc) {}

    void change_ticket_cost() {
        int ticketType;
        int price;

        cout << "Enter your ticket price:\n";
        cout << "Press 1 to set price for Default ticket\n";
        cout << "Press 2 to set price for Vip ticket\n";
        cin >> ticketType;

        switch (ticketType) {
            case 1:
                cout << "Enter price for Default ticket (between 1 and 100 dollars): ";
                cin >> price;
                if (price >= 1 && price <= 100) {
                    ticket_cost = price;
                    cout << "Price for Default ticket: $" << ticket_cost << endl;
                } else {
                    cout << "Invalid price! Please enter a value between 1 and 100 dollars.\n";
                }
                break;
            case 2:
                cout << "Enter price for Vip ticket (between 5 and 100 dollars): ";
                cin >> price;
                if (price >= 5 && price <= 100) {
                    ticket_cost = price;
                    cout << "Price for Vip ticket: $" << ticket_cost << endl;
                } else {
                    cout << "Invalid price! Please enter a value between 5 and 100 dollars.\n";
                }
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    }

    void printout_of_free_and_occupied_lots() {
        for (int i = 1; i <= max_lots; ++i) {
            if (rand() % 2 == 0) { 
                free_lots.push_back(i);
            } else {
                occupied_lots.push_back(i);
            }
        }

        int choice;
        cout << "Press 3 to see a Free Lot.\n";
        cout << "Press 4 to see an Occupied Lot.\n";
        cin >> choice;

        switch(choice) {
            case 3:
                if (free_lots.empty()) {
                    cout << "No free lots available.\n";
                } else {
                    int random = rand() % free_lots.size();
                    cout << "Free Lot: " << free_lots[random] << endl;
                }
                break;

            case 4:
                if (occupied_lots.empty()) {
                    cout << "No occupied lots available.\n";
                } else {
                    int random = rand() % occupied_lots.size();
                    cout << "Occupied Lot: " << occupied_lots[random] << endl;
                }
                break;

            default:
                cout << "Invalid choice!\n";
                break;
        }
    }
};

int main() {
    srand(time(0));
    Admin admin(0);

    admin.change_ticket_cost();
    admin.printout_of_free_and_occupied_lots();

    return 0;
}
