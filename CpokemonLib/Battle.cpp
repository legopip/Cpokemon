#include "Battle.h"

#include <algorithm>

Battle::Battle(Player* player, Trainer* trainer, bool isWildEncounter, bool isDoubleBattle) {
    this->isWildEncouter = isWildEncounter;
    this->player = player;
    this->enemy = trainer;
    this->isDoubleBattle = isDoubleBattle;

}

Battle::~Battle() {

}

void Battle::ResolveBattle() {

    playerActivePokemon = player->team[0];
    enemyActivePokemon = enemy->team[0];

    while (!player->OutOfUseablePokemon() && !enemy->OutOfUseablePokemon()) {
        //Print the current status (this will be replaced by Lucas's UI later
        PrintBattleHUD();
        //figure out which move each pokemon will use (random is fine right now)
        std::cout << "What would you like to do?" << std::endl;
        for (int i = 0; i < playerActivePokemon->numberOfKnownMoves; i++) {
            std::cout << i << ". " << playerActivePokemon->knownMoves[i].move->name << "  ";           
        }
        std::cout << std::endl;
        int pk1ChosenMove = -1; 
        while (pk1ChosenMove < 0 || pk1ChosenMove >= playerActivePokemon->numberOfKnownMoves) {
            std::cin >> pk1ChosenMove;
        }
        
        int pk2ChosenMove = rand() % enemyActivePokemon->numberOfKnownMoves;
        //Determine Move Order (Move Priority then Pokemon Speed)
        TurnMovePair pk1turn;
        pk1turn.pokemon = playerActivePokemon;
        pk1turn.move = playerActivePokemon->knownMoves[pk1ChosenMove].move;

        switch (playerActivePokemon->knownMoves[pk1ChosenMove].move->range)
        {
        case TARGETS_SELF:
            pk1turn.targets.push_back(playerActivePokemon);
            break;
        case TARGETS_1ENEMY:
            if (!isDoubleBattle) {
                pk1turn.targets.push_back(enemyActivePokemon);
            }
            else {
                //get input for who to target
            }
            break;
        case TARGETS_1ALLY:
            if (!isDoubleBattle) {
                pk1turn.targets.push_back(playerActivePokemon);
            }
            else {
                //get input for who to target
            }
            break;
        case TARGETS_ALL_ENEMIES:
            pk1turn.targets.push_back(enemyActivePokemon);
            if (isDoubleBattle) {
                if (enemyActivePokemon2) {
                    pk1turn.targets.push_back(enemyActivePokemon2);
                }
            }
            break;
        case TARGETS_ALL_ALLIES:
            pk1turn.targets.push_back(playerActivePokemon);
            if (isDoubleBattle) {
                if (playerActivePokemon2) {
                    pk1turn.targets.push_back(playerActivePokemon2);
                }
            }
            break;
        case TARGETS_ALL_OTHERS:
            pk1turn.targets.push_back(enemyActivePokemon);
            if (isDoubleBattle) {
                if (enemyActivePokemon2) {
                    pk1turn.targets.push_back(enemyActivePokemon2);
                }
                if (playerActivePokemon2) {
                    pk1turn.targets.push_back(playerActivePokemon2);
                }
            }
            break;
        default:
            break;
        }

        //ai does this
        TurnMovePair pk2turn;
        pk2turn.pokemon = enemyActivePokemon;
        pk2turn.move = enemyActivePokemon->knownMoves[pk2ChosenMove].move;
        pk2turn.targets.push_back(playerActivePokemon);

        std::vector<TurnMovePair> turns;
        turns.push_back(pk1turn);
        turns.push_back(pk2turn);
        std::sort(turns.begin(), turns.end(), OrderTurns);

        //resolve turn
        for (int i = 0; i < turns.size(); i++) {
            if (turns[i].pokemon->currentHP > 0) {
                turns[i].move->Invoke(turns[i].pokemon, turns[i].targets);
            }
        }
        if (playerActivePokemon->nvStatus) {
            playerActivePokemon->nvStatus->Upkeep();
        }
        if (enemyActivePokemon->nvStatus) {
            enemyActivePokemon->nvStatus->Upkeep();
        }
    }
    //reward the winner with exp
    GiveRewards();
}


//Private stuff

void Battle::PrintBattleHUD() {
    std::cout << playerActivePokemon->nickname << std::endl;
    std::cout << playerActivePokemon->GetTextHPbar() << std::endl;
    std::cout << enemyActivePokemon->nickname << std::endl;
    std::cout << enemyActivePokemon->GetTextHPbar() << std::endl;
}

void Battle::GiveRewards() {
    if (playerActivePokemon->currentHP > 0) {
        switch (enemyActivePokemon->species.evYeild)
        {
        case HP_STAT:
            playerActivePokemon->EVHP += enemyActivePokemon->species.evYeildAmount;
            break;
        case ATK_STAT:
            playerActivePokemon->EVATK += enemyActivePokemon->species.evYeildAmount;
            break;
        case DEF_STAT:
            playerActivePokemon->EVDEF += enemyActivePokemon->species.evYeildAmount;
            break;
        case SPATK_STAT:
            playerActivePokemon->EVSPATK += enemyActivePokemon->species.evYeildAmount;
            break;
        case SPDEF_STAT:
            playerActivePokemon->EVSPDEF += enemyActivePokemon->species.evYeildAmount;
            break;
        case SPD_STAT:
            playerActivePokemon->EVSPD += enemyActivePokemon->species.evYeildAmount;
            break;
        default:
            break;
        }
        playerActivePokemon->exp += enemyActivePokemon->GetEXPyeild();
        playerActivePokemon->CheckForLevelUp();
    }
}

bool Battle::OrderTurns(TurnMovePair lhs, TurnMovePair rhs) {
    if (lhs.move->priority == rhs.move->priority) {
        return lhs.pokemon->GetSPD() > rhs.pokemon->GetSPD();
    }
    else {
        return lhs.move->priority > rhs.move->priority;
    }
}