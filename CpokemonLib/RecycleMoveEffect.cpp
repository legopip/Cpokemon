#include "RecycleMoveEffect.h"

void RecycleMoveEffect::Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery) {
	if (!user->heldItem && user->oldHeldItem) {
		user->heldItem = user->oldHeldItem;
		std::cout << "It recovered it's item." << std::endl;
	}
	else {
		std::cout << "But it failed!" << std::endl;
	}
}