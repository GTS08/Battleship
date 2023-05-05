#ifndef SHIP_H
#define SHIP_H
#include "Board.h"

//Δήλωση μελών της κλάσης(μεταβλητές, συναρτήσεις, constructor, enum)

class Ship{
    public:
        Ship(int s);
        enum Orientation {horizontal, vertical};
        bool placeShip(Tile startCell, Orientation direction, Tile board[][N]);
        bool isOutOfBoard(Tile board[][N], Tile startCell, Orientation direction, bool exceptionMessages);
        bool isAnotherShip(Tile board[][N], Tile startCell, Orientation direction, bool exceptionMessages);
        bool isNextToAnotherShip(Tile board[][N], Tile startCell, Orientation direction, bool exceptionMessages);

    private:
        int shipSize;
};

#endif
