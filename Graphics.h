#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
// Graphics class
// Uses SFML API to create the window and draw the grid of creatures

using namespace std;
#define MAX_TEXTURES 20
class CreatureTable;
class Graphics
{
private:
	int width;
	int height;
	sf::Texture textures[MAX_TEXTURES];
	sf::RenderWindow *window;
public:
	Graphics();                     // create the window
	void drawShapeAt(int, int, int);  // draw a texture at position x y
	void addTexture(int, string);     // add a texture id to the list of textures
	void setWindowSize(int, int);     // set the width and height of the window
	void draw(CreatureTable*, CreatureTable *);  // draw the creature grid
};

