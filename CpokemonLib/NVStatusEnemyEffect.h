#pragma once

#include "MoveEffect.h"
#include "StatusConditionBuilder.h"
#include "Move.h"

class NVStatusEnemyEffect : public MoveEffect {
public:
    NonVolatileStatusNames nvStatus;
    int chance;
    bool isIndependant; //does this require the move to have hit before?

    void Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery);
};