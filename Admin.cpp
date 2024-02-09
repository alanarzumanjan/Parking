#include <iostream>
#include <vector>

using namespace std;

class Admin
{
public:
    int ticket_cost;

    Admin(int tc) : ticket_cost(tc) {}

    void change_ticket_cost()
    {
        int ticketType;
        int price;

        cout << "Enter your ticket price:\n";
        cout << "Press 1 for Default ticket\n";
        cout << "Press 2 for Vip ticket\n";
        cin >> ticketType;

        switch (ticketType)
        {
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
};

int main()
{
    Admin admin(0);

    admin.change_ticket_cost();

    return 0;
}
