#pragma once

#include "MoveEffect.h"
#include "Move.h"

class RecoilEffect : public MoveEffect {
    float recoilAmount;

    void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary& summery) {
        user->currentHP -= summery.damageTotal * recoilAmount;
        //std::cout << "Healing " << summery.damageTotal / 2 + 1 << " Damage" << std::endl;
        std::cout << user->nickname << " was hurt by recoil." << std::endl;
    }
};