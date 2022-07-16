#pragma once

#include "Player.h"
#include "Move.h"

struct TurnMovePair {
    Pokemon* pokemon;
    Move* move;
    std::vector<Pokemon*> targets;
};

class Battle {
public:


private:
    bool OrderTurns(TurnMovePair lhs, TurnMovePair rhs) {
        if (lhs.move->priority == rhs.move->priority) {
            return lhs.pokemon->GetSPD() > rhs.pokemon->GetSPD();
        }
        else {
            return lhs.move->priority > rhs.move->priority;
        }
    }
};