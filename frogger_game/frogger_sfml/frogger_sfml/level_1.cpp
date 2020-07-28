#include<iostream>
#include "level_1.h"
#include "level_2.h"
#include "top5.h"
#include<ctime>
#include <SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Network.hpp>
#include<SFML\Window.hpp>
#include<vector>
#include <set>
#include<map>
using namespace sf;
using namespace std;



// constructor
level_1::level_1(string Name)
{
	window.create(VideoMode(799, 675), "FROGGER DEMO", Style::Close);
	name1 = Name;
	score_dis = 0;
	healthcnt = 3;
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
void level_1::load_from_file()
{

	// loading objects in water from folder
	if (!RoadPH.loadFromFile("background.png")) {
		cout << "Failed loading from file \n";
	}
	if (!ForggerPH.loadFromFile("froggers.png")) {
		cout << "Failed loading from file \n";
	}

	//loading objects in sea from folder
	if (!Object1PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object11PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object111PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object1111PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object2PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object22PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object222PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object2222PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object22222PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object222222PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object2222222PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object22222222PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object222222222PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object2222222222PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object3PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object33PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Object333PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}

	// loading cars in road from folder
	if (!car1PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car11PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car2PH.loadFromFile("cars.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car22PH.loadFromFile("cars.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car3PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car33PH.loadFromFile("objects.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car4PH.loadFromFile("cars1.png")) {
		cout << "Failed loading from file \n";
	}
	if (!car44PH.loadFromFile("cars1.png")) {
		cout << "Failed loading from file \n";
	}

	// win palce
	if (!Winplace1.loadFromFile("vehicles.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Winplace2.loadFromFile("vehicles.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Winplace3.loadFromFile("vehicles.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Winplace4.loadFromFile("vehicles.png")) {
		cout << "Failed loading from file \n";
	}
	if (!Winplace5.loadFromFile("vehicles.png")) {
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
	// music el frogger when sinking in sea
	if (!froggerSinking_buffer.loadFromFile("froggerDunked.ogg")) {
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

	// sinking in sea
	if (!Sinking.loadFromFile("water_drop.png")) {
		cout << "Failed loading from file \n";
	}



}


void level_1::set_texture()
{
	//background
	backgroundSprite.setTexture(RoadPH);




	//frogger
	froggerSprite.setTexture(ForggerPH);
	froggerSprite.setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
	froggerSprite.setPosition(Vector2f(300.f, 600.f));
	for (int i = 0; i < 5; i++) {
		Froggers.push_back(froggerSprite);
	}




	// objects in water
	object1Sprite.setTexture(Object1PH);
	object1Sprite.setTextureRect(IntRect(520, 290, 200, 75));
	object1Sprite.setPosition(Vector2f(552.f, 60.f));
	objectsSeaLeft.push_back(object1Sprite);
	positionsSeaLeft.push_back(Vector2f(552.f, 60.f));

	object11Sprite.setTexture(Object11PH);
	object11Sprite.setTextureRect(IntRect(520, 290, 200, 75));
	object11Sprite.setPosition(Vector2f(250.f, 60.f));
	objectsSeaLeft.push_back(object11Sprite);
	positionsSeaLeft.push_back(Vector2f(250.f, 60.f));

	object111Sprite.setTexture(Object111PH);
	object111Sprite.setTextureRect(IntRect(520, 290, 200, 75));
	object111Sprite.setPosition(Vector2f(850.f, 60.f));
	objectsSeaLeft.push_back(object111Sprite);
	positionsSeaLeft.push_back(Vector2f(850.f, 60.f));

	object1111Sprite.setTexture(Object1111PH);
	object1111Sprite.setTextureRect(IntRect(520, 290, 200, 75));
	object1111Sprite.setPosition(Vector2f(1100.f, 60.f));
	objectsSeaLeft.push_back(object1111Sprite);
	positionsSeaLeft.push_back(Vector2f(1100.f, 60.f));

	object2Sprite.setTexture(Object2PH);
	object2Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object2Sprite.setPosition(Vector2f(-100.f, 130.f));
	objectsSeaRight.push_back(object2Sprite);
	positionsSeaRight.push_back(Vector2f(-100.f, 130.f));

	object22Sprite.setTexture(Object22PH);
	object22Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object22Sprite.setPosition(Vector2f(-200.f, 130.f));
	objectsSeaRight.push_back(object22Sprite);
	positionsSeaRight.push_back(Vector2f(-200.f, 130.f));

	object222Sprite.setTexture(Object222PH);
	object222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object222Sprite.setPosition(Vector2f(-300.f, 130.f));
	objectsSeaRight.push_back(object222Sprite);
	positionsSeaRight.push_back(Vector2f(-300.f, 130.f));

	object2222Sprite.setTexture(Object2222PH);
	object2222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object2222Sprite.setPosition(Vector2f(-400.f, 130.f));
	objectsSeaRight.push_back(object2222Sprite);
	positionsSeaRight.push_back(Vector2f(-400.f, 130.f));

	object22222Sprite.setTexture(Object22222PH);
	object22222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object22222Sprite.setPosition(Vector2f(-500.f, 130.f));
	objectsSeaRight.push_back(object22222Sprite);
	positionsSeaRight.push_back(Vector2f(-500.f, 130.f));


	object222222Sprite.setTexture(Object222222PH);
	object222222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object222222Sprite.setPosition(Vector2f(-600.f, 130.f));
	objectsSeaRight.push_back(object222222Sprite);
	positionsSeaRight.push_back(Vector2f(-600.f, 130.f));

	object2222222Sprite.setTexture(Object2222222PH);
	object2222222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object2222222Sprite.setPosition(Vector2f(-700.f, 130.f));
	objectsSeaRight.push_back(object2222222Sprite);
	positionsSeaRight.push_back(Vector2f(-700.f, 130.f));

	object22222222Sprite.setTexture(Object22222222PH);
	object22222222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object22222222Sprite.setPosition(Vector2f(-800.f, 130.f));
	objectsSeaRight.push_back(object22222222Sprite);
	positionsSeaRight.push_back(Vector2f(-800.f, 130.f));

	object222222222Sprite.setTexture(Object222222222PH);
	object222222222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object222222222Sprite.setPosition(Vector2f(-900.f, 130.f));
	objectsSeaRight.push_back(object222222222Sprite);
	positionsSeaRight.push_back(Vector2f(-900.f, 130.f));

	object2222222222Sprite.setTexture(Object2222222222PH);
	object2222222222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object2222222222Sprite.setPosition(Vector2f(-1000.f, 130.f));
	objectsSeaRight.push_back(object2222222222Sprite);
	positionsSeaRight.push_back(Vector2f(-1000.f, 130.f));

	object3Sprite.setTexture(Object3PH);
	object3Sprite.setTextureRect(IntRect(150, 370, 280, 75));
	object3Sprite.setPosition(Vector2f(750.f, 200.f));
	objectsSeaLeft.push_back(object3Sprite);
	positionsSeaLeft.push_back(Vector2f(750.f, 200.f));

	object33Sprite.setTexture(Object33PH);
	object33Sprite.setTextureRect(IntRect(150, 370, 280, 75));
	object33Sprite.setPosition(Vector2f(250.f, 200.f));
	objectsSeaLeft.push_back(object33Sprite);
	positionsSeaLeft.push_back(Vector2f(250.f, 200.f));

	object333Sprite.setTexture(Object333PH);
	object333Sprite.setTextureRect(IntRect(150, 370, 280, 75));
	object333Sprite.setPosition(Vector2f(-100.f, 200.f));
	objectsSeaLeft.push_back(object333Sprite);
	positionsSeaLeft.push_back(Vector2f(-100.f, 200.f));



	//cars in road
	car1Spritesheet.setTexture(car1PH);
	car1Spritesheet.setTextureRect(IntRect(120, 440, 215, 70));
	car1Spritesheet.setPosition(Vector2f(100.f, 340.f));
	objectsRoadRight.push_back(car1Spritesheet);
	positionsRoadRight.push_back(Vector2f(100.f, 340.f));


	car11Spritesheet.setTexture(car11PH);
	car11Spritesheet.setTextureRect(IntRect(120, 440, 215, 70));
	car11Spritesheet.setPosition(Vector2f(-300.f, 340.f));
	objectsRoadRight.push_back(car11Spritesheet);
	positionsRoadRight.push_back(Vector2f(-300.f, 340.f));

	car2Spritesheet.setTexture(car2PH);
	car2Spritesheet.setTextureRect(IntRect(70, 80, 65, 40));
	car2Spritesheet.setPosition(Vector2f(400.f, 420.f));
	objectsRoadLeft.push_back(car2Spritesheet);
	positionsRoadLeft.push_back(Vector2f(400.f, 420.f));

	car22Spritesheet.setTexture(car22PH);
	car22Spritesheet.setTextureRect(IntRect(70, 80, 65, 40));
	car22Spritesheet.setPosition(Vector2f(180.f, 420.f));
	objectsRoadLeft.push_back(car22Spritesheet);
	positionsRoadLeft.push_back(Vector2f(180.f, 420.f));

	car3Spritesheet.setTexture(car3PH);
	car3Spritesheet.setTextureRect(IntRect(280, 520, 160, 70));
	car3Spritesheet.setPosition(Vector2f(-160.f, 465.f));
	objectsRoadRight.push_back(car3Spritesheet);
	positionsRoadRight.push_back(Vector2f(-160.f, 465.f));

	car33Spritesheet.setTexture(car33PH);
	car33Spritesheet.setTextureRect(IntRect(280, 520, 160, 70));
	car33Spritesheet.setPosition(Vector2f(-450.f, 465.f));
	objectsRoadRight.push_back(car33Spritesheet);
	positionsRoadRight.push_back(Vector2f(-450.f, 465.f));

	car4Spritesheet.setTexture(car4PH);
	car4Spritesheet.setTextureRect(IntRect(5, 75, 70, 60));
	car4Spritesheet.setPosition(Vector2f(554.f, 525.f));
	objectsRoadLeft.push_back(car4Spritesheet);
	positionsRoadLeft.push_back(Vector2f(554.f, 525.f));

	car44Spritesheet.setTexture(car44PH);
	car44Spritesheet.setTextureRect(IntRect(5, 75, 70, 60));
	car44Spritesheet.setPosition(Vector2f(280.f, 525.f));
	objectsRoadLeft.push_back(car44Spritesheet);
	positionsRoadLeft.push_back(Vector2f(280.f, 525.f));


	// win place 
	Winplacesprite1.setTexture(Winplace1);
	Winplacesprite1.setTextureRect(IntRect(600, 0, 120, 100));
	Winplacesprite1.setPosition(650, -40);
	Wins.push_back(Winplacesprite1);


	Winplacesprite2.setTexture(Winplace2);
	Winplacesprite2.setTextureRect(IntRect(600, 0, 120, 100));
	Winplacesprite2.setPosition(490, -40);
	Wins.push_back(Winplacesprite2);

	Winplacesprite3.setTexture(Winplace3);
	Winplacesprite3.setTextureRect(IntRect(600, 0, 120, 100));
	Winplacesprite3.setPosition(340, -40);
	Wins.push_back(Winplacesprite3);

	Winplacesprite4.setTexture(Winplace4);
	Winplacesprite4.setTextureRect(IntRect(600, 0, 120, 100));
	Winplacesprite4.setPosition(180, -40);
	Wins.push_back(Winplacesprite4);

	Winplacesprite5.setTexture(Winplace5);
	Winplacesprite5.setTextureRect(IntRect(600, 0, 120, 100));
	Winplacesprite5.setPosition(15, -40);
	Wins.push_back(Winplacesprite5);


	// hearts
	heartsprite1.setTexture(heart1);
	heartsprite1.setTextureRect(IntRect(0, 0, 40, 30));
	heartsprite1.setPosition(Vector2f(8.f, 605.f));
	Hearts.push_back(heartsprite1);

	heartsprite2.setTexture(heart2);
	heartsprite2.setTextureRect(IntRect(0, 0, 40, 30));
	heartsprite2.setPosition(Vector2f(50.f, 605.f));
	Hearts.push_back(heartsprite2);

	heartsprite3.setTexture(heart3);
	heartsprite3.setTextureRect(IntRect(0, 0, 40, 30));
	heartsprite3.setPosition(Vector2f(92.f, 605.f));
	Hearts.push_back(heartsprite3);


	// font bta3 el score
	score_text.setFont(score_font);
	score_text.setCharacterSize(25);
	score_text.setFillColor(Color::Blue);
	score_text.setPosition(550, 640);

	//font el timer
	timer_text.setFont(timer_font);
	timer_time = seconds(188);
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

	//audio of frogger Skining in water
	froggerSinking_sound.setBuffer(froggerSinking_buffer);

	//audio of timer ends
	timer_end_sound.setBuffer(timer_end_buffer);

	//audio of frooger reach wins
	win_sound.setBuffer(win_buffer);


	//trucked with cars
	bombSprite.setTexture(bomb);

	// sinking in water
	SinkingSprite.setTexture(Sinking);


}


void level_1::playing()
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
			top5 top(name1, score_dis);
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


			Hearts.erase(Hearts.begin() + healthcnt - 1);
			Froggers[froggernm].setPosition(Vector2f(300.f, 630.f));
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
				top5 top(name1, score_dis);
				//-----
			}
		}



		// to change position of frogger
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) { window.close(); }

			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Right) {
					Froggers[froggernm].move(Vector2f(57, 0));
					Froggers[froggernm].setTextureRect(IntRect(50 * 2, 50 * 2, 50, 40));
					window.draw(Froggers[froggernm]);
					window.display();
					Froggers[froggernm].setTextureRect(IntRect((50 * 1) + 5, 50 * 2, 50, 40));
					froggerHop_sound.play();
				}

				else if (event.key.code == Keyboard::Left) {
					Froggers[froggernm].move(Vector2f(-57, 0));
					Froggers[froggernm].setTextureRect(IntRect(50 * 2, 50 * 1, 50, 40));
					window.draw(Froggers[froggernm]);
					window.display();
					Froggers[froggernm].setTextureRect(IntRect((50 * 1) + 3, 50 * 1, 50, 40));
					froggerHop_sound.play();
				}

				else if (event.key.code == Keyboard::Up) {
					Froggers[froggernm].move(Vector2f(0, -57));
					Froggers[froggernm].setTextureRect(IntRect(50 * 2, 50 * 3, 50, 40));
					window.draw(Froggers[froggernm]);
					window.display();
					Froggers[froggernm].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
					froggerHop_sound.play();

					// to insert position of frogger up Hop in set to display score
					countscore.insert(Froggers[froggernm].getPosition().y);

				}

				else if (event.key.code == Keyboard::Down) {
					Froggers[froggernm].move(Vector2f(0, 57));
					Froggers[froggernm].setTextureRect(IntRect(50 * 2, 50 * 0, 50, 40));
					window.draw(Froggers[froggernm]);
					window.display();
					Froggers[froggernm].setTextureRect(IntRect(50 * 1, 0, 50, 40));
					froggerHop_sound.play();
				}
				else if (event.key.code == Keyboard::Escape) {
					window.close();
					mainsound.stop();
					timer_end_sound.stop();
					//----
					top5 top(name1, score_dis);
					//-----
				}

			}

		}

		window.clear();
		window.draw(backgroundSprite);

		for (auto i : objectsSeaRight) {
			window.draw(i);
		}
		for (auto i : objectsSeaLeft) {
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

		//objects move and frogger sinking handel!!
		for (int i = 0; i < objectsSeaRight.size(); i++) {
			if (Collision::PixelPerfectTest(objectsSeaRight[i], Froggers[froggernm])) {
				objectsSeaRight[i].move(2.f, 0.f);
				froggerfound = true;
				Froggers[froggernm].move(2.f, 0.f);
			}

			else {
				objectsSeaRight[i].move(2.f, 0.f);
			}

			if (objectsSeaRight[i].getPosition().x > window.getSize().x + 70) {
				objectsSeaRight[i].setPosition(-180.f, positionsSeaRight[i].y);
			}
		}


		for (int i = 0; i < objectsSeaLeft.size(); i++) {
			if (Collision::PixelPerfectTest(objectsSeaLeft[i], Froggers[froggernm])) {
				objectsSeaLeft[i].move(-2.f, 0.f);
				froggerfound = true;
				Froggers[froggernm].move(-2.f, 0.f);
			}

			else {
				objectsSeaLeft[i].move(-2.f, 0.f);
			}

			if (objectsSeaLeft[i].getPosition().x < 0 - 280.f) {
				objectsSeaLeft[i].setPosition(window.getSize().x + 80.f, positionsSeaLeft[i].y);
			}
		}


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

				Hearts.erase(Hearts.begin() + healthcnt - 1);
				Froggers[froggernm].setPosition(Vector2f(300.f, 630.f));
				Froggers[froggernm].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
				window.draw(Froggers[froggernm]);
				window.display();
				healthcnt--;
				if (!healthcnt) {
					window.close();
					mainsound.stop();
					timer_end_sound.stop();
					//----
					top5 top(name1, score_dis);
					//-----
				}

			}

			else {
				objectsRoadLeft[i].move(-2.f, 0.f);
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


				Hearts.erase(Hearts.begin() + healthcnt - 1);
				Froggers[froggernm].setPosition(Vector2f(300.f, 630.f));
				Froggers[froggernm].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
				window.draw(Froggers[froggernm]);
				window.display();
				healthcnt--;
				if (!healthcnt) {
					window.close();
					mainsound.stop();
					timer_end_sound.stop();
					//----
					top5 top(name1, score_dis);
					//-----
				}
			}

			else {
				objectsRoadRight[i].move(2.f, 0.f);
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
						level_2 game1(healthcnt, score_dis, name1);
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

					Hearts.erase(Hearts.begin() + healthcnt - 1);
					Froggers[froggernm].setPosition(Vector2f(300.f, 630.f));
					Froggers[froggernm].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
					window.draw(Froggers[froggernm]);
					window.display();
					healthcnt--;
					if (!healthcnt) {
						window.close();
						mainsound.stop();
						timer_end_sound.stop();
						//----
						top5 top(name1, score_dis);
						//-----
					}

				}
			}
		}




		if (Froggers[froggernm].getPosition().y < 235) {
			if (!froggerfound) {

				if (!Collision::PixelPerfectTest(Winplacesprite1, Froggers[froggernm]) &&
					!Collision::PixelPerfectTest(Winplacesprite2, Froggers[froggernm]) &&
					!Collision::PixelPerfectTest(Winplacesprite3, Froggers[froggernm]) &&
					!Collision::PixelPerfectTest(Winplacesprite4, Froggers[froggernm]) &&
					!Collision::PixelPerfectTest(Winplacesprite5, Froggers[froggernm])) {

					score_dis += countscore.size();
					countscore.clear();

					froggerSinking_sound.play();

					for (int i = 0; i < 3; i++) {
						SinkingSprite.setTextureRect(IntRect(200, 0, 150, 120));
						SinkingSprite.setPosition(Vector2f(Froggers[froggernm].getPosition().x, Froggers[froggernm].getPosition().y - 50));
						window.draw(SinkingSprite);
						window.display();
					}


					Hearts.erase(Hearts.begin() + healthcnt - 1);
					Froggers[froggernm].setPosition(Vector2f(300.f, 630.f));
					Froggers[froggernm].setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
					window.draw(Froggers[froggernm]);
					window.display();
					healthcnt--;
					if (!healthcnt) {
						window.close();
						mainsound.stop();
						timer_end_sound.stop();
						//----
						top5 top(name1, score_dis);
						//-----
					}
				}
			}
		}


	}

}


