#pragma once
#include "Creature.h"
// Snake class
// subclass of Creature
class Snake : public Creature
{
public:
	void spawn(int, int); // spawn a baby snake 
	Snake(int, int, int); // initialize the properties of a snake
};

