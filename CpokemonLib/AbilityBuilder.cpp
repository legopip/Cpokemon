#include "AbilityBuilder.h"

#include "LowHPPowerUpAbility.h"

AbilityBuilder::AbilityBuilder() {

}

AbilityBuilder::~AbilityBuilder() {
	for (std::map<AbilityNames, Ability*>::iterator i = abilityMap.begin(); i != abilityMap.end(); i++) {
		delete i->second;
		i->second = 0;
	}
	abilityMap.clear();
}

Ability* AbilityBuilder::BuildAbility(AbilityNames abilityToMake) {
	//check if the move already exists
	if (abilityMap.count(abilityToMake) > 0) {
		return abilityMap[abilityToMake];
	}
	switch (abilityToMake)
	{
	case OVERGROW: {
		LowHPPowerUpAbility* ability = new LowHPPowerUpAbility();
		ability->requiredType = GRASS_TYPE;
		ability->name = "Overgrow";
		ability->description = "Powers up grass-type moves in a pinch.";

		abilityMap[abilityToMake] = ability;
		return abilityMap[abilityToMake];
	}
	case BLAZE: {
		LowHPPowerUpAbility* ability = new LowHPPowerUpAbility();
		ability->requiredType = FIRE_TYPE;
		ability->name = "Blaze";
		ability->description = "Powers up fire-type moves in a pinch.";

		abilityMap[abilityToMake] = ability;
		return abilityMap[abilityToMake];
	}
	case TORRENT: {
		LowHPPowerUpAbility* ability = new LowHPPowerUpAbility();
		ability->requiredType = WATER_TYPE;
		ability->name = "Torrent";
		ability->description = "Powers up water-type moves in a pinch.";

		abilityMap[abilityToMake] = ability;
		return abilityMap[abilityToMake];
	}
	default:
		return 0;
		break;
	}
}