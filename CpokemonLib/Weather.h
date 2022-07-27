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
	virtual float GetSPDEFModifier(Typings Type1, Typings type2);
	
	virtual void SetupLimit(bool extended = false);
	void CleanUpLimit();
	virtual void Upkeep(std::vector<Pokemon*> affectedPokemon);
protected:
	bool isLimitted;
	int turnLimit;

};