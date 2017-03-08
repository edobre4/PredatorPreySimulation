#include "Rat.h"
#include "HerbivoreEatStrategy.h"
#include "HerbivoreMoveStrategy.h"
#include "HerbivoreReproduceStrategy.h"
#include "EvadeCarnivoreStrategy.h"
#include "AgeStrategy.h"
#include "DieStrategy.h"

// Rats have a high reproduction rate, and are more agile than rabbits ( can evade at very low food level)
// Their metabolic rate is faster and they only live for 15 days
Rat::Rat(int texture, int posx, int posy)
{
        visited = false;
        moved = false;
	creatureType = HERBIVORE;
	textureId = texture;
	mMaxFood = 30;
	mFood = 10;
	mMetabolicRate = 5;
	x = posx; y = posy;
	mMoveStrategy = new HerbivoreMoveStrategy(this);
	mEatStrategy = new HerbivoreEatStrategy(this, 3);
	mSurvivalStrategy = new EvadeCarnivoreStrategy(this, 2);
	mReproduceStrategy = new HerbivoreReproduceStrategy(this, 1.0, 10, 6);
	mDieStrategy = new DieStrategy(this, 15);
	mAgeStrategy = new AgeStrategy(this);
}


// spawn a baby rat at the specified location
void Rat::spawn(int x, int y)
{
	CreatureTable *animalTable = &SimulationGrid::mAnimalTable;
	Creature *c = new Rat(textureId, x, y);
	animalTable->setCreature(x, y, c);
	// baby rat has to wait until next turn
	c->setVisited(true);
}
