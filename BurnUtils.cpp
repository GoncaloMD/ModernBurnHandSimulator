#include <vector>
#include <algorithm>

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

int countLands(std::vector<Card> hand) {
    int numberOfLands = 0;
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i].getType() == LAND) {
            numberOfLands++;
        }
    }
    return numberOfLands;
}

int countNonLands(std::vector<Card> hand) {
    int numberOfNonLands = 0;
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i].getType() != LAND) {
            numberOfNonLands++;
        }
    }
    return numberOfNonLands;
}

int countCanopyLands(vector<Card> hand) {
    int numberOfCanopies = 0;
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i] == sunbakedCanyon || hand[i] == fieryIslet) {
            numberOfCanopies++;
        }
    }

    return numberOfCanopies;
}

void crackCanopy(std::vector<Card> &hand) {

    auto it = std::find_if(hand.begin(), hand.end(), [](const Card& card) {
        return card.isCanopy();
    });

    if (it != hand.end()) {
        hand.erase(it);
    }
}

void printCards(std::vector<Card> hand) {
    cout << "Hand: ";
    for (int i = 0; i < hand.size(); i++) {
        cout << toStringFromCardName(hand[i].getName()) << " ";
    }
    cout << endl;
}

SimulationResult simulate(Deck deck, int numberOfReps, bool isOnPlay) {

    vector<int> numberOfMulls{ 0, 0, 0, 0, 0, 0, 0, 0 };
    vector<int> numberOfKeeps{ 0, 0, 0, 0, 0, 0, 0, 0 };
    vector<int> numberOfFloods{ 0, 0, 0, 0, 0, 0, 0, 0 };

    for (int rep = 0; rep < numberOfReps; rep++) {
        Deck library = deck.getShuffledCopy();
        vector<Card> hand;

        for (int i = 0; i < 7; i++) {
            library.draw(hand);
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

                if (isFlooding(library, hand)) {
                    numberOfFloods[1]++;
                }
            }
            //Keep hands that include at least one copy of Play with Fire and at least 2 cards you can cast for 1 mana
            else if (containsCard(hand, playWithFire) && numberOfTurnOnePlays(hand) >= 2) {
                numberOfKeeps[1]++;

                if (isFlooding(library, hand)) {
                    numberOfFloods[1]++;
                }
            }
            else {
                numberOfMulls[1]++;
            }

            break;

        case 2:
            //Keep hands that include at least one card you can cast on turn 1
            if (numberOfTurnOnePlays(hand) >= 1) {
                numberOfKeeps[2]++;

                if (isFlooding(library, hand)) {
                    numberOfFloods[2]++;
                }
            }
            else {
                numberOfMulls[2]++;
            }

            break;

        case 3:
            //Keep hands that include at least one card you can cast on turn 1
            if (numberOfTurnOnePlays(hand) >= 1) {
                numberOfKeeps[3]++;

                if (isFlooding(library, hand)) {
                    numberOfFloods[3]++;
                }
            }
            else {
                numberOfMulls[3]++;
            }

            break;

        case 4:
            //Keep 4 landers that have X canlands
            if (numberOfTurnOnePlays(hand) >= 1 && countCanopyLands(hand) >= 2) {
                numberOfKeeps[4]++;

                if (isFlooding(library, hand)) {
                    numberOfFloods[4]++;
                }
            }
            else {
                numberOfMulls[4]++;
            }

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
	
    return SimulationResult(numberOfMulls, numberOfKeeps, numberOfFloods);
}

std::vector<SimulationResult> simulatePlayDraw(Deck deck, int numberOfReps) {
    std::vector<SimulationResult> results;

    results.push_back(simulate(deck, numberOfReps, true));
    results.push_back(simulate(deck, numberOfReps, false));

    return results;
}

bool isFlooding(Deck &deck, vector<Card> &hand) {



    while (true) {
        if (countLands(hand) >= 5) {

            if (containsCard(hand, sunbakedCanyon) || containsCard(hand, fieryIslet)) {
                
                crackCanopy(hand);

                deck.draw(hand);
                deck.draw(hand);
                continue;
            }

            return true;
        }
        else if (countNonLands(hand) >= 7) {
            return false;
        }
        else {
            deck.draw(hand);
        }
    }
}