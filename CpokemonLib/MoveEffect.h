#pragma once

#include "TypeChart.h"
#include "Stats.h"
#include "Pokemon.h"
#include "Ability.h"

struct MoveSummary;
class MoveEffect {
public:
	virtual void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary& summery) = 0;
	Typings* type;
};