#include "CarnivoreEatStrategy.h"
#include "Creature.h"

// eat() function for carnivores
// if there is a herbivore adjacent to this creature
// eat the herbivore and move to its position
void CarnivoreEatStrategy::eat()
{
	// carnivore will only eat if their food level is below the threshold
	if (creaturePtr->getFood() > foodThreshold)
		return;
	int x = creaturePtr->getx();
	int y = creaturePtr->gety();
	// check each adjacent square for a herbivore

	// check upper square
	Creature *c = animalTable->getCreature(x, y - 1);
	if (c != NULL && c->getCreatureType() == HERBIVORE) {

		c->clear(); // frees up memory allocated by c
		delete c;

		// move creature to position of the deceased herbivore
		animalTable->setCreature(x, y - 1, creaturePtr);
		animalTable->setCreature(x, y, NULL);
		creaturePtr->sety(y - 1);

		creaturePtr->hasMoved(true);
		creaturePtr->setMoved(x, y);
		creaturePtr->setFood(creaturePtr->getFood() + 10);
		return;
	}

	// check lower square
	c = animalTable->getCreature(x, y + 1);
	if (c != NULL && c->getCreatureType() == HERBIVORE) {

		c->clear();
		delete c;
		animalTable->setCreature(x, y + 1, creaturePtr);
		animalTable->setCreature(x, y, NULL);
		creaturePtr->sety(y + 1);

		creaturePtr->hasMoved(true);
		creaturePtr->setMoved(x, y);
		creaturePtr->setFood(creaturePtr->getFood() + 10);

		return;
	}

	// check left square
	c = animalTable->getCreature(x - 1, y);
	if (c != NULL && c->getCreatureType() == HERBIVORE) {

		c->clear();
		delete c;
		animalTable->setCreature(x - 1, y, creaturePtr);
		animalTable->setCreature(x, y, NULL);
		creaturePtr->setx(x - 1);

		creaturePtr->hasMoved(true);
		creaturePtr->setMoved(x, y);
		creaturePtr->setFood(creaturePtr->getFood() + 10);

		return;
	}

	// check right square
	c = animalTable->getCreature(x + 1, y);
	if (c != NULL && c->getCreatureType() == HERBIVORE) {

		c->clear();
		delete c;
		animalTable->setCreature(x + 1, y, creaturePtr);
		animalTable->setCreature(x, y, NULL);
		creaturePtr->setx(x + 1);

		creaturePtr->hasMoved(true);
		creaturePtr->setMoved(x, y);
		creaturePtr->setFood(creaturePtr->getFood() + 10);

		return;
	}
}

// consturctor
CarnivoreEatStrategy::CarnivoreEatStrategy(Creature *c, int t)
{
	creaturePtr = c;
	foodThreshold = t;
	animalTable = &SimulationGrid::mAnimalTable;
}
