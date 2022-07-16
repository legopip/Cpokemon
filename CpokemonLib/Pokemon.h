#pragma once

#include "PokemonSpecies.h"

#include "Nature.h"
#include "PokemonGenders.h"
#include "NonVolatileStatusCondition.h"

class Ability;
struct KnownMove {
	int currentPP;
	Move* move;
};

class Pokemon {
public:
	Pokemon();
	~Pokemon();

	bool isTrainerPokemon;
	PokemonSpecies species;
	PokemonGenders gender;
	Ability* ability;
	NonVolatileStatusCondition* nvStatus; //A pokemon can only be affected by one of these at a time

	int currentHP;

	int exp;
	int expToLevel;

	int level;
	int happiness;

	std::string nickname;

	Nature nature;

	int GetHP();
	int GetATK();
	int GetDEF();
	int GetSPATK();
	int GetSPDEF();
	int GetSPD();

	int GetEXPyeild();
	void CheckForLevelUp();

	int numberOfKnownMoves;
	KnownMove knownMoves[4];

	std::string ToString();
	std::string GetTextHPbar();

	int IVHP;
	int IVATK;
	int IVDEF;
	int IVSPATK;
	int IVSPDEF;
	int IVSPD;

	int EVHP;
	int EVATK;
	int EVDEF;
	int EVSPATK;
	int EVSPDEF;
	int EVSPD;

	int ATKmod;
	int DEFmod;
	int SPATKmod;
	int SPDEFmod;
	int SPDmod;

private:
	float StatModToStatChange(int mod);

};