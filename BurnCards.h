#ifndef BURN_CARDS_H
#define BURN_CARDS_H

#include "Card.h"
#include "ManaCost.h"

const Card goblinGuide = Card(
    CardName::GOBLIN_GUIDE
    , Type::CREATURE
    , 1
    , ManaCost(0, 0, 0, 1, 0, 0)
);

const Card monasterySwiftspear = Card(
    CardName::MONASTERY_SWIFTSPEAR
    , Type::CREATURE
    , 1
    , ManaCost(0, 0, 0, 1, 0, 0)
);

const Card lightningBolt = Card(
    CardName::LIGHTNING_BOLT
    , Type::INSTANT
    , 1
    , ManaCost(0, 0, 0, 1, 0, 0)
);

const Card lavaSpike = Card(
    CardName::LAVA_SPIKE
    , Type::SORCERY
    , 1
    , ManaCost(0, 0, 0, 1, 0, 0)
);

const Card riftBolt = Card(
    CardName::RIFT_BOLT
    , Type::SORCERY
    , 3
    , ManaCost(0, 0, 0, 1, 0, 2)
);

const Card skewerTheCritics = Card(
    CardName::SKEWER_THE_CRITICS
    , Type::SORCERY
    , 3
    , ManaCost(0, 0, 0, 1, 0, 2)
);

const Card borosCharm = Card(
    CardName::BOROS_CHARM
    , Type::INSTANT
    , 2
    , ManaCost(1, 0, 0, 1, 0, 0)
);

const Card searingBlaze = Card(
    CardName::SEARING_BLAZE
    , Type::INSTANT
    , 2
    , ManaCost(0, 0, 0, 2, 0, 0)
);

const Card skullcrack = Card(
    CardName::SKULLCRACK
    , Type::INSTANT
    , 2
    , ManaCost(0, 0, 0, 1, 0, 1)
);

const Card lightningHelix = Card(
    CardName::LIGHTNING_HELIX
    , Type::INSTANT
    , 2
    , ManaCost(1, 0, 0, 1, 0, 0)
);

const Card playWithFire = Card(
    CardName::PLAY_WITH_FIRE
    , Type::INSTANT
    , 1
    , ManaCost(0, 0, 0, 1, 0, 0)
);

const Card reinforcedRonin = Card(
    CardName::REINFORCED_RONIN
    , Type::CREATURE
    , 1
    , ManaCost(0, 0, 0, 1, 0, 0)
);

const Card shardVolley = Card(
    CardName::SHARD_VOLLEY
    , Type::INSTANT
    , 1
    , ManaCost(0, 0, 0, 1, 0, 0)
);

const Card mountain = Card::Land(
    CardName::MOUNTAIN
);

const Card inspiringVantage = Card::Land(
    CardName::INSPIRING_VANTAGE
);

const Card sunbakedCanyon = Card::Land(
    CardName::SUNBAKED_CANYON
);

const Card fieryIslet = Card::Land(
    CardName::FIERY_ISLET
);

const Card sacredFoundry = Card::Land(
    CardName::SACRED_FOUNDRY
);

const Card aridMesa = Card::Land(
    CardName::ARID_MESA
);

const Card scaldingTarn = Card::Land(
    CardName::SCALDING_TARN
);

#endif