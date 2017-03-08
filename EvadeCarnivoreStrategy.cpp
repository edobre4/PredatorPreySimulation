#include "EvadeCarnivoreStrategy.h"
#include "Creature.h"
#include "CreatureTable.h"

// strategy to evade carnivores
// check if there is a carnivore adjacent to the herbivore's location
// if there is one, move up to 2 spaces away from it
// if the herbivore did not evade, it will eat and reproduce
void EvadeCarnivoreStrategy::useSurvivalStrategy()
{
	// can only evade if food is above required food level
	if (creaturePtr->getFood() >= foodLevel) {
		// check if there is a carnivore on the upper square
		Creature * c = animalTable->getCreature(creaturePtr->getx(), creaturePtr->gety() - 1);
		if (c != NULL && c->getCreatureType() == CARNIVORE) {
			// try to move 2 squares down
			if (creaturePtr->gety() + 2 < 30 && animalTable->getCreature(creaturePtr->getx(), creaturePtr->gety() + 2) == NULL) {
				// can move 2 squares
				animalTable->setCreature(creaturePtr->getx(), creaturePtr->gety() + 2, creaturePtr);
				animalTable->setCreature(creaturePtr->getx(), creaturePtr->gety(), NULL);
				creaturePtr->sety(creaturePtr->gety() + 2);
			}
			else if (creaturePtr->gety() + 1 < 30 && animalTable->getCreature(creaturePtr->getx(), creaturePtr->gety() + 1) == NULL) {
				// can move 1 square
				animalTable->setCreature(creaturePtr->getx(), creaturePtr->gety() + 1, creaturePtr);
				animalTable->setCreature(creaturePtr->getx(), creaturePtr->gety(), NULL);
				creaturePtr->sety(creaturePtr->gety() + 1);
			}
			return;
		}

		// check if there is a carnivore on the lower square
		c = animalTable->getCreature(creaturePtr->getx(), creaturePtr->gety() + 1);
		if (c != NULL && c->getCreatureType() == CARNIVORE) {
			// try to move 2 squares up
			if (creaturePtr->gety() - 2 >= 0 && animalTable->getCreature(creaturePtr->getx(), creaturePtr->gety() - 2) == NULL) {
				// can move 2 squares
				animalTable->setCreature(creaturePtr->getx(), creaturePtr->gety() - 2, creaturePtr);
				animalTable->setCreature(creaturePtr->getx(), creaturePtr->gety(), NULL);
				creaturePtr->sety(creaturePtr->gety() - 2);
			}
			else if (creaturePtr->gety() - 1 >= 0 && animalTable->getCreature(creaturePtr->getx(), creaturePtr->gety() - 1) == NULL) {
				// can move 1 square
				animalTable->setCreature(creaturePtr->getx(), creaturePtr->gety() - 1, creaturePtr);
				animalTable->setCreature(creaturePtr->getx(), creaturePtr->gety(), NULL);
				creaturePtr->sety(creaturePtr->gety() - 1);
			}
			return;
		}

		// check if there is a carnivore on the left square
		c = animalTable->getCreature(creaturePtr->getx() - 1, creaturePtr->gety());
		if (c != NULL && c->getCreatureType() == CARNIVORE) {
			// try to move 2 squares right
			if (creaturePtr->getx() + 2 < 40 && animalTable->getCreature(creaturePtr->getx() + 2, creaturePtr->gety()) == NULL) {
				// can move 2 squares
				animalTable->setCreature(creaturePtr->getx() + 2, creaturePtr->gety(), creaturePtr);
				animalTable->setCreature(creaturePtr->getx(), creaturePtr->gety(), NULL);
				creaturePtr->setx(creaturePtr->getx() + 2);
			}
			else if (creaturePtr->getx() + 1 < 40 && animalTable->getCreature(creaturePtr->getx() + 1, creaturePtr->gety()) == NULL) {
				// can move 1 square
				animalTable->setCreature(creaturePtr->getx() + 1, creaturePtr->gety(), creaturePtr);
				animalTable->setCreature(creaturePtr->getx(), creaturePtr->gety(), NULL);
				creaturePtr->setx(creaturePtr->getx() + 1);
			}
			return;
		}

		// check if there is a carnivore on the right square
		c = animalTable->getCreature(creaturePtr->getx() + 1, creaturePtr->gety());
		if (c != NULL && c->getCreatureType() == CARNIVORE) {
			// try to move 2 squares left
			if (creaturePtr->getx() - 2 >= 0 && animalTable->getCreature(creaturePtr->getx() - 2, creaturePtr->gety()) == NULL) {
				// can move 2 squares
				animalTable->setCreature(creaturePtr->getx() - 2, creaturePtr->gety(), creaturePtr);
				animalTable->setCreature(creaturePtr->getx(), creaturePtr->gety(), NULL);
				creaturePtr->setx(creaturePtr->getx() - 2);
			}
			else if (creaturePtr->getx() - 1 >= 0 && animalTable->getCreature(creaturePtr->getx() - 1, creaturePtr->gety()) == NULL) {
				// can move 1 square
				animalTable->setCreature(creaturePtr->getx() - 1, creaturePtr->gety(), creaturePtr);
				animalTable->setCreature(creaturePtr->getx(), creaturePtr->gety(), NULL);
				creaturePtr->setx(creaturePtr->getx() - 1);
			}
			return;
		}

		// no carnivores around, herbivore can eat now
		creaturePtr->getEatStrategy()->eat();
		// also reproduce
		creaturePtr->getReproduceStrategy()->reproduce();
	}
	// didn't evade, can eat
	creaturePtr->getEatStrategy()->eat();
	// also reproduce
	creaturePtr->getReproduceStrategy()->reproduce();

}

//  constructor
EvadeCarnivoreStrategy::EvadeCarnivoreStrategy(Creature *c, int food)
{
	creaturePtr = c;
	grassTable = &SimulationGrid::mGrassTable;
	animalTable = &SimulationGrid::mAnimalTable;
	foodLevel = food;
}
