#include <iostream>
#include "card-enum.cpp"
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int numberOfReps = 100000;

void print(std::vector<int> const &v)
{
    for (int i: v) {
        std::cout << i << ' ';
    }
    cout << endl;
}

int main(){

    //Card translator
    map<int, string> cardTranslator{
        {LIGHTNING_BOLT, "lightning bolt"},
        {LAVA_SPIKE, "lava spike"},
        {RIFT_BOLT, "rift bolt"},
        {SKEWER_THE_CRITICS, "skewer the critics"},
        {GOBLIN_GUIDE, "goblin guide"},
        {MONASTERY_SWIFTSPEAR, "monastery swiftspear"},
        {EIDOLON_OF_THE_GREAT_REVEL, "eidolon of the great revel"},
        {BOROS_CHARM, "boros charm"},
        {LIGHTNING_HELIX, "lightning helix"},
        {SKULLCRACK, "skullcrack"},
        {SEARING_BLAZE, "searing blaze"},
        {MOUNTAIN, "land"}
    };

    //Building deck
    vector<int> deck;
    for(int i=0; i<4; i++){
        deck.push_back(LIGHTNING_BOLT);
        deck.push_back(LAVA_SPIKE);
        deck.push_back(RIFT_BOLT);
        deck.push_back(SKEWER_THE_CRITICS);
        deck.push_back(BOROS_CHARM);
        deck.push_back(GOBLIN_GUIDE);
        deck.push_back(MONASTERY_SWIFTSPEAR);
    }

    for(int i=0; i<3; i++){
        deck.push_back(SEARING_BLAZE);
        deck.push_back(SKULLCRACK);
        deck.push_back(LIGHTNING_HELIX);
        deck.push_back(EIDOLON_OF_THE_GREAT_REVEL);
    }

    for(int i=0; i<20; i++){
        deck.push_back(MOUNTAIN);
    }

    int numberOfKeeps = 0;
    int numberOfMulls = 0;

    for(int rep=0; rep<numberOfReps; rep++){
        // get a time-based seed
        unsigned seed = std::chrono::system_clock::now()
                            .time_since_epoch()
                            .count();
        shuffle (deck.begin(), deck.end(), std::default_random_engine(seed));

        int numberOfLands = 0;
        bool keepableHand = false;
        for(int i=0; i<7; i++){
            if(deck[i] == MOUNTAIN) numberOfLands++;
        }

        if(numberOfLands == 2 || numberOfLands == 3){
            numberOfKeeps++;
        }
        else{
            numberOfMulls++;
        }

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
    cout << "Number of keeps: " << numberOfKeeps << endl;
    cout << "Number of mulls: " << numberOfMulls << endl;
}