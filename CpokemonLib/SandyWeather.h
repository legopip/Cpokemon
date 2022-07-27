#pragma once

#include "Weather.h"

class SandyWeather : public Weather {
public:
	SandyWeather();
	~SandyWeather();

	float GetMoveDamageModifier(Typings type);
	float GetSPDEFModifier(Typings Type1, Typings type2);

	void SetupLimit(bool extended = false);
	void Upkeep(std::vector<Pokemon*> affectedPokemon);
private:

};