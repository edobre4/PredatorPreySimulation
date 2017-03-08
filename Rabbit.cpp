#include "Rabbit.h"
#include "HerbivoreEatStrategy.h"
#include "HerbivoreMoveStrategy.h"
#include "HerbivoreReproduceStrategy.h"
#include "EvadeCarnivoreStrategy.h"
#include "DieStrategy.h"
#include "AgeStrategy.h"

// rabbit constructor, takes texture id and position
Rabbit::Rabbit(int texture, int posx, int posy)
{
        visited = false;
        moved = false;
	// set the properties of a rabbit
	creatureType = HERBIVORE;
	textureId = texture;
	mMaxFood = 45;
	mFood = 10;
	mMetabolicRate = 2;
	x = posx; y = posy;
	mMoveStrategy = new HerbivoreMoveStrategy(this);
	mEatStrategy = new HerbivoreEatStrategy(this, 5);
	mSurvivalStrategy = new EvadeCarnivoreStrategy(this, 30);
	mReproduceStrategy = new HerbivoreReproduceStrategy(this, 0.5, 40, 10);
	mDieStrategy = new DieStrategy(this, 25);
	mAgeStrategy = new AgeStrategy(this);
}

// spawn a baby rabbit at the specified location
void Rabbit::spawn(int x, int y)
{
	CreatureTable *animalTable = &SimulationGrid::mAnimalTable;
	Creature *c = new Rabbit(textureId, x, y);
	animalTable->setCreature(x, y, c);
	// baby rabbit has to wait until next turn
	c->setVisited(true);
}
