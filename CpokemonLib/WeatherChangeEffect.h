#pragma once

#include "MoveEffect.h"

#include "Move.h"

class WeatherChangeEffect : public MoveEffect {
public:
    WeatherNames weatherType;

    void Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery);
};