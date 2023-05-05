#ifndef GAME_H
#define GAME_H

#include <string>

using std::string;

//Δήλωση μελών της κλάσης(μεταβλητές, συναρτήσεις)

class Game{
    public:
        int cboard[2];
				int* getInput();

    private:
        string line;
        int nX;
        int nY;
};

#endif
