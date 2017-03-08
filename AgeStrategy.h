#pragma once
/*
 Age strategy class
 defines creature behaviour when aging
*/
class Creature;
class AgeStrategy
{
protected:
	Creature *creaturePtr;
public:
	virtual void age();
	AgeStrategy(Creature *c);
	AgeStrategy();
};

