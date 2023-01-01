#include <iostream>

#include "Card.h"

using namespace std;

Card::Card(){}

Card::Card(CardName name, Type type, int manaValue, ManaCost manaCost) :
    name(name),
    type(type),
    manaValue(manaValue),
    manaCost(manaCost)
{}

Card Card::Land(CardName name) {
	return Card(
		name
		, Type::LAND
		, 0
		, ManaCost(0, 0, 0, 0, 0, 0)
	);
}

bool Card::operator==(const Card& card) const {
    return (name == card.name);
}

void Card::print() {
	cout << toStringFromCardName(name) << " ";
}


//GETTERS
CardName Card::getName() const {
	return name;
}

Type Card::getType() const {
	return type;
}

int Card::getManaValue() const {
	return manaValue;
}