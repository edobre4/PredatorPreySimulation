#pragma once
#include <stdlib.h>
#include <iostream>
// Creature Table class
// contains a table and provides a getter and setter for a 
// creature within the table
using namespace std;
class Creature;
class CreatureTable
{
	// table is a 2d table of Creature pointers
	Creature *table[40][30];
public:
	CreatureTable();
	Creature *getCreature(int x, int y);       // get creature at position x y
	void setCreature(int x, int y, Creature *); // set creature at x y 
};

