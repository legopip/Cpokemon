#pragma once

//#include "Pokemon.h"
#include "StatusConditionNames.h"

class Pokemon;
class NonVolatileStatusCondition {
public:
	Pokemon* affectedPokemon;

	NonVolatileStatusNames name;

	float ATKmod;
	float DEFmod;
	float SPATKmod;
	float SPDEFmod;
	float SPDmod;

	virtual void Upkeep() = 0;
};