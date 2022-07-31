#pragma once

#include "MoveEffect.h"
#include "StatusConditionBuilder.h"
#include "WeatherLookUp.h"

class StatChangeEffect : public MoveEffect {
public:
    Stats affectedStat;
    int change;
    int chance;
    bool isIndependant; //does this require the move to have hit before?
    bool affectsUser = false;

    void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary& summery) {
        if (affectsUser) {
            bool hasHit = false;
            for (int i = 0; i < targets.size(); i++) {
                if (summery.hits[i]) { hasHit = true; break; }
            }
            if (hasHit) {
                switch (affectedStat)
                {
                case ATK_STAT:
                    user->ATKmod += change;
                    if (user->ATKmod < -6) {
                        std::cout << "It can't go any lower!" << std::endl;
                        user->ATKmod = -6;
                    }
                    if (user->ATKmod > 6) {
                        std::cout << "It can't go any higher!" << std::endl;
                        user->ATKmod = 6;
                    }
                    break;
                case DEF_STAT:
                    user->DEFmod += change;
                    if (user->DEFmod < -6) {
                        std::cout << "It can't go any lower!" << std::endl;
                        user->DEFmod = -6;
                    }
                    if (user->DEFmod > 6) {
                        std::cout << "It can't go any higher!" << std::endl;
                        user->DEFmod = 6;
                    }
                    break;
                case SPATK_STAT:
                    user->SPATKmod += change;
                    if (user->SPATKmod < -6) {
                        std::cout << "It can't go any lower!" << std::endl;
                        user->SPATKmod = -6;
                    }
                    if (user->SPATKmod > 6) {
                        std::cout << "It can't go any higher!" << std::endl;
                        user->SPATKmod = 6;
                    }
                    break;
                case SPDEF_STAT:
                    user->SPDEFmod += change;
                    if (user->SPDEFmod < -6) {
                        std::cout << "It can't go any lower!" << std::endl;
                        user->SPDEFmod = -6;
                    }
                    if (user->SPDEFmod > 6) {
                        std::cout << "It can't go any higher!" << std::endl;
                        user->SPDEFmod = 6;
                    }
                    break;
                case SPD_STAT:
                    user->SPDmod += change;
                    if (user->SPDmod < -6) {
                        std::cout << "It can't go any lower!" << std::endl;
                        user->SPDmod = -6;
                    }
                    if (user->SPDmod > 6) {
                        std::cout << "It can't go any higher!" << std::endl;
                        user->SPDmod = 6;
                    }
                    break;
                case EVA_STAT:
                    user->EVAmod += change;
                    if (user->EVAmod < -3) {
                        std::cout << "It can't go any lower!" << std::endl;
                        user->EVAmod = -3;
                    }
                    if (user->EVAmod > 3) {
                        std::cout << "It can't go any higher!" << std::endl;
                        user->EVAmod = 3;
                    }
                    break;
                case ACC_STAT:
                    user->ACCmod += change;
                    if (user->ACCmod < -3) {
                        std::cout << "It can't go any lower!" << std::endl;
                        user->ACCmod = -3;
                    }
                    if (user->ACCmod > 3) {
                        std::cout << "It can't go any higher!" << std::endl;
                        user->ACCmod = 3;
                    }
                    break;
                default:
                    break;
                }
            }
            return;
        }

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
            case EVA_STAT:
                targets[i]->EVAmod += change;
                if (targets[i]->EVAmod < -3) {
                    std::cout << "It can't go any lower!" << std::endl;
                    targets[i]->EVAmod = -3;
                }
                if (targets[i]->EVAmod > 3) {
                    std::cout << "It can't go any higher!" << std::endl;
                    targets[i]->EVAmod = 3;
                }
                break;
            case ACC_STAT:
                targets[i]->ACCmod += change;
                if (targets[i]->ACCmod < -3) {
                    std::cout << "It can't go any lower!" << std::endl;
                    targets[i]->ACCmod = -3;
                }
                if (targets[i]->ACCmod > 3) {
                    std::cout << "It can't go any higher!" << std::endl;
                    targets[i]->ACCmod = 3;
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

class WeatherChangeEffect : public MoveEffect {
public :
    WeatherNames weatherType;

    void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary& summery) {
        if (weatherType == summery.currentWeather) {
            std::cout << "But it failed!" << std::endl;
            return;
        }
        //tell the weather to be limited
        weatherLookUp.weather[weatherType]->SetupLimit();

        summery.currentWeather = weatherType;
    }
};