#pragma once

#include "Trainer.h"

class Player : public Trainer {
public:
	Player(std::string name, std::string trainerClass);
	~Player();

	int numberOfBadges;


	//bag

	//should PCboxs also be stored here?

};