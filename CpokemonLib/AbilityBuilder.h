#pragma once

#include "AbilityNames.h"
#include "Ability.h"
#include <map>

class AbilityBuilder
{
public:
	AbilityBuilder();
	~AbilityBuilder();

	Ability* BuildAbility(AbilityNames abilityToMake);

private:
	std::map<AbilityNames, Ability*> abilityMap;
};

static AbilityBuilder abilityBuilder;