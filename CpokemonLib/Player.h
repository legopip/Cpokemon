#pragma once

#include "Trainer.h"
#include "ItemEnums.h"

#include <map>

class Player : public Trainer {
public:
	Player(std::string name, std::string trainerClass);
	~Player();

	int numberOfBadges;


	//bag
	std::map<MiscItems, int> miscItemsPocket;
	std::map<MedicineItems, int> medicineItemsPocket;
	std::map<BallItems, int> ballItemsPocket;
	std::map<BerryItems, int> berryItemsPocket;
	std::map<KeyItems, int> keyItemsPocket;


	//should PCboxs also be stored here?

};