#include "HerbivoreReproduceStrategy.h"
#include "Creature.h"
#include "CreatureTable.h"

#include <stdlib.h>
#include <time.h>

// reproduce for herbivores
// check the requirements to reproduce
// check if there is a carnivore nearby (herbivore will not reproduce if there is a carnivore
// adjacent to its location
void HerbivoreReproduceStrategy::reproduce()
{
	// check food req
	if (creaturePtr->getFood() < foodReq)
		return;

	// check age req
	if (creaturePtr->getAge() < ageReq)
		return;

	// check if sitting by a carnivore
	int x = creaturePtr->getx();
	int y = creaturePtr->gety();

	Creature *c = animalTable->getCreature(x, y - 1);
	if (c != NULL && c->getCreatureType() == CARNIVORE)
		return;

	c = animalTable->getCreature(x, y + 1);
	if (c != NULL && c->getCreatureType() == CARNIVORE)
		return;
	
	c = animalTable->getCreature(x + 1, y);
	if (c != NULL && c->getCreatureType() == CARNIVORE)
		return;

	c = animalTable->getCreature(x - 1, y);
	if (c != NULL && c->getCreatureType() == CARNIVORE)
		return;


	double random = ((double)rand()) / RAND_MAX;
	// check the chance of reproducing
	if (chance < random)
		return;

	// check if moved
	if (creaturePtr->hasMoved()) {
		int mx = creaturePtr->getMovedX();
		int my = creaturePtr->getMovedY();
		// spawn a new creature of the same type
		creaturePtr->spawn(mx, my);
		return;
	}	
}

// constructor
HerbivoreReproduceStrategy::HerbivoreReproduceStrategy(Creature *c, double ch, int foodrq, int agerq)
{
	creaturePtr = c;
	grassTable = &SimulationGrid::mGrassTable;
	animalTable = &SimulationGrid::mAnimalTable;
	chance = ch;
	foodReq = foodrq;
	ageReq = agerq;
}
