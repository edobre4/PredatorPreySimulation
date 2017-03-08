#include "HerbivoreMoveStrategy.h"
#include "Creature.h"

// move() for herbivores
// find the tile with most food around the herbivore and move to it
// after moving a herbivore will evade any nearby carnivores
void HerbivoreMoveStrategy::move()
{	
	// get the food level at each adjacent square (up down left and right)

	// get food level for upper square
	int foodUp = -1;
	Creature *grassUp = GrassTablePtr->getCreature(CreaturePtr->getx(), CreaturePtr->gety() - 1);
	if (grassUp != NULL)
		foodUp = grassUp->getFood();

	// get food level for lower square
	int foodDown = -1;
	Creature *grassDown = GrassTablePtr->getCreature(CreaturePtr->getx(), CreaturePtr->gety() + 1);
	if (grassDown != NULL)
		foodDown = grassDown->getFood();

	// get food level for left square
	int foodLeft = -1;
	Creature *grassLeft = GrassTablePtr->getCreature(CreaturePtr->getx() - 1, CreaturePtr->gety());
	if (grassLeft != NULL)
		foodLeft = grassLeft->getFood();

	// get food level for right square
	int foodRight = -1;
	Creature *grassRight = GrassTablePtr->getCreature(CreaturePtr->getx() + 1, CreaturePtr->gety());
	if (grassRight != NULL)
		foodRight = grassRight->getFood();

	// check creature table to make sure each of the adjacent squares are empty
	Creature *c = AnimalTablePtr->getCreature(CreaturePtr->getx(), CreaturePtr->gety() - 1);
	// if there is a creature on the upper square, set foodUp to -1. This will prevent creature from moving up.
	if (c != NULL)
		foodUp = -1;

	// do the same for other directions
	c = AnimalTablePtr->getCreature(CreaturePtr->getx(), CreaturePtr->gety() + 1);
	if (c != NULL)
		foodDown = -1;

	c = AnimalTablePtr->getCreature(CreaturePtr->getx() - 1, CreaturePtr->gety());
	if (c != NULL)
		foodLeft = -1;

	c = AnimalTablePtr->getCreature(CreaturePtr->getx() + 1, CreaturePtr->gety());
	if (c != NULL)
		foodRight = -1;
	// unable to move
	if (foodUp == -1 && foodDown == -1 && foodLeft == -1 && foodRight == -1) {
		return;
	}


	// upper square has most food
	if (foodUp >= foodDown && foodUp >= foodLeft && foodUp >= foodRight) {
		// move up
		AnimalTablePtr->setCreature(CreaturePtr->getx(), CreaturePtr->gety() - 1, CreaturePtr);
		AnimalTablePtr->setCreature(CreaturePtr->getx(), CreaturePtr->gety(), NULL);

		CreaturePtr->sety(CreaturePtr->gety() - 1);
		CreaturePtr->hasMoved(true);
		CreaturePtr->setMoved(CreaturePtr->getx(), CreaturePtr->gety() + 1);
	}
	// lower square has most food
	else if (foodDown >= foodUp && foodDown >= foodLeft && foodDown >= foodRight) {
		AnimalTablePtr->setCreature(CreaturePtr->getx(), CreaturePtr->gety() + 1, CreaturePtr);
		AnimalTablePtr->setCreature(CreaturePtr->getx(), CreaturePtr->gety(), NULL);

		CreaturePtr->sety(CreaturePtr->gety() + 1);
		CreaturePtr->hasMoved(true);
		CreaturePtr->setMoved(CreaturePtr->getx(), CreaturePtr->gety() - 1);
	}
	// left square has most food
	else if (foodLeft >= foodUp && foodLeft >= foodDown && foodLeft >= foodRight) {
		AnimalTablePtr->setCreature(CreaturePtr->getx() - 1, CreaturePtr->gety(), CreaturePtr);
		AnimalTablePtr->setCreature(CreaturePtr->getx(), CreaturePtr->gety(), NULL);

		CreaturePtr->setx(CreaturePtr->getx() - 1);
		CreaturePtr->hasMoved(true);
		CreaturePtr->setMoved(CreaturePtr->getx() + 1, CreaturePtr->gety());
	}
	// right square has most food
	else if (foodRight >= foodUp && foodRight >= foodDown && foodRight >= foodLeft) {
		AnimalTablePtr->setCreature(CreaturePtr->getx() + 1, CreaturePtr->gety(), CreaturePtr);
		AnimalTablePtr->setCreature(CreaturePtr->getx(), CreaturePtr->gety(), NULL);

		CreaturePtr->setx(CreaturePtr->getx() + 1);
		CreaturePtr->hasMoved(true);
		CreaturePtr->setMoved(CreaturePtr->getx() - 1, CreaturePtr->gety());
	}
	// after creature has moved, evade any carnivores that are close
	CreaturePtr->getSurvivalStrategy()->useSurvivalStrategy();
}

// constructor
HerbivoreMoveStrategy::HerbivoreMoveStrategy(Creature *c)
{
	CreaturePtr = c;
	AnimalTablePtr = &SimulationGrid::mAnimalTable;
	GrassTablePtr = &SimulationGrid::mGrassTable;
}