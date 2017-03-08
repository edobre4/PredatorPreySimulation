#pragma once
#include "MoveStrategy.h"
#include "EatStrategy.h"
#include "SurvivalStrategy.h"
#include "ReproduceStrategy.h"
#include "DieStrategy.h"
#include "AgeStrategy.h"
/*
 * Creature Class - subclassed by specific creatures like Grass, Rabbit, Wolf
 * This class defines the fields associated with a creature, and provides getters and setters for each field
 * Choosing a strategy for each action is deferred to subclasses of Creature.
 */
enum CTYPE {GRASS, HERBIVORE, CARNIVORE};

class Creature
{
protected:
	CTYPE creatureType;    // can be grass, carnivore, or herbivore
	int mMaxFood;          // maximum food level
	int mFood;             // current food level
	int mMetabolicRate;    // amount of food used per day
	int mAge;              // age in days
	int x;                 // x position
	int y;                 // y position
	int textureId;         // id of the texture for this creature
	bool visited;  // flag indicating if a creature has performed an action during a given day
	bool moved;    // flag indicating if a creature has moved (used to determined if creature can reproduce)
	int movedx;            // the x position that creature moved from
	int movedy;            // the y position that creature moved from

	MoveStrategy *mMoveStrategy;  // strategy to perform when moving
	EatStrategy *mEatStrategy;    // strategy to perform when eating
	SurvivalStrategy *mSurvivalStrategy;  // survival strategy - herbivores evade, carnivores chase
	ReproduceStrategy *mReproduceStrategy; // strategy used to reproduce
	DieStrategy *mDieStrategy;    // strategy to perform to determine if a creature should die
	AgeStrategy *mAgeStrategy;    // strategy to perform when a creature should age

public:

	Creature(); // constructor
	void clear();        // free memory used by this class
	int getTexture();    // get the texture id of this creature
	void setTexture(int); // set texture id
	int getFood();        // food getter
	virtual void setFood(int);  // food setter - virtual function (may be overriden when a creature wants to change its texture after eating)
	int getx();                 // position 
	void setx(int);             // getters 
	int gety();                 // and
	void sety(int);             // setters
	int getMetabolicRate();     // metabolic rate getter
	int getAge();               // age getter
	void setAge(int);           // age setter
	bool isVisited();           // visited getter           
	void setVisited(bool);      // visited setter
	int getMaxFood();           // maxFood getter
	CTYPE getCreatureType();    // creatureType getter
	bool hasMoved();            // hasMoved getter
	void hasMoved(bool);        // hasMoved setter
	int getMovedX();   
	int getMovedY();
	void setMoved(int, int);
	virtual void spawn(int, int) = 0;  // spawn a creature at given position. Overriden by subclasses to spawn creatures of the same type

	// strategy getters
	MoveStrategy *getMoveStrategy();
	EatStrategy *getEatStrategy();
	SurvivalStrategy *getSurvivalStrategy();
	ReproduceStrategy *getReproduceStrategy();
	DieStrategy *getDieStrategy();
	AgeStrategy *getAgeStrategy();
};

