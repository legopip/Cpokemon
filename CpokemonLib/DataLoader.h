#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>

#include "PokemonSpecies.h"


static std::vector<PokemonSpecies> pokemonSpecies;

class DataLoader {
public:
	DataLoader() {
		LoadPokemonSpecies();
	}
private:
	void LoadPokemonSpecies() {
		//std::cout << std::filesystem::current_path() << std::endl;
		std::ifstream file("Pokemon.pkif");
		if (!file) {
			std::cout << "Oh no, there's no pokemon" << std::endl;
			return;
		}

		std::string in = "";
		while (std::getline(file, in)) {
			std::vector<std::string> tokens = Split(in, ':');
			if (tokens.size() > 0) {
				if (tokens[0] == "NATNUM") { //the start of a pokemon entry
					PokemonSpecies pokemon;
					pokemon.nationalDexNumber = std::stoi(tokens[1]);

					//Name and Gender
					std::getline(file, in);
					tokens = Split(in, ':');
					pokemon.name = tokens[1];
					pokemon.genus = tokens[2];
					pokemon.genderRatio = std::stoi(tokens[3]);

					//Type
					std::getline(file, in);
					tokens = Split(in, ':');
					pokemon.type1 = (Typings)std::stoi(tokens[1]);
					pokemon.type2 = (Typings)std::stoi(tokens[2]);

					//Egg Groups
					std::getline(file, in);
					tokens = Split(in, ':');
					pokemon.egg1 = (EggGroups)std::stoi(tokens[1]);
					pokemon.egg2 = (EggGroups)std::stoi(tokens[2]);

					//Abilities
					std::getline(file, in);
					tokens = Split(in, ':');
					pokemon.ability1 = (AbilityNames)std::stoi(tokens[1]);
					pokemon.ability2 = (AbilityNames)std::stoi(tokens[2]);
					pokemon.hiddenAbility = (AbilityNames)std::stoi(tokens[3]);

					//base stat totals
					std::getline(file, in);
					tokens = Split(in, ':');
					pokemon.baseHP = std::stoi(tokens[1]);
					pokemon.baseATK = std::stoi(tokens[2]);
					pokemon.baseDEF = std::stoi(tokens[3]);
					pokemon.baseSPATK = std::stoi(tokens[4]);
					pokemon.baseSPDEF = std::stoi(tokens[5]);
					pokemon.baseSPD = std::stoi(tokens[6]);
					pokemon.BSTtotal = std::stoi(tokens[7]);

					//Exp stuff
					std::getline(file, in);
					tokens = Split(in, ':');
					pokemon.expCurve = ExpCurve(std::stoi(tokens[1]));
					pokemon.expYeild = std::stoi(tokens[2]);
					pokemon.evYeild = (Stats)std::stoi(tokens[3]);
					pokemon.evYeildAmount = std::stoi(tokens[4]);

					//catch stuff
					std::getline(file, in);
					tokens = Split(in, ':');
					pokemon.captureRate = std::stoi(tokens[1]);
					pokemon.baseFriendship = std::stoi(tokens[2]);

					//Held Items
					std::getline(file, in);
					tokens = Split(in, ':');
					for (int i = 1; i < tokens.size(); i++) {
						std::vector<std::string> heldItemData = Split(tokens[i], ',');
						HeldItemData heldItem;
						heldItem.itemType = (ItemTypes)std::stoi(heldItemData[0]);
						heldItem.itemCode = std::stoi(heldItemData[1]);
						heldItem.chance = std::stoi(heldItemData[2]);
						pokemon.possibleHeldItems.push_back(heldItem);
					}

					//Pokedex entry info
					std::getline(file, in);
					tokens = Split(in, ':');
					pokemon.height = std::stof(tokens[1]);
					pokemon.weight = std::stof(tokens[2]);
					pokemon.shape = (Shape)std::stoi(tokens[3]);
					pokemon.habitat = (Habitat)std::stoi(tokens[4]);
					pokemon.colour = (Colour)std::stoi(tokens[5]);

					//Moveset
					std::getline(file, in);
					tokens = Split(in, ':');
					for (int i = 1; i < tokens.size(); i++) {
						std::vector<std::string> moveData = Split(tokens[i], ',');
						LevelMovePair levelMovePair;
						levelMovePair.level = std::stoi(moveData[0]);
						levelMovePair.moveName = (MoveNames)std::stoi(moveData[1]);
						pokemon.moveset.push_back(levelMovePair);
					}

					//pokedex description
					std::getline(file, in);
					tokens = Split(in, ':');
					pokemon.description = tokens[1];

					pokemonSpecies.push_back(pokemon);
				}
			}
		}

		file.close();
	}

	std::vector<std::string> Split(const std::string& s, char delim) {
		std::vector<std::string> result;
		std::stringstream ss(s);
		std::string item;

		while (getline(ss, item, delim)) {
			result.push_back(item);
		}

		return result;
	}
};

