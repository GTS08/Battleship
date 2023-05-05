#include "Tile.h"
#include "Ship.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Board.h"
#include "Player.h"
#include "Game.h"

#include <iostream>
#include <string>

using namespace std;


//Setter και getter συναρτήσεις για το όνομα του χρήστη

void Player::setName(string n){
    name = n;
}

string Player::getName(){
    return name;
}


//Ανάλογα με τον τύπο του ήδη υπάρχοντος κελιού το κελί αλλάζει σύμφωνα με τη βολή μας και ενημερώνει ανάλογα τα στατιστικά του παίκτη

void Player::fire(Tile board[][N], int cboard[2]){
    shotsMade++;

    int x = cboard[0];
    int y = cboard[1];

    if(board[x][y].getTileType()==Tile::Type::miss){
        shotsRepeated++;
        cout << "You already missed that shot." << endl;
    }
    else if(board[x][y].getTileType()==Tile::Type::hit){
        shotsRepeated++;
        cout << "You already hit that shot." << endl;
    }
    else if(board[x][y].getTileType()==Tile::Type::sea){
        board[x][y].setMiss();
        shotsMissed++;
        cout << "You missed your shot." << endl;
    }
    else if(board[x][y].getTileType()==Tile::Type::ship){
        board[x][y].setHit();
        shotsHit++;
        cout << "You hit a ship." << endl;
    }
}


//Εκτυπώνει τα στατιστικά του παίκτη

void Player::getStats(){
  	cout << "Name of player: " << name << endl;
    cout << "Shots made: " << shotsMade << endl;
    cout << "Shots missed: " << shotsMissed << endl;
    cout << "Shots hit: " << shotsHit << endl;
    cout << "Shots repeated: " << shotsRepeated << endl;
}
