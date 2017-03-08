#pragma once
class Creature;
class CreatureTable;
// Class Reproduce Strategy
// abstract class, subclassed by concrete reproduce strategies for herbivores and carnivores
class ReproduceStrategy
{
protected:
	Creature *creaturePtr;
	CreatureTable *grassTable;
	CreatureTable *animalTable;
public:
	ReproduceStrategy();
	virtual void reproduce() = 0;
};

