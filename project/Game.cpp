#include "Tile.h"
#include "Ship.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Board.h"
#include "Player.h"
#include "Game.h"

#include <iostream>
#include <sstream>

using namespace std;


//Συνάρτηση που επιστρέφει τις δύο τιμές από τον παίκτη σε πίνακα αφού ελέγξει πρώτα ότι η μορρφοποίση είναι όπως απαιτείται

int* Game::getInput(){

    while (getline(cin, line)){
        stringstream ss(line);

        if (ss >> nX >> nY && ( nX<M && nX>=0  && nY<N && nY>=0)){
            if (ss.eof()){
                break;
            }
        }

        cout << "Please, enter a correct value." << endl;
    }

    cboard[0] = nX;
    cboard[1] = nY;

    return cboard;
}
