#include "SleepStatusCondition.h"

SleepStatusCondition::SleepStatusCondition(Pokemon* pokemon) {
	affectedPokemon = pokemon;

	name = SLEEP_NV_STATUS;

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
		affectedPokemon->cleanUpNVStatus = true;
	}
}