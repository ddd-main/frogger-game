#pragma once
#include<iostream>
#include "level_1.h"
#include "level_2.h"
#include<ctime>
#include <SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Network.hpp>
#include<SFML\Window.hpp>
#include<vector>
#include <fstream>
#include <string>
#include <set>
using namespace std;
using namespace sf;

class top5
{

private:
	RenderWindow window;
	//Event event;
	Texture back;
	Sprite back_sprite;

	Font top_font;
	Text top_text;

	Font player_font[5];
	Text player_text[5];

	Font play_font;
	Text play_text;

	Font exit_font;
	Text exit_text;

	SoundBuffer lay;
	Sound layy;

	int scorak; string namak;
	vector<pair<int, string>>vec;
public:
	top5(string, int);
	int gtpress();
	int slectedItem;
	void playing();
	void up();
	void down();
	~top5(void);
};

