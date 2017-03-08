#pragma once
// Class Die Strategy
// defines the strategy used to determine if a creature should die
class Creature;
class CreatureTable;
class DieStrategy
{
protected:
	Creature *creaturePtr;
	CreatureTable *animalTable;
	// number of days before a creature dies of old age
	int lifespan;
public:
	void die();
	DieStrategy(Creature *, int);
};

