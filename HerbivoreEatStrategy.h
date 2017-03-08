#pragma once
#include "EatStrategy.h"
// Herbivore Eat strategy class
// Concrete subclass of Eat Strategy for herbivores
class HerbivoreEatStrategy :
	public EatStrategy
{
	// amount of food the herbivore eats per day (excluding extra food the herbivore might eat if there is an excessive amount of food)
	int foodToEat;
public:
	void eat();
	HerbivoreEatStrategy(Creature *,int);
};

