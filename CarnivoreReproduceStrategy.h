//#pragma once
#include "ReproduceStrategy.h"
// Carnivore Reproduce Strategy class
// defines reproduce behaviour for carnivore creatures
class CarnivoreReproduceStrategy :
	public ReproduceStrategy
{
protected:
	// chance that carnivore will reproduce during this day
	double chance;

	// amount of food required to reproduce
	int foodReq;

	// age required to reproduce
	int ageReq;
public:
	void reproduce();
	CarnivoreReproduceStrategy(Creature *, double, int, int);
};

