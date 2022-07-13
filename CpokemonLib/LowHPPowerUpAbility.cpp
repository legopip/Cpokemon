#include "LowHPPowerUpAbility.h"

float LowHPPowerUpAbility::GetAttackMod(Pokemon* user, Typings* moveType) {
	if (*moveType != requiredType) { return 1.0f; }

	if (user->currentHP <= user->GetHP() / 3) { return 1.5f; }

	return 1.0f;
}