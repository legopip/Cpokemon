#include "SandyWeather.h"

SandyWeather::SandyWeather() {
	isLimitted = false;
	cleanUpFlag = false;
	turnLimit = 0;
	weatherType = CLEAR_WEATHER;
}

SandyWeather::~SandyWeather() {

}

float SandyWeather::GetMoveDamageModifier(Typings type) {
	return 1.0f;
}

float SandyWeather::GetSPDEFModifier(Typings Type1, Typings type2) {
	if (Type1 == ROCK_TYPE || type2 == ROCK_TYPE) { return 1.5f; }
	return 1.0f;
}

void SandyWeather::SetupLimit(bool extended = false) {
	turnLimit = rand() % 3 + 3;
	if (extended) { turnLimit += 2; }

	isLimitted = true;
}

void SandyWeather::Upkeep(std::vector<Pokemon*> affectedPokemon) {
	for (int i = 0; i < affectedPokemon.size(); i++) {
		bool isSteelType = affectedPokemon[i]->species.type1 == STEEL_TYPE 
			|| affectedPokemon[i]->species.type2 == STEEL_TYPE;
		bool isRockType = affectedPokemon[i]->species.type1 == ROCK_TYPE
			|| affectedPokemon[i]->species.type2 == ROCK_TYPE;
		bool isGroundType = affectedPokemon[i]->species.type1 == GROUND_TYPE
			|| affectedPokemon[i]->species.type2 == GROUND_TYPE;

		if (!isSteelType && !isRockType && !isGroundType) {
			affectedPokemon[i]->currentHP -= affectedPokemon[i]->GetHP() / 16;
		}
	}
	if (isLimitted) {
		turnLimit--;
		if (turnLimit == 0) {
			isLimitted = false;
			cleanUpFlag = true;
		}
	}
}