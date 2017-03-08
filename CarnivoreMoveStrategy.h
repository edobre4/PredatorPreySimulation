#pragma once
#include "MoveStrategy.h"
// Carnivore Move Strategy class
// defines move behaviour for carnivore creatures
class CarnivoreMoveStrategy : public MoveStrategy

{
public:
	void move();
	CarnivoreMoveStrategy( Creature *);
};

