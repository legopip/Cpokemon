#include "MoveBuilder.h"
#include "PhysicalAttackMove.h"
#include "SpecialAttackMove.h"
#include "LifeStealEffect.h"
#include "RecoilEffect.h"
#include "StatChangeEffect.h"
#include "NVStatusEnemyEffect.h"
#include "WeatherChangeEffect.h"
#include "CopyMoveEffect.h"
#include "RecycleMoveEffect.h"

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
	} break;
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
	} break;
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
	} break;
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
	} break;
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
	} break;
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
	} break;
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
	} break;
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
	} break;
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
	} break;
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
	} break;
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
	} break;
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
	} break;
	case COPY_CAT: { //WARNING THIS ISN"T COMPLETE (It doesn't Aim correctly)
		move->name = "Copy Cat";
		move->type = NORMAL_TYPE;
		move->PP = 20;
		move->category = STATUS_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_SELF;

		CopyMoveEffect* copyEffect = new CopyMoveEffect();

		move->AddEffect(copyEffect);
	} break;
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
	} break;
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
	} break;
	case MAGICAL_LEAF: {
		move->name = "Magical Leaf";
		move->type = GRASS_TYPE;
		move->PP = 20;
		move->category = SPECIAL_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		SpecialAttackMove* attack = new SpecialAttackMove();
		attack->power = 60;
		attack->accuracy = -1;

		move->AddEffect(attack);
	} break;
	case FLAME_WHEEL: {
		move->name = "Flame Wheel";
		move->type = FIRE_TYPE;
		move->PP = 25;
		move->category = PHYSICAL_MOVE;
		move->makesContact = true;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		PhysicalAttackMove* attack = new PhysicalAttackMove();
		attack->power = 60;
		attack->accuracy = 100;

		NVStatusEnemyEffect* nvStatusEffect = new NVStatusEnemyEffect();
		nvStatusEffect->nvStatus = BURN_NV_STATUS;
		nvStatusEffect->chance = 10;
		nvStatusEffect->isIndependant = false;

		move->AddEffect(attack);
		move->AddEffect(nvStatusEffect);
	} break;
	case RAIN_DANCE: {
		move->name = "Rain Dance";
		move->type = WATER_TYPE;
		move->PP = 5;
		move->category = STATUS_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_SELF;

		WeatherChangeEffect* weatherEffect = new WeatherChangeEffect();
		weatherEffect->weatherType = RAINY_WEATHER;

		move->AddEffect(weatherEffect);
	} break;
	case GROWTH: {
		move->name = "Growth";
		move->type = NORMAL_TYPE;
		move->PP = 20;
		move->category = STATUS_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_SELF;

		StatChangeEffect* statChange1 = new StatChangeEffect();
		statChange1->affectedStat = ATK_STAT;
		statChange1->chance = 100;
		statChange1->change = +1;
		statChange1->isIndependant = true;

		StatChangeEffect* statChange2 = new StatChangeEffect();
		statChange2->affectedStat = SPATK_STAT;
		statChange2->chance = 100;
		statChange2->change = +1;
		statChange2->isIndependant = true;

		move->AddEffect(statChange1);
		move->AddEffect(statChange2);
	} break;
	case FLASH: {
		move->name = "FLASH";
		move->type = NORMAL_TYPE;
		move->PP = 15;
		move->category = STATUS_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_ALL_OTHERS;

		StatChangeEffect* statChange = new StatChangeEffect();
		statChange->affectedStat = ACC_STAT;
		statChange->chance = 100;
		statChange->change = -1;
		statChange->isIndependant = true;

		move->AddEffect(statChange);
	} break;
	case AQUA_JET: {
		move->name = "Aqua Jet";
		move->type = WATER_TYPE;
		move->PP = 20;
		move->category = PHYSICAL_MOVE;
		move->makesContact = true;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;
		move->priority = 2;

		PhysicalAttackMove* attack = new PhysicalAttackMove();
		attack->power = 40;
		attack->accuracy = 100;

		move->AddEffect(attack);
	} break;
	case BABY_DOLL_EYES: {
		move->name = "Baby-doll Eyes";
		move->type = FAIRY_TYPE;
		move->PP = 30;
		move->category = STATUS_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_ALL_ENEMIES;
		move->priority = 1;

		StatChangeEffect* statChange = new StatChangeEffect();
		statChange->affectedStat = ATK_STAT;
		statChange->chance = 100;
		statChange->change = -1;
		statChange->isIndependant = true;

		move->AddEffect(statChange);
	} break;
	case DRAINING_KISS: {
		move->name = "Draining Kiss";
		move->type = FAIRY_TYPE;
		move->PP = 10;
		move->category = SPECIAL_MOVE;
		move->makesContact = true;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		SpecialAttackMove* attack = new SpecialAttackMove();
		attack->power = 50;
		attack->accuracy = 100;

		LifeStealEffect* lifeSteal = new LifeStealEffect();

		move->AddEffect(attack);
		move->AddEffect(lifeSteal);
	} break;
	case METAL_SOUND: {
		move->name = "Metal Sound";
		move->type = STEEL_TYPE;
		move->PP = 40;
		move->category = STATUS_MOVE;
		move->makesContact = false;
		move->isSoundBased = true;
		move->range = TARGETS_1ENEMY;

		StatChangeEffect* statChange = new StatChangeEffect();
		statChange->affectedStat = SPDEF_STAT;
		statChange->chance = 85;
		statChange->change = -2;
		statChange->isIndependant = true;

		move->AddEffect(statChange);
	} break;
	case METAL_CLAW: {
		move->name = "Metal Claw";
		move->type = STEEL_TYPE;
		move->PP = 35;
		move->category = PHYSICAL_MOVE;
		move->makesContact = true;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		PhysicalAttackMove* attack = new PhysicalAttackMove();
		attack->power = 50;
		attack->accuracy = 95;

		StatChangeEffect* statChange = new StatChangeEffect();
		statChange->affectedStat = ATK_STAT;
		statChange->chance = 10;
		statChange->change = +1;
		statChange->isIndependant = false;
		statChange->affectsUser = true;

		move->AddEffect(attack);
		move->AddEffect(statChange);
	}break;
	case FEINT_ATTACK: {
		move->name = "Feint Attack";
		move->type = DARK_TYPE;
		move->PP = 20;
		move->category = PHYSICAL_MOVE;
		move->makesContact = true;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		PhysicalAttackMove* attack = new PhysicalAttackMove();
		attack->power = 60;
		attack->accuracy = -1;

		move->AddEffect(attack);
	} break;
	case PURSUIT: { //!POWER INCREASE EFFECT NOT IMPLEMENTED!
		move->name = "Pursuit";
		move->type = DARK_TYPE;
		move->PP = 20;
		move->category = PHYSICAL_MOVE;
		move->makesContact = true;
		move->isSoundBased = false;
		move->range = TARGETS_1ENEMY;

		PhysicalAttackMove* attack = new PhysicalAttackMove();
		attack->power = 40;
		attack->accuracy = -1;

		move->AddEffect(attack);
	} break;
	case MEGA_DRAIN: {
		move->name = "Mega Drain";
		move->type = GRASS_TYPE;
		move->PP = 15;
		move->category = SPECIAL_MOVE;
		move->makesContact = false;
		move->isSoundBased = false;
		move->range = TARGETS_ALL_ENEMIES;

		SpecialAttackMove* attack = new SpecialAttackMove();
		attack->power = 50;
		attack->accuracy = 95;

		LifeStealEffect* lifeSteal = new LifeStealEffect();

		move->AddEffect(attack);
		move->AddEffect(lifeSteal);
	} break;
	case FIRE_FANG: {

	} break;
	case TAKE_DOWN: {

	} break;
	default:
		break;
	}
	//We had to make this move so add it to the map
	moveMap[moveToMake] = move;
	return moveMap[moveToMake];
}