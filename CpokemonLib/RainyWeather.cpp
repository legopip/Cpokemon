#include "RainyWeather.h"

RainyWeather::RainyWeather() {
	isLimitted = false;
	cleanUpFlag = false;
	turnLimit = 0;
	weatherType = CLEAR_WEATHER;
}

RainyWeather::~RainyWeather() {

}

float RainyWeather::GetMoveDamageModifier(Typings type) {
	if (type == WATER_TYPE) { return 1.5f; }
	if (type == FIRE_TYPE) { return 0.5f; }
	return 1.0f;
}

float RainyWeather::GetSPDEFModifier(Typings Type1, Typings type2) {
	return 1.0f;
}

void RainyWeather::SetupLimit(bool extended) {
	turnLimit = rand() % 3 + 3; 
	if (extended) { turnLimit += 2; }

	isLimitted = true;
}

void RainyWeather::Upkeep(std::vector<Pokemon*> affectedPokemon) {
	if (isLimitted) {
		turnLimit--;
		if (turnLimit == 0) {
			isLimitted = false;
			cleanUpFlag = true;
		}
	}
}