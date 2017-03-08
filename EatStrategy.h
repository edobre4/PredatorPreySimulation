#pragma once
// Eat Strategy Abstract Class
// Subclassed by specific eat strategies for herbivores and carnivores
class Creature;
class CreatureTable;
class EatStrategy
{
protected:
	Creature *creaturePtr;
	CreatureTable *grassTable;
	CreatureTable *animalTable;
public:
	EatStrategy();
	// pure virtual function - implemented in subclases
	virtual void eat() = 0;
};

