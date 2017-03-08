#pragma once
#include "EatStrategy.h"
/* Carnivore Eat Strategy class
   defines eat behaviour for carnivore creatures
*/
class CarnivoreEatStrategy : public EatStrategy
{
protected:
	// carnivores will not eat if their food level is above this threshold
	int foodThreshold;
public:
	void eat();
	CarnivoreEatStrategy(Creature *, int);
};

