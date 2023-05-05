#ifndef TILE_H
#define TILE_H

//Δήλωση μελών της κλάσης(μεταβλητές, συναρτήσεις, enum)

class Tile{
    public:
        enum Type {sea, ship, hit, miss};
        int getCoordinatesX();
        int getCoordinatesY();
        void setCoordinates(int x, int y);
        void setSea();
        void setShip();
        void setHit();
        void setMiss();
        Type getTileType();
        void draw(bool hidden);

    private:
        int X, Y;
        char symbol;
        Type tileType;
};

#endif
