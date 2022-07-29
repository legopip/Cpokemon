// CpokemonConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "TypeChart.h"
#include "DataLoader.h"
#include "PokemonBuilder.h"
#include "Battle.h"

int main()
{

    DataLoader dL;
    srand(time(NULL));

    std::cout << "Number of pokemon loaded: " << pokemonSpecies.size() << std::endl;

    PokemonBuilder pkmnBuilder;
    
    Player* player = new Player("Player", "Player");
    Trainer* trainer = new Trainer("Test", "Placeholder");

    int chosenPokemon = rand() % 3;
    Pokemon* pk1 = pkmnBuilder.BuildWeakTrainerPokemon(TAPID, 15);
    pk1->nickname = "Hero";
    player->AddPokemonToTeam(pk1);
    chosenPokemon = rand() % 3;
    Pokemon* pk2 = pkmnBuilder.BuildRegularPokemon(MOALT, 15);
    trainer->AddPokemonToTeam(pk2);

    std::cout << pk1->ToString() << std::endl;
    std::cout << pk2->ToString() << std::endl;
     
    Battle battle(player, trainer, false, false);
    battle.ResolveBattle();

    std::cout << pk1->nickname << " HP: " << pk1->currentHP << "/" << pk1->GetHP() << std::endl;
    std::cout << pk2->nickname << " HP: " << pk2->currentHP << "/" << pk2->GetHP() << std::endl;

    delete player;
    delete trainer;
}


