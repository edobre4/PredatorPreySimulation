#pragma once
class Creature;
class CreatureTable;
// Class Survival Strategy
// abstract class subclassed by concrete survival strategies for herbivores and carnivores

class SurvivalStrategy
{
protected:
	Creature *creaturePtr;
	CreatureTable *grassTable;
	CreatureTable *animalTable;
public:
	SurvivalStrategy();
	virtual void useSurvivalStrategy() = 0;
};

