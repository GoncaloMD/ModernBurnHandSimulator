#include "BurnUtils.h"
#include "CardName.h"

bool isTurnOnePlay(Card card) {
	if (card.getManaValue() == 1 || card.getName() == CardName::RIFT_BOLT) {
		if (card.getName() == CardName::SHARD_VOLLEY) {
			return false;
		}
		else {
			return true;
		}
	}
	return false;
}

bool containsTurnOnePlay(vector<Card> hand) {
	for (int i = 0; i < hand.size(); i++) {
		if (isTurnOnePlay(hand[i])) {
			return true;
		}
	}
	return false;
}

int numberOfTurnOnePlays(vector<Card> hand) {
	int numberOfTurnOnePlays = 0;
	for (int i = 0; i < hand.size(); i++) {
		if (isTurnOnePlay(hand[i])) {
			numberOfTurnOnePlays++;
		}
	}
	return numberOfTurnOnePlays;
}