#pragma once

#include "MoveEffect.h"
#include "WeatherLookUp.h"
#include "Move.h"

class SpecialAttackMove : public MoveEffect {
public:
    int power;
    int accuracy; //-1 for always hits moves

    void Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery);
};