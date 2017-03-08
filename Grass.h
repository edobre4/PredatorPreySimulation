#pragma once
#include "Creature.h"
// Grass class
// subclass of creature
class Grass :
	public Creature
{
	// grass has 4 textures
	int texture1;  // used when food < 25
	int texture2;  // used when food > 25 and food < 50
	int texture3;  // used when food > 50 and food < 75
	int texture4;  // used when food > 75
public:
	void setFood(int);    // override superclass function - when changing food level, update texture
	void updateTexture(); // set the texture id according to the food level
	Grass(int, int, int, int);  // constructor
	void spawn(int, int);       // grass does not reproduce so spawn() does nothing. Required to implement since it is abstract
};

