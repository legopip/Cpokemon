#include "SnowyWeather.h"

SnowyWeather::SnowyWeather() {
	isLimitted = false;
	cleanUpFlag = false;
	turnLimit = 0;
	weatherType = CLEAR_WEATHER;
}

SnowyWeather::~SnowyWeather() {

}

float SnowyWeather::GetMoveDamageModifier(Typings type) {
	if (type == ICE_TYPE) { return 1.5f; }
	return 1.0f;
}

float SnowyWeather::GetSPDEFModifier(Typings Type1, Typings type2) {
	return 1.0f;
}

void SnowyWeather::SetupLimit(bool extended = false) {
	turnLimit = rand() % 3 + 3;
	if (extended) { turnLimit += 2; }

	isLimitted = true;
}

void SnowyWeather::Upkeep(std::vector<Pokemon*> affectedPokemon) {
	for (int i = 0; i < affectedPokemon.size(); i++) {
		bool isIceType = affectedPokemon[i]->species.type1 == ICE_TYPE
			|| affectedPokemon[i]->species.type2 == ICE_TYPE;

		if (!isIceType) {
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