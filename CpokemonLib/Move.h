#pragma once

#include <string>

#include "MoveEffect.h"
#include "Typings.h"

enum MoveCategory {
	STATUS_MOVE,
	PHYSICAL_MOVE,
	SPECIAL_MOVE
};

enum MoveRange {
	TARGETS_SELF,
	TARGETS_1ENEMY,
	TARGETS_1ALLY,
	TARGETS_ALL_ENEMIES,
	TARGETS_ALL_ALLIES,
	TARGETS_ALL_OTHERS
};

struct MoveSummary {
	int damageTotal;
	std::vector<bool> hits;
	Move* lastUsedMove;
};

class Move {
public:
	~Move();
	std::string name;
	Typings type;
	int PP;
	int priority;
	MoveCategory category;
	MoveRange range;

	bool makesContact;
	bool isSoundBased;

	std::vector<MoveEffect*> effects;

	void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary summery = MoveSummary());

	void AddEffect(MoveEffect* effect);
};