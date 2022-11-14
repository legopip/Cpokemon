#include "Battle.h"

#include <algorithm>

#include "WeatherLookUp.h"

Battle::Battle(Player* player, Trainer* trainer, bool isWildEncounter, bool isDoubleBattle) {
    this->isWildEncouter = isWildEncounter;
    this->player = player;
    this->enemy = trainer;
    this->isDoubleBattle = isDoubleBattle;

   
    battlestate.currentWeather = CLEAR_WEATHER;
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
        

        std::vector<TurnMovePair> turns;
        turns.push_back(pk1turn);
        turns.push_back(SetUpEnemyTurn(enemyActivePokemon));
        std::sort(turns.begin(), turns.end(), OrderTurns);

        //resolve turn
        for (int i = 0; i < turns.size(); i++) {
            if (turns[i].pokemon->currentHP > 0) {
                if (turns[i].pokemon->cleanUpNVStatus) {
                    delete turns[i].pokemon->nvStatus;
                    turns[i].pokemon->cleanUpNVStatus = false;
                    std::cout << turns[i].pokemon->nickname << " is all better!" << std::endl;
                }
                if (turns[i].pokemon->nvStatus) {
                    if (turns[i].pokemon->nvStatus->name == SLEEP_NV_STATUS) {
                        std::cout << turns[i].pokemon->nickname << " is fast asleep!" << std::endl;
                        continue;
                    }
                }
                
                turns[i].move->Resolve(turns[i].pokemon, turns[i].targets, battlestate);
                
                lastUsedMove = turns[i].move;
            }
        }
        if (playerActivePokemon->nvStatus) {
            playerActivePokemon->nvStatus->Upkeep();
            
        }
        if (enemyActivePokemon->nvStatus) {
            enemyActivePokemon->nvStatus->Upkeep();
        }
        //weather Upkeep
        std::vector<Pokemon*> currentPokemon;
        currentPokemon.push_back(playerActivePokemon);
        currentPokemon.push_back(enemyActivePokemon);
        weatherLookUp.weather[battlestate.currentWeather]->Upkeep(currentPokemon);
        if (weatherLookUp.weather[battlestate.currentWeather]->cleanUpFlag) {
            battlestate.currentWeather = CLEAR_WEATHER;
        }
    }
    //reward the winner with exp
    GiveRewards();
    //in case any non-persisting weather is still in effect
    weatherLookUp.weather[battlestate.currentWeather]->CleanUpLimit();

    //! END OF BATTLE MIGHT NOT BE CLEANING UP PROPERLY
}


//Private stuff

void Battle::PrintBattleHUD() {
    std::cout << playerActivePokemon->nickname << std::endl;
    std::cout << playerActivePokemon->GetTextHPbar() << std::endl;
    std::cout << enemyActivePokemon->nickname << std::endl;
    std::cout << enemyActivePokemon->GetTextHPbar() << std::endl;
}

TurnMovePair Battle::SetUpEnemyTurn(Pokemon* enemyPk) {
    TurnMovePair movePair;

    int chosenMove = rand() % enemyPk->numberOfKnownMoves;
    movePair.pokemon = enemyPk;
    movePair.move = enemyPk->knownMoves[chosenMove].move;
    
    switch (enemyPk->knownMoves[chosenMove].move->range)
    {
    case TARGETS_SELF:
        movePair.targets.push_back(enemyPk);
        break;
    case TARGETS_1ENEMY:
        if (!isDoubleBattle) {
            movePair.targets.push_back(playerActivePokemon);
        }
        else {
            
        }
        break;
    case TARGETS_1ALLY:
        if (!isDoubleBattle) {
            movePair.targets.push_back(enemyPk);
        }
        else {
            
        }
        break;
    case TARGETS_ALL_ENEMIES:
        movePair.targets.push_back(playerActivePokemon);
        if (isDoubleBattle) {
            if (playerActivePokemon2) {
                movePair.targets.push_back(playerActivePokemon2);
            }
        }
        break;
    case TARGETS_ALL_ALLIES:
        movePair.targets.push_back(enemyPk);
        if (isDoubleBattle) {
            if (enemyActivePokemon2) {
                movePair.targets.push_back(enemyActivePokemon2);
            }
        }
        break;
    case TARGETS_ALL_OTHERS:
        movePair.targets.push_back(playerActivePokemon);
        if (isDoubleBattle) {
            if (enemyActivePokemon2) {
                movePair.targets.push_back(enemyActivePokemon2);
            }
            if (playerActivePokemon2) {
                movePair.targets.push_back(playerActivePokemon2);
            }
        }
        break;
    default:
        break;
    }
    return movePair;
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