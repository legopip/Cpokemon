#pragma once

#include "MoveEffect.h"
#include "StatusConditionBuilder.h"
#include "Move.h"

class NVStatusEnemyEffect : public MoveEffect {
public:
    NonVolatileStatusNames nvStatus;
    int chance;
    bool isIndependant; //does this require the move to have hit before?

    void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary& summery) {
        for (int i = 0; i < targets.size(); i++) {
            if (!isIndependant) {
                if (!summery.hits[i]) { continue; } //the attack missed this pokemon, so skip it
            }

            int effectChance = rand() % 100 + 1;
            if (effectChance > chance) {
                if (targets.size() == 1) {
                    std::cout << "It had no effect!" << std::endl;
                }
                else {
                    std::cout << "it had no effect on the opponent " << targets[i]->species.name << std::endl;
                }
                continue;
            }

            targets[i]->nvStatus = statusConditionBuilder.BuildNonVolatileStatusCondition(nvStatus, targets[i]);
        }
    }
};