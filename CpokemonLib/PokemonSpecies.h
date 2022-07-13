#pragma once

#include <string>
#include <vector>

#include "Typings.h"
#include "Stats.h"
#include "EggGroups.h"
#include "PokedexInfo.h"
#include "ExpCurves.h"
#include "MoveNames.h"
#include "AbilityNames.h"

class Move;
struct LevelMovePair {
	int level;
	MoveNames moveName;
};
class PokemonSpecies {
public:
	int nationalDexNumber;
	std::string name;
	std::string genus;
	int genderRatio;

	Typings type1;
	Typings type2;
	EggGroups egg1;
	EggGroups egg2;

	AbilityNames ability1;
	AbilityNames ability2;
	AbilityNames hiddenAbility;

	int baseHP;
	int baseATK;
	int baseDEF;
	int baseSPATK;
	int baseSPDEF;
	int baseSPD;
	int BSTtotal;

	ExpCurve expCurve;
	int expYeild;
	Stats evYeild;
	int evYeildAmount;
	
	int captureRate;
	int baseFriendship;

	float height;
	float weight;
	Shape shape;
	Habitat habitat;
	Colour colour;

	std::vector<LevelMovePair> moveset;

	std::string description;
};