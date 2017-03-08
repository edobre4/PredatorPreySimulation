#include "Creature.h"

// constructor
Creature::Creature()
{
}

// clear memory allocated for each strategy
void Creature::clear()
{
	delete mAgeStrategy;
	delete mMoveStrategy;
	delete mEatStrategy;
	delete mReproduceStrategy;
	delete mSurvivalStrategy;
}


// texture getter
int Creature::getTexture()
{
	return textureId;
}

// texture setter
void Creature::setTexture(int id)
{
	textureId = id;
}

// food getter
int Creature::getFood()
{
	return mFood;
}

// food setter
void Creature::setFood(int a)
{
	mFood = a;
}

// x position getter
int Creature::getx()
{
	return x;
}


// x position setter
void Creature::setx(int a)
{
	x = a;
}


// y position getter
int Creature::gety()
{
	return y;
}

// y position setter
void Creature::sety(int a)
{
	y = a;
}


// metabolic rate getter
int Creature::getMetabolicRate()
{
	return mMetabolicRate;
}

// age getter
int Creature::getAge()
{
	return mAge;
}

// age setter
void Creature::setAge(int a)
{
	mAge = a;
}

// visited getter
bool Creature::isVisited()
{
	return visited;
}

// visited setter
void Creature::setVisited(bool v)
{
	if (v == false) {
		moved = false;
	}
	visited = v;
}

// maxFood getter
int Creature::getMaxFood()
{
	return mMaxFood;
}

// creature type getter
CTYPE Creature::getCreatureType()
{
	return creatureType;
}

// moved getter
bool Creature::hasMoved()
{
	return moved;
}


// moved setter
void Creature::hasMoved(bool b)
{
	moved = b;
}

// movedx getter
int Creature::getMovedX()
{
	return movedx;
}

// movedy getter
int Creature::getMovedY()
{
	return movedy;
}


// movedx and movedy setter
void Creature::setMoved(int x, int y)
{
	movedx = x;
	movedy = y;
}

// move strategy getter
MoveStrategy *Creature::getMoveStrategy()
{
	return mMoveStrategy;
}

// eat strategy getter
EatStrategy *Creature::getEatStrategy()
{
	return mEatStrategy;
}

// survival strategy getter
SurvivalStrategy *Creature::getSurvivalStrategy()
{
	return mSurvivalStrategy;
}

// reproduce strategy getter
ReproduceStrategy *Creature::getReproduceStrategy()
{
	return mReproduceStrategy;
}

// die strategy getter
DieStrategy *Creature::getDieStrategy()
{
	return mDieStrategy;
}

// age strategy getter
AgeStrategy *Creature::getAgeStrategy()
{
	return mAgeStrategy;
}
