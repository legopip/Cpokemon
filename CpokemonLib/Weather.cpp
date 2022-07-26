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
	return 1.0f;
}

float Weather::GetSPDEFModifier(Typings Type) {
	return 1.0f;
}

void Weather::SetupLimit(bool extended = false) {
	//since this is the default weather is will never be on a timer 
}

void Weather::Upkeep(std::vector<Pokemon*> affectedPokemon) {
	//has no effects
}