#include "Tile.h"
#include "Ship.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Board.h"
#include "Player.h"
#include "Game.h"

#include <iostream>
#include <ctime>

using namespace std;


//Constructor
//Ο τύπος κάθε Tile του πίνακα γίνεται sea

Board::Board(){
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            board[i][j].setSea();
        }
    }
}


//Συνάρτηση που εκτυπώνει το board

void Board::drawBoards(){
    int i, j;

    cout << "\t-\tC\tO\tM\t- " << "\n\n" << " ";

    for(i=0; i<N; i++){
        cout << "\t" << i;
    }

    cout << endl << endl;

    for(i=0; i<M; i++)
    {
        cout << i << "\t";

        for(j=0; j<N; j++)
        {
            board[i][j].draw(true);
            cout << "\t";
        }

    cout << endl << endl ;
    }
}


//Τοποθέτηση όλων των πλοίων τυχαία λαμβάνοντας υπόψη τα exception

void Board::placeAllShips(){
    srand (time(NULL)); //Το δηλώνω για να έχω τυχαίες τιμές με βάση το χρόνο

    int randomX, randomY, i;
    const int numberOfShips = 3;
    Ship::Orientation randomOrientation;
    Tile startTile;

    Ship* ships[numberOfShips];
    ships[0] = new Battleship;
    ships[1] = new Cruiser;
    ships[2] = new Destroyer;

    for(i=0; i<numberOfShips; i++){
        while(true){
            randomX = rand() % M;
            randomY = rand() % N;
            randomOrientation = static_cast<Ship::Orientation>(rand()%2);
            startTile.setCoordinates(randomX, randomY);

            if(ships[i] -> isOutOfBoard(board, startTile, randomOrientation, false) == false &&
               ships[i] -> isAnotherShip(board, startTile, randomOrientation, false) == false &&
               ships[i] -> isNextToAnotherShip(board, startTile, randomOrientation, false) == false){
                ships[i] -> placeShip(startTile, randomOrientation, board);
                break;
               }
        }
    }

  	for(i=0; i<numberOfShips; i++){
      delete [] ships[i];
    }
}


//Συνάρτηση που ελέγχει αν τα πλοία έχουν βυθιστεί
//Εάν έστω και ένα κελί  του πίνακα είναι ship τότε επιστρέφει false, αλλιώς true

bool Board::allShipsSunk(){

    bool isValid=true;

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(board[i][j].getTileType()==Tile::Type::ship){
                isValid=false;
            }
        }
    }

    return isValid;
}
