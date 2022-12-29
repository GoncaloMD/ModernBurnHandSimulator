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

KeepPercentageResult getKeepPercentageDistribution(Deck deck, int numberOfReps, bool isOnPlay) {

    int numberOfMulls = 0;
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
            numberOfMulls++;
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
                numberOfMulls++;
            }
            break;

        case 2:
            //Keep hands that include at least one card you can cast on turn 1
            if (numberOfTurnOnePlays(hand) >= 1) {
                numberOfKeeps[2]++;
            }
            else {
                numberOfMulls++;
            }
            break;

        case 3:
            //Keep hands that include at least one card you can cast on turn 1
            if (numberOfTurnOnePlays(hand) >= 1) {
                numberOfKeeps[3]++;
            }
            else {
                numberOfMulls++;
            }
            break;

        case 4:
        case 5:
        case 6:
        case 7:
        default:
            numberOfMulls++;
            break;
        }
    }
	
    return KeepPercentageResult(numberOfMulls, numberOfKeeps);
}

std::vector<KeepPercentageResult> getKeepPercentageDistributionPlayDraw(Deck deck, int numberOfReps) {
    std::vector<KeepPercentageResult> results;

    results.push_back(getKeepPercentageDistribution(deck, numberOfReps, true));
    results.push_back(getKeepPercentageDistribution(deck, numberOfReps, false));

    return results;
}