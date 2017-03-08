#include "Graphics.h"
#include "CreatureTable.h"
#include "Creature.h"

Graphics::Graphics()
{

}

// draws a shape using provided texture id at the specified location
void Graphics::drawShapeAt(int id, int x, int y)
{
	if (id < 0)
		return;
	sf::RectangleShape shape(sf::Vector2f(18, 18));
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(1);
	shape.setTexture(&textures[id]);
	shape.setPosition(sf::Vector2f(x * 20, y * 20));
	window->draw(shape);
}

// loads a texture and saves it into textures[]
void Graphics::addTexture(int id, string filename)
{
	textures[id] = sf::Texture();
	if (!textures[id].loadFromFile(filename)) {
		cout << "Unable to load file " + filename << endl;
	}
}

// create a window with specified dimensions
void Graphics::setWindowSize(int w, int h)
{
	width = w;
	height = h;
	window = new sf::RenderWindow(sf::VideoMode(width * 20, height * 20), "Predator Prey Simulation");
}

// draw a frame
// draws every creature in grass table and animal table to the window
void Graphics::draw(CreatureTable *grassTable, CreatureTable *animalTable)
{
	if (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		// clear the screen
		window->clear();

		// render grass table
		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 30; j++) {
				Creature *c = grassTable->getCreature(i, j);
				if (c != NULL)
					drawShapeAt(c->getTexture(), i, j);
			}
		}

		// render animal table
		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 30; j++) {
				Creature *c = animalTable->getCreature(i, j);
				if (c != NULL)
					drawShapeAt(c->getTexture(), i, j);
			}
		}
		// display the buffer
		window->display();
	}
}