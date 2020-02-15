#ifndef DESTROYER_H
#define DESTROYER_H

//Δήλωση μελών της κλάσης(constructor)

class Destroyer: public Ship{
    public:
        Destroyer(int d=2):Ship(d){};
};

#endif
