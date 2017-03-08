#include "HerbivoreEatStrategy.h"

#include "Creature.h"
#include "CreatureTable.h"

// eat() function for herbivores
// eats foodToEat units of food from grass tile positioned at the herbivore's location
// herbivores will eat 1 extra food for every 20 levels of food the grass tile has
void HerbivoreEatStrategy::eat()
{
	// get the grass instance
	Creature *grass = grassTable->getCreature(creaturePtr->getx(), creaturePtr->gety());

	// check if grass has enough food levels to eat
	if (grass->getFood() < foodToEat) {
		int amount = grass->getFood();
		
		if (creaturePtr->getFood() + amount > creaturePtr->getMaxFood()) {
			amount = creaturePtr->getMaxFood() - creaturePtr->getFood();
		}
		creaturePtr->setFood(creaturePtr->getFood() + amount);
		grass->setFood(grass->getFood() - amount);
	}
	else {
		// grass has enough food levels to eat
		// for every 20 food levels add 1 to amount to eat
		int amount = foodToEat + ( grass->getFood() / 20 );

		if (creaturePtr->getFood() + amount > creaturePtr->getMaxFood()) {
			amount = creaturePtr->getMaxFood() - creaturePtr->getFood();
		}

		creaturePtr->setFood(creaturePtr->getFood() + amount);
		grass->setFood(grass->getFood() - amount);
	}
}

// constructor
// set the creature pointer and pointers to grass table and creature table
// amount is the amount of food the creature eats at each turn
HerbivoreEatStrategy::HerbivoreEatStrategy(Creature *c, int amount)
{
	creaturePtr = c;
	grassTable = &SimulationGrid::mGrassTable;
	animalTable = &SimulationGrid::mAnimalTable;
	foodToEat = amount;
}
