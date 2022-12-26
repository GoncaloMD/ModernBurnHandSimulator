#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

using namespace std;

class Deck {
	private:
		vector<Card> deck;

	public:
		Deck() {};

		void addCard(Card card);
		void addCards(Card card, int numberOfCopies);

		void shuffle();
		Deck getShuffledCopy();

		Card draw();

		void print();

		//Getters
		vector<Card> getDeck();
};

#endif