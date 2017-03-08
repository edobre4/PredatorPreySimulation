#include "DieStrategy.h"
#include "Creature.h"
#include "CreatureTable.h"


// die() 
// checks if food level is below zero or if creature age is above lifespan
void DieStrategy::die()
{
	if ( (creaturePtr->getAge()) >= lifespan || (creaturePtr->getFood()) < 0) {
		// kill creature
		int x = creaturePtr->getx();
		int y = creaturePtr->gety();
		creaturePtr->clear();
		delete creaturePtr;
		animalTable->setCreature(x, y, NULL);
	}
}

// constructores
DieStrategy::DieStrategy(Creature *c, int days)
{
	creaturePtr = c;
	animalTable = &SimulationGrid::mAnimalTable;
	lifespan = days;
}

