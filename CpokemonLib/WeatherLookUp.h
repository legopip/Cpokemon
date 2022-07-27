#pragma once

#include "RainyWeather.h"
#include "SandyWeather.h"
#include "SnowyWeather.h"
#include "SunnyWeather.h"

#include <map>

class WeatherLookUp {
public:
	std::map<WeatherNames, Weather*> weather;

	WeatherLookUp() {
		weather[CLEAR_WEATHER] = new Weather();
		weather[RAINY_WEATHER] = new RainyWeather();
		weather[SANDY_WEATHER] = new SandyWeather();
		weather[SNOWY_WEATHER] = new SnowyWeather();
		weather[SUNNY_WEATHER] = new SunnyWeather();
	}

	~WeatherLookUp() {
		for (std::map<WeatherNames, Weather*>::iterator i = weather.begin(); i != weather.end(); i++) {
			delete i->second;
			i->second = 0;
		}
		weather.clear();
	}
};

static WeatherLookUp weatherLookUp;