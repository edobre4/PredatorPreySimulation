#include "CarnivoreMoveStrategy.h"

#include "Creature.h"
#include "CreatureTable.h"

// move () for carnivores
// 
// creature will first try to chase herbivores (moving to a position adjacent to them if successful)
// next creature will try to eat
// if the creature successfully eats, it will reproduce
// if the creature did not eat, it will move 1 space in a random direction (if move was succesful creature will reproduce)
void CarnivoreMoveStrategy::move()
{
	// first try to chase herbivores
	CreaturePtr->getSurvivalStrategy()->useSurvivalStrategy();
	// try to eat
	int food = CreaturePtr->getFood();
	CreaturePtr->getEatStrategy()->eat();
	int foodAfterEat = CreaturePtr->getFood();
	
	// if carnivore has eaten, reproduce
	if (foodAfterEat !=  food) {
		CreaturePtr->getReproduceStrategy()->reproduce();
		return;
	}

	// now move

	int x = CreaturePtr->getx();
	int y = CreaturePtr->gety();

	// check which squares are available to move and pick a random one of them
	int dirs[4];
	int count = 0;
	
	Creature *c = AnimalTablePtr->getCreature(x, y - 1);
	if (y - 1 >= 0 && c == NULL)
		dirs[count++] = 0;

	c = AnimalTablePtr->getCreature(x, y + 1);
	if (y + 1 < 30 && c == NULL)
		dirs[count++] = 1;

	c = AnimalTablePtr->getCreature(x - 1, y);
	if (x - 1 >= 0 && c == NULL)
		dirs[count++] = 2;

	c = AnimalTablePtr->getCreature(x + 1, y);
	if (x + 1 < 40 && c == NULL)
		dirs[count++] = 3;
	// if every square is occupied, don't move
	if (count == 0)
		return;
	int index = rand() % count;
	int newx = x;
	int newy = y;

	switch (dirs[index]) {
	case 0:
		newy--;
		break;
	case 1:
		newy++;
		break;
	case 2:
		newx--;
		break;
	case 3:
		newx++;
		break;
	}

	// move in the chosen direction
	CreaturePtr->setx(newx);
	CreaturePtr->sety(newy);
	AnimalTablePtr->setCreature(x, y, NULL);
	AnimalTablePtr->setCreature(newx, newy, CreaturePtr);

	// indicate that the previous location is vacant
	CreaturePtr->hasMoved(true);
	CreaturePtr->setMoved(x, y);
	// reproduce
	CreaturePtr->getReproduceStrategy()->reproduce();
}

// constructor
CarnivoreMoveStrategy::CarnivoreMoveStrategy(Creature *c)
{
	CreaturePtr = c;
	AnimalTablePtr = &SimulationGrid::mAnimalTable;
}
