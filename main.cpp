#include <SFML/Graphics.hpp>
#include "Graphics.h"
#include "SimulationGrid.h"
//#include "Windows.h" visual studio
#include "Grass.h"
#include "Rabbit.h"
#include "Wolf.h"
#include "Fox.h"
#include "Rat.h"
#include "Snake.h"
#include <unistd.h>

// texture ids for each creature
#define GRASS_L1 0
#define GRASS_L2 1
#define GRASS_L3 2
#define GRASS_L4 3
#define RABBIT 4
#define WOLF 5
#define FOX 6
#define SNAKE 7
#define RAT 8
#define NONE -1



int main()
{
	// number of creatures to spawn
	int snakes = 2;
	int wolves = 1;
	int foxes = 2;
	int rabbits = 15;
	int rats = 15;

	// seed rng
	srand(time(NULL));

	// time in microseconds between each draw
	int sleepTime = 250000; // 250 milliseconds

	// create the drawing window
	Graphics gp;
	gp.setWindowSize(40, 30);

	// add textures for each creature
	gp.addTexture(GRASS_L1, "grass1.png");
	gp.addTexture(GRASS_L2, "grass2.png");
	gp.addTexture(GRASS_L3, "grass3.png");
	gp.addTexture(GRASS_L4, "grass4.png");
	gp.addTexture(RABBIT, "rabbit.png");
	gp.addTexture(WOLF, "wolf.png");
	gp.addTexture(FOX, "fox.png");
	gp.addTexture(SNAKE, "snake.png");
	gp.addTexture(RAT, "rat.png");

	// get a reference to each table of creatures
	CreatureTable *grassTable = &SimulationGrid::mGrassTable;
	CreatureTable *animalTable = &SimulationGrid::mAnimalTable;

	// first clear out animal table, and add grass to each tile
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 30; j++) {
			grassTable->setCreature(i, j, new Grass(GRASS_L1, GRASS_L2, GRASS_L3, GRASS_L4));
			animalTable->setCreature(i, j, NULL);
		} 
	}
	
	// spawn wolves
	for (int i = 0; i < wolves; i++) {
		int x = rand() % 40;
		int y = rand() % 30;

		while (animalTable->getCreature(x, y) != NULL) {
			x = rand() % 40;
			y = rand() % 30;
		}
		Creature *wolf = new Wolf(WOLF, x, y);
		animalTable->setCreature(x, y, wolf);
	}

	// spawn foxes
	for (int i = 0; i < foxes; i++) {
		int x = rand() % 40;
		int y = rand() % 30;

		while (animalTable->getCreature(x, y) != NULL) {
			x = rand() % 40;
			y = rand() % 30;
		}
		Creature *fox = new Fox(FOX, x, y);
		animalTable->setCreature(x, y, fox);
	}

	// spawn snakes
	for (int i = 0; i < snakes; i++) {
		int x = rand() % 40;
		int y = rand() % 30;

		while (animalTable->getCreature(x, y) != NULL) {
			x = rand() % 40;
			y = rand() % 30;
		}
		Creature *snake = new Snake(SNAKE, x, y);
		animalTable->setCreature(x, y, snake);
	}
	
	// spawn rabbits
	for (int i = 0; i < rabbits; i++) {
		int x = rand() % 40;
		int y = rand() % 30;

		while (animalTable->getCreature(x, y) != NULL) {
			x = rand() % 40;
			y = rand() % 30;
		}
		Creature *rabbit = new Rabbit(RABBIT, x, y);
		animalTable->setCreature(x, y, rabbit);
	}
	
	// spawn  rats
	for (int i = 0; i < rats; i++) {
		int x = rand() % 40;
		int y = rand() % 30;

		while (animalTable->getCreature(x, y) != NULL) {
			x = rand() % 40;
			y = rand() % 30;
		}
		Creature *rat = new Rat(RAT, x, y);
		animalTable->setCreature(x, y, rat);
	}

	// draw loop
	while (true) {
		// draw screen once per day
		gp.draw(grassTable, animalTable);
		// pause
		//Sleep(sleepTime); // windows
                usleep(sleepTime);
		// for each creature (including grass), perform its daily routine - which starts with age
		// at the end of the day check if the creature must die (due to old age, or hunger)
		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 30; j++) {
				Creature *grass = grassTable->getCreature(i, j);
				if (grass != NULL)
					grass->getAgeStrategy()->age();
				Creature *animal = animalTable->getCreature(i, j);
				if (animal != NULL  && ! animal->isVisited()) {
					animal->getAgeStrategy()->age();
					animal->setVisited(true);
					animal->getDieStrategy()->die();

				}
			}
		}

		// clear visited status of each animal
		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 30; j++) {
				Creature *cr = animalTable->getCreature(i, j);
				if (cr != NULL) {
					cr->setVisited(false);
				}
			}
		}
	}


	return 0;
}
