#include <vector>

#include "BurnUtils.h"
#include "CardName.h"
#include "BurnCards.h"

//TODO: migrate this to Card class
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

//TODO: maybe these vector<card> methods should be somewhere else. statics in card?
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

bool containsCard(std::vector<Card> list, Card card) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == card) return true;
    }
    return false;
}

SimulationResult simulate(Deck deck, int numberOfReps, bool isOnPlay) {

    vector<int> numberOfMulls{ 0, 0, 0, 0, 0, 0, 0, 0 };
    vector<int> numberOfKeeps{ 0, 0, 0, 0, 0, 0, 0, 0 };

    for (int rep = 0; rep < numberOfReps; rep++) {
        Deck library = deck.getShuffledCopy();
        vector<Card> hand;

        for (int i = 0; i < 7; i++) {
            hand.push_back(library.draw());
        }

        //calculate keeps
        int numberOfLands = 0;

        //calculate number of lands in opener
        for (int i = 0; i < hand.size(); i++) {
            if (hand[i].getType() == Type::LAND) {
                numberOfLands++;
            }
        }

        switch (numberOfLands) {
        case 0:
            numberOfMulls[0]++;
            break;

        case 1:
            //Keep hands that are on the play AND contain at least 2 cards you can cast for 1 mana
            if (!isOnPlay && numberOfTurnOnePlays(hand) >= 2) {
                numberOfKeeps[1]++;
            }
            //Keep hands that include at least one copy of Play with Fire and at least 2 cards you can cast for 1 mana
            else if (containsCard(hand, playWithFire) && numberOfTurnOnePlays(hand) >= 2) {
                numberOfKeeps[1]++;
            }
            else {
                numberOfMulls[1]++;
            }
            break;

        case 2:
            //Keep hands that include at least one card you can cast on turn 1
            if (numberOfTurnOnePlays(hand) >= 1) {
                numberOfKeeps[2]++;
            }
            else {
                numberOfMulls[2]++;
            }
            break;

        case 3:
            //Keep hands that include at least one card you can cast on turn 1
            if (numberOfTurnOnePlays(hand) >= 1) {
                numberOfKeeps[3]++;
            }
            else {
                numberOfMulls[3]++;
            }
            break;

        case 4:
            numberOfMulls[4]++;
            break;

        case 5:
            numberOfMulls[5]++;
            break;

        case 6:
            numberOfMulls[6]++;
            break;

        case 7:
            numberOfMulls[7]++;
            break;

        default:
            break;
        }
    }
	
    return SimulationResult(numberOfMulls, numberOfKeeps);
}

std::vector<SimulationResult> simulatePlayDraw(Deck deck, int numberOfReps) {
    std::vector<SimulationResult> results;

    results.push_back(simulate(deck, numberOfReps, true));
    results.push_back(simulate(deck, numberOfReps, false));

    return results;
}