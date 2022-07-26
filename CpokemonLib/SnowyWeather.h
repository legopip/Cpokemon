#pragma once

#include "Weather.h"

class SnowyWeather : public Weather {
public:
	SnowyWeather();
	~SnowyWeather();

	float GetMoveDamageModifier(Typings type);
	float GetSPDEFModifier(Typings Type);

	void SetupLimit(bool extended = false);
	void Upkeep(std::vector<Pokemon*> affectedPokemon);
private:

};