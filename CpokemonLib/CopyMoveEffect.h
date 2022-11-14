#pragma once

#include "MoveEffect.h"
#include "Move.h"

class CopyMoveEffect : public MoveEffect {
public:

	void Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery);
private:
	
};