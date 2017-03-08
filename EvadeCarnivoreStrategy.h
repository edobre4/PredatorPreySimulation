#pragma once
#include "SurvivalStrategy.h"
// Evade Carnivore Strategy class
// defines behaviour for herbivores when evading
class EvadeCarnivoreStrategy :
	public SurvivalStrategy
{
	// herbivores will not evade if their food level is below this amount
	int foodLevel;
public:
	void useSurvivalStrategy();
	EvadeCarnivoreStrategy(Creature *, int );
};

