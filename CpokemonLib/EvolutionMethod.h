#pragma once

#include "PokemonNames.h"

class Pokemon;
class EvolutionMethod {
public:
	virtual bool TryToEvole(Pokemon* pokemon) = 0;

protected:
	PokemonNames evolution;

	EvolutionMethod(PokemonNames evolution) {
		this->evolution = evolution;
	}
};
