#pragma once

#include <string>

#include "MoveEffect.h"
#include "Typings.h"

enum MoveCategory {
	STATUS_MOVE,
	PHYSICAL_MOVE,
	SPECIAL_MOVE
};

class Move : public MoveFunction {
public:
	~Move();
	std::string name;
	Typings type;
	int PP;
	int priority;
	MoveCategory category;

	bool makesContact;
	bool isSoundBased;

	std::vector<MoveEffect*> effects;

	void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary summery = MoveSummary());

	void AddEffect(MoveEffect* effect);
};