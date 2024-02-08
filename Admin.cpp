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
        cout << "Press 1 for 1 hour ticket:\n";
        cout << "Press 2 for 2 hour ticket\n";
        cout << "Press 3 for 1 day ticket\n";
        cin >> ticketType;

        switch (ticketType)
        {
        case 1:
            cout << "Enter price for 1 hour ticket (between 1 and 10 dollars): ";
            cin >> price;
            if (price >= 1 && price <= 10) {
                ticket_cost = price;
                cout << "Price for 1 hour ticket: $" << ticket_cost << endl;
            } else {
                cout << "Invalid price! Please enter a value between 1 and 10 dollars.\n";
            }
            break;
        case 2:
            cout << "Enter price for 2 hour ticket (between 5 and 15 dollars): ";
            cin >> price;
            if (price >= 5 && price <= 15) {
                ticket_cost = price;
                cout << "Price for 2 hour ticket: $" << ticket_cost << endl;
            } else {
                cout << "Invalid price! Please enter a value between 5 and 15 dollars.\n";
            }
            break;
        case 3:
            cout << "Enter price for 1 day ticket (between 25 and 40 dollars): ";
            cin >> price;
            if (price >= 1 && price <= 10) {
                ticket_cost = price;
                cout << "Price for 1 day ticket: $" << ticket_cost << endl;
            } else {
                cout << "Invalid price! Please enter a value between 25 and 40 dollars.\n";
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
