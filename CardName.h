#ifndef CARDNAME_H
#define CARDNAME_H

#include <string>

enum CardName {

	/*Core*/
	//Creatures
	GOBLIN_GUIDE
	, MONASTERY_SWIFTSPEAR

	//Red
	, LIGHTNING_BOLT
	, LAVA_SPIKE
	, RIFT_BOLT
	, SKEWER_THE_CRITICS

	//White
	, BOROS_CHARM

	//Black
	, BUMP_IN_THE_NIGHT

	/*Flex*/
	//Creatures
	, EIDOLON_OF_THE_GREAT_REVEL
	, DRAGONS_RAGE_CHANNELER
	, REINFORCED_RONIN
	, SHARD_VOLLEY

	//Red
	, SKULLCRACK
	, SEARING_BLAZE
	, PLAY_WITH_FIRE

	//White
	, LIGHTNING_HELIX

	//Lands
	, MOUNTAIN
	, INSPIRING_VANTAGE
	, SUNBAKED_CANYON
	, FIERY_ISLET
	, SACRED_FOUNDRY
	, ARID_MESA
	, SCALDING_TARN

	//default
	, UNKNOWN_CARD
};

std::string toStringFromCardName(CardName name);
CardName toCardNameFromString(std::string name);

#endif