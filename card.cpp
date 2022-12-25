#include "Card.h"

using namespace std;

Card::Card(){}

Card::Card(string name, Type type, int manaValue, ManaCost manaCost){
	this->name = name;
	this->type = type;
	this->manaValue = manaValue;
	this->manaCost = manaCost;
}

string Card::getName(){
	return this->name;
}

Type Card::getType() {
	return this->type;
}

int Card::getManaValue() {
	return this->manaValue;
}
