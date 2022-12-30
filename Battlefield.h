#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include<vector>

#include "Card.h"


class Battlefield {

	private:
		vector<Card> battlefield;

	public:
		Battlefield() { ; }

		void play(Card card);

};

#endif