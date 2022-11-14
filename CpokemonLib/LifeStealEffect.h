#pragma once

#include "MoveEffect.h"
#include "Move.h"

class LifeStealEffect : public MoveEffect {
public:
    void Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery);
};