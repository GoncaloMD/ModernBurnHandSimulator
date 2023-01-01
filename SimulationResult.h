#ifndef SIMULATION_RESULT_H
#define SIMULATION_RESULT_H

#include "Deck.h"

class SimulationResult {

	private:
		int numberOfReps;//NOT USED
		vector<int> numberOfMulls;
		vector<int> numberOfKeeps;

		vector<int> numberOfFloods;

	public:
		SimulationResult(vector<int> numberOfMulls, vector<int> numberOfKeeps, vector<int> numberOfFloods);

		void print();
		void printIndex(int i);

		vector<int> getNumberOfMulls() { return numberOfMulls; }
		int getTotalNumberOfMulls();
		vector<int> getNumberOfKeeps() { return numberOfKeeps; }
		int getTotalNumberOfKeeps();

		vector<int> getNumberOfFloods() { return numberOfFloods; }
		int getTotalNumberOfFloods();
};

#endif