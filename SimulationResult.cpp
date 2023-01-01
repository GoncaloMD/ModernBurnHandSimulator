#include "SimulationResult.h"

SimulationResult::SimulationResult(vector<int> numberOfMulls, vector<int> numberOfKeeps, vector<int> numberOfFloods) {
	this->numberOfMulls = numberOfMulls;
	this->numberOfKeeps = numberOfKeeps;

    this->numberOfReps = getTotalNumberOfMulls() + getTotalNumberOfKeeps();

    this->numberOfFloods = numberOfFloods;
}

void SimulationResult::print() {

    std::cout << "Number of repetitions: " << numberOfReps << endl;

    printIndex(1);
    printIndex(2);
    printIndex(3);
    printIndex(4);

    std::cout
        << "Number of keeps: "
        << getTotalNumberOfKeeps()
        << " (" << (float)getTotalNumberOfKeeps() / (float)numberOfReps * 100 << "%)"
        << endl;
    std::cout 
        << "Number of mulls: " 
        << getTotalNumberOfMulls() 
        << " (" << (float)getTotalNumberOfMulls() / (float)numberOfReps * 100 << "%)" 
        << endl 
        << endl;
}

void SimulationResult::printIndex(int i) {
    std::cout
        << i << " Land(s) (" << getNumberOfKeeps()[i] + getNumberOfMulls()[i] << "): "
        << getNumberOfKeeps()[i] << " Keeps"
        << " (" << (float)getNumberOfKeeps()[i] / (float)numberOfReps * 100 << "%)"
        << " | "
        << getNumberOfMulls()[i] << " Mulls"
        << " (" << (float)getNumberOfMulls()[2] / (float)numberOfReps * 100 << "%)"
        << " | "
        << getNumberOfFloods()[i] << " Floods"
        << " (" << (float)getNumberOfFloods()[i] / (float)getNumberOfKeeps()[i] * 100 << "%)"
        << endl;
}

int SimulationResult::getTotalNumberOfKeeps() {
    int totalNumberOfKeeps = 0;
    for (int i = 0; i < numberOfKeeps.size(); i++) {
        totalNumberOfKeeps += numberOfKeeps[i];
    }
    return totalNumberOfKeeps;
}

int SimulationResult::getTotalNumberOfMulls() {
    int totalNumberOfMulls = 0;
    for (int i = 0; i < numberOfMulls.size(); i++) {
        totalNumberOfMulls += numberOfMulls[i];
    }
    return totalNumberOfMulls;
}

int SimulationResult::getTotalNumberOfFloods() {
    int totalNumberOfFloods = 0;
    for (int i = 0; i < numberOfFloods.size(); i++) {
        totalNumberOfFloods += numberOfFloods[i];
    }
    return totalNumberOfFloods;
}