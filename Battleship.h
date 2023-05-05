#ifndef BATTLESHIP_H
#define BATTLESHIP_H

//Δήλωση μελών της κλάσης(constructor)

class Battleship: public Ship{
    public:
        Battleship(int b=4):Ship(b){};
};

#endif
