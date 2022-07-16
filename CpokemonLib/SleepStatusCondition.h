#pragma once

#include "NonVolatileStatusCondition.h"
#include "Pokemon.h"

class SleepStatusCondition : public NonVolatileStatusCondition {
public:
	SleepStatusCondition(Pokemon* pokemon);
	~SleepStatusCondition();

	void Upkeep();
private:
	int turnCounter;
};