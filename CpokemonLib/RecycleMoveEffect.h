#pragma once

#include "MoveEffect.h"
#include "Move.h"

class RecycleMoveEffect : public MoveEffect {
	void Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery);
};