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

        cout << "Choose ticket type:\n";
        cout << "Press 1 for hour ticket\n";
        cout << "Press 2 for 2 hour ticket\n";
        cout << "Press 3 for 1 day ticket\n";
        cin >> ticketType;

        switch (ticketType)
        {
        case 1:
            cout << "Price for 1 hour ticket: $3\n";
            break;
        case 2:
            cout << "Price for 2 hour ticket: $5\n";
            break;
        case 3:
            cout << "Price for 1 day ticket: $30\n";
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
