#pragma once
#include "Creature.h"
// Rabbit class
// subclass of creature

class Rabbit : public Creature
{
public:
	Rabbit(int, int ,int); // initializes the properties of the rabbit creature
	void spawn(int, int);  // spawn a baby rabbit at the position mom rabbit moved from
};

