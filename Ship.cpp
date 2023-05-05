#include "Tile.h"
#include "Ship.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Board.h"
#include "Player.h"
#include "Game.h"

#include <iostream>

using namespace std;


//Constructor

Ship::Ship(int s){
    shipSize = s;
}


//Συνάρτηση που επιστρέφει true αν τοποθετήθηκε πλοίο

bool Ship::placeShip(Tile startCell, Orientation direction, Tile board[][N]){

    int i;
    int x = startCell.getCoordinatesX();
    int y = startCell.getCoordinatesY();

    if(direction == horizontal){
        for(i=y; i<=y+shipSize - 1; i++){
            board[x][i].setShip();
        }
    }
    else if(direction == vertical){
        for(i=x; i<=x+shipSize - 1; i++){
            board[i][y].setShip();
        }
    }

    return true;
}


//Συνάρτηση που εάν το πλοίο ξεπερνάει τα όρια του πίνακα θα κάνει throw OversizeException και θα επιστρέψει true

bool Ship::isOutOfBoard(Tile board[][N], Tile startCell, Orientation direction, bool exceptionMessages){

    int x = startCell.getCoordinatesX();
    int y = startCell.getCoordinatesY();
    bool isInvalid = false;

    try{
        if(direction == horizontal){
            if(y+shipSize-1>=N){
                isInvalid=true;
            }
        }

        else if(direction == vertical){
            if(x+shipSize-1>=M){
                isInvalid=true;
            }
        }

        if(isInvalid == true){
            throw "OversizeException occurred! ";
        }
    }
    catch(const char *e){
        if(exceptionMessages == true){
            cout << e << "The ship cant get out of the gameboard borders." << endl;
        }
    }

    return isInvalid;
}


//Συνάρτηση που εάν η θέση που τοποθετηθεί το πλοίο υπάρχει άλλο θα κάνει throw OverlapTilesException και θα επιστρέψει true

bool Ship::isAnotherShip(Tile board[][N], Tile startCell, Orientation direction, bool exceptionMessages){

    int i;
    int x = startCell.getCoordinatesX();
    int y = startCell.getCoordinatesY();
    bool isInvalid=false;

    try{
        if(direction == horizontal){
            for(i=y; i<=y+shipSize - 1; i++){
                if(board[x][i].getTileType() == Tile::Type::ship){
                    isInvalid = true;
                }
            }
        }
        else if(direction == vertical){
            for(i=x; i<=x+shipSize - 1; i++){
                if(board[i][y].getTileType() == Tile::Type::ship){
                    isInvalid = true;
                }
            }
        }

        if(isInvalid == true){
            throw "OverlapTilesException occurred! ";
        }

    }
    catch(const char *e){
        if(exceptionMessages == true){
            cout << e << "The ship cannot be placed in a tile where another one is already placed." << endl;
        }
    }

    return isInvalid;
}


//Συνάρτηση που ελέγχει αν στα γειτονικά κελιά υπάρχει ήδη πλοίο, αν ναι επιστρέφει true αλλιώς επιστρέφει false

bool Ship::isNextToAnotherShip(Tile board[][N], Tile startCell, Orientation direction, bool exceptionMessages){

    int i;
    int x = startCell.getCoordinatesX();
    int y = startCell.getCoordinatesY();
    bool isInvalid=false;

    try{
        if(direction == horizontal){
            if(y>0){
                if(board[x][y-1].getTileType() == Tile::Type::ship){
                    isInvalid = true;
                }
            }

            if(y+shipSize<N){
                if(board[x][y+shipSize].getTileType() == Tile::Type::ship){
                    isInvalid = true;
                }
            }

            for(i=y; i<y+shipSize; i++){
                if(x>0){
                    if(board[x-1][i].getTileType() == Tile::Type::ship){
                        isInvalid = true;
                    }
                }

                if(x<M-1){
                    if(board[x+1][i].getTileType() == Tile::Type::ship){
                        isInvalid = true;
                    }
                }
            }
        }
        else if(direction == vertical){
            if(x>0){
                if(board[x-1][y].getTileType() == Tile::Type::ship){
                    isInvalid = true;
                }
            }

            if(x+shipSize < M){
                if(board[x+1][y].getTileType() == Tile::Type::ship){
                    isInvalid = true;
                }
            }

            for(i=x; i<x+shipSize; i++){
                if(y>0){
                    if(board[i][y-1].getTileType() == Tile::Type::ship){
                        isInvalid = true;
                    }
                }

                if(y<N-1){
                    if(board[i][y+1].getTileType() == Tile::Type::ship){
                        isInvalid = true;
                    }
                }
            }
        }

        if(isInvalid == true){
            throw "AdjacentTilesException occurred! ";
        }
    }
    catch(const char *e){
            if(exceptionMessages == true){
                cout << e << "There must be at least one tile empty between ships." << endl;
        }
    }

    return isInvalid;
}
