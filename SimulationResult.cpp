#include "SimulationResult.h"

SimulationResult::SimulationResult(vector<int> numberOfMulls, vector<int> numberOfKeeps) {
	this->numberOfMulls = numberOfMulls;
	this->numberOfKeeps = numberOfKeeps;

    this->numberOfReps = getTotalNumberOfMulls() + getTotalNumberOfKeeps();
}

void SimulationResult::print() {

    std::cout << "Number of repetitions: " << numberOfReps << endl;
    std::cout
        << "1 Land: "
        << getNumberOfKeeps()[1] << " Keeps" 
        << " (" << (float)getNumberOfKeeps()[1] / (float)numberOfReps * 100 << "%)"
        << " | "
        << getNumberOfMulls()[1] << " Mulls"
        << " (" << (float)getNumberOfMulls()[1] / (float)numberOfReps * 100 << "%)"
        << endl;
    std::cout
        << "2 Lands: "
        << getNumberOfKeeps()[2] << " Keeps"
        << " (" << (float)getNumberOfKeeps()[2] / (float)numberOfReps * 100 << "%)"
        << " | "
        << getNumberOfMulls()[2] << " Mulls"
        << " (" << (float)getNumberOfMulls()[2] / (float)numberOfReps * 100 << "%)"
        << endl;
    std::cout
        << "3 Lands: "
        << getNumberOfKeeps()[3] << " Keeps"
        << " (" << (float)getNumberOfKeeps()[3] / (float)numberOfReps * 100 << "%)"
        << " | "
        << getNumberOfMulls()[3] << " Mulls"
        << " (" << (float)getNumberOfMulls()[3] / (float)numberOfReps * 100 << "%)"
        << endl;
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