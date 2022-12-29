#ifndef BURNUTILS_H
#define BURNUTILS_H

#include <vector>

#include "Card.h"
#include "Deck.h"
#include "KeepPercentageResult.h"

//Card utils
bool isTurnOnePlay(Card card);
bool containsTurnOnePlay(vector<Card> hand);
int numberOfTurnOnePlays(vector<Card> hand);

//Keep percentage calculator
bool containsCard(std::vector<Card> list, Card card);
KeepPercentageResult getKeepPercentageDistribution(Deck deck, int numberOfReps, bool isOnPlay);
std::vector<KeepPercentageResult> getKeepPercentageDistributionPlayDraw(Deck deck, int numberOfReps);

#endif