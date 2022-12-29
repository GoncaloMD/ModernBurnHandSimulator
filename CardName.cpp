#include "CardName.h"

#include <string>

std::string toStringFromCardName(CardName name) {
	//TODO: there are better ways of doing this
	switch (name) {
		case GOBLIN_GUIDE:
			return "Goblin Guide";

		case MONASTERY_SWIFTSPEAR:
			return "Monastery Swiftspear";

		case LIGHTNING_BOLT:
			return "Lightning Bolt";

		case LAVA_SPIKE:
			return "Lava Spike";

		case RIFT_BOLT:
			return "Rift Bolt";

		case SKEWER_THE_CRITICS:
			return "Skewer the Critics";

		case BOROS_CHARM:
			return "Boros Charm";

		case BUMP_IN_THE_NIGHT:
			return "Bump in the Night";

		case EIDOLON_OF_THE_GREAT_REVEL:
			return "Eidolon of the Great Revel";

		case DRAGONS_RAGE_CHANNELER:
			return "Dragon's Rage Channeler";

		case REINFORCED_RONIN:
			return "Reinforced Ronin";

		case SHARD_VOLLEY:
			return "Shard Volley";

		case SKULLCRACK:
			return "Skullcrack";

		case SEARING_BLAZE:
			return "Searing Blaze";
		
		case PLAY_WITH_FIRE:
			return "Play with Fire";

		case LIGHTNING_HELIX:
			return "Lightning Helix";

		case MOUNTAIN:
			return "Mountain";

		case INSPIRING_VANTAGE:
			return "Inspiring Vantage";

		case SUNBAKED_CANYON:
			return "Sunbaked Canyon";

		case FIERY_ISLET:
			return "Fiery Islet";

		case SACRED_FOUNDRY:
			return "Sacred Foundry";

		case ARID_MESA:
			return "Arid Mesa";

		case SCALDING_TARN:
			return "Scalding Tarn";

		default:
			return "Card name missing in mapping... Add it please";
	}
}

CardName toCardNameFromString(std::string name) {
	//TODO: investigate if there is a better way to do this
	if (name == "Goblin Guide") {
		return GOBLIN_GUIDE;
	} 
	else if (name == "Monastery Swiftspear") {
		return MONASTERY_SWIFTSPEAR;
	}
	else if (name == "Lightning Bolt") {
		return LIGHTNING_BOLT;

	}
	else {
		return UNKNOWN_CARD;
	}
}