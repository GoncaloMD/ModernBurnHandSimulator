#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>

#include "Card.h"
#include "CardName.h"
#include "Type.h"
#include "ManaCost.h"
#include "Deck.h"
#include "BurnUtils.h"
#include "SimulationResult.h"
#include "BurnCards.h"

using namespace std;

int numberOfReps = 100000;
bool onPlay = true;

int main(){

    //Deck builder
    //TODO do this somewhere else
    Deck stockBoros = Deck();
    stockBoros.addCards(goblinGuide, 4);
    stockBoros.addCards(monasterySwiftspear, 4);
    stockBoros.addCards(lightningBolt, 4);
    stockBoros.addCards(lavaSpike, 4);
    stockBoros.addCards(riftBolt, 4);
    stockBoros.addCards(skewerTheCritics, 4);
    stockBoros.addCards(borosCharm, 4);
    stockBoros.addCards(skullcrack, 4);
    stockBoros.addCards(searingBlaze, 4);
    stockBoros.addCards(lightningHelix, 4);

    stockBoros.addCards(mountain, 3);
    stockBoros.addCards(inspiringVantage, 4);
    stockBoros.addCards(sunbakedCanyon, 4);
    stockBoros.addCards(fieryIslet, 2);
    stockBoros.addCards(sacredFoundry, 2);
    stockBoros.addCards(aridMesa, 2);
    stockBoros.addCards(scaldingTarn, 3);

    //My version of the deck
    Deck myBoros = Deck();
    myBoros.addCards(goblinGuide, 4);
    myBoros.addCards(monasterySwiftspear, 4);
    myBoros.addCards(lightningBolt, 4);
    myBoros.addCards(lavaSpike, 4);
    myBoros.addCards(riftBolt, 4);
    myBoros.addCards(skewerTheCritics, 4);
    myBoros.addCards(borosCharm, 4);
    myBoros.addCards(skullcrack, 3);
    myBoros.addCards(searingBlaze, 3);
    myBoros.addCards(playWithFire, 4);
    myBoros.addCards(reinforcedRonin, 2);
    myBoros.addCards(shardVolley, 1);

    myBoros.addCards(mountain, 3);
    myBoros.addCards(inspiringVantage, 4);
    myBoros.addCards(sunbakedCanyon, 4);
    myBoros.addCards(fieryIslet, 2);
    myBoros.addCards(sacredFoundry, 2);
    myBoros.addCards(aridMesa, 4);

    //Percentage of keeps simulator

    vector<SimulationResult> stockBorosKeepPercentageResult = simulatePlayDraw(stockBoros, numberOfReps);
    cout << "Play:" << endl;
    stockBorosKeepPercentageResult[0].print();
    cout << "Draw:" << endl;
    stockBorosKeepPercentageResult[1].print();

    vector<SimulationResult> myBorosKeepPercentageResult = simulatePlayDraw(myBoros, numberOfReps);
    cout << "Play:" << endl;
    myBorosKeepPercentageResult[0].print();
    cout << "Draw:" << endl;
    myBorosKeepPercentageResult[1].print();

    return 0;
}