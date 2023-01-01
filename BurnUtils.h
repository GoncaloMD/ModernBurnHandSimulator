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
bool containsCard(std::vector<Card> list, Card card);
int countLands(std::vector<Card> hand);
int countNonLands(std::vector<Card> hand);
int countCanopyLands(std::vector<Card> hand);
void crackCanopy(std::vector<Card> &hand);
void printCards(std::vector<Card> hand);

//Keep percentage calculator
SimulationResult simulate(Deck deck, int numberOfReps, bool isOnPlay);
std::vector<SimulationResult> simulatePlayDraw(Deck deck, int numberOfReps);
bool isFlooding(Deck &deck, vector<Card> &hand);

#endif