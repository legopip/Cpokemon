#include "SleepStatusCondition.h"

SleepStatusCondition::SleepStatusCondition(Pokemon* pokemon) {
	affectedPokemon = pokemon;

	turnCounter = rand() % 3 + 3;

	ATKmod = 1.5f;
	DEFmod = 1.0f;
	SPATKmod = 1.0f;
	SPDEFmod = 1.0f;
	SPDmod = 1.0f;
}

SleepStatusCondition::~SleepStatusCondition() {

}

void SleepStatusCondition::Upkeep() {
	turnCounter--;
	if (turnCounter == 0) {
		//update a flag in the pokemon to tell it to remove the status condition
	}
}