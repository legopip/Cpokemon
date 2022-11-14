#include "WeatherChangeEffect.h"

#include "WeatherLookUp.h"

void WeatherChangeEffect::Resolve(Pokemon* user, std::vector<Pokemon*> targets, BattleState& battleState, MoveSummery& summery) {
    if (weatherType == battleState.currentWeather) {
        std::cout << "But it failed!" << std::endl;
        return;
    }
    //tell the weather to be limited
    weatherLookUp.weather[weatherType]->SetupLimit();

    battleState.currentWeather = weatherType;
}