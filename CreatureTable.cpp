#include "CreatureTable.h"

#include "Creature.h"

// constructor
CreatureTable::CreatureTable()
{
}

// return a pointer to the creature residing position x y
Creature * CreatureTable::getCreature(int x, int y)
{
	if (x < 0 || x >= 40 || y < 0 || y >= 30) {
		return NULL;
	}
		
	return table[x][y];
}

// set creature residing x y to c
void CreatureTable::setCreature(int x, int y, Creature *c)
{
	if (x < 0 || x >= 40 || y < 0 || y >= 30) {
		return;
	}
	table[x][y] = c;
}
