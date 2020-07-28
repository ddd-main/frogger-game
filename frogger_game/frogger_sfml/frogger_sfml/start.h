#pragma once
#include "level_1.h"
#include <string>
#include <SFML\Graphics.hpp>
using namespace sf;


#define max_num 2
//extern int slectedItem;
class start
{
private:
	Font font;
	Text text[max_num];
	Texture men;
	Sprite menu1;
	int slectedItem;
	string name;


public:
	start(string);
	~start();
	void draw(sf::RenderWindow &window);
	void moveup();
	void movedown();
	int getpress();
	void playing();

};
