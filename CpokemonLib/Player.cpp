#include "Player.h"

Player::Player(std::string name, std::string trainerClass) : Trainer(name, trainerClass) {
	numberOfBadges = 0;
}

Player::~Player() {

}