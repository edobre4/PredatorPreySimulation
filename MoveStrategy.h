#pragma once
#include "SimulationGrid.h"
class Creature;
class CreatureTable;
// Move Strategy abstract class
// subclassed by concrete move strategies for carnivores and herbivores
class MoveStrategy
{
protected:
	Creature *CreaturePtr;
	CreatureTable *GrassTablePtr;
	CreatureTable *AnimalTablePtr;
public:
	MoveStrategy();
	virtual void move() = 0; // implementation deferred to subclasses
};

