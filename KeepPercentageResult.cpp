#include "KeepPercentageResult.h"

KeepPercentageResult::KeepPercentageResult(int numberOfMulls, vector<int> numberOfKeeps) {
	this->numberOfMulls = numberOfMulls;
	this->numberOfKeeps = numberOfKeeps;
}

void KeepPercentageResult::print() {

    int numberOfReps = getTotalNumberOfKeeps() + numberOfMulls;

    std::cout << "Number of repetitions: " << numberOfReps << endl;
    std::cout
        << "Number of keeps (1 land): "
        << getNumberOfKeeps()[1]
        << " ("
        << (float)getNumberOfKeeps()[1] / (float)numberOfReps * 100
        << "%)"
        << endl;
    std::cout
        << "Number of keeps (2 lands): "
        << getNumberOfKeeps()[2]
        << " ("
        << (float)getNumberOfKeeps()[2] / (float)numberOfReps * 100
        << "%)"
        << endl;
    std::cout
        << "Number of keeps (3 lands): "
        << getNumberOfKeeps()[3]
        << " ("
        << (float)getNumberOfKeeps()[3] / (float)numberOfReps * 100
        << "%)"
        << endl;
    std::cout
        << "Number of keeps: "
        << getTotalNumberOfKeeps()
        << " ("
        << (float)getTotalNumberOfKeeps() / (float)numberOfReps * 100
        << "%)"
        << endl;
    std::cout << "Number of mulls: " << getNumberOfMulls() << " (" << (float)getNumberOfMulls() / (float)numberOfReps * 100 << "%)" << endl << endl;
}

int KeepPercentageResult::getTotalNumberOfKeeps() {
    int totalNumberOfKeeps = 0;
    for (int i = 0; i < numberOfKeeps.size(); i++) {
        totalNumberOfKeeps += numberOfKeeps[i];
    }
    return totalNumberOfKeeps;
}