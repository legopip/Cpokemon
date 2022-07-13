// CpokemonConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "TypeChart.h"
#include "DataLoader.h"
#include "PokemonBuilder.h"

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
    
    //set up the Battle (this logic will be moved to the LIB later
    std::vector<Pokemon*> enemyPokemon;
    enemyPokemon.push_back(pk2);
    std::vector<Pokemon*> playerPokemon;
    playerPokemon.push_back(pk1);

    while (pk1->currentHP > 0 && pk2->currentHP > 0) {
        //Print the current status (this will be replaced by Lucas's UI later
        std::cout << pk1->nickname << " HP: " << pk1->currentHP << "/" << pk1->GetHP() << std::endl;
        std::cout << pk2->nickname << " HP: " << pk2->currentHP << "/" << pk2->GetHP() << std::endl;
        //figure out which move each pokemon will use (random is fine right now)
        int pk1ChosenMove = rand() % pk1->numberOfKnownMoves;
        int pk2ChosenMove = rand() % pk2->numberOfKnownMoves;
        //Determine Move Order (Move Priority then Pokemon Speed)
        
        //resolve turn
        pk1->knownMoves[pk1ChosenMove].move->Invoke(pk1, enemyPokemon);
        pk2->knownMoves[pk2ChosenMove].move->Invoke(pk2, playerPokemon);
    }
    //reward the winner with exp
    std::cout << pk1->nickname << " HP: " << pk1->currentHP << "/" << pk1->GetHP() << std::endl;
    std::cout << pk2->nickname << " HP: " << pk2->currentHP << "/" << pk2->GetHP() << std::endl;

    delete pk1;
    delete pk2;
}


