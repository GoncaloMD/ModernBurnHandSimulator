#include "BurnUtils.h"
#include "CardName.h"

bool isTurnOnePlay(Card card) {
	if (card.getManaValue() == 1 || card.getName() == CardName::RIFT_BOLT) {
		return true;
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