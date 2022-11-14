#pragma once

#include "MoveEffect.h"
#include "Move.h"

class RecoilEffect : public MoveEffect {
    float recoilAmount;

    void Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery);
};