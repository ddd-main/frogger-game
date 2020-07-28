#include<iostream>
#include"level_1.h"
#include "level_3.h"
#include<ctime>
#include <SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Network.hpp>
#include "level_1.h"
#include "level_2.h"
#include<iostream>
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



level_3::level_3(int health, int score, string Name)
{

	window.create(VideoMode(799, 675), "FROGGER DEMO", Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	score_dis = score;
	healthcnt = health;
	name3 = Name;
	frogger_num = 0;
	memset(winsFound, false, sizeof winsFound);

	background();
	set_bg();
	start();

}

void level_3::background()
{
	if (!water.loadFromFile("water.png"))
		cout << "Failed loading from file \n" << endl;

	if (!forgger.loadFromFile("froggers.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood1.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood2.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood3.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood4.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood5.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood6.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood7.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood11.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood22.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood33.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood44.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!w1.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!w2.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!w3.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!crocodile.loadFromFile("crocodile.png"))
		cout << "Failed loading from file \n" << endl;

	if (!crocodile1.loadFromFile("crocodile.png"))
		cout << "Failed loading from file \n" << endl;

	if (!crocodile2.loadFromFile("crocodile.png"))
		cout << "Failed loading from file \n" << endl;

	if (!font.loadFromFile("Noteworthy-Bold.otf"))
		cout << "Failed loading from file \n" << endl;

	if (!timer_font.loadFromFile("Noteworthy-Bold.otf"))
		cout << "Failed loading from file \n" << endl;


	if (!score_font.loadFromFile("Noteworthy-Bold.otf"))
		cout << "Failed loading from file \n" << endl;

	if (!wood_r1.loadFromFile("crocodile.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood_r2.loadFromFile("crocodile.png"))
		cout << "Failed loading from file \n" << endl;

	if (!wood_r3.loadFromFile("crocodile.png"))
		cout << "Failed loading from file \n" << endl;

	if (!c3.loadFromFile("crocodile.png"))
		cout << "Failed loading from file \n" << endl;

	if (!sink_text.loadFromFile("water_drop.png"))
		cout << "Failed loading from file \n" << endl;

	if (!win.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!win1.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!win2.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!win3.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!win4.loadFromFile("objects.png"))
		cout << "Failed loading from file \n" << endl;

	if (!heart.loadFromFile("hearts.png"))
		cout << "Failed loading from file \n" << endl;

	if (!heart1.loadFromFile("hearts.png"))
		cout << "Failed loading from file \n" << endl;

	if (!heart2.loadFromFile("hearts.png"))
		cout << "Failed loading from file \n" << endl;

	//------ all music in level
	if (!timer_buffer.loadFromFile("TickingClock.wav"))
		cout << "Failed loading from file \n";

	if (!froggerSinking_buffer.loadFromFile("froggerDunked.ogg")) {
		cout << "Failed loading from file \n";
	}

	if (!win_buffer.loadFromFile("glass_ping.wav"))
		cout << "Failed loading from file \n";

	if (!froggerTrucked_buffer.loadFromFile("froggerTrucked.ogg"))
		cout << "Failed loading from file \n";

	//main music of the game
	if (!mainbuffer.loadFromFile("froggerLeche_Remix.ogg"))
		cout << "Failed loading from file \n";

	// music of frogger Hop
	if (!froggerHops_buffer.loadFromFile("froggerHop.ogg"))
		cout << "Failed loading from file \n";

	if (!bomb.loadFromFile("bomb.png")) {
		cout << "Failed loading from file \n";
	}

}


void level_3::set_bg()
{
	bg.setTexture(water);

	sink.setTexture(sink_text);

	///////////
	f.setTexture(forgger);
	f.setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
	f.setPosition(Vector2f(370.f, 600.f));
	for (int i = 0; i < 4; i++) {
		frogerrvec.push_back(f);
	}


	timer_text.setFont(timer_font);
	timer_time = seconds(60);
	timer_text.setPosition(0, 600);
	timer_text.setFillColor(Color::Blue);
	//////////
	win_sprite.setTexture(win);
	win_sprite.setTextureRect(IntRect(630, 170, 120, 120));
	win_sprite.setPosition(30, 10);
	wins.push_back(win_sprite);



	win_s1.setTexture(win1);
	win_s1.setTextureRect(IntRect(630, 170, 120, 120));
	win_s1.setPosition(230, 10);
	wins.push_back(win_s1);


	win_s2.setTexture(win2);
	win_s2.setTextureRect(IntRect(630, 170, 120, 120));
	win_s2.setPosition(430, 10);
	wins.push_back(win_s2);


	win_s3.setTexture(win3);
	win_s3.setTextureRect(IntRect(630, 170, 120, 120));
	win_s3.setPosition(630, 10);
	wins.push_back(win_s3);



	win_s4.setTexture(win4);
	win_s4.setTextureRect(IntRect(630, 170, 120, 120));
	win_s4.setPosition(350.f, 550.f);

	//////////health
	h.setTexture(heart1);
	h.setTextureRect(IntRect(0, 0, 40, 30));
	h.setPosition(Vector2f(140.f, 605.f));

	h1.setTexture(heart2);
	h1.setTextureRect(IntRect(0, 0, 40, 30));
	h1.setPosition(Vector2f(180.f, 605.f));

	h2.setTexture(heart2);
	h2.setTextureRect(IntRect(0, 0, 40, 30));
	h2.setPosition(Vector2f(220.f, 605.f));

	for (int i = 0; i < healthcnt; i++) {
		if (i == 0) {
			Heart.push_back(h);
		}
		if (i == 1) {
			Heart.push_back(h1);
		}
		if (i == 2) {
			Heart.push_back(h2);
		}
	}

	//////// down turtiless
	woo3.setTexture(wood3);
	woo3.setTextureRect(IntRect(60, 120, 160, 80));
	woo3.setPosition(Vector2f(600.f, 440.f));
	water_obj_l.push_back(woo3);
	water_obj_p.push_back(Vector2f(600.f, 282.f));


	woo1.setTexture(wood1);
	woo1.setTextureRect(IntRect(60, 120, 160, 80));
	woo1.setPosition(Vector2f(410.f, 440.f));
	water_obj_l.push_back(woo1);
	water_obj_p.push_back(Vector2f(410.f, 282.f));


	woo2.setTexture(wood2);
	woo2.setTextureRect(IntRect(60, 120, 160, 80));
	woo2.setPosition(Vector2f(300.f, 440.f));
	water_obj_l.push_back(woo2);
	water_obj_p.push_back(Vector2f(220.f, 282.f));


	woo5.setTexture(wood5);
	woo5.setTextureRect(IntRect(60, 120, 160, 80));
	woo5.setPosition(Vector2f(150.f, 440.f));
	water_obj_l.push_back(woo5);
	water_obj_p.push_back(Vector2f(100.f, 400.f));


	woo.setTexture(wood);
	woo.setTextureRect(IntRect(60, 120, 160, 80));
	woo.setPosition(Vector2f(5.f, 440.f));
	water_obj_l.push_back(woo);
	water_obj_p.push_back(Vector2f(5.f, 282.f));

	woo4.setTexture(wood4);
	woo4.setTextureRect(IntRect(60, 120, 160, 80));
	woo4.setPosition(Vector2f(-200.f, 440.f));
	water_obj_l.push_back(woo4);
	water_obj_p.push_back(Vector2f(-100.f, 282.f));

	///// long wood
	w1_sprite.setTexture(w1);
	w1_sprite.setTextureRect(IntRect(150, 370, 280, 75));
	w1_sprite.setPosition(Vector2f(-120.f, 525.f));
	water_obj_l.push_back(w1_sprite);
	water_obj_p.push_back(Vector2f(-100.f, 200.f));

	w2_sprite.setTexture(w2);
	w2_sprite.setTextureRect(IntRect(150, 370, 280, 75));
	w2_sprite.setPosition(Vector2f(-450.f, 525.f));
	water_obj_l.push_back(w2_sprite);
	water_obj_p.push_back(Vector2f(-100.f, 200.f));

	w3_sprite.setTexture(w3);
	w3_sprite.setTextureRect(IntRect(150, 370, 280, 75));
	w3_sprite.setPosition(Vector2f(-850.f, 525.f));
	water_obj_l.push_back(w3_sprite);
	water_obj_p.push_back(Vector2f(-100.f, 200.f));

	////////
	cro.setTexture(crocodile);
	cro.setTextureRect(IntRect(64.5, 200.69, 64.75, 220.75));
	cro.setScale(2.3, 1.5);
	cro.setPosition(Vector2f(799.f, 132.f));
	water_obj_r.push_back(cro);
	water_obj_p_right.push_back(Vector2f(600.f, 60.f));

	cro1.setTexture(crocodile1);
	cro1.setTextureRect(IntRect(64.5, 200.69, 64.75, 220.75));
	cro1.setScale(2.3, 1.5);
	cro1.setPosition(Vector2f(500.f, 132.f));
	water_obj_r.push_back(cro1);
	water_obj_p_right.push_back(Vector2f(410.f, 60.f));

	cro2.setTexture(crocodile2);
	cro2.setTextureRect(IntRect(64.5, 200.69, 64.75, 220.75));
	cro2.setScale(2.3, 1.5);
	cro2.setPosition(Vector2f(250.f, 132.f));
	water_obj_r.push_back(cro2);
	water_obj_p_right.push_back(Vector2f(220.f, 60.f));

	c_spr3.setTexture(c3);
	c_spr3.setTextureRect(IntRect(64.5, 200.69, 64.75, 220.75));
	c_spr3.setScale(2.3, 1.5);
	c_spr3.setPosition(Vector2f(50.f, 132.f));
	water_obj_r.push_back(c_spr3);
	water_obj_p_right.push_back(Vector2f(220.f, 400.f));

	/////////////

	////down cro
	cro.setTexture(crocodile);
	cro.setTextureRect(IntRect(64.5, 200.69, 64.75, 220.75));
	cro.setScale(2.3, 1.5);
	cro.setPosition(Vector2f(799.f, 358.f));
	water_obj_r.push_back(cro);
	water_obj_p_right.push_back(Vector2f(600.f, 400.f));

	cro1.setTexture(crocodile1);
	cro1.setTextureRect(IntRect(64.5, 200.69, 64.75, 220.75));
	cro1.setScale(2.3, 1.5);
	cro1.setPosition(Vector2f(500.f, 358.f));
	water_obj_r.push_back(cro1);
	water_obj_p_right.push_back(Vector2f(410.f, 400.f));

	cro2.setTexture(crocodile2);
	cro2.setTextureRect(IntRect(64.5, 200.69, 64.75, 220.75));
	cro2.setScale(2.3, 1.5);
	cro2.setPosition(Vector2f(250.f, 358.f));
	water_obj_r.push_back(cro2);
	water_obj_p_right.push_back(Vector2f(220.f, 400.f));

	c_spr3.setTexture(c3);
	c_spr3.setTextureRect(IntRect(64.5, 200.69, 64.75, 220.75));
	c_spr3.setScale(2.3, 1.5);
	c_spr3.setPosition(Vector2f(50.f, 358.f));
	water_obj_r.push_back(c_spr3);
	water_obj_p_right.push_back(Vector2f(220.f, 400.f));
	////////////
	woo11.setTexture(wood11);
	woo11.setTextureRect(IntRect(520, 290, 200, 75));
	woo11.setPosition(Vector2f(20.f, 277.f));
	water_obj_l.push_back(woo11);
	water_obj_p.push_back(Vector2f(552.f, 210.f));

	woo22.setTexture(wood22);
	woo22.setTextureRect(IntRect(520, 290, 200, 75));
	woo22.setPosition(Vector2f(270.f, 277.f));
	water_obj_l.push_back(woo22);
	water_obj_p.push_back(Vector2f(250.f, 210.f));

	woo33.setTexture(wood33);
	woo33.setTextureRect(IntRect(520, 290, 200, 75));
	woo33.setPosition(Vector2f(520.f, 277.f));
	water_obj_l.push_back(woo33);
	water_obj_p.push_back(Vector2f(850.f, 210.f));

	woo44.setTexture(wood44);
	woo44.setTextureRect(IntRect(520, 290, 200, 75));
	woo44.setPosition(Vector2f(800.f, 277.f));
	water_obj_l.push_back(woo44);
	water_obj_p.push_back(Vector2f(850.f, 210.f));
	/////////up turtilres
	woo3.setTexture(wood3);
	woo3.setTextureRect(IntRect(60, 120, 160, 80));
	woo3.setPosition(Vector2f(260.f, 213.f));
	water_obj_l.push_back(woo3);
	water_obj_p.push_back(Vector2f(600.f, 145.f));

	woo1.setTexture(wood1);
	woo1.setTextureRect(IntRect(60, 120, 160, 80));
	woo1.setPosition(Vector2f(20.f, 213.f));
	water_obj_l.push_back(woo1);
	water_obj_p.push_back(Vector2f(410.f, 145.f));

	woo2.setTexture(wood2);
	woo2.setTextureRect(IntRect(60, 120, 160, 80));
	woo2.setPosition(Vector2f(140.f, 213.f));
	water_obj_l.push_back(woo2);
	water_obj_p.push_back(Vector2f(220.f, 145.f));

	woo5.setTexture(wood5);
	woo5.setTextureRect(IntRect(60, 120, 160, 80));
	woo5.setPosition(Vector2f(500.f, 213.f));
	water_obj_l.push_back(woo5);
	water_obj_p.push_back(Vector2f(100.f, 145.f));

	woo.setTexture(wood);
	woo.setTextureRect(IntRect(60, 120, 160, 80));
	woo.setPosition(Vector2f(980.f, 213.f));
	water_obj_l.push_back(woo);
	water_obj_p.push_back(Vector2f(5.f, 145.f));

	woo4.setTexture(wood4);
	woo4.setTextureRect(IntRect(60, 120, 160, 80));
	woo4.setPosition(Vector2f(380.f, 213.f));
	water_obj_l.push_back(woo4);
	water_obj_p.push_back(Vector2f(-100.f, 145.f));

	woo6.setTexture(wood6);
	woo6.setTextureRect(IntRect(60, 120, 160, 80));
	woo6.setPosition(Vector2f(635.f, 213.f));
	water_obj_l.push_back(woo6);
	water_obj_p.push_back(Vector2f(-100.f, 145.f));

	woo7.setTexture(wood7);
	woo7.setTextureRect(IntRect(60, 120, 160, 80));
	woo7.setPosition(Vector2f(745.f, 213.f));
	water_obj_l.push_back(woo7);
	water_obj_p.push_back(Vector2f(-100.f, 145.f));
	/////////////

	bomb_sprite.setTexture(bomb);


	score_text.setFont(score_font);
	score_text.setCharacterSize(25);
	score_text.setFillColor(Color::Blue);
	score_text.setPosition(550, 640);

	//music
	mainsound.setBuffer(mainbuffer);
	mainsound.setVolume(30.f);
	mainsound.play();
	mainsound.setLoop(true);

	timer_sound.setBuffer(timer_buffer);

	froggerTrucked_sound.setBuffer(froggerTrucked_buffer);

	win_sound.setBuffer(win_buffer);

	froggerHop_sound.setBuffer(froggerHops_buffer);

	froggerSinking_sound.setBuffer(froggerSinking_buffer);


}

void level_3::start()
{
	while (window.isOpen()) {

		//score
		count_score = to_string(countscore.size() + score_dis);
		score_text.setString("score: " + count_score);


		//timer
		elabsed = timer_clock.getElapsedTime();
		int timer = (timer_time - elabsed).asSeconds();
		timer_string = to_string(timer);
		timer_text.setString("timer: " + timer_string);


		if (timer == 10) {
			timer_sound.play();
			timer_sound.setLoop(true);
		}

		if (timer == 0) {
			window.close();
			mainsound.stop();
			timer_sound.stop();
			top5 top(name3, score_dis);
		}


		//left
		if (frogerrvec[frogger_num].getPosition().x < 0.f) {
			froggerTrucked_sound.play();
			for (int i = 5; i >= 3; i--) {
				bomb_sprite.setTextureRect(IntRect(100 * i, 0, 100, 100));
				bomb_sprite.setPosition(Vector2f(frogerrvec[frogger_num].getPosition().x, frogerrvec[frogger_num].getPosition().y - 50));
				window.draw(bomb_sprite);
				window.display();
			}

			frogerrvec[frogger_num].setPosition(Vector2f(350.f, 600.f));
			frogerrvec[frogger_num].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
			healthcnt--;
			Heart.pop_back();
			window.draw(frogerrvec[frogger_num]);
			window.display();
			score_dis += countscore.size();
			countscore.clear();
			if (!healthcnt) {
				window.close();
				mainsound.stop();
				timer_sound.stop();
				top5 top(name3, score_dis);
			}
		}

		//top
		if (frogerrvec[frogger_num].getPosition().y < 0.f)
		{
			froggerTrucked_sound.play();
			for (int i = 5; i >= 3; i--) {
				bomb_sprite.setTextureRect(IntRect(100 * i, 0, 100, 100));
				bomb_sprite.setPosition(Vector2f(frogerrvec[frogger_num].getPosition().x, frogerrvec[frogger_num].getPosition().y - 20));
				window.draw(bomb_sprite);
				window.display();
			}

			frogerrvec[frogger_num].setPosition(Vector2f(350.f, 600.f));
			frogerrvec[frogger_num].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
			healthcnt--;
			Heart.pop_back();
			window.draw(frogerrvec[frogger_num]);
			window.display();
			score_dis += countscore.size();
			countscore.clear();
			if (!healthcnt) {
				window.close();
				mainsound.stop();
				timer_sound.stop();
				top5 top(name3, score_dis);
			}
		}

		//right
		if (frogerrvec[frogger_num].getPosition().x + frogerrvec[frogger_num].getGlobalBounds().width > 799)
		{
			froggerTrucked_sound.play();
			for (int i = 5; i >= 3; i--) {
				bomb_sprite.setTextureRect(IntRect(100 * i, 0, 100, 100));
				bomb_sprite.setPosition(Vector2f(frogerrvec[frogger_num].getPosition().x, frogerrvec[frogger_num].getPosition().y - 50));
				window.draw(bomb_sprite);
				window.display();
			}
			frogerrvec[frogger_num].setPosition(Vector2f(350.f, 600.f));
			frogerrvec[frogger_num].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
			healthcnt--;
			Heart.pop_back();
			window.draw(frogerrvec[frogger_num]);
			window.display();
			score_dis += countscore.size();
			countscore.clear();
			if (!healthcnt) {
				window.close();
				mainsound.stop();
				timer_sound.stop();
				top5 top(name3, score_dis);
			}
		}

		//down
		if (frogerrvec[frogger_num].getPosition().y + frogerrvec[frogger_num].getGlobalBounds().height > 675)
		{
			froggerTrucked_sound.play();
			for (int i = 5; i >= 3; i--) {
				bomb_sprite.setTextureRect(IntRect(100 * i, 0, 100, 100));
				bomb_sprite.setPosition(Vector2f(frogerrvec[frogger_num].getPosition().x, frogerrvec[frogger_num].getPosition().y - 150));
				window.draw(bomb_sprite);
				window.display();
			}

			frogerrvec[frogger_num].setPosition(Vector2f(350.f, 600.f));
			frogerrvec[frogger_num].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
			healthcnt--;
			Heart.pop_back();
			window.draw(frogerrvec[frogger_num]);
			window.display();
			score_dis += countscore.size();
			countscore.clear();
			if (!healthcnt) {
				window.close();
				mainsound.stop();
				timer_sound.stop();
				top5 top(name3, score_dis);
			}
		}




		while (window.pollEvent(event)) {
			if (event.type == event.Closed)  window.close();

			if (event.type == event.KeyPressed) {
				if (event.key.code == Keyboard::Up) {
					frogerrvec[frogger_num].move(Vector2f(0, -75));
					frogerrvec[frogger_num].setTextureRect(IntRect(50 * 2, 50 * 3, 50, 40));
					window.draw(frogerrvec[frogger_num]);
					window.display();
					frogerrvec[frogger_num].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));

					/// to insert position of frogger up Hop in set to display score
					countscore.insert(frogerrvec[frogger_num].getPosition().y);
					froggerHop_sound.play();
				}

				else if (event.key.code == Keyboard::Down) {
					frogerrvec[frogger_num].move(Vector2f(0, 75));
					frogerrvec[frogger_num].setTextureRect(IntRect(50 * 2, 50 * 0, 50, 40));
					window.draw(frogerrvec[frogger_num]);
					window.display();
					frogerrvec[frogger_num].setTextureRect(IntRect(50 * 1, 0, 50, 40));
					froggerHop_sound.play();
				}

				else if (event.key.code == Keyboard::Left) {
					frogerrvec[frogger_num].move(Vector2f(-75, 0));
					frogerrvec[frogger_num].setTextureRect(IntRect(50 * 2, 50 * 1, 50, 40));
					window.draw(frogerrvec[frogger_num]);
					window.display();
					frogerrvec[frogger_num].setTextureRect(IntRect((50 * 1) + 3, 50 * 1, 50, 40));
					froggerHop_sound.play();
				}

				else if (event.key.code == Keyboard::Right) {
					frogerrvec[frogger_num].move(Vector2f(75, 0));
					frogerrvec[frogger_num].setTextureRect(IntRect(50 * 2, 50 * 2, 50, 40));
					window.draw(frogerrvec[frogger_num]);
					window.display();
					frogerrvec[frogger_num].setTextureRect(IntRect((50 * 1) + 5, 50 * 2, 50, 40));
					froggerHop_sound.play();
				}

				else if (event.key.code == Keyboard::Escape) { window.close(); }
			}
		}


		window.clear();
		window.draw(bg);
		window.draw(p);
		window.draw(win_s4);

		for (auto i : water_obj_l)
			window.draw(i);

		for (auto i : water_obj_r)
			window.draw(i);
		for (auto i : wins)
			window.draw(i);
		for (auto i : Heart)
			window.draw(i);

		for (int i = 0; i <= frogger_num; i++) {
			window.draw(frogerrvec[i]);
		}

		window.draw(timer_text);
		window.draw(score_text);

		window.display();


		frogger_f = false;

		//objects move and frogger sinking handel!!

		for (int i = 0; i < water_obj_l.size(); i++) {
			if (Collision::PixelPerfectTest(water_obj_l[i], frogerrvec[frogger_num])) {
				water_obj_l[i].move(2.f, 0.f);
				frogerrvec[frogger_num].move(2.f, 0.f);
				frogger_f = true;
			}

			else {
				water_obj_l[i].move(2.f, 0.f);
			}

			if (water_obj_l[i].getPosition().x > window.getSize().x + 70) {
				water_obj_l[i].setPosition(-280.f, water_obj_l[i].getPosition().y);
			}
		}


		for (int i = 0; i < water_obj_r.size(); i++) {
			if (Collision::PixelPerfectTest(water_obj_r[i], frogerrvec[frogger_num])) {
				water_obj_r[i].move(-2.f, 0.f);
				frogger_f = true;
				frogerrvec[frogger_num].move(-2.f, 0.f);
			}
			else {
				water_obj_r[i].move(-2.f, 0.f);
			}

			if (water_obj_r[i].getPosition().x < 0 - 165.f) {
				water_obj_r[i].setPosition(window.getSize().x + 80.f, water_obj_r[i].getPosition().y);
			}

		}



		for (int i = 0; i < wins.size(); i++) {
			if (!winsFound[i]) {
				if (Collision::PixelPerfectTest(wins[i], frogerrvec[frogger_num])) {
					score_dis += countscore.size();
					countscore.clear();

					win_sound.play();
					win_sound.setVolume(30.f);

					frogger_num++;
					winsFound[i] = true;
					if (frogger_num == 4) {

						frogger_num--;
						window.close();
						mainsound.stop();
						timer_sound.stop();
						top5 top(name3, score_dis);
						break;
					}
					window.draw(frogerrvec[frogger_num]);
					window.display();
					break;
				}
			}

			else {
				if (Collision::PixelPerfectTest(wins[i], frogerrvec[frogger_num])) {

					froggerTrucked_sound.play();
					for (int i = 5; i >= 3; i--) {
						bomb_sprite.setTextureRect(IntRect(100 * i, 0, 100, 100));
						bomb_sprite.setPosition(Vector2f(frogerrvec[frogger_num].getPosition().x, frogerrvec[frogger_num].getPosition().y - 20));
						window.draw(bomb_sprite);
						window.display();
					}

					Heart.pop_back();
					frogerrvec[frogger_num].setPosition(Vector2f(300.f, 630.f));
					frogerrvec[frogger_num].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
					window.draw(frogerrvec[frogger_num]);
					window.display();
					healthcnt--;
					if (!healthcnt) {

						window.close();
						mainsound.stop();
						timer_sound.stop();
						top5 top(name3, score_dis);
					}
				}


			}
		}



		if (!frogger_f) {

			if (Collision::PixelPerfectTest(frogerrvec[frogger_num], win_s4))
				continue;

			score_dis += countscore.size();
			countscore.clear();

			froggerSinking_sound.play();
			for (int i = 0; i < 3; i++) {
				sink.setTextureRect(IntRect(200, 0, 150, 120));
				sink.setPosition(Vector2f(frogerrvec[frogger_num].getPosition().x, frogerrvec[frogger_num].getPosition().y - 60));
				window.draw(sink);
				window.display();
			}

			frogerrvec[frogger_num].setPosition(Vector2f(350.f, 600.f));
			frogerrvec[frogger_num].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
			healthcnt--;
			if (!healthcnt) {
				window.close();
				mainsound.stop();
				timer_sound.stop();
				top5 top(name3, score_dis);
			}
			Heart.pop_back();
			window.draw(frogerrvec[frogger_num]);
			window.display();
		}


	}
}


