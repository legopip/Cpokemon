#include "Trainer.h"

Trainer::Trainer(std::string name, std::string trainerClass)
{
	this->name = name;
	this->trainerClass = trainerClass;

	teamSize = 0;
}

Trainer::~Trainer()
{
	//this?
	for (int i = 0; i < teamSize; i++) {
		delete team[i];
	}
	//or this?
	//delete[] team;
}

void Trainer::AddPokemonToTeam(Pokemon* pokemon) {
	if (teamSize < 6) {
		team[teamSize] = pokemon;
		teamSize++;
	}
}

bool Trainer::OutOfUseablePokemon() {
	for (int i = 0; i < teamSize; i++) {
		if (team[i]->currentHP > 0) { return false; }
	}
	return true;
}