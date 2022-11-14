#include "NVStatusEnemyEffect.h"

void NVStatusEnemyEffect::Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery) {
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