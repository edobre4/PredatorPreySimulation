#include "Snake.h"
#include "CarnivoreEatStrategy.h"
#include "CarnivoreMoveStrategy.h"
#include "CarnivoreReproduceStrategy.h"
#include "ChaseHerbivoreStrategy.h"
#include "AgeStrategy.h"
#include "DieStrategy.h"

// snake constructor
// snakes are very agile ( can chase for up to 6 tiles in each direction)
// they have small chance of reproducing, but they can reproduce at a very young age and very low food level
// snakes also have a very high metabolic rate compared to wolves and foxes and their lifespan is only 10 days
// 
Snake::Snake(int texture, int posx, int posy)
{
        visited = false;
        moved = false;
	// set the properties of the snake
	creatureType = CARNIVORE;
	textureId = texture;
	mMaxFood = 100;
	mFood = 50;
	mMetabolicRate = 6;
	x = posx; y = posy;
	mMoveStrategy = new CarnivoreMoveStrategy(this);
	mEatStrategy = new CarnivoreEatStrategy(this, 130);
	mSurvivalStrategy = new ChaseHerbivoreStrategy(this, 10, 50);
	mReproduceStrategy = new CarnivoreReproduceStrategy(this, 0.2, 15, 3);
	mDieStrategy = new DieStrategy(this, 15);
	mAgeStrategy = new AgeStrategy(this);
}

// spawn baby snake at specified location
void Snake::spawn(int x, int y)
{
	CreatureTable *animalTable = &SimulationGrid::mAnimalTable;
	Creature *c = new Snake(textureId, x, y);
	animalTable->setCreature(x, y, c);
	c->setVisited(true);
}

