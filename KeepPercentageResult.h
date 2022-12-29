#ifndef KEEP_PERCENTAGE_RESULT_H
#define KEEP_PERCENTAGE_RESULT_H

#include "Deck.h"

class KeepPercentageResult {

	private:
		int numberOfMulls;
		vector<int> numberOfKeeps;

	public:
		KeepPercentageResult(int numberOfMulls, vector<int> numberOfKeeps);

		void print();

		int getNumberOfMulls() { return numberOfMulls; }
		vector<int> getNumberOfKeeps() { return numberOfKeeps; }
		int getTotalNumberOfKeeps();
};

#endif