#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include<vector>

#include "Card.h"


class Battlefield {

	private:
		vector<Card> battlefield;

	public:
		void play(const Card& card);
};

#endif