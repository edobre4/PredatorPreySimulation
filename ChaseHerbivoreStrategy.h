#pragma once
#include "SurvivalStrategy.h"
// Chase Herbivore Strategy
// defines chase behaviour for carnivore creatures
class ChaseHerbivoreStrategy :
	public SurvivalStrategy
{
protected:
	// number of tiles a carnivore will chase
	int chaseDistance;

	// carnivores chase when hungry (their food is below maxFoodToChase)
	int maxFoodToChase;
public:
	void useSurvivalStrategy();
	ChaseHerbivoreStrategy(Creature *, int, int);
};

