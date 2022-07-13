#pragma once

#include "NonVolatileStatusCondition.h"
#include "Pokemon.h"

class BurnStatusCondition : public NonVolatileStatusCondition {
public:
	BurnStatusCondition(Pokemon* pokemon);
	~BurnStatusCondition();

	void Upkeep();
};