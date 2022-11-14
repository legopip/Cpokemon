#pragma once

#include "TypeChart.h"
#include "Stats.h"
#include "Pokemon.h"
#include "Ability.h"

struct MoveSummery;
struct BattleState;
class MoveEffect {
public:
	virtual void Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery) = 0;
	Typings* type;
};