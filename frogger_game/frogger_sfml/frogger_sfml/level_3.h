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
#include<map>
#include "top5.h"
#include"start.h"
using namespace sf;
using namespace std;


class level_3
{
	RenderWindow window;
	Texture water, plant, forgger, wood, wood1, wood2, wood3, wood4, wood5, wood6, wood7, wood11, wood22, wood33, wood44, crocodile, crocodile1, crocodile2, c3, wood_r1, wood_r2, wood_r3, w1, w2, w3, sink_text, win, win1, win2, win3, win4, heart, heart1, heart2, bomb;
	Sprite bg, p, f, woo, woo1, woo2, woo3, woo4, woo5, woo6, woo7, woo11, woo22, woo33, woo44, cro, cro1, cro2, c_spr3, woo_r1, woo_r2, woo_r3, w1_sprite, w2_sprite, w3_sprite, sink, win_sprite, win_s1, win_s2, win_s3, win_s4, h, h1, h2, bomb_sprite;
	Event event;
	int frogger_num;
	bool frogger_f;
	bool winsFound[5];
	vector<Sprite>frogerrvec;
	vector<Sprite>water_obj_l;
	vector<Vector2f>water_obj_p;
	vector<Sprite>water_obj_r;
	vector<Vector2f>water_obj_p_right;
	vector<Sprite>wins;
	vector<Sprite>Heart;
	set<int>countscore;
	int healthcnt;
	Clock clock;
	Time elapsed;
	Font font;
	Text text;
	Text textt;
	Text j;
	map<pair < int, int >, String > mp;


	string count_score;
	int score_dis;
	Font score_font;
	Text score_text;
	///timer
	Time elabsed;
	Font timer_font;
	Text timer_text;
	Clock timer_clock;
	Time timer_time;
	string timer_string;

	//music in level
	SoundBuffer mainbuffer;
	Sound mainsound;


	SoundBuffer froggerHops_buffer;
	Sound froggerHop_sound;

	SoundBuffer froggerSinking_buffer;
	Sound froggerSinking_sound;

	SoundBuffer timer_buffer;
	Sound timer_sound;

	SoundBuffer win_buffer;
	Sound  win_sound;

	SoundBuffer froggerTrucked_buffer;
	Sound froggerTrucked_sound;

	string name3;


public:
	level_3(int health, int score, string Name);
	void background();
	void set_bg();
	void start();
};