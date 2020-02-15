#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"

#include <string>

using std::string;

//Δήλωση μελών της κλάσης(μεταβλητές, συναρτήσεις)

class Player{
    public:
        void fire(Tile board[][N], int cboard[2]);
        void getStats();
        void setName(string n);
        string getName();

    private:
        int shotsMade=0;
        int shotsMissed=0;
        int shotsHit=0;
        int shotsRepeated=0;
        string name;
};

#endif
