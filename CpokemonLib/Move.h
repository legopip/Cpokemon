#pragma once

#include <string>

#include "MoveEffect.h"
#include "Typings.h"
#include "WeatherNames.h"

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

struct BattleState { //this should go somewhere else
	Move* lastUsedMove;
	WeatherNames currentWeather;
};

struct MoveSummery {
	int totalDamage;
	std::vector<bool> hits;
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

	void Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState);

	void AddEffect(MoveEffect* effect);
};