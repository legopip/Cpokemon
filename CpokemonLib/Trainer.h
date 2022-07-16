#pragma once

#include "Pokemon.h"

class Trainer
{
public:
	Trainer(std::string name, std::string trainerClass);
	~Trainer();

	std::string name;
	std::string trainerClass;

	int teamSize;
	Pokemon* team[6];

	void AddPokemonToTeam(Pokemon* pokemon);

private:

};

