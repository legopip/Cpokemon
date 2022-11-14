#include "LifeStealEffect.h"


void LifeStealEffect::Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery) {
    user->currentHP += summery.totalDamage / 2 + 1;
    //std::cout << "Healing " << summery.damageTotal / 2 + 1 << " Damage" << std::endl;
    std::cout << user->nickname << " regained HP." << std::endl;
    if (user->currentHP > user->GetHP()) { user->currentHP = user->GetHP(); }
}