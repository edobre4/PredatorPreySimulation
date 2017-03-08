#pragma once
#include "MoveStrategy.h"
// Herbivore Move Strategy
// Concrete subclass of Move Strategy for herbivores
class HerbivoreMoveStrategy :
	public MoveStrategy
{

public:
	void move();
	HerbivoreMoveStrategy(Creature *c);
};

