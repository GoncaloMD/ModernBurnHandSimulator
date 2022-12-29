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
	Deck copy = Deck();
	copy.deck = deck;
	copy.shuffle();
	copy.shuffle();
	copy.shuffle();
	copy.shuffle();
	copy.shuffle();
	copy.shuffle();
	copy.shuffle();
	return copy;
}

Card Deck::draw() {
	Card card = deck[0];
	deck.erase(deck.begin());
	return card;
}

void Deck::print() {
	for (int i = 0; i < deck.size(); i++) {
		cout << toStringFromCardName(deck[i].getName()) << endl;
	}
	cout << endl;
}

vector<Card> Deck::getDeck() {
	return deck;
}