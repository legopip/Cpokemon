#pragma once

#include "Ability.h"

class LowHPPowerUpAbility : public Ability {
public:
	Typings requiredType;

	float GetAttackMod(Pokemon* user, Typings* moveType);
};