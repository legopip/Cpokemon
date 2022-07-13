// CpokemonConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "TypeChart.h"
#include "DataLoader.h"
#include "PokemonBuilder.h"

struct TurnMovePair {
    Pokemon* pokemon;
    Move* move;  
    std::vector<Pokemon*> targets;
};

bool OrderTurns(TurnMovePair lhs, TurnMovePair rhs) {
    if (lhs.move->priority == rhs.move->priority) {
        return lhs.pokemon->GetSPD() > rhs.pokemon->GetSPD();
    }
    else {
        return lhs.move->priority > rhs.move->priority;
    }
}

int main()
{

    DataLoader dL;
    srand(time(NULL));

    std::cout << "Number of pokemon loaded: " << pokemonSpecies.size() << std::endl;

    PokemonBuilder pkmnBuilder;
    
    int chosenPokemon = rand() % 3;
    Pokemon* pk1 = pkmnBuilder.BuildRegularPokemon(chosenPokemon, 5);
    pk1->nickname = "Hero";
    chosenPokemon = rand() % 3;
    Pokemon* pk2 = pkmnBuilder.BuildRegularPokemon(chosenPokemon, 5);
    

    std::cout << pk1->ToString() << std::endl;
    std::cout << pk2->ToString() << std::endl;
        

    while (pk1->currentHP > 0 && pk2->currentHP > 0) {
        //Print the current status (this will be replaced by Lucas's UI later
        std::cout << pk1->nickname << " HP: " << pk1->currentHP << "/" << pk1->GetHP() << std::endl;
        std::cout << pk2->nickname << " HP: " << pk2->currentHP << "/" << pk2->GetHP() << std::endl;
        //figure out which move each pokemon will use (random is fine right now)
        int pk1ChosenMove = rand() % pk1->numberOfKnownMoves;
        int pk2ChosenMove = rand() % pk2->numberOfKnownMoves;
        //Determine Move Order (Move Priority then Pokemon Speed)
        TurnMovePair pk1turn;
        pk1turn.pokemon = pk1;
        pk1turn.move = pk1->knownMoves[pk1ChosenMove].move;
        pk1turn.targets.push_back(pk2);
        
        TurnMovePair pk2turn;
        pk2turn.pokemon = pk2;
        pk2turn.move = pk2->knownMoves[pk2ChosenMove].move;
        pk2turn.targets.push_back(pk1);

        std::vector<TurnMovePair> turns;
        turns.push_back(pk1turn);
        turns.push_back(pk2turn);
        std::sort(turns.begin(), turns.end(), OrderTurns);

        //resolve turn
        for (int i = 0; i < turns.size(); i++) {
            turns[i].move->Invoke(turns[i].pokemon, turns[i].targets);
        }
    }
    //reward the winner with exp
    if (pk1->currentHP > 0) {
        pk1->exp += pk2->GetEXPyeild();
    }
    std::cout << pk1->nickname << " HP: " << pk1->currentHP << "/" << pk1->GetHP() << std::endl;
    std::cout << pk2->nickname << " HP: " << pk2->currentHP << "/" << pk2->GetHP() << std::endl;

    delete pk1;
    delete pk2;
}


