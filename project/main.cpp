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


int main(){
    Board b;
    Player p;
    Game g;

    cout << "---------------------\n---- BATTLESHIP -----\n---------------------\n\n";

    cout << "Please, enter your name: ";
    string userName;
    getline(cin, userName);
    p.setName(userName);
    cout << endl;

    b.placeAllShips();

    cout << "The Opponent has placed all of its ships." << endl
         << "Here is its board." << endl
         << endl;

    b.drawBoards();

    cout << p.getName() <<", you have 10 shots to destroy all of its ships." << endl
         << "Make them count!" << endl
         << endl;

    cout << "Please enter two integer values separating by space." << endl
         << "First one is for row and second its for column."
         << endl;

    int counter=1;

    cout << endl;


    //Όσο ο παίκτης δεν έχει καταστρέψει όλα τα πλοία ή δεν έχει συμπληρώσει δέκα βολές, θα συνεχίζει να ρίχνει βολές
    //Αυτό γίνεται με την χρήση while loop

    while(b.allShipsSunk()==false && counter<=10){
        if(counter==1){
            cout << "Give coordinates for your " << counter << "st try: "<< endl;
        }
        else if(counter==2){
            cout << "Give coordinates for your " << counter << "nd try: "<< endl;
        }
        else if(counter==3){
            cout << "Give coordinates for your " << counter << "rd try: "<< endl;
        }
        else{
            cout << "Give coordinates for your " << counter << "th try: "<< endl;
        }

        g.getInput();
        cout << endl;

        p.fire(b.board, g.cboard);
        cout << endl;

        b.drawBoards();
        counter++;
    }

    cout << endl;


    //Εκτύπωση αποτελεσμάτων

    if(b.allShipsSunk()==true){
        cout << "CONGRATULATIONS! YOU WON!" << endl << endl;
    }
    else{
        cout << "BETTER LUCK NEXT TIME! YOU LOST!" << endl << endl;
    }

    cout << "YOUR STATS" << endl;
    cout << "----------" << endl;

    p.getStats();//Εκτύπωση των στατιστικών του παίκτη

    return 0;
}
