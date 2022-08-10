#pragma once

#include "MoveEffect.h"
#include "Move.h"

class LifeStealEffect : public MoveEffect {
    void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary& summery) {
        user->currentHP += summery.damageTotal / 2 + 1;
        //std::cout << "Healing " << summery.damageTotal / 2 + 1 << " Damage" << std::endl;
        std::cout << user->nickname << " regained HP." << std::endl;
        if (user->currentHP > user->GetHP()) { user->currentHP = user->GetHP(); }
    }
};