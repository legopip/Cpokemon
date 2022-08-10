#pragma once

#include "MoveEffect.h"
#include "Move.h"

class CopyMoveEffect : public MoveEffect {
	void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary& summery) {
		if (summery.lastUsedMove) {
			summery.lastUsedMove->Invoke(user, targets, summery);
		}
		else {
			std::cout << "But it failed!" << std::endl;
		}
	}
};