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

using namespace std;

int numberOfReps = 100;
bool onPlay = true;

int main(){

    //Defining cards in the deck
    //TODO define this in an external class
    Card goblinGuide = Card(
        CardName::GOBLIN_GUIDE
        , Type::CREATURE
        , 1
        , ManaCost(0, 0, 0, 1, 0, 0)
    );

    Card monasterySwiftspear = Card(
        CardName::MONASTERY_SWIFTSPEAR
        , Type::CREATURE
        , 1
        , ManaCost(0, 0, 0, 1, 0, 0)
    );

    Card lightningBolt = Card(
        CardName::LIGHTNING_BOLT
        , Type::INSTANT
        , 1
        , ManaCost(0, 0, 0, 1, 0, 0)
    );

    Card lavaSpike = Card(
        CardName::LAVA_SPIKE
        , Type::SORCERY
        , 1
        , ManaCost(0, 0, 0, 1, 0, 0)
    );

    Card riftBolt = Card(
        CardName::RIFT_BOLT
        , Type::SORCERY
        , 3
        , ManaCost(0, 0, 0, 1, 0, 2)
    );

    Card skewerTheCritics = Card(
        CardName::SKEWER_THE_CRITICS
        , Type::SORCERY
        , 3
        , ManaCost(0, 0, 0, 1, 0, 2)
    );

    Card borosCharm = Card(
        CardName::BOROS_CHARM
        , Type::INSTANT
        , 2
        , ManaCost(1, 0, 0, 1, 0, 0)
    );

    Card searingBlaze = Card(
        CardName::SEARING_BLAZE
        , Type::INSTANT
        , 2
        , ManaCost(0, 0, 0, 2, 0, 0)
    );

    Card skullcrack = Card(
        CardName::SKULLCRACK
        , Type::INSTANT
        , 2
        , ManaCost(0, 0, 0, 1, 0, 1)
    );

    Card lightningHelix = Card(
        CardName::LIGHTNING_HELIX
        , Type::INSTANT
        , 2
        , ManaCost(1, 0, 0, 1, 0, 0)
    );

    Card mountain = Card::Land(
        CardName::MOUNTAIN
    );

    Card inspiringVantage = Card::Land(
        CardName::INSPIRING_VANTAGE
    );

    Card sunbakedCanyon = Card::Land(
        CardName::SUNBAKED_CANYON
    );

    Card sacredFoundry = Card::Land(
        CardName::SACRED_FOUNDRY
    );

    Card aridMesa = Card::Land(
        CardName::ARID_MESA
    );

    Card scaldingTarn = Card::Land(
        CardName::SCALDING_TARN
    );

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

    stockBoros.print();

    //Percentage of keeps simulator
    int numberOfKeeps = 0;
    int numberOfMulls = 0;

    for (int rep = 0; rep < numberOfReps; rep++) {
        Deck library = stockBoros.getShuffledCopy();
        vector<Card> hand;

        for (int i = 0; i < 7; i++) {
            hand.push_back(library.draw());
            //hand[i].print();
            //std::cout << endl;
        }

        //calculate keeps
        int numberOfLands = 0;
        int numberOfOneDrops = 0;
        int numberOfCanopies = 0;

        //calculate number of lands in opener
        for (int i = 0; i < hand.size(); i++) {
            if (hand[i].getType() == Type::LAND) numberOfLands++;
        }

        //keep 2 and 3 landers that have turn 1 play
        if (numberOfLands == 2 || numberOfLands == 3) {
            if (containsTurnOnePlay(hand)) {
                numberOfKeeps++;
            }
            else {
                numberOfMulls++;
            }
        }
        else {
            numberOfMulls++;
        }
    }

    cout << "Number of repetitions: " << numberOfReps << endl;
    cout << "Number of keeps: " << numberOfKeeps << " (" << (float)numberOfKeeps / (float)numberOfReps * 100 << "%)" << endl;
    cout << "Number of mulls: " << numberOfMulls << " (" << (float)numberOfMulls / (float)numberOfReps * 100 << "%)" << endl;
    cout << numberOfKeeps + numberOfMulls << endl;

    /*
        
        //keep 1 landers if on the draw + have at least two turn 1 plays
        else if(!onPlay && numberOfLands == 1){
            for(int i=0; i<7; i++){
                if (deck[i].isTurnOnePlay()) {
                    numberOfOneDrops++;
                }
            }

            if (numberOfOneDrops > 1) {
                numberOfKeeps++;
            }
            else {
                numberOfMulls++;
            }
        } 
        
        //keep 4 landers if they have at least 1 canopy land
        else if(numberOfLands == 4){
            for(int i=0; i<7; i++){
                if (deck[i].getName() == SUNBAKED_CANYON || deck[i].getName() == FIERY_ISLET) {
                    numberOfCanopies++;
                }
            }

            if (numberOfCanopies > 0) {
                numberOfKeeps++;
            }
            else {
                numberOfMulls++;
            }
            numberOfCanopies = 0;
        } 
        
        //mull everythhing else
        else{
            numberOfMulls++;
        }

        //calculate flooding TODO

    }

    cout << "Number of repetitions: " << numberOfReps << endl;
    cout << "Number of keeps: " << numberOfKeeps << " (" << (float) numberOfKeeps / (float) numberOfReps * 100 << "%)" << endl;
    cout << "Number of mulls: " << numberOfMulls << " (" << (float) numberOfMulls / (float) numberOfReps * 100 << "%)" << endl;
    cout << numberOfKeeps + numberOfMulls << endl;
    */
}