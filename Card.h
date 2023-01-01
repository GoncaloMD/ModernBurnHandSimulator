#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

#include "CardName.h"
#include "Type.h"
#include "ManaCost.h"

using namespace std;

class Card{

    private:
        CardName name;
        Type type;
        int manaValue;
        ManaCost manaCost;

    public:
        Card();
        Card(CardName name, Type type, int manaValue, ManaCost manaCost);

        static Card Land(CardName name);

        bool operator ==(const Card& card) const;

        void print();

        //Getters
        CardName getName() const;
        Type getType() const;
        int getManaValue() const;

        bool isCanopy() const {
            return (name == SUNBAKED_CANYON || name == FIERY_ISLET);
        }

};
#endif