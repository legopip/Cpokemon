#pragma once

#include "MoveFunction.h"

#include "TypeChart.h"
#include "Stats.h"
#include "Pokemon.h"
#include "Ability.h"

class MoveEffect : public MoveFunction {
public:
	virtual void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary& summery) = 0;
	Typings* type;
};