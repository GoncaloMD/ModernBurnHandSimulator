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

        Deck(const vector<Card>& deck)
            : deck(deck) {};
		void addCard(Card card);
		void addCards(Card card, int numberOfCopies);

		void shuffle();
		Deck getShuffledCopy();

		void draw(vector<Card> &hand);

		void print();

		//Getters
		vector<Card> getDeck();
};

#endif