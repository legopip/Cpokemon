#pragma once

#include "MoveEffect.h"

#include "WeatherLookUp.h"

class PhysicalAttackMove : public MoveEffect {
public:
	int power;
	int accuracy; //-1 for always hits moves

    void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary& summery) {
        for (int i = 0; i < targets.size(); i++) {
            float effectiveness = chart.GetEffectiveness(*type, 
                targets[i]->species.type1, targets[i]->species.type2);

            //Check if it hits
            if (accuracy > -1) { 
                int hitChance = rand() % 100 + 1;
                if (hitChance > accuracy) {
                    summery.hits.push_back(false);
                    if (targets.size() == 1) {
                        std::cout << "The attack missed!" << std::endl;
                    }
                    else {
                        std::cout << "The attack missed the opponent " << targets[i]->species.name << std::endl;
                    }
                    continue;
                }
            }
            summery.hits.push_back(true);

            //get the attacker and Defender Data
            int attackerATK = user->GetATK();
            int defenderDEF = targets[i]->GetDEF();
            int attackerLVL = user->level;
            float STAB = 1.0f;
            if (*type == user->species.type1 || *type == user->species.type1) {
                STAB = 1.5f;
            }

            float randomness = (rand() % 15 + 85) / 100.0f;
            float critical = 1.0f;
            int critChance = rand() % 26;
            if (critChance == 0) {
                std::cout << "Critical Hit!" << std::endl;
                critical = 1.5f;
            }

            if (effectiveness == 0.0f) {
                std::cout << "It had no effect." << std::endl;
            }
            else if (effectiveness > 1.0f) {
                std::cout << "It's super effective!" << std::endl;
            }
            else if (effectiveness < 1.0f) {
                std::cout << "It's not very effective..." << std::endl;
            }

            //plug it into the pokemon damage formula
            //source: https://bulbapedia.bulbagarden.net/wiki/Damage
            int damage = ((((2 * attackerLVL) / 5.0f + 2) * (power * user->ability->GetAttackMod(user, type)) * (attackerATK / defenderDEF)) / 50.0f + 2)
                * critical * randomness * effectiveness * STAB;

            //std::cout << "Dealing " << damage << " damage" << std::endl;
            damage *= weatherLookUp.weather[summery.currentWeather]->GetMoveDamageModifier(*type);

            targets[i]->currentHP -= damage;

            summery.damageTotal += damage;
        }
	}
};

class SpecialAttackMove : public MoveEffect {
public:
    int power;
    int accuracy; //-1 for always hits moves

    void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary& summery) {
        for (int i = 0; i < targets.size(); i++) {
            float effectiveness = chart.GetEffectiveness(*type,
                targets[i]->species.type1, targets[i]->species.type2);

            //Check if it hits
            if (accuracy > -1) {
                int hitChance = rand() % 100 + 1;
                if (hitChance > accuracy) {
                    summery.hits.push_back(false);
                    if (targets.size() == 1) {
                        std::cout << "The attack missed!" << std::endl;
                    }
                    else {
                        std::cout << "The attack missed the opponent " << targets[i]->species.name << std::endl;
                    }
                    continue;
                }
            }
            summery.hits.push_back(true);

            //get the attacker and Defender Data
            int attackerATK = user->GetSPATK();
            int defenderDEF = targets[i]->GetSPDEF() 
                * weatherLookUp.weather[summery.currentWeather]->GetSPDEFModifier(targets[1]->species.type1, targets[1]->species.type2);
            int attackerLVL = user->level;
            float STAB = 1.0f;
            if (*type == user->species.type1 || *type == user->species.type1) {
                STAB = 1.5f;
            }

            float randomness = (rand() % 15 + 85) / 100.0f;
            float critical = 1.0f;
            int critChance = rand() % 26;
            if (critChance == 0) {
                std::cout << "Critical Hit!" << std::endl;
                critical = 1.5f;
            }

            if (effectiveness == 0.0f) {
                std::cout << "It had no effect." << std::endl;
            }else if (effectiveness > 1.0f) {
                std::cout << "It's super effective!" << std::endl;
            }else if (effectiveness < 1.0f) {
                std::cout << "It's not very effective..." << std::endl;
            }

            //plug it into the pokemon damage formula
            //source: https://bulbapedia.bulbagarden.net/wiki/Damage
            int damage = ((((2 * attackerLVL) / 5.0f + 2) * (power * user->ability->GetAttackMod(user, type)) * (attackerATK / defenderDEF)) / 50.0f + 2)
                * critical * randomness * effectiveness * STAB;

            //std::cout << "Dealing " << damage << " damage" << std::endl;
            damage *= weatherLookUp.weather[summery.currentWeather]->GetMoveDamageModifier(*type);

            targets[i]->currentHP -= damage;

            summery.damageTotal += damage;
        }
    }
};

class LifeStealEffect : public MoveEffect {
    void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary& summery) {
        user->currentHP += summery.damageTotal / 2 + 1;
        //std::cout << "Healing " << summery.damageTotal / 2 + 1 << " Damage" << std::endl;
        std::cout << user->nickname << " regained HP." << std::endl;
        if (user->currentHP > user->GetHP()) { user->currentHP = user->GetHP(); }
    }
};