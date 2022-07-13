#pragma once

#include "Pokemon.h"

class Ability {
public:
	std::string name;
	std::string description;

	virtual float GetAttackMod(Pokemon* user, Typings* moveType) = 0;
};