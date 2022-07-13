#pragma once

#include "MoveEffect.h"
#include "StatusConditionBuilder.h"

class StatChangeEffect : public MoveEffect {
public:
    Stats affectedStat;
    int change;
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

            switch (affectedStat)
            {
            case ATK_STAT:
                targets[i]->ATKmod += change;
                if (targets[i]->ATKmod < -6) {
                    std::cout << "It can't go any lower!" << std::endl;
                    targets[i]->ATKmod = -6;
                }
                if (targets[i]->ATKmod > 6) {
                    std::cout << "It can't go any higher!" << std::endl;
                    targets[i]->ATKmod = 6;
                }
                break;
            case DEF_STAT:
                targets[i]->DEFmod += change;
                if (targets[i]->DEFmod < -6) {
                    std::cout << "It can't go any lower!" << std::endl;
                    targets[i]->DEFmod = -6;
                }
                if (targets[i]->DEFmod > 6) {
                    std::cout << "It can't go any higher!" << std::endl;
                    targets[i]->DEFmod = 6;
                }
                break;
            case SPATK_STAT:
                targets[i]->SPATKmod += change;
                if (targets[i]->SPATKmod < -6) {
                    std::cout << "It can't go any lower!" << std::endl;
                    targets[i]->SPATKmod = -6;
                }
                if (targets[i]->SPATKmod > 6) {
                    std::cout << "It can't go any higher!" << std::endl;
                    targets[i]->SPATKmod = 6;
                }
                break;
            case SPDEF_STAT:
                targets[i]->SPDEFmod += change;
                if (targets[i]->SPDEFmod < -6) {
                    std::cout << "It can't go any lower!" << std::endl;
                    targets[i]->SPDEFmod = -6;
                }
                if (targets[i]->SPDEFmod > 6) {
                    std::cout << "It can't go any higher!" << std::endl;
                    targets[i]->SPDEFmod = 6;
                }
                break;
            case SPD_STAT:
                targets[i]->SPDmod += change;
                if (targets[i]->SPDmod < -6) {
                    std::cout << "It can't go any lower!" << std::endl;
                    targets[i]->SPDmod = -6;
                }
                if (targets[i]->SPDmod > 6) {
                    std::cout << "It can't go any higher!" << std::endl;
                    targets[i]->SPDmod = 6;
                }
                break;
            default:
                break;
            }
        }
    }
};

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