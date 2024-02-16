```mermaid
--- 
title: Parking menegment
---
classDiagram
    class Car
        Car : +int car_number
        Car : +float parking_time
        Car : +parking_seconds
        Car : +hours
        Car : +minutes
        Car : car_autorization()
        Car : calculate_time()
<<<<<<< HEAD
        Car : car_end()

=======
        Car : return_choice(int choice)
        Car : car_autorization()
        Car : car_end()
        Car : updateCarNumber(string number)
>>>>>>> 19a19b3 (Markus is so hard pony)
    class Parking
        Parking : +int max_places
        Parking : +int filled_lots
        Parking : +int notfilled_places
        Parking : fill_random_lots()
        Parking : +int minNotFilled
        Parking : +int maxNotFilled
        Parking : takeParkingSpot()
        Parking : print_notfilled_lots()

    class Ticket
        Ticket : +int ticket_id
        Ticket : +int cost_hour
        Ticket : +int place_number
        Ticket : +float total_cost
        Ticket : +vector Ticket
        Ticket : printTicket()
        Ticket : print_check_ticket()

    class VipTicket
        VipTicket : +int ticket_id
        VipTicket : +int cost_hour
        VipTicket : +int place_number
        VipTicket : +float total_cost
        VipTicket : +vector VipTicket
        VipTicket : printVipTicket()
        VipTicket : print_check_ticket()
        
    class Admin
        Admin: +int ticket_cost
        Admin: +int choice
        Admin: +int price
        Admin: main_menu()
        Admin: choice_ticket()
        Admin: set_ticket_cost()
        Admin: printout_of_free_and_occupied_seats()

    VipTicket <|-- Ticket
    Ticket <-- Car
    Parking o-- Car
    Parking <-- Admin
```