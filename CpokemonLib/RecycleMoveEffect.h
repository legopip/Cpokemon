#pragma once

#include "MoveEffect.h"
#include "Move.h"

class RecycleMoveEffect : public MoveEffect {
	void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary& summery) {
		if (!user->heldItem && user->oldHeldItem) {
			user->heldItem = user->oldHeldItem;
			std::cout << "It recovered it's item." << std::endl;
		}
		else {
			std::cout << "But it failed!" << std::endl;
		}
	}
};