#pragma once

#include "Pokemon.h"
#include "DataLoader.h"
#include "MoveBuilder.h"
#include "AbilityBuilder.h"

class PokemonBuilder {
public:

	Pokemon* BuildRegularPokemon(int index, int level) {
		Pokemon* pokemon = new Pokemon();

		pokemon->species = pokemonSpecies[index];
		pokemon->EVHP = 0;
		pokemon->EVATK = 0;
		pokemon->EVDEF = 0;
		pokemon->EVSPATK = 0;
		pokemon->EVSPDEF = 0;
		pokemon->EVSPD = 0;

		pokemon->IVHP = rand() % 32;
		pokemon->IVATK = rand() % 32;
		pokemon->IVDEF = rand() % 32;
		pokemon->IVSPATK = rand() % 32;
		pokemon->IVSPDEF = rand() % 32; 
		pokemon->IVSPD = rand() % 32;

		pokemon->nature = Natures[rand() % 25];

		pokemon->nickname = pokemon->species.name;

		if (pokemon->species.genderRatio == -1) {
			pokemon->gender = UNKNOWN_PKMN_GENDER;
		}
		else {
			int gender = rand() % 100 + 1;
			if (gender > pokemon->species.genderRatio) {
				pokemon->gender = FEMALE_PKMN_GENDER;
			}
			else {
				pokemon->gender = MALE_PKMN_GENDER;
			}
		}

		int pokemonAbility = rand() % 2;
		if (pokemonAbility == 0) {
			pokemon->ability = abilityBuilder.BuildAbility(pokemon->species.ability1);
		}
		else {
			pokemon->ability = abilityBuilder.BuildAbility(pokemon->species.ability2);
		}

		pokemon->level = level;
		pokemon->exp = lookUpExp(pokemon->species.expCurve, level - 1);
		if (level > 100) {
			pokemon->expToLevel = lookUpExp(pokemon->species.expCurve, level);
		}

		int moveIndex = 0;
		while (moveIndex < pokemon->species.moveset.size()) { //gets the last learnable move in the moveset
			if (pokemon->species.moveset[moveIndex].level > pokemon->level) { break; }
			moveIndex++;
		}
		if (moveIndex < 4) {
			pokemon->numberOfKnownMoves = 0;
			for (int i = 0; i < moveIndex; i++) {
				KnownMove knownMove;
				knownMove.move = moveBuilder.BuildMove(pokemon->species.moveset[i].moveName);
				knownMove.currentPP = knownMove.move->PP;
				pokemon->knownMoves[i] = knownMove;
				pokemon->numberOfKnownMoves++;
			}
		}
		else {
			pokemon->numberOfKnownMoves = 4;
			for (int i = 0; i < 4; i++) {
				KnownMove knownMove;
				knownMove.move = moveBuilder.BuildMove(pokemon->species.moveset[moveIndex - 4 + i].moveName);
				knownMove.currentPP = knownMove.move->PP;
				pokemon->knownMoves[i] = knownMove;
			}
		}

		for (int i = 0; i < pokemon->species.possibleHeldItems.size(); i++) {
			int chance = rand() % 100 + 1;
			if (chance > pokemon->species.possibleHeldItems[i].chance) { continue; }
			
			//make the item and set it to be the pokemon's held item
			break;
		}

		pokemon->currentHP = pokemon->GetHP();
		pokemon->isTrainerPokemon = false;
		return pokemon;
	}

	Pokemon* BuildWeakTrainerPokemon(int index, int level) {
		Pokemon* pokemon = BuildRegularPokemon(index, level);
		pokemon->isTrainerPokemon = true;
		return pokemon;
	}
};

