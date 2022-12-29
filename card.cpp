#include <iostream>

#include "Card.h"

using namespace std;

Card::Card(){}

Card::Card(CardName name, Type type, int manaValue, ManaCost manaCost){
	this->name = name;
	this->type = type;
	this->manaValue = manaValue;
	this->manaCost = manaCost;
}

Card Card::Land(CardName name) {
	return Card(
		name
		, Type::LAND
		, 0
		, ManaCost(0, 0, 0, 0, 0, 0)
	);
}

bool Card::operator==(const Card& card) {
	//We only need to compare the names of cards
	if (name == card.name) {
		return 1;
	}
	else {
		return 0;
	}
}

void Card::print() {
	cout << toStringFromCardName(name) << " ";
}


//GETTERS
CardName Card::getName(){
	return this->name;
}

Type Card::getType() {
	return this->type;
}

int Card::getManaValue() {
	return this->manaValue;
}