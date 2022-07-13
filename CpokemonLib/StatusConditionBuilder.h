#pragma once

#include "StatusConditionNames.h"
#include "BurnStatusCondition.h"

class StatusConditionBuilder
{
public:
	NonVolatileStatusCondition* BuildNonVolatileStatusCondition(
		NonVolatileStatusNames nvStatusToMake, Pokemon* pokemon);

private:

};

static StatusConditionBuilder statusConditionBuilder;
