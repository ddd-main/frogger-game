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
#include <set>
using namespace sf;
using namespace std;

class level_2
{
private:
	RenderWindow window;
	int healthcnt;
	int froggernm;
	bool froggerfound;
	bool winsFound[5];
	Event event;
	vector<Sprite>Froggers;
	//---------------------------------------
	vector<Sprite>objectsRoad2Right;
	vector<Vector2f>positionsRoad2Right;
	vector<Sprite>objectsRoad2Left;
	vector<Vector2f>positionsRoad2Left;
	//----------------------------------------
	vector<Sprite>objectsRoadRight;
	vector<Vector2f>positionsRoadRight;
	vector<Sprite>objectsRoadLeft;
	vector<Vector2f>positionsRoadLeft;
	vector<Sprite>Wins;
	vector<Sprite>Hearts;
	set<int>countscore;

	//string to display the count the score of frogger 
	string count_score;
	int score_dis;

	//declaration for road and frogger (textures)
	Texture RoadPH, ForggerPH;

	// start position of frogger place
	Texture start_place;
	Sprite start_place_sprite;
	// declaration for objects (textures) which in road2
	Texture ccar1PH, ccar12PH, ccar13PH, ccar14PH, ccar21PH, ccar22PH, ccar23PH, ccar31PH, ccar32PH, ccar33PH, bomb, Sinking;


	// declaration for cars (textures) which in road
	Texture car1PH, car12PH, car21PH, car22PH, car31PH, car32PH, car41PH, car42PH;

	// declaration for win place (textures)
	Texture Winplace1, Winplace2, Winplace3, Winplace4, Winplace5;

	// declaration for hearts (texture)
	Texture heart1, heart2, heart3;


	//declaration for road and frogger (sprites)
	Sprite backgroundSprite, froggerSprite;

	//declaration for sprites for objects in water (sprites)
	Sprite ccar1Sprite, ccar12Sprite, ccar13Sprite, ccar14Sprite, ccar2Sprite, ccar22Sprite, ccar23Sprite, ccar31Sprite, ccar32Sprite, ccar33Sprite
		, bombSprite, SinkingSprite;


	//declaration for sprites for cars in road (sprites)
	Sprite car1Spritesheet, car11Spritesheet, car2Spritesheet, car22Spritesheet, car3Spritesheet, car33Spritesheet, car4Spritesheet, car44Spritesheet;

	//declaration for win place (sprite) 
	Sprite Winplacesprite1, Winplacesprite2, Winplacesprite3, Winplacesprite4, Winplacesprite5;

	//declaration for hearts (sprite)
	Sprite heartsprite1, heartsprite2, heartsprite3;


	// font el score
	Font score_font;
	Text score_text;

	// font (el timer )
	Time elabsed;
	Font timer_font;
	Text timer_text;
	Clock timer_clock;
	Time timer_time;
	string timer_string;


	// music in the game
	SoundBuffer mainbuffer;
	Sound mainsound;

	SoundBuffer froggerHops_buffer;
	Sound froggerHop_sound;

	SoundBuffer froggerTrucked_buffer;
	Sound froggerTrucked_sound;

	SoundBuffer timer_end_buffer;
	Sound timer_end_sound;

	SoundBuffer win_buffer;
	Sound win_sound;
	string name2;

public:
	level_2(void);
	level_2(int health, int count, string name2);
	void load_from_file();
	void set_texture();
	void playing();
	~level_2(void);
};



