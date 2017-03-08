#include "Wolf.h"
#include "CarnivoreEatStrategy.h"
#include "CarnivoreMoveStrategy.h"
#include "CarnivoreReproduceStrategy.h"
#include "ChaseHerbivoreStrategy.h"
#include "DieStrategy.h"
#include "AgeStrategy.h"

// spawn baby wolf at the specified location
void Wolf::spawn(int x, int y)
{
	CreatureTable *animalTable = &SimulationGrid::mAnimalTable;
	Creature *c = new Wolf(textureId, x, y);
	animalTable->setCreature(x, y, c);
	c->setVisited(true);
}

// wolf constructor
// wolves have a high max level of food, moderate metabolic rate, small reproduce chance, s
Wolf::Wolf(int texture, int posx, int posy)
{
        visited = false;
        moved = false;
	creatureType = CARNIVORE;
	textureId = texture;
	mMaxFood = 200;
	mFood = 150;
	mMetabolicRate = 5; // modified metabolic rate from 2 
	x = posx; y = posy;
	mMoveStrategy = new CarnivoreMoveStrategy(this);
	mEatStrategy = new CarnivoreEatStrategy(this, 190);
	mSurvivalStrategy = new ChaseHerbivoreStrategy(this, 2, 20);
	mReproduceStrategy = new CarnivoreReproduceStrategy(this, 0.3, 120, 10); // modified reproduce chance from 0.4
	mDieStrategy = new DieStrategy(this, 50);
	mAgeStrategy = new AgeStrategy(this);
}
