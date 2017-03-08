project3: main.o Creature.o CreatureTable.o SimulationGrid.o Fox.o Rat.o Wolf.o Grass.o Snake.o Rabbit.o Graphics.o AgeStrategy.o DieStrategy.o EatStrategy.o MoveStrategy.o SurvivalStrategy.o ReproduceStrategy.o CarnivoreEatStrategy.o HerbivoreEatStrategy.o CarnivoreMoveStrategy.o HerbivoreMoveStrategy.o ChaseHerbivoreStrategy.o EvadeCarnivoreStrategy.o CarnivoreReproduceStrategy.o HerbivoreReproduceStrategy.o
	g++ -g -o project3 main.o Creature.o CreatureTable.o SimulationGrid.o Fox.o Rat.o Wolf.o Grass.o Snake.o Rabbit.o Graphics.o AgeStrategy.o DieStrategy.o EatStrategy.o MoveStrategy.o SurvivalStrategy.o ReproduceStrategy.o CarnivoreEatStrategy.o HerbivoreEatStrategy.o CarnivoreMoveStrategy.o HerbivoreMoveStrategy.o ChaseHerbivoreStrategy.o EvadeCarnivoreStrategy.o CarnivoreReproduceStrategy.o HerbivoreReproduceStrategy.o -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

Creature.o: Creature.cpp Creature.h
	g++ -c Creature.cpp

CreatureTable.o: CreatureTable.cpp CreatureTable.h
	g++ -c CreatureTable.cpp

SimulationGrid.o: SimulationGrid.cpp SimulationGrid.h
	g++ -c SimulationGrid.cpp

Fox.o: Fox.cpp Fox.h
	g++ -c Fox.cpp

Rat.o: Rat.cpp Rat.h
	g++ -c Rat.cpp

Wolf.o: Wolf.cpp Wolf.h
	g++ -c Wolf.cpp

Grass.o: Grass.cpp Grass.h
	g++ -c Grass.cpp

Snake.o: Snake.cpp Snake.h
	g++ -c Snake.cpp

Rabbit.o: Rabbit.cpp Rabbit.h
	g++ -c Rabbit.cpp

Graphics.o: Graphics.cpp Graphics.h
	g++ -c Graphics.cpp

AgeStrategy.o: AgeStrategy.cpp AgeStrategy.h
	g++ -c AgeStrategy.cpp

DieStrategy.o: DieStrategy.cpp DieStrategy.h
	g++ -c DieStrategy.cpp

EatStrategy.o: EatStrategy.cpp EatStrategy.h
	g++ -c EatStrategy.cpp

MoveStrategy.o: MoveStrategy.cpp MoveStrategy.h
	g++ -c MoveStrategy.cpp

SurvivalStrategy.o: SurvivalStrategy.cpp SurvivalStrategy.h
	g++ -c SurvivalStrategy.cpp

ReproduceStrategy.o: ReproduceStrategy.cpp ReproduceStrategy.h
	g++ -c ReproduceStrategy.cpp

CarnivoreEatStrategy.o: CarnivoreEatStrategy.cpp CarnivoreEatStrategy.h
	g++ -c CarnivoreEatStrategy.cpp

HerbivoreEatStrategy.o: HerbivoreEatStrategy.cpp HerbivoreEatStrategy.h
	g++ -c HerbivoreEatStrategy.cpp

CarnivoreMoveStrategy.o: CarnivoreMoveStrategy.cpp CarnivoreMoveStrategy.h
	g++ -c CarnivoreMoveStrategy.cpp

HerbivoreMoveStrategy.o: HerbivoreMoveStrategy.cpp HerbivoreMoveStrategy.h
	g++ -c HerbivoreMoveStrategy.cpp

ChaseHerbivoreStrategy.o: ChaseHerbivoreStrategy.cpp ChaseHerbivoreStrategy.h
	g++ -c ChaseHerbivoreStrategy.cpp

EvadeCarnivoreStrategy.o: EvadeCarnivoreStrategy.cpp EvadeCarnivoreStrategy.h
	g++ -c EvadeCarnivoreStrategy.cpp

CarnivoreReproduceStrategy.o: CarnivoreReproduceStrategy.cpp CarnivoreReproduceStrategy.h
	g++ -c CarnivoreReproduceStrategy.cpp

HerbivoreReproduceStrategy.o: HerbivoreReproduceStrategy.cpp HerbivoreReproduceStrategy.h
	g++ -c HerbivoreReproduceStrategy.cpp
