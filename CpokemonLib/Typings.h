#pragma once

#include <string>

enum Typings {
	NORMAL_TYPE = 0,
	GRASS_TYPE = 1,
	FIRE_TYPE = 2,
	WATER_TYPE = 3,
	ELECTRIC_TYPE = 4,
	GROUND_TYPE = 5,
	BUG_TYPE = 6,
	FLYING_TYPE = 7,
	ROCK_TYPE = 8,
	POISON_TYPE = 9,
	FIGHTING_TYPE = 10,
	PSYCHIC_TYPE = 11,
	GHOST_TYPE = 12,
	ICE_TYPE = 13,
	DRAGON_TYPE = 14,
	DARK_TYPE = 15,
	STEEL_TYPE = 16,
	FAIRY_TYPE = 17,
	NONE_TYPE = 18
};

static const std::string TypeToString(Typings type) {
	switch (type)
	{
	case NORMAL_TYPE:
		return "Normal";
	case GRASS_TYPE:
		return "Grass";
	case FIRE_TYPE:
		return "Fire";
	case WATER_TYPE:
		return "Water";
	case ELECTRIC_TYPE:
		return "Electric";
	case GROUND_TYPE:
		return "Ground";
	case BUG_TYPE:
		return "Bug";
	case FLYING_TYPE:
		return "Flying";
	case ROCK_TYPE:
		return "Rock";
	case POISON_TYPE:
		return "Poison";
	case FIGHTING_TYPE:
		return "Fighting";
	case PSYCHIC_TYPE:
		return "Psychic";
	case GHOST_TYPE:
		return "Ghost";
	case ICE_TYPE:
		return "Ice";
	case DRAGON_TYPE:
		return "Dragon";
	case DARK_TYPE:
		return "Dark";
	case STEEL_TYPE:
		return "Steel";
	case FAIRY_TYPE:
		return "Fairy";
	default:
		return " - ";
	}
}