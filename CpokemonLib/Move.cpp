#include "Move.h"

Move::~Move() {
	//this is wrong?
	for (int i = effects.size() - 1; i >= 0; i--) {
		delete effects[i];
	}
}

void Move::Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary summery) {
	std::cout << user->nickname << " used " << name << "." << std::endl;
	summery.damageTotal = 0;
	for (int i = 0; i < effects.size(); i++) {
		effects[i]->Invoke(user, targets, summery);
	}
}

void Move::AddEffect(MoveEffect* effect) {
	effect->type = &this->type;
	effects.push_back(effect);
}