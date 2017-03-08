#include "CarnivoreReproduceStrategy.h"
#include "Creature.h"

// reproduce() for carnivore
// make sure the carnivore meets all the requirements, if it does spawn a carnivore at
// the position that the parent carnivore has moved from
void CarnivoreReproduceStrategy::reproduce()
{
	// check food req
	if (creaturePtr->getFood() < foodReq)
		return;

	// check age req
	if (creaturePtr->getAge() < ageReq)
		return;

	// check chance
	double random = ( (double) rand() ) / RAND_MAX;
	if (chance < random)
		return;

	if (creaturePtr->hasMoved()) {
		int mx = creaturePtr->getMovedX();
		int my = creaturePtr->getMovedY();
		creaturePtr->spawn(mx, my);
	}
}

// constructor
CarnivoreReproduceStrategy::CarnivoreReproduceStrategy(Creature *c, double ch, int foodrq, int agerq)
{
	creaturePtr = c;
	animalTable = &SimulationGrid::mAnimalTable;
	chance = ch;
	foodReq = foodrq;
	ageReq = agerq;
}

