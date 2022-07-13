#pragma once

//#include "Pokemon.h"

class Pokemon;
class NonVolatileStatusCondition {
public:
	Pokemon* affectedPokemon;

	float ATKmod;
	float DEFmod;
	float SPATKmod;
	float SPDEFmod;
	float SPDmod;

	virtual void Upkeep() = 0;
};