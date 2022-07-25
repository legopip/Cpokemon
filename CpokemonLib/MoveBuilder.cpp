#include "MoveBuilder.h"
#include "DamagingMoveEffects.h"
#include "StatusMoveEffects.h"
#include "OddMoveEffects.h"

MoveBuilder::MoveBuilder()
{
}

MoveBuilder::~MoveBuilder()
{
	for (std::map<MoveNames, Move*>::iterator i = moveMap.begin(); i != moveMap.end(); i++) {
		delete i->second;
		i->second = 0;
	}
	moveMap.clear();
}

Move* MoveBuilder::BuildMove(MoveNames moveToMake) {
	//check if the move already exists
	if (moveMap.count(moveToMake) > 0) {
		return moveMap[moveToMake];
	}
	//if not make the move
	Move* move = new Move();
	switch (moveToMake)
	{
	case POUND: {
		move->name = "Pound";
		move->type = NORMAL_TYPE;
		move->PP = 35;
		move->category = PHYSICAL_MOVE;
		move->makesContact = true;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		PhysicalAttackMove* attack = new PhysicalAttackMove();
		attack->power = 40;
		attack->accuracy = 95;

		move->AddEffect(attack);
	}
		break;
	case SCRATCH: {
		move->name = "Scratch";
		move->type = NORMAL_TYPE;
		move->PP = 35;
		move->category = PHYSICAL_MOVE;
		move->makesContact = true;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		PhysicalAttackMove* attack = new PhysicalAttackMove();
		attack->power = 40;
		attack->accuracy = 95;

		move->AddEffect(attack);
	}
		break;
	case TACKLE: {
		move->name = "Tackle";
		move->type = NORMAL_TYPE;
		move->PP = 35;
		move->category = PHYSICAL_MOVE;
		move->makesContact = true;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		PhysicalAttackMove* attack = new PhysicalAttackMove();
		attack->power = 40;
		attack->accuracy = 95;

		move->AddEffect(attack);
	}
		break;
	case GROWL: {
		move->name = "Growl";
		move->type = NORMAL_TYPE;
		move->PP = 40;
		move->category = STATUS_MOVE;
		move->makesContact = false;
		move->isSoundBased = true;
		move->range = TARGETS_ALL_ENEMIES;

		StatChangeEffect* statChange = new StatChangeEffect();
		statChange->affectedStat = ATK_STAT;
		statChange->chance = 100;
		statChange->change = -1;
		statChange->isIndependant = true;

		move->AddEffect(statChange);
	}
		break;
	case LEER: {
		move->name = "Leer";
		move->type = NORMAL_TYPE;
		move->PP = 40;
		move->category = STATUS_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_ALL_ENEMIES;

		StatChangeEffect* statChange = new StatChangeEffect();
		statChange->affectedStat = DEF_STAT;
		statChange->chance = 100;
		statChange->change = -1;
		statChange->isIndependant = true;

		move->AddEffect(statChange);
	}
		break;
	case TAIL_WHIP: {
		move->name = "Tail Whip";
		move->type = NORMAL_TYPE;
		move->PP = 40;
		move->category = STATUS_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_ALL_ENEMIES;

		StatChangeEffect* statChange = new StatChangeEffect();
		statChange->affectedStat = DEF_STAT;
		statChange->chance = 100;
		statChange->change = -1;
		statChange->isIndependant = true;

		move->AddEffect(statChange);
	}
		break;
	case ABSORB: {
		move->name = "Absorb";
		move->type = GRASS_TYPE;
		move->PP = 25;
		move->category = SPECIAL_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		SpecialAttackMove* attack = new SpecialAttackMove();
		attack->power = 25;
		attack->accuracy = 95;

		LifeStealEffect* lifeSteal = new LifeStealEffect();

		move->AddEffect(attack);
		move->AddEffect(lifeSteal);
	}
		break;
	case EMBER: {
		move->name = "Ember";
		move->type = FIRE_TYPE;
		move->PP = 25;
		move->category = SPECIAL_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		SpecialAttackMove* attack = new SpecialAttackMove();
		attack->power = 40;
		attack->accuracy = 95;

		NVStatusEnemyEffect* nvStatusEffect = new NVStatusEnemyEffect();
		nvStatusEffect->nvStatus = BURN_NV_STATUS;
		nvStatusEffect->chance = 10;
		nvStatusEffect->isIndependant = false;

		move->AddEffect(attack);
		move->AddEffect(nvStatusEffect);
	}
		break;
	case WATER_GUN: {
		move->name = "Water Gun";
		move->type = WATER_TYPE;
		move->PP = 25;
		move->category = SPECIAL_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		SpecialAttackMove* attack = new SpecialAttackMove();
		attack->power = 40;
		attack->accuracy = 95;

		move->AddEffect(attack);
	}
		break;
	case GRASS_WHISTLE: {
		move->name = "Grass Whistle";
		move->type = GRASS_TYPE;
		move->PP = 15;
		move->category = STATUS_MOVE;
		move->makesContact = false;
		move->isSoundBased = true;
		move->range = TARGETS_1ENEMY;

		NVStatusEnemyEffect* nvStatusEffect = new NVStatusEnemyEffect();
		nvStatusEffect->nvStatus = SLEEP_NV_STATUS;
		nvStatusEffect->chance = 75;
		nvStatusEffect->isIndependant = true;

		move->AddEffect(nvStatusEffect);
	}
		break;
	case HARDEN: {
		move->name = "Harden";
		move->type = NORMAL_TYPE;
		move->PP = 30;
		move->category = STATUS_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_SELF;

		StatChangeEffect* statChange = new StatChangeEffect();
		statChange->affectedStat = DEF_STAT;
		statChange->chance = 100;
		statChange->change = +1;
		statChange->isIndependant = true;

		move->AddEffect(statChange);
	}
		break;
	case MUD_SHOT: {
		move->name = "Mud Shot";
		move->type = GROUND_TYPE;
		move->PP = 15;
		move->category = SPECIAL_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		SpecialAttackMove* attack = new SpecialAttackMove();
		attack->power = 55;
		attack->accuracy = 95;

		StatChangeEffect* statChange = new StatChangeEffect();
		statChange->affectedStat = SPD_STAT;
		statChange->chance = 100;
		statChange->change = -1;
		statChange->isIndependant = false;

		move->AddEffect(attack);
		move->AddEffect(statChange);
	}
		break;
	case COPY_CAT: { //WARNING THIS ISN"T COMPLETE (It doesn't Aim correctly)
		move->name = "Copy Cat";
		move->type = NORMAL_TYPE;
		move->PP = 20;
		move->category = STATUS_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		CopyMoveEffect* copyEffect = new CopyMoveEffect();

		move->AddEffect(copyEffect);
	}
		break;
	case RECYCLE: {
		move->name = "Recycle";
		move->type = NORMAL_TYPE;
		move->PP = 10;
		move->category = STATUS_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_SELF;

		RecycleMoveEffect* recycleEffect = new RecycleMoveEffect();

		move->AddEffect(recycleEffect);
	}
		break;
	case BUBBLEBEAM: {
		move->name = "Bubblebeam";
		move->type = WATER_TYPE;
		move->PP = 20;
		move->category = SPECIAL_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		SpecialAttackMove* attack = new SpecialAttackMove();
		attack->power = 65;
		attack->accuracy = 100;

		StatChangeEffect* statChange = new StatChangeEffect();
		statChange->affectedStat = SPD_STAT;
		statChange->chance = 10;
		statChange->change = -1;
		statChange->isIndependant = false;

		move->AddEffect(attack);
		move->AddEffect(statChange);
	}
		break;
	default:
		break;
	}
	//We had to make this move so add it to the map
	moveMap[moveToMake] = move;
	return moveMap[moveToMake];
}