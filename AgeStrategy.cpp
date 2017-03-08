#include "AgeStrategy.h"


#include "Creature.h"

// age()
// subtract metabolic rate from food level
// increase age by 1 day
// move (if creature has a set move strategy)
void AgeStrategy::age()
{
	creaturePtr->setFood(creaturePtr->getFood() - creaturePtr->getMetabolicRate());

	// metabolic rate may be negative - make sure food level did not exceed max food
	if (creaturePtr->getFood() > creaturePtr->getMaxFood()) {
		creaturePtr->setFood(creaturePtr->getMaxFood());
	}

	// age++
	creaturePtr->setAge(creaturePtr->getAge() + 1);

	// move()
	if (creaturePtr->getMoveStrategy() != NULL) {
		creaturePtr->getMoveStrategy()->move();
	}
}

// constructor
AgeStrategy::AgeStrategy(Creature *c)
{
	creaturePtr = c;
}

// default constructor
AgeStrategy::AgeStrategy()
{
}
