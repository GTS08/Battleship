#ifndef BOARD_H
#define BOARD_H

#define M 5
#define N 5

//Δήλωση μελών της κλάσης(μεταβλητές, συναρτήσεις, constructor)

class Board{
    public:
        Tile board[M][N];
        Board();
        void drawBoards();
        void placeAllShips();
        bool allShipsSunk();
};

#endif
