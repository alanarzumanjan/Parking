```mermaid
--- 
title: Parking menegment
---
classDiagram
    class Parking
        Parking : +int max_places
        Parking : +int filled_lots
        Parking : +int notfilled_places
        Parking : fill_random_lots()
        Parking : +int minNotFilled
        Parking : +int maxNotFilled
        Parking : takeParkingSpot()
        Parking : print_notfilled_lots()