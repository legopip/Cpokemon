#pragma once

#include <vector>
#include "Pokemon.h"

struct MoveSummary {
	int damageTotal;
	std::vector<bool> hits;
};

class MoveFunction {	
public:
	//virtual void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary summery = MoveSummary()) = 0;
};