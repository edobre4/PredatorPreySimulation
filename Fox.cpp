#include "Fox.h"
#include "CarnivoreEatStrategy.h"
#include "CarnivoreMoveStrategy.h"
#include "CarnivoreReproduceStrategy.h"
#include "ChaseHerbivoreStrategy.h"
#include "DieStrategy.h"
#include "AgeStrategy.h"

// spawn baby fox at the specified location
void Fox::spawn(int x, int y)
{
	CreatureTable *animalTable = &SimulationGrid::mAnimalTable;
	Creature *c = new Fox(textureId, x, y);
	animalTable->setCreature(x, y, c);
	c->setVisited(true);
}

// fox constructor
// foxes have a  very small metabolic rate but also low level of max food
// very long lifespan of 100 days
// they have a relatively short chase distance (and they only chase when above 50 food)
Fox::Fox(int texture, int posx, int posy)
{
        visited = false;
         moved = false;
	// set fox properties
	creatureType = CARNIVORE;
	textureId = texture;
	mMaxFood = 60;
	mFood = 50;
	mMetabolicRate = 3;
	x = posx; y = posy;
	mMoveStrategy = new CarnivoreMoveStrategy(this);
	mEatStrategy = new CarnivoreEatStrategy(this, 50);
	mSurvivalStrategy = new ChaseHerbivoreStrategy(this, 3, 10);
	mReproduceStrategy = new CarnivoreReproduceStrategy(this, 0.1, 50, 30);
	mDieStrategy = new DieStrategy(this, 100);
	mAgeStrategy = new AgeStrategy(this);
}
