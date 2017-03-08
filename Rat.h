#pragma once
#include "Creature.h"
// class Rat
// subclass of Creature
class Rat :
	public Creature
{
public:
	void spawn(int, int);
	Rat(int, int, int);
};

