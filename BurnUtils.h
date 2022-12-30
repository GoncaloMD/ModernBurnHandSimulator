#ifndef BURNUTILS_H
#define BURNUTILS_H

#include <vector>

#include "Card.h"
#include "Deck.h"
#include "SimulationResult.h"

//Card utils
bool isTurnOnePlay(Card card);
bool containsTurnOnePlay(vector<Card> hand);
int numberOfTurnOnePlays(vector<Card> hand);

//Keep percentage calculator
bool containsCard(std::vector<Card> list, Card card);
SimulationResult simulate(Deck deck, int numberOfReps, bool isOnPlay);
std::vector<SimulationResult> simulatePlayDraw(Deck deck, int numberOfReps);

#endif