#include "Move.h"

Move::~Move() {
	//this is wrong?
	for (int i = effects.size() - 1; i >= 0; i--) {
		delete effects[i];
	}
}


void Move::Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState) {
	MoveSummery summery;
	summery.totalDamage = 0;
	std::cout << user->nickname << " used " << name << "." << std::endl;
	for (int i = 0; i < effects.size(); i++) {
		effects[i]->Resolve(user, targets, battleState, summery);
	}
}

void Move::AddEffect(MoveEffect* effect) {
	effect->type = &this->type;
	effects.push_back(effect);
}