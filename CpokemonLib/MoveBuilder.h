#pragma once

#include "MoveNames.h"
#include "Move.h"
#include <map>

class MoveBuilder
{
public:
	MoveBuilder();
	~MoveBuilder();

	Move* BuildMove(MoveNames moveToMake);

private:
	std::map<MoveNames, Move*> moveMap;
};

static MoveBuilder moveBuilder;

