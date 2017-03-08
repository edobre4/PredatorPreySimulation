#include "Grass.h"

// change the amount of food the grass has
// overrides setFood() from Creature so that it can update the texture
void Grass::setFood(int a)
{
	mFood = a;
	updateTexture();
}

// sets the texture for this grass tile based on the amount of food it has
void Grass::updateTexture()
{
	if (mFood < 25)
		setTexture(texture1);
	else if (mFood < 50)
		setTexture(texture2);
	else if (mFood < 75)
		setTexture(texture3);
	else
		setTexture(texture4);
}

// constructor
Grass::Grass(int t1, int t2, int t3, int t4)
{
	// set textures
	texture1 = t1;
	texture2 = t2;
	texture3 = t3;
	texture4 = t4;

	// set grass fields
	creatureType = GRASS;
	mMaxFood = 100;
	mFood = 20;
	mMetabolicRate = -1;
	x = 0; y = 0;
	updateTexture();

	// grass can only age
	mMoveStrategy = NULL;
	mEatStrategy = NULL;
	mSurvivalStrategy = NULL;
	mReproduceStrategy = NULL;
	mDieStrategy = NULL;
	mAgeStrategy = new AgeStrategy(this);
}

// grass does not reproduce
void Grass::spawn(int x, int y)
{
}