//Collision
namespace Collision
{
	class BitmaskManager
	{
	public:
		~BitmaskManager() {
			std::map<const sf::Texture*, sf::Uint8*>::const_iterator end = Bitmasks.end();
			for (std::map<const sf::Texture*, sf::Uint8*>::const_iterator iter = Bitmasks.begin(); iter != end; iter++)
				delete[] iter->second;
		}

		sf::Uint8 GetPixel(const sf::Uint8* mask, const sf::Texture* tex, unsigned int x, unsigned int y) {
			if (x > tex->getSize().x || y > tex->getSize().y)
				return 0;

			return mask[x + y * tex->getSize().x];
		}

		sf::Uint8* GetMask(const sf::Texture* tex) {
			sf::Uint8* mask;
			std::map<const sf::Texture*, sf::Uint8*>::iterator pair = Bitmasks.find(tex);
			if (pair == Bitmasks.end())
			{
				sf::Image img = tex->copyToImage();
				mask = CreateMask(tex, img);
			}
			else
				mask = pair->second;

			return mask;
		}

		sf::Uint8* CreateMask(const sf::Texture* tex, const sf::Image& img) {
			sf::Uint8* mask = new sf::Uint8[tex->getSize().y*tex->getSize().x];

			for (unsigned int y = 0; y < tex->getSize().y; y++)
			{
				for (unsigned int x = 0; x < tex->getSize().x; x++)
					mask[x + y * tex->getSize().x] = img.getPixel(x, y).a;
			}

			Bitmasks.insert(std::pair<const sf::Texture*, sf::Uint8*>(tex, mask));

			return mask;
		}
	private:
		std::map<const sf::Texture*, sf::Uint8*> Bitmasks;
	};

	BitmaskManager Bitmasks;

	bool PixelPerfectTest(const sf::Sprite& Object1, const sf::Sprite& Object2, sf::Uint8 AlphaLimit) {
		sf::FloatRect Intersection;
		if (Object1.getGlobalBounds().intersects(Object2.getGlobalBounds(), Intersection)) {
			sf::IntRect O1SubRect = Object1.getTextureRect();
			sf::IntRect O2SubRect = Object2.getTextureRect();

			sf::Uint8* mask1 = Bitmasks.GetMask(Object1.getTexture());
			sf::Uint8* mask2 = Bitmasks.GetMask(Object2.getTexture());

			// Loop through our pixels
			for (int i = Intersection.left; i < Intersection.left + Intersection.width; i++) {
				for (int j = Intersection.top; j < Intersection.top + Intersection.height; j++) {

					sf::Vector2f o1v = Object1.getInverseTransform().transformPoint(i, j);
					sf::Vector2f o2v = Object2.getInverseTransform().transformPoint(i, j);

					// Make sure pixels fall within the sprite's subrect
					if (o1v.x > 0 && o1v.y > 0 && o2v.x > 0 && o2v.y > 0 &&
						o1v.x < O1SubRect.width && o1v.y < O1SubRect.height &&
						o2v.x < O2SubRect.width && o2v.y < O2SubRect.height) {

						if (Bitmasks.GetPixel(mask1, Object1.getTexture(), (int)(o1v.x) + O1SubRect.left, (int)(o1v.y) + O1SubRect.top) > AlphaLimit &&
							Bitmasks.GetPixel(mask2, Object2.getTexture(), (int)(o2v.x) + O2SubRect.left, (int)(o2v.y) + O2SubRect.top) > AlphaLimit)
							return true;

					}
				}
			}
		}
		return false;
	}
}


// destructor
level_1::~level_1(void)
{
}