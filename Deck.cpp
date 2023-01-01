#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

#include "Deck.h"
#include "CardName.h"

void Deck::addCard(Card card) {
	deck.push_back(card);
}

void Deck::addCards(Card card, int numberOfCopies) {
	for (int i = 0; i < numberOfCopies; i++) {
		deck.push_back(card);
	}
}

void Deck::shuffle() {
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}

Deck Deck::getShuffledCopy() {
	Deck copy = Deck(deck);
	copy.shuffle();
	return copy;
}

void Deck::draw(vector<Card> &hand) {
	hand.push_back(deck[deck.size() - 1]);

	deck.pop_back();
}

void Deck::print() {
    for (const auto& card : deck) {
        cout << toStringFromCardName(card.getName()) << endl;
    }
	cout << endl;
}

vector<Card> Deck::getDeck() {
	return deck;
}