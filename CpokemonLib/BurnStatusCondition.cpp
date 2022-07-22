#include "BurnStatusCondition.h"

BurnStatusCondition::BurnStatusCondition(Pokemon* pokemon) {
	affectedPokemon = pokemon;

	name = BURN_NV_STATUS;

	ATKmod = 0.5f;
	DEFmod = 1.0f;
	SPATKmod = 1.0f;
	SPDEFmod = 1.0f;
	SPDmod = 1.0f;
}

BurnStatusCondition::~BurnStatusCondition() {

}

void BurnStatusCondition::Upkeep() {
	affectedPokemon->currentHP -= affectedPokemon->GetHP() / 8.0f;
}