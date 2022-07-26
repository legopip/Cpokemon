#include "Weather.h"

Weather::Weather() {
	isLimitted = false;
	cleanUpFlag = false;
	turnLimit = 0;
	weatherType = CLEAR_WEATHER;
}

Weather::~Weather() {

}

float Weather::GetMoveDamageModifier(Typings type) {
	if (type == WATER_TYPE) { return 1.5f; }
	if (type == FIRE_TYPE) { return 0.5f; }
	return 1.0f;
}

float Weather::GetSPDEFModifier(Typings Type) {
	return 1.0f;
}

void Weather::SetupLimit(bool extended = false) {
	turnLimit = rand() % 3 + 3; 
	if (extended) { turnLimit += 2; }

	isLimitted = true;
}

void Weather::Upkeep(std::vector<Pokemon*> affectedPokemon) {
	if (isLimitted) {
		turnLimit--;
		if (turnLimit == 0) {
			isLimitted = false;
			cleanUpFlag = true;
		}
	}
}