#include<iostream>
#include "level_1.h"
#include "level_2.h"
#include "level_3.h"
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

// constructor
level_2::level_2(void)
{
}

level_2::level_2(int health, int score, string Name) {
	window.create(VideoMode(799, 675), "FROGGER DEMO", Style::Close);
	score_dis = score;
	healthcnt = health;
	name2 = Name;
	froggernm = 0;

	memset(winsFound, false, sizeof winsFound);
	froggerfound = false;
	//Frame rate.
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);


	// calling functions 
	load_from_file();
	set_texture();
	playing();
}



// this function to load tectures from folder
void level_2::load_from_file()
{

	// loading objects in water from folder
	if (!RoadPH.loadFromFile("background_lvl2.png")) {
		cout << "Failed loading from file \n";
	}
	if (!ForggerPH.loadFromFile("froggers.png")) {
		cout << "Failed loading from file \n";
	}

	//start position of frogger place
	if (!start_place.loadFromFile("start.png")) {
		cout << "Failed loading from file \n";
	}

	//------------------------------------------------------------------------
	if (!ccar1PH.loadFromFile("bike.png")) {
		cout << "Failed loading from file \n";
	}
	if (!ccar12PH.loadFromFile("car flipped.png")) {
		cout << "Failed loading from file \n";
	}
	if (!ccar13PH.loadFromFile("car flipped.png")) {
		cout << "Failed loading from file \n";
	}
	if (!ccar14PH.loadFromFile("bike.png")) {
		cout << "Failed loading from file \n";
	}
	if (!ccar21PH.loadFromFile("car.png")) {
		cout << "Failed loading from file \n";
	}
	if (!ccar22PH.loadFromFile("car.png")) {
		cout << "Failed loading from file \n";
	}
	if (!ccar23PH.loadFromFile("car.png")) {
		cout << "Failed loading from file \n";
	}

	if (!ccar31PH.loadFromFile("bike.png")) {
		cout << "Failed loading from file \n";
	}
	if (!ccar32PH.loadFromFile("car flipped.png")) {
		cout << "Failed loading from file \n";
	}
	if (!ccar33PH.loadFromFile("car flipped.png")) {
		cout << "Failed loading from file \n";
	}
	//-------------------------------------------------------------------------------------------------
	// loading cars in road from folder
	if (!car1PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car12PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car21PH.loadFromFile("cars.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car22PH.loadFromFile("cars.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car31PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car32PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car41PH.loadFromFile("cars1.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car42PH.loadFromFile("cars1.png")) {
		cout << "Failed loading from file \n";
	}

	// win palce
	if (!Winplace1.loadFromFile("winplace.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Winplace2.loadFromFile("winplace.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Winplace3.loadFromFile("winplace.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Winplace4.loadFromFile("winplace.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Winplace5.loadFromFile("winplace.png")) {
		cout << "Failed loading from file \n";
	}

	// hearts
	if (!heart1.loadFromFile("hearts.png")) {
		cout << "Failed loading from file \n";
	}
	if (!heart2.loadFromFile("hearts.png")) {
		cout << "Failed loading from file \n";
	}
	if (!heart3.loadFromFile("hearts.png")) {
		cout << "Failed loading from file \n";
	}

	// font el score
	if (!score_font.loadFromFile("Noteworthy-Bold.otf")) {
		cout << "Failed loading from file \n";
	}

	// font el timer
	if (!timer_font.loadFromFile("Noteworthy-Bold.otf")) {
		cout << "Failed loading from file \n";
	}


	//main music of the game
	if (!mainbuffer.loadFromFile("froggerLeche_Remix.ogg")) {
		cout << "Failed loading from file \n";
	}
	// music of frogger Hop
	if (!froggerHops_buffer.loadFromFile("froggerHop.ogg")) {
		cout << "Failed loading from file \n";
	}
	//music of frogger Trucked
	if (!froggerTrucked_buffer.loadFromFile("froggerTrucked.ogg")) {
		cout << "Failed loading from file \n";
	}

	//music timer ends (last 10 seconds)
	if (!timer_end_buffer.loadFromFile("TickingClock.wav")) {
		cout << "Failed loading from file \n";
	}
	//music frogger reach wins
	if (!win_buffer.loadFromFile("glass_ping.wav")) {
		cout << "Failed loading from file \n";
	}


	//bomb in case of coliision with cars
	if (!bomb.loadFromFile("bomb.png")) {
		cout << "Failed loading from file \n";
	}

}


void level_2::set_texture()
{
	//background
	backgroundSprite.setTexture(RoadPH);

	//frogger
	froggerSprite.setTexture(ForggerPH);
	froggerSprite.setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
	froggerSprite.setPosition(Vector2f(345.f, 615.f));
	for (int i = 0; i < 5; i++) {
		Froggers.push_back(froggerSprite);
	}

	// start position of frogger place
	start_place_sprite.setTexture(start_place);
	start_place_sprite.setPosition(280, 530);

	//---------------------------------------------------------------------
	// objects in road2
	ccar1Sprite.setTexture(ccar1PH);

	ccar1Sprite.setTextureRect(IntRect(6, 55, 100, 75));
	ccar1Sprite.setPosition(Vector2f(552.f, 50.f));
	objectsRoad2Left.push_back(ccar1Sprite);
	positionsRoad2Left.push_back(Vector2f(552.f, 50.f));

	ccar12Sprite.setTexture(ccar12PH);
	ccar12Sprite.setTextureRect(IntRect(520, 180, 230, 100));
	ccar12Sprite.setPosition(Vector2f(250.f, 30.f));
	objectsRoad2Left.push_back(ccar12Sprite);
	positionsRoad2Left.push_back(Vector2f(250.f, 30.f));

	ccar13Sprite.setTexture(ccar13PH);
	ccar13Sprite.setTextureRect(IntRect(7, 0, 200, 75));
	ccar13Sprite.setPosition(Vector2f(750.f, 50.f));
	objectsRoad2Left.push_back(ccar13Sprite);
	positionsRoad2Left.push_back(Vector2f(750.f, 50.f));

	ccar14Sprite.setTexture(ccar14PH);
	ccar14Sprite.setTextureRect(IntRect(6, 55, 100, 75));
	ccar14Sprite.setPosition(Vector2f(1100.f, 50.f));
	objectsRoad2Left.push_back(ccar14Sprite);
	positionsRoad2Left.push_back(Vector2f(1100.f, 50.f));

	ccar2Sprite.setTexture(ccar21PH);
	ccar2Sprite.setTextureRect(IntRect(5, 0, 80, 80));
	ccar2Sprite.setPosition(Vector2f(0.f, 110.f));
	objectsRoad2Right.push_back(ccar2Sprite);
	positionsRoad2Right.push_back(Vector2f(-100.f, 110.f));

	ccar22Sprite.setTexture(ccar22PH);
	ccar22Sprite.setTextureRect(IntRect(350, 100, 210, 80));
	ccar22Sprite.setPosition(Vector2f(-500.f, 130.f));
	objectsRoad2Right.push_back(ccar22Sprite);
	positionsRoad2Right.push_back(Vector2f(-400.f, 130.f));

	ccar23Sprite.setTexture(ccar23PH);
	ccar23Sprite.setTextureRect(IntRect(580, 80, 300, 100));
	ccar23Sprite.setPosition(Vector2f(-800.f, 110.f));
	objectsRoad2Right.push_back(ccar23Sprite);
	positionsRoad2Right.push_back(Vector2f(-300.f, 110.f));


	ccar31Sprite.setTexture(ccar31PH);
	ccar31Sprite.setTextureRect(IntRect(6, 55, 100, 75));
	ccar31Sprite.setPosition(Vector2f(750.f, 180.f));
	objectsRoad2Left.push_back(ccar31Sprite);
	positionsRoad2Left.push_back(Vector2f(750.f, 180.f));

	ccar32Sprite.setTexture(ccar32PH);
	ccar32Sprite.setTextureRect(IntRect(520, 180, 230, 100));
	ccar32Sprite.setPosition(Vector2f(250.f, 165.f));
	objectsRoad2Left.push_back(ccar32Sprite);
	positionsRoad2Left.push_back(Vector2f(250.f, 165.f));

	ccar33Sprite.setTexture(ccar33PH);
	ccar33Sprite.setTextureRect(IntRect(7, 0, 200, 75));
	ccar33Sprite.setPosition(Vector2f(-100.f, 180.f));
	objectsRoad2Left.push_back(ccar33Sprite);
	positionsRoad2Left.push_back(Vector2f(-100.f, 180.f));


	//---------------------------------------------------------------------------------------------------
	//cars in road
	car1Spritesheet.setTexture(car1PH);
	car1Spritesheet.setTextureRect(IntRect(120, 440, 215, 70));
	car1Spritesheet.setPosition(Vector2f(100.f, 340.f));
	objectsRoadRight.push_back(car1Spritesheet);
	positionsRoadRight.push_back(Vector2f(100.f, 340.f));


	car11Spritesheet.setTexture(car12PH);
	car11Spritesheet.setTextureRect(IntRect(120, 440, 215, 70));
	car11Spritesheet.setPosition(Vector2f(-300.f, 340.f));
	objectsRoadRight.push_back(car11Spritesheet);
	positionsRoadRight.push_back(Vector2f(-300.f, 340.f));

	car2Spritesheet.setTexture(car21PH);
	car2Spritesheet.setTextureRect(IntRect(70, 80, 65, 40));
	car2Spritesheet.setPosition(Vector2f(400.f, 420.f));
	objectsRoadLeft.push_back(car2Spritesheet);
	positionsRoadLeft.push_back(Vector2f(400.f, 420.f));

	car22Spritesheet.setTexture(car22PH);
	car22Spritesheet.setTextureRect(IntRect(70, 80, 65, 40));
	car22Spritesheet.setPosition(Vector2f(180.f, 420.f));
	objectsRoadLeft.push_back(car22Spritesheet);
	positionsRoadLeft.push_back(Vector2f(180.f, 420.f));

	car3Spritesheet.setTexture(car31PH);
	car3Spritesheet.setTextureRect(IntRect(280, 520, 160, 70));
	car3Spritesheet.setPosition(Vector2f(-160.f, 465.f));
	objectsRoadRight.push_back(car3Spritesheet);
	positionsRoadRight.push_back(Vector2f(-160.f, 465.f));

	car33Spritesheet.setTexture(car32PH);
	car33Spritesheet.setTextureRect(IntRect(280, 520, 160, 70));
	car33Spritesheet.setPosition(Vector2f(-450.f, 465.f));
	objectsRoadRight.push_back(car33Spritesheet);
	positionsRoadRight.push_back(Vector2f(-450.f, 465.f));

	car4Spritesheet.setTexture(car41PH);
	car4Spritesheet.setTextureRect(IntRect(5, 75, 70, 60));
	car4Spritesheet.setPosition(Vector2f(554.f, 525.f));
	objectsRoadLeft.push_back(car4Spritesheet);
	positionsRoadLeft.push_back(Vector2f(554.f, 525.f));

	car44Spritesheet.setTexture(car42PH);
	car44Spritesheet.setTextureRect(IntRect(5, 75, 70, 60));
	car44Spritesheet.setPosition(Vector2f(280.f, 525.f));
	objectsRoadLeft.push_back(car44Spritesheet);
	positionsRoadLeft.push_back(Vector2f(280.f, 525.f));

	//---------------------------------------------------------------------
	// win place 
	Winplacesprite1.setTexture(Winplace1);
	Winplacesprite1.setTextureRect(IntRect(10, 10, 100, 90));
	Winplacesprite1.setPosition(650, -40);
	Wins.push_back(Winplacesprite1);


	Winplacesprite2.setTexture(Winplace2);
	Winplacesprite2.setTextureRect(IntRect(10, 10, 100, 90));
	Winplacesprite2.setPosition(490, -40);
	Wins.push_back(Winplacesprite2);

	Winplacesprite3.setTexture(Winplace3);
	Winplacesprite3.setTextureRect(IntRect(10, 10, 100, 90));
	Winplacesprite3.setPosition(340, -40);
	Wins.push_back(Winplacesprite3);

	Winplacesprite4.setTexture(Winplace4);
	Winplacesprite4.setTextureRect(IntRect(10, 10, 100, 90));
	Winplacesprite4.setPosition(180, -40);
	Wins.push_back(Winplacesprite4);

	Winplacesprite5.setTexture(Winplace5);
	Winplacesprite5.setTextureRect(IntRect(10, 10, 100, 90));
	Winplacesprite5.setPosition(15, -40);
	Wins.push_back(Winplacesprite5);
	//----------------------------------------------------------------------------------------------

	// hearts
	heartsprite1.setTexture(heart1);
	heartsprite1.setTextureRect(IntRect(0, 0, 40, 30));
	heartsprite1.setPosition(Vector2f(8.f, 605.f));

	heartsprite2.setTexture(heart2);
	heartsprite2.setTextureRect(IntRect(0, 0, 40, 30));
	heartsprite2.setPosition(Vector2f(50.f, 605.f));

	heartsprite3.setTexture(heart3);
	heartsprite3.setTextureRect(IntRect(0, 0, 40, 30));
	heartsprite3.setPosition(Vector2f(92.f, 605.f));

	for (int i = 0; i < healthcnt; i++) {
		if (i == 0) {
			Hearts.push_back(heartsprite1);
		}
		if (i == 1) {
			Hearts.push_back(heartsprite2);
		}
		if (i == 2) {
			Hearts.push_back(heartsprite3);
		}
	}
	// font bta3 el score
	score_text.setFont(score_font);
	score_text.setCharacterSize(25);
	score_text.setFillColor(Color::Blue);
	score_text.setPosition(550, 640);


	//font el timer
	timer_text.setFont(timer_font);
	timer_time = seconds(120);
	timer_text.setPosition(15, 640);
	timer_text.setFillColor(Color::Blue);




	// audio of the game
	mainsound.setBuffer(mainbuffer);
	mainsound.setVolume(30.f);
	mainsound.play();
	mainsound.setLoop(true);

	//audio of frogger Hop
	froggerHop_sound.setBuffer(froggerHops_buffer);

	//audio of frogger trucked
	froggerTrucked_sound.setBuffer(froggerTrucked_buffer);

	//audio of timer ends
	timer_end_sound.setBuffer(timer_end_buffer);

	//audio of frooger reach wins
	win_sound.setBuffer(win_buffer);


	//trucked with cars
	bombSprite.setTexture(bomb);


}


void level_2::playing()
{

	while (window.isOpen()) {

		//convert int to string bta3t el score
		count_score = to_string(countscore.size() + score_dis);
		score_text.setString("score: " + count_score);



		//Timer
		elabsed = timer_clock.getElapsedTime();
		int timer = (timer_time - elabsed).asSeconds();
		timer_string = to_string(timer);
		timer_text.setString("timer: " + timer_string);


		//audio clock (last 10 seconds)
		if (timer == 10) {
			timer_end_sound.play();
			timer_end_sound.setLoop(true);
		}

		// time elapsed case of ZERO
		if (!timer) {
			window.close();
			mainsound.stop();
			timer_end_sound.stop();
			//----
			top5 top(name2, score_dis);
			//-----

		}


		// window dimensions to kill frogger
		if (Froggers[froggernm].getPosition().x < 0 || Froggers[froggernm].getPosition().x >= 780 || Froggers[froggernm].getPosition().y >= 660 || Froggers[froggernm].getPosition().y <= -30) {
			froggerTrucked_sound.play();
			if (Froggers[froggernm].getPosition().x < 0) {
				for (int i = 5; i >= 3; i--) {
					bombSprite.setTextureRect(IntRect(100 * i, 0, 100, 100));
					bombSprite.setPosition(Vector2f(Froggers[froggernm].getPosition().x, Froggers[froggernm].getPosition().y - 50));
					window.draw(bombSprite);
					window.display();
				}
			}

			else if (Froggers[froggernm].getPosition().x >= 780) {
				for (int i = 5; i >= 3; i--) {
					bombSprite.setTextureRect(IntRect(100 * i, 0, 100, 100));
					bombSprite.setPosition(Vector2f(Froggers[froggernm].getPosition().x - 80, Froggers[froggernm].getPosition().y - 50));
					window.draw(bombSprite);
					window.display();
				}
			}

			else if (Froggers[froggernm].getPosition().y >= 660) {
				for (int i = 5; i >= 3; i--) {
					bombSprite.setTextureRect(IntRect(100 * i, 0, 100, 100));
					bombSprite.setPosition(Vector2f(Froggers[froggernm].getPosition().x, Froggers[froggernm].getPosition().y - 150));
					window.draw(bombSprite);
					window.display();
				}
			}


			Hearts.pop_back();
			Froggers[froggernm].setPosition(Vector2f(345.f, 615.f));
			Froggers[froggernm].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
			window.draw(Froggers[froggernm]);
			window.display();
			healthcnt--;
			score_dis += countscore.size();
			countscore.clear();
			if (!healthcnt) {
				window.close();
				mainsound.stop();
				timer_end_sound.stop();
				//----
				top5 top(name2, score_dis);
				//-----
			}


		}

		// to change position of frogger
		while (window.pollEvent(event)) {
			bool pass = true;

			if (event.type == Event::Closed) { window.close(); }

			if (Froggers[froggernm].getPosition().x >= 0 && Froggers[froggernm].getPosition().x <= 452 && Froggers[froggernm].getPosition().y >= 220 && Froggers[froggernm].getPosition().y <= 339)
				pass = false;

			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Right) {
					Froggers[froggernm].move(Vector2f(50, 0));
					Froggers[froggernm].setTextureRect(IntRect(50 * 2, 50 * 2, 50, 40));
					window.draw(Froggers[froggernm]);
					window.display();
					Froggers[froggernm].setTextureRect(IntRect((50 * 1) + 5, 50 * 2, 50, 40));
					froggerHop_sound.play();
				}

				else if (event.key.code == Keyboard::Left) {
					if (pass) {
						Froggers[froggernm].move(Vector2f(-50, 0));
						Froggers[froggernm].setTextureRect(IntRect(50 * 2, 50 * 1, 50, 40));
						window.draw(Froggers[froggernm]);
						window.display();
						Froggers[froggernm].setTextureRect(IntRect((50 * 1) + 3, 50 * 1, 50, 40));
						froggerHop_sound.play();
					}
				}
				else if (event.key.code == Keyboard::Up) {
					if (pass) {
						Froggers[froggernm].move(Vector2f(0, -50));
						Froggers[froggernm].setTextureRect(IntRect(50 * 2, 50 * 3, 50, 40));
						window.draw(Froggers[froggernm]);
						window.display();
						Froggers[froggernm].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
						froggerHop_sound.play();

						// to insert position of frogger up Hop in set to display score
						countscore.insert(Froggers[froggernm].getPosition().y);

					}
				}

				else if (event.key.code == Keyboard::Down) {
					if (pass) {
						Froggers[froggernm].move(Vector2f(0, 50));
						Froggers[froggernm].setTextureRect(IntRect(50 * 2, 50 * 0, 50, 40));
						window.draw(Froggers[froggernm]);
						window.display();
						Froggers[froggernm].setTextureRect(IntRect(50 * 1, 0, 50, 40));
						froggerHop_sound.play();
					}
				}

				else if (event.key.code == Keyboard::Escape) {
					window.close();
					mainsound.stop();
					timer_end_sound.stop();
					//----
					top5 top(name2, score_dis);
					//-----
				}

			}


		}

		window.clear();
		window.draw(backgroundSprite);
		window.draw(start_place_sprite);

		for (auto i : objectsRoad2Right) {
			window.draw(i);
		}
		for (auto i : objectsRoad2Left) {
			window.draw(i);

		}
		for (auto i : objectsRoadRight) {
			window.draw(i);
		}
		for (auto i : objectsRoadLeft) {
			window.draw(i);
		}
		for (auto i : Wins) {
			window.draw(i);
		}
		for (auto i : Hearts) {
			window.draw(i);
		}

		for (int i = 0; i <= froggernm; i++) {
			window.draw(Froggers[i]);
		}

		//score draw
		window.draw(score_text);
		// timer draw
		window.draw(timer_text);

		window.display();





		froggerfound = false;
		//-----------------------------------------------------------------------------------------------------------------

		for (int i = 0; i < objectsRoad2Right.size(); i++) {
			if (Collision::PixelPerfectTest(objectsRoad2Right[i], Froggers[froggernm])) {
				score_dis += countscore.size();
				countscore.clear();
				froggerTrucked_sound.play();

				for (int i = 5; i >= 3; i--) {
					bombSprite.setTextureRect(IntRect(100 * i, 0, 100, 100));
					bombSprite.setPosition(Vector2f(Froggers[froggernm].getPosition().x, Froggers[froggernm].getPosition().y - 50));
					window.draw(bombSprite);
					window.display();
				}


				Hearts.pop_back();
				Froggers[froggernm].setPosition(Vector2f(345.f, 615.f));
				Froggers[froggernm].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
				window.draw(Froggers[froggernm]);
				window.display();
				healthcnt--;
				if (!healthcnt) {
					window.close();
					mainsound.stop();
					timer_end_sound.stop();
					//----
					top5 top(name2, score_dis);
					//-----
				}

			}
			else {
				objectsRoad2Right[i].move(2.f, 0.f);
			}
			if (objectsRoad2Right[i].getPosition().x > window.getSize().x + 70) {
				objectsRoad2Right[i].setPosition(-180.f, positionsRoad2Right[i].y);
			}

		}

		for (int i = 0; i < objectsRoad2Left.size(); i++) {
			if (Collision::PixelPerfectTest(objectsRoad2Left[i], Froggers[froggernm])) {
				score_dis += countscore.size();
				countscore.clear();
				froggerTrucked_sound.play();

				for (int i = 5; i >= 3; i--) {
					bombSprite.setTextureRect(IntRect(100 * i, 0, 100, 100));
					bombSprite.setPosition(Vector2f(Froggers[froggernm].getPosition().x, Froggers[froggernm].getPosition().y - 50));
					window.draw(bombSprite);
					window.display();
				}


				Hearts.pop_back();
				Froggers[froggernm].setPosition(Vector2f(345.f, 615.f));
				Froggers[froggernm].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
				window.draw(Froggers[froggernm]);
				window.display();
				healthcnt--;
				if (!healthcnt) {
					window.close();
					mainsound.stop();
					timer_end_sound.stop();
					//----
					top5 top(name2, score_dis);
					//-----
				}


			}

			else {
				objectsRoad2Left[i].move(-2.f, 0.f);
			}

			if (objectsRoad2Left[i].getPosition().x < 0 - 280.f) {
				objectsRoad2Left[i].setPosition(window.getSize().x + 80.f, positionsRoad2Left[i].y);
			}

		}

		//-------------------------------------------------------------------------------------------------------------------------

		for (int i = 0; i < objectsRoadLeft.size(); i++) {
			if (Collision::PixelPerfectTest(objectsRoadLeft[i], Froggers[froggernm])) {
				score_dis += countscore.size();
				countscore.clear();

				froggerTrucked_sound.play();

				for (int i = 5; i >= 3; i--) {
					bombSprite.setTextureRect(IntRect(100 * i, 0, 100, 100));
					bombSprite.setPosition(Vector2f(Froggers[froggernm].getPosition().x, Froggers[froggernm].getPosition().y - 50));
					window.draw(bombSprite);
					window.display();
				}


				Hearts.pop_back();
				Froggers[froggernm].setPosition(Vector2f(345.f, 615.f));
				Froggers[froggernm].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
				window.draw(Froggers[froggernm]);
				window.display();
				healthcnt--;
				if (!healthcnt) {
					window.close();
					mainsound.stop();
					timer_end_sound.stop();
					//----
					top5 top(name2, score_dis);
					//-----
				}


			}

			else {
				objectsRoadLeft[i].move(-5.f, 0.f);
			}

			if (objectsRoadLeft[i].getPosition().x < 0 - 280.f) {
				objectsRoadLeft[i].setPosition(window.getSize().x + 80.f, positionsRoadLeft[i].y);
			}
		}


		for (int i = 0; i < objectsRoadRight.size(); i++) {
			if (Collision::PixelPerfectTest(objectsRoadRight[i], Froggers[froggernm])) {
				score_dis += countscore.size();
				countscore.clear();
				froggerTrucked_sound.play();

				for (int i = 5; i >= 3; i--) {
					bombSprite.setTextureRect(IntRect(100 * i, 0, 100, 100));
					bombSprite.setPosition(Vector2f(Froggers[froggernm].getPosition().x, Froggers[froggernm].getPosition().y - 50));
					window.draw(bombSprite);
					window.display();
				}


				Hearts.pop_back();
				Froggers[froggernm].setPosition(Vector2f(345.f, 615.f));
				Froggers[froggernm].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
				window.draw(Froggers[froggernm]);
				window.display();
				healthcnt--;
				if (!healthcnt) {
					window.close();
					mainsound.stop();
					timer_end_sound.stop();
					//----
					top5 top(name2, score_dis);
					//-----
				}
			}

			else {
				objectsRoadRight[i].move(5.f, 0.f);
			}

			if (objectsRoadRight[i].getPosition().x > window.getSize().x + 70) {
				objectsRoadRight[i].setPosition(-200.f, positionsRoadRight[i].y);
			}
		}



		for (int i = 0; i < Wins.size(); i++) {
			if (!winsFound[i]) {
				if (Collision::PixelPerfectTest(Wins[i], Froggers[froggernm])) {
					score_dis += countscore.size();
					countscore.clear();

					win_sound.play();
					win_sound.setVolume(30.f);

					froggernm++; winsFound[i] = true;
					if (froggernm == 5) {
						froggernm--;
						window.close();
						mainsound.stop();
						timer_end_sound.stop();
						level_3 lev(healthcnt, score_dis, name2);
						break;
					}
					window.draw(Froggers[froggernm]);
					window.display();
					break;
				}
			}

			else {
				if (Collision::PixelPerfectTest(Wins[i], Froggers[froggernm])) {
					froggerTrucked_sound.play();

					for (int i = 5; i >= 3; i--) {
						bombSprite.setTextureRect(IntRect(100 * i, 0, 100, 100));
						bombSprite.setPosition(Vector2f(Froggers[froggernm].getPosition().x, Froggers[froggernm].getPosition().y - 50));
						window.draw(bombSprite);
						window.display();
					}

					Hearts.pop_back();
					Froggers[froggernm].setPosition(Vector2f(345.f, 615.f));
					Froggers[froggernm].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
					window.draw(Froggers[froggernm]);
					window.display();
					healthcnt--;
					if (!healthcnt) {
						window.close();
						mainsound.stop();
						timer_end_sound.stop();
						//----
						top5 top(name2, score_dis);
						//-----
					}

				}

			}

		}

	}

}

// destructor
level_2::~level_2(void)
{
}