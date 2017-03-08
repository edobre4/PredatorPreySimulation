#pragma once
#include "Creature.h"
// Fox class
// Subclass of Creature
// initializes fields such as food level, metabolic rate, etc.
// sets strategies for each action
class Fox :
	public Creature
{
public:
	// override spawn() - spawn a baby fox at the position momma fox moved from
	void spawn(int, int);
	Fox(int, int, int);
};

