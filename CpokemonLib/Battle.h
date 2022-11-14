#pragma once

#include "Player.h"
#include "Move.h"
#include "WeatherNames.h"

struct TurnMovePair {
    Pokemon* pokemon;
    Move* move;
    std::vector<Pokemon*> targets;
};

class Battle {
public:
    Battle(Player* player, Trainer* trainer, bool isWildEncounter, bool isDoubleBattle);
    ~Battle();

    void ResolveBattle();

private:
    bool isWildEncouter;
    bool isDoubleBattle;

    BattleState battlestate;

    Move* lastUsedMove;

    Player* player;
    Trainer* enemy;

    //pointer for the active pokemon;
    Pokemon* playerActivePokemon;
    Pokemon* enemyActivePokemon;
    //for double battle
    Pokemon* playerActivePokemon2;
    Pokemon* enemyActivePokemon2;

    void PrintBattleHUD();
    TurnMovePair SetUpEnemyTurn(Pokemon* enemyPk);
    void GiveRewards();

    static bool OrderTurns(TurnMovePair lhs, TurnMovePair rhs);
};