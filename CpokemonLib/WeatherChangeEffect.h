#pragma once

#include "MoveEffect.h"
#include "WeatherLookUp.h"
#include "Move.h"

class WeatherChangeEffect : public MoveEffect {
public:
    WeatherNames weatherType;

    void Invoke(Pokemon* user, std::vector<Pokemon*> targets, MoveSummary& summery) {
        if (weatherType == summery.currentWeather) {
            std::cout << "But it failed!" << std::endl;
            return;
        }
        //tell the weather to be limited
        weatherLookUp.weather[weatherType]->SetupLimit();

        summery.currentWeather = weatherType;
    }
};