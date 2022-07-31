#include "Pokemon.h"

#include "Move.h"
#include "Ability.h"

Pokemon::Pokemon() {
	ATKmod = 0;
	DEFmod = 0;
	SPATKmod = 0;
	SPDEFmod = 0;
	SPDmod = 0;
	EVAmod = 0;
	ACCmod = 0;
	cleanUpNVStatus = false;
}

Pokemon::~Pokemon() {
}

int Pokemon::GetHP() {
	return ((2 * species.baseHP + IVHP + (EVHP/4))*level/100) + level + 10;
}

int Pokemon::GetATK() {
	float statusMod = 1.0f;
	if (nvStatus) { statusMod = nvStatus->ATKmod; }
	return ((2 * species.baseATK + IVATK + (EVATK / 4)) * level/100 + 5) 
		* nature.ATKmod * statusMod * StatModToStatChange(ATKmod);
}

int Pokemon::GetDEF() {
	float statusMod = 1.0f;
	if (nvStatus) { statusMod = nvStatus->DEFmod; }
	return ((2 * species.baseDEF + IVDEF + (EVDEF / 4)) * level / 100 + 5) 
		* nature.DEFmod * statusMod * StatModToStatChange(DEFmod);
}

int Pokemon::GetSPATK() {
	float statusMod = 1.0f;
	if (nvStatus) { statusMod = nvStatus->SPATKmod; }
	return ((2 * species.baseSPATK + IVSPATK + (EVSPATK / 4)) * level / 100 + 5) 
		* nature.SPATKmod * statusMod * StatModToStatChange(SPATKmod);
}

int Pokemon::GetSPDEF() {
	float statusMod = 1.0f;
	if (nvStatus) { statusMod = nvStatus->SPDEFmod; }
	return ((2 * species.baseSPDEF + IVSPDEF + (EVSPDEF / 4)) * level / 100 + 5) 
		* nature.SPDEFmod * statusMod * StatModToStatChange(SPDEFmod);
}

int Pokemon::GetSPD() {
	float statusMod = 1.0f;
	if (nvStatus) { statusMod = nvStatus->SPDmod; }
	return ((2 * species.baseSPD + IVSPD + (EVSPD / 4)) * level/ 100 + 5) 
		* nature.SPDmod * statusMod * StatModToStatChange(SPDmod);
}

//Formula adapted from: https://bulbapedia.bulbagarden.net/wiki/Experience
int Pokemon::GetEXPyeild() {
	int trainerBonus = 1.0f;
	if (isTrainerPokemon) { trainerBonus = 1.5f; }
	return (species.expYeild * level * trainerBonus) / 7; //add in stuff like trainer exp and lucky egg later
}

void Pokemon::CheckForLevelUp() {
	if (level < 100) {
		while (exp >= expToLevel) {
			std::cout << nickname << " leveled up!" << std::endl;
			int oldHp = GetHP();
			level++;
			for (int i = 0; i < species.evolutions.size(); i++) {
				if (species.evolutions[i]->TryToEvole(this)) {
					break;
				}
			}
			int newHp = GetHP();
			currentHP += newHp - oldHp;
			if (level < 100) {
				expToLevel = lookUpExp(species.expCurve, level);
			}
		}
	}
}

std::string Pokemon::ToString() {
	std::string string = "";
	string += nickname + " the " + species.name;
	switch (gender)
	{
	case UNKNOWN_PKMN_GENDER:
		break;
	case MALE_PKMN_GENDER:
		string += " (m)";
		break;
	case FEMALE_PKMN_GENDER:
		string += " (f)";
		break;
	default:
		break;
	}
	string += "\nability: " + ability->name;
	string += "\nlevel: " + std::to_string(level);
	string += "\nnature: " + nature.name;
	string += "\nHP: " + std::to_string(GetHP());
	string += " ATK: " + std::to_string(GetATK());
	string += " DEF: " + std::to_string(GetDEF());
	string += "\nSPATK: " + std::to_string(GetSPATK());
	string += " SPDEF: " + std::to_string(GetSPDEF());
	string += " SPD: " + std::to_string(GetSPD());
	string += "\n" + species.description;
	string += "\nMoves: ";
	for (int i = 0; i < 4; i++) {
		if (knownMoves[i].move) {
			string += knownMoves[i].move->name + ", ";
		}
	}
	return string;
}

std::string Pokemon::GetTextHPbar() {
	std::string string = "HP:=";
	int hpOutOfTen = ((float)currentHP / GetHP()) * 10.0f;
	for (int i = 0; i < hpOutOfTen; i++) {
		string += "=";
	}
	return string;
}


//PRIVATE
float Pokemon::StatModToStatChange(int mod) {
	//this has been changed from GameFreaks formula so that stat changes have 
	//diminishing returns
	switch (mod)
	{
	case 1:
		return 3.0f / 2.0f;
	case 2:
		return 7.0f / 4.0f;
	case 3:
		return 4.0f / 2.0f;
	case 4:
		return 9.0f / 4.0f;
	case 5:
		return 19.0f / 8.0f;
	case 6: 
		return 5.0f / 2.0f;
	case -1:
		return 2.0f / 3.0f;
	case -2:
		return 4.0f / 7.0f;
	case -3:
		return 2.0f / 4.0f;
	case -4:
		return 4.0f / 9.0f;
	case -5:
		return 8.0f / 19.0f;
	case -6:
		return 2.0f / 5.0f;
	default:
		return 1;
	}
}