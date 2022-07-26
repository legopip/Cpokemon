#pragma once

#include "WeatherNames.h"

#include "Pokemon.h"

//SuperClass, also serves as Clear Weather
class Weather {
public:
	WeatherNames weatherType;
	
	bool cleanUpFlag;

	Weather();
	~Weather();

	virtual float GetMoveDamageModifier(Typings type);
	virtual float GetSPDEFModifier(Typings Type);
	
	virtual void SetupLimit(bool extended = false);
	virtual void Upkeep(std::vector<Pokemon*> affectedPokemon);
private:
	bool isLimitted;
	int turnLimit;

};