#pragma once

#include "MoveEffect.h"
#include "Move.h"

class StatChangeEffect : public MoveEffect {
public:
    Stats affectedStat;
    int change;
    int chance;
    bool isIndependant; //does this require the move to have hit before?
    bool affectsUser = false;

    void Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery);
    
};