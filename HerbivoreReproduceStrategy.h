//#pragma once
#include "ReproduceStrategy.h"
// Herbivore Reproduce Strategy class
// defines reproduce behaviour for herbivores
class HerbivoreReproduceStrategy :
	public ReproduceStrategy
{
protected:
	double chance;  // chance of reproducing
	int foodReq;    // food required to reproduce
	int ageReq;     // age required to reproduce
public:
	void reproduce();
	HerbivoreReproduceStrategy(Creature *, double, int, int);
};

