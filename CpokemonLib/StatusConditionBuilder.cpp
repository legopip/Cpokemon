#include "StatusConditionBuilder.h"

NonVolatileStatusCondition* 
StatusConditionBuilder::BuildNonVolatileStatusCondition(
	NonVolatileStatusNames nvStatusToMake, Pokemon* pokemon) {
	switch (nvStatusToMake)
	{
	case BURN_NV_STATUS: {
		BurnStatusCondition* status = new BurnStatusCondition(pokemon);
		return status;
	}
	case FREEZE_NV_STATUS:
		return 0;
	case PARALYSIS_NV_STATUS:
		return 0;
	case POISON_NV_STATUS:
		return 0;
	case BAD_POISON_NV_STATUS:
		return 0;
	case SLEEP_NV_STATUS:
		return 0;
	case FLUX_NV_STATUS:
		return 0;
	default:
		return 0;
	}
}