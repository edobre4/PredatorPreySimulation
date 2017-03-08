#include "ChaseHerbivoreStrategy.h"
#include "Creature.h"

// survival strategy for chasing
// carnivore checks for herbivores (up to chaseDistance spaces) in each direction
// (up, down, left, and right). If it finds a herbivore, it will move to a position adjacent to the herbivore.
void ChaseHerbivoreStrategy::useSurvivalStrategy()
{
	int x = creaturePtr->getx();
	int y = creaturePtr->gety();

	// the carnivore must be hungry to hunt (its food level must be less than maxFoodToChase)
	if (creaturePtr->getFood() > maxFoodToChase)
		return;

	// check for herbivores in uppper direction
	for (int i = 1; i <= chaseDistance; i++) {
		Creature *c = animalTable->getCreature(x, y - i);
		if (c != NULL && c->getCreatureType() == HERBIVORE) {

			// move up as much as possible (at some point will be just under the herbivore)
			while (y - 1 >= 0 && animalTable->getCreature(x, y - 1) == NULL) {
				creaturePtr->sety(y - 1);
				animalTable->setCreature(x, y, NULL);
				animalTable->setCreature(x, y - 1, creaturePtr);
				y--;
			}
			return;
		}
	}

	// check for herbivores in lower squares
	for (int i = 1; i <= chaseDistance; i++) {
		Creature *c = animalTable->getCreature(x, y + i);
		if (c != NULL && c->getCreatureType() == HERBIVORE) {

			// move up as much as possible (at some point will be just under the herbivore)
			while (y + 1 < 30 && animalTable->getCreature(x, y + 1) == NULL) {
				creaturePtr->sety(y + 1);
				animalTable->setCreature(x, y, NULL);
				animalTable->setCreature(x, y + 1, creaturePtr);
				y++;
			}
			return;
		}
	}

	// check for herbivores in left squares
	for (int i = 1; i <= chaseDistance; i++) {
		Creature *c = animalTable->getCreature(x - i, y);
		if (c != NULL && c->getCreatureType() == HERBIVORE) {

			// move up as much as possible (at some point will be just under the herbivore)
			while (x - 1 >= 0 && animalTable->getCreature(x - 1, y) == NULL) {
				creaturePtr->setx(x - 1);
				animalTable->setCreature(x, y, NULL);
				animalTable->setCreature(x - 1, y, creaturePtr);
				x--;
			}
			return;
		}
	}

	// check for herbivores in right squares
	for (int i = 1; i <= chaseDistance; i++) {
		Creature *c = animalTable->getCreature(x + i, y);
		if (c != NULL && c->getCreatureType() == HERBIVORE) {

			// move up as much as possible (at some point will be just under the herbivore)
			while (x + 1 < 40 && animalTable->getCreature(x + 1, y) == NULL) {
				creaturePtr->setx(x + 1);
				animalTable->setCreature(x, y, NULL);
				animalTable->setCreature(x + 1, y, creaturePtr);
				x++;
			}
			return;
		}
	}
}

ChaseHerbivoreStrategy::ChaseHerbivoreStrategy(Creature *c, int dist, int food)
{
	creaturePtr = c;
	chaseDistance = dist;
	animalTable = &SimulationGrid::mAnimalTable;
	maxFoodToChase = food;
}
