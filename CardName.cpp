#include "CardName.h"

#include <string>

std::string getCardNameAsString(CardName name) {
	//TODO: there are better ways of doing this
	switch (name) {
		case GOBLIN_GUIDE:
			return "Goblin Guide";

		case MONASTERY_SWIFTSPEAR:
			return "Monastery Swiftspear";

		default:
			return "Card name missing in mapping... Add it please";
	}
}