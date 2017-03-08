#pragma once
#include "Creature.h"
// Wolf class
// subclass of Creature
class Wolf :
	public Creature
{
public:
	// spawn a baby wolf
	void spawn(int, int);

	// initialize the properties of the wolf
	Wolf(int, int, int);
};

