#include "SunnyWeather.h"

SunnyWeather::SunnyWeather() {
	isLimitted = false;
	cleanUpFlag = false;
	turnLimit = 0;
	weatherType = CLEAR_WEATHER;
}

SunnyWeather::~SunnyWeather() {

}

float SunnyWeather::GetMoveDamageModifier(Typings type) {
	if (type == FIRE_TYPE) { return 1.5f; }
	if (type == WATER_TYPE) { return 0.5f; }
	return 1.0f;
}

float SunnyWeather::GetSPDEFModifier(Typings Type1, Typings type2) {
	return 1.0f;
}

void SunnyWeather::SetupLimit(bool extended = false) {
	turnLimit = rand() % 3 + 3;
	if (extended) { turnLimit += 2; }

	isLimitted = true;
}

void SunnyWeather::Upkeep(std::vector<Pokemon*> affectedPokemon) {
	if (isLimitted) {
		turnLimit--;
		if (turnLimit == 0) {
			isLimitted = false;
			cleanUpFlag = true;
		}
	}
}