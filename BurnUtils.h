#ifndef BURNUTILS_H
#define BURNUTILS_H

#include <vector>

#include "Card.h"
#include "Deck.h"
#include "SimulationResult.h"

//Card utils
bool isTurnOnePlay(const Card& card);
bool containsTurnOnePlay(const std::vector<Card>& hand);
int numberOfTurnOnePlays(const std::vector<Card>& hand);
bool containsCard(const std::vector<Card>& list, const Card& card);
int countLands(const std::vector<Card>& hand);
int countNonLands(const std::vector<Card>& hand);
int countCanopyLands(const std::vector<Card>& hand);
void crackCanopy(const std::vector<Card>& hand);
void printCards(const std::vector<Card>& hand);

//Keep percentage calculator
SimulationResult simulate(Deck deck, int numberOfReps, bool isOnPlay);
std::vector<SimulationResult> simulatePlayDraw(Deck deck, int numberOfReps);
bool isFlooding(Deck &deck, vector<Card> &hand);

#endif