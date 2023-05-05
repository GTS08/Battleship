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


//Getters συναρτήσεις για τις συντεταγμένες

int Tile::getCoordinatesX(){
    return X;
}


int Tile::getCoordinatesY(){
    return Y;
}


//Setter συνάρτηση για τις συντεταγμένες

void Tile::setCoordinates(int x, int y){
    X = x;
    Y = y;
}


//Setters συναρτήσεις για τον τύπο του Tile δηλαδή το tileType
//Το tileType μπορεί να πάρει τις τιμές sea, ship, hit και miss

void Tile::setSea(){
    tileType = sea;
}

void Tile::setShip(){
    tileType = ship;
}

void Tile::setHit(){
    tileType = hit;
}

void Tile::setMiss(){
    tileType = miss;
}


//Getter συνάρτηση για τον τύπο του Tile

Tile::Type Tile::getTileType(){
    return tileType;
}

//Εκτύπωση συμβόλου ανάλογα με το τύπο του enum
//Γίνεται χρήση της switch statement

void Tile::draw(bool hidden){

    switch(tileType){
        case hit:
            symbol = 'X';
            cout << symbol;
            break;

        case sea:
            symbol = '~';
            cout << symbol;
            break;

        case miss:
            symbol='o';
            cout << symbol;
            break;

        case ship:
            symbol='s';
            char printSymbol;
            if(hidden==false){
                printSymbol = symbol;
                cout << printSymbol;
            }
            else{
                printSymbol='~';
                cout << printSymbol;
            }
            break;

        default:
            cout << "Something went wrong";
            break;
    }
}
