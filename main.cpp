#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

#include "Card.h"
#include "CardName.h"
#include "Type.h"
#include "ManaCost.h"
#include "Deck.h"
#include "BurnUtils.h"
#include "SimulationResult.h"
#include "BurnCards.h"

using namespace std;

// Configuration options
struct Config {
    int numberOfReps;
    //bool debug;
    //std::string log_level;
    //std::string server;
    //int port;
};

// Function to trim leading and trailing whitespace from a string
std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t");
    size_t end = s.find_last_not_of(" \t");
    if (start == std::string::npos || end == std::string::npos) {
        return "";
    }
    return s.substr(start, end - start + 1);
}

int main(){

    //config.ini parsing TODO migrate to another file
    std::ifstream file("config.ini");
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open config.ini for reading" << '\n';
        return 1;
    }

    // Create a map to store the configuration options
    std::unordered_map<std::string, std::string> options;
    std::string line;

    while (std::getline(file, line)) {
        // Ignore empty lines and comments
        if (line.empty() || line[0] == '#') {
            continue;
        }

        //If line starts with '[' make a section
        if (line[0] == '[') {
            // Extract the section name from the line
            size_t end = line.find(']');
            if (end == std::string::npos) {
                std::cerr << "Error: Invalid section name: " << line << '\n';
                return 1;
            }
            std::string section = line.substr(1, end - 1);

            // Set the current section in the map
            options["_section"] = section;
        }
        else {
            // Split the line into a key and value
            std::istringstream iss(line);
            std::string key, value;
            if (!std::getline(iss, key, '=') || !std::getline(iss, value)) {
                std::cerr << "Error: Invalid key-value pair: " << line << '\n';
                return 1;
            }

            // Trim the key and value
            key = trim(key);
            value = trim(value);

            // Store the key-value pair in the map, using the current section as the prefix
            std::string prefix = options["_section"] + ".";
            options[prefix + key] = value;
        }
    }

    // Close the file
    file.close();

    // Convert the options map to a Config struct
    Config config;
    config.numberOfReps = std::stoi(options["general.numberOfReps"]);
    //config.debug = options.count("general.debug") && options["general.debug"] == "true";
    //config.log_level = options["general.log_level"];
    //config.server = options["network.server"];
    //config.port = std::stoi(options["network.port"]);

    //Deck builder
    //TODO migrate to another file, possibly make it read from file (would be cool if it could read mtgo .dek files too)
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
    /*vector<SimulationResult> stockBorosKeepPercentageResult = simulatePlayDraw(stockBoros, numberOfReps);
    cout << "Play:" << endl;
    stockBorosKeepPercentageResult[0].print();
    cout << "Draw:" << endl;
    stockBorosKeepPercentageResult[1].print();*/

    vector<SimulationResult> myBorosKeepPercentageResult = simulatePlayDraw(
        myBoros
        , config.numberOfReps
    );
    cout << "Play:" << endl;
    myBorosKeepPercentageResult[0].print();
    cout << "Draw:" << endl;
    myBorosKeepPercentageResult[1].print();

    return 0;
}