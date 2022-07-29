#pragma once

#include "EvolutionMethod.h"
#include "Pokemon.h"
#include "AllPokemon.h"

class LevelUpEvolution : public EvolutionMethod {
public:
	LevelUpEvolution(PokemonNames evolution, int requiredLevel) : EvolutionMethod(evolution) {
		this->requiredLevel = requiredLevel;
	}

	bool TryToEvole(Pokemon* pokemon) {
		if(pokemon->level >= requiredLevel){
			pokemon->species = pokemonSpecies[evolution];
			return true;
		}
		return false;
	}

private:
	int requiredLevel;
};