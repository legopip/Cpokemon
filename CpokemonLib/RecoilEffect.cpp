#include "RecoilEffect.h"

void RecoilEffect::Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery) {
    user->currentHP -= summery.totalDamage * recoilAmount;

    std::cout << user->nickname << " was hurt by recoil." << std::endl;
}