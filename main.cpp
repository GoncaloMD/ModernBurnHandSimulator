#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>

#include "card.cpp"

using namespace std;

int numberOfReps = 100000;
bool onPlay = false;

void print(std::vector<int> const &v)
{
    for (int i: v) {
        std::cout << i << ' ';
    }
    cout << endl;
}

int main(){

    //Card names - to be moved to separate file
    string LIGHTNING_BOLT = "Lightning Bolt";
    string LAVA_SPIKE = "Lava Spike";
    string RIFT_BOLT = "Rift Bolt";
    string SKEWER_THE_CRITICS = "Skewer the Critics";

    string GOBLIN_GUIDE = "Goblin Guide";
    string MONASTERY_SWIFTSPEAR = "Monastery Swiftspear";
    string EIDOLON_OF_THE_GREAT_REVEL = "Eidolon of the Great Revel";
    string REINFORECED_RONIN = "Reinforce Ronin";

    string BOROS_CHARM = "Boros Charm";

    string SEARING_BLAZE = "Searing Blaze";
    string LIGHTNING_HELIX = "Lightning Helix";
    string SKULLCRACK = "Skullcrack";

    string MOUNTAIN = "Mountain";
    string SACRED_FOUNDRY = "Sacred Foundry";
    string INSPIRING_VANTAGE = "Inspiring Vantage";
    string SUNBAKED_CANYON = "Sunbaked Canyon";
    string FIERY_ISLET = "Fiery Islet";
    string FETCHLAND = "Arid Mesa";

    //Card types - to be moved to separate file
    string CREATURE = "Creature";
    string LAND = "Land";
    string INSTANT = "Instant";
    string SORCERY = "Sorcery";

    //Creating cards - these could also be in separate file
    Card lightningBolt = Card(LIGHTNING_BOLT, INSTANT, 1);
    Card lavaSpike = Card(LAVA_SPIKE, SORCERY, 1);
    Card riftBolt = Card(RIFT_BOLT, SORCERY, 1);
    Card skewerTheCritics = Card(SKEWER_THE_CRITICS, SORCERY, 1);

    Card goblinGuide = Card(GOBLIN_GUIDE, CREATURE, 1);
    Card monasterySwiftspear = Card(MONASTERY_SWIFTSPEAR, CREATURE, 1);

    Card borosCharm = Card(BOROS_CHARM, INSTANT, 2);

    Card searingBlaze = Card(SEARING_BLAZE, INSTANT, 2);
    Card skullcrack = Card(SKULLCRACK, INSTANT, 2);
    Card lightningHelix = Card(LIGHTNING_HELIX, INSTANT, 2);

    Card mountain = Card(MOUNTAIN, LAND, 0);
    Card sacredFoundry = Card(SACRED_FOUNDRY, LAND, 0);
    Card inspiringVantage = Card(INSPIRING_VANTAGE, LAND, 0);
    Card sunbakedCanyon = Card(SUNBAKED_CANYON, LAND, 0);
    Card fieryIslet = Card(FIERY_ISLET, LAND, 0);
    Card fetch = Card(FETCHLAND, LAND, 0);

    //Building deck
    vector<Card> deck;

    for(int i=0; i<4; i++){
        deck.push_back(lightningBolt);
        deck.push_back(lavaSpike);
        deck.push_back(riftBolt);
        deck.push_back(skewerTheCritics);
        
        deck.push_back(goblinGuide);
        deck.push_back(monasterySwiftspear);
        
        deck.push_back(borosCharm);

        deck.push_back(searingBlaze);
        deck.push_back(skullcrack);
        deck.push_back(lightningHelix);

        deck.push_back(inspiringVantage);
        deck.push_back(sunbakedCanyon);
    }

    deck.insert(deck.end(), 3, mountain);
    deck.insert(deck.end(), 2, sacredFoundry);
    deck.insert(deck.end(), 7, fetch);

    int numberOfKeeps = 0;
    int numberOfMulls = 0;

    int numberOfOneDrops = 0;

    for(int rep=0; rep<numberOfReps; rep++){
        //get a time-based seed
        unsigned seed = std::chrono::system_clock::now()
                            .time_since_epoch()
                            .count();

        //shuffle deck
        shuffle (deck.begin(), deck.end(), std::default_random_engine(seed));

        //calculate keeps
        int numberOfLands = 0;
        for(int i=0; i<7; i++){
            if(deck[i].getType() == LAND) numberOfLands++;
        }

        if(numberOfLands == 2 || numberOfLands == 3){
            for(int i=0; i<7; i++){
                if(deck[i].isTurnOnePlay()){
                    numberOfKeeps++;
                    break;
                }
            }
        } else if(!onPlay && numberOfLands == 1){
            for(int i=0; i<7; i++){
                if(deck[i].isTurnOnePlay()) numberOfOneDrops++;
            }

            if(numberOfOneDrops >= 2) numberOfKeeps ++;
            numberOfOneDrops = 0;
        } else if(numberOfLands == 4){
            for(int i=0; i<7; i++){
                if(deck[i].getName() == SUNBAKED_CANYON || deck[i].getName() == FIERY_ISLET) numberOfKeeps++;
            }
        } else{
            numberOfMulls++;
        }

        //calculate flooding

        //print(deck);

        /*cout << "opening hand is: ";
        cout << cardTranslator[deck[0]] << ", ";
        cout << cardTranslator[deck[1]] << ", ";
        cout << cardTranslator[deck[2]] << ", ";
        cout << cardTranslator[deck[3]] << ", ";
        cout << cardTranslator[deck[4]] << ", ";
        cout << cardTranslator[deck[5]] << ", ";
        cout << cardTranslator[deck[6]] << ", ";
        cout << endl;*/
    }

    cout << "Number of repetitions: " << numberOfReps << endl;
    cout << "Number of keeps: " << numberOfKeeps << " (" << (float) numberOfKeeps / (float) numberOfReps * 100 << "%)" << endl;
    cout << "Number of mulls: " << numberOfMulls << " (" << (float) numberOfMulls / (float) numberOfReps * 100 << "%)" << endl;
}