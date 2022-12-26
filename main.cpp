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

int numberOfReps = 100000;
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

    Card fieryIslet = Card::Land(
        CardName::FIERY_ISLET
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

    stockBoros.addCards(mountain, 2);
    stockBoros.addCards(inspiringVantage, 4);
    stockBoros.addCards(sunbakedCanyon, 4);
    stockBoros.addCards(fieryIslet, 2);
    stockBoros.addCards(sacredFoundry, 2);
    stockBoros.addCards(aridMesa, 2);
    stockBoros.addCards(scaldingTarn, 3);

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
                if (!onPlay && numberOfTurnOnePlays(hand) >= 2) {
                    numberOfKeeps++;
                }
                else {
                    numberOfMulls++;
                }
                break;

            case 2:
                if (numberOfTurnOnePlays(hand) >= 1) {
                    numberOfKeeps++;
                }
                else {
                    numberOfMulls++;
                }
                break;

            case 3:
                if (numberOfTurnOnePlays(hand) >= 1) {
                    numberOfKeeps++;
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

    cout << "Number of repetitions: " << numberOfReps << endl;
    cout << "Number of keeps: " << numberOfKeeps << " (" << (float)numberOfKeeps / (float)numberOfReps * 100 << "%)" << endl;
    cout << "Number of mulls: " << numberOfMulls << " (" << (float)numberOfMulls / (float)numberOfReps * 100 << "%)" << endl;
    cout << numberOfKeeps + numberOfMulls << endl;

    /*

        
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

    return 0;
}