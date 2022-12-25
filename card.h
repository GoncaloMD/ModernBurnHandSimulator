#ifndef CARD_H
#define CARD_H

#include <string>

#include "Type.h"
#include "ManaCost.h"

using namespace std;

class Card{

    private:
        string name;
        Type type;
        int manaValue;
        ManaCost manaCost;

    public:
        Card();
        Card(string name, Type type, int manaValue, ManaCost manaCost);

        //Getters
        string getName();
        Type getType();
        int getManaValue();

};
#endif