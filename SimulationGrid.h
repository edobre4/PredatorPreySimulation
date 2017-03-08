#pragma once
#include "CreatureTable.h"

// Simulation Grid class
// contains 2 public static creature tables - one for grass and one for animals
class SimulationGrid
{
public:
	SimulationGrid();
	static CreatureTable mGrassTable;
	static CreatureTable mAnimalTable;
};

