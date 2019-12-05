#include "level_1.h"
#include<iostream>
#include<ctime>
#include <SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Network.hpp>
#include<SFML\Window.hpp>
#include<vector>
#include <set>
using namespace sf;
using namespace std;

// constructor
level_1::level_1(void)
{
	window.create (VideoMode(800, 676), "FROGGER DEMO"/*,Style::Fullscreen*/);
	view.setCenter(Vector2f(400.f,338.f));
	view.setSize(Vector2f(800.f,676.f));

	// calling functions 
	load_from_file();
	set_texture();	
	playing();

}


// this function to load tectures from folder
void level_1::load_from_file()
{

	// loading objects in water from folder
	if(!RoadPH.loadFromFile("background.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!ForggerPH.loadFromFile("froggers.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Object1PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Object11PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Object111PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Object1111PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Object2PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Object22PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Object222PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Object2222PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Object22222PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Object222222PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Object3PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Object33PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	

	// loading cars in road from folder
	if(!car1PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!car11PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!car2PH.loadFromFile("cars.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!car22PH.loadFromFile("cars.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!car3PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!car33PH.loadFromFile("objects.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!car4PH.loadFromFile("cars1.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!car44PH.loadFromFile("cars1.png")){
	   cout<<"Failed loading from file \n";
	}

	// win palce
	if(!Winplace1.loadFromFile("vehicles.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Winplace2.loadFromFile("vehicles.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Winplace3.loadFromFile("vehicles.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Winplace4.loadFromFile("vehicles.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!Winplace5.loadFromFile("vehicles.png")){
	   cout<<"Failed loading from file \n";
	}

	// hearts
	if(!heart1.loadFromFile("hearts.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!heart2.loadFromFile("hearts.png")){
	   cout<<"Failed loading from file \n";
	}
	if(!heart3.loadFromFile("hearts.png")){
	   cout<<"Failed loading from file \n";
	}

	// font el score
	if(!score_font.loadFromFile("Noteworthy-Bold.otf")){
	   cout<<"Failed loading from file \n";
	}

	// font el timer
	if(!timer_font.loadFromFile("Noteworthy-Bold.otf")){
	   cout<<"Failed loading from file \n";
	}
    
	//main music of the game
	if(!mainbuffer.loadFromFile("froggerLeche_Remix.ogg")){
	   cout<<"Failed loading from file \n";
	}
	// music of frogger Hop
	if(!froggerHops_buffer.loadFromFile("froggerHop.ogg")){
	   cout<<"Failed loading from file \n";
	}
	 
}


void level_1::set_texture()
{
	//background
	backgroundSprite.setTexture(RoadPH);


	//frogger
	froggerSprite.setTexture(ForggerPH);
	froggerSprite.setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
	froggerSprite.setPosition(Vector2f(300.f, 630.f));


    // objects in water
	object1Sprite.setTexture(Object1PH);
	object1Sprite.setTextureRect(IntRect(520, 290, 200, 75));
	object1Sprite.setPosition(Vector2f(552.f, 60.f));
	objectsLeft.push_back(object1Sprite);
	positionsLeft.push_back(Vector2f( 552.f, 60.f));

	object11Sprite.setTexture(Object11PH);
	object11Sprite.setTextureRect(IntRect(520, 290, 200, 75));
	object11Sprite.setPosition(Vector2f(250.f, 60.f));
    objectsLeft.push_back(object11Sprite);
	positionsLeft.push_back(Vector2f(250.f, 60.f));

	object111Sprite.setTexture(Object111PH);
	object111Sprite.setTextureRect(IntRect(520, 290, 200, 75));
	object111Sprite.setPosition(Vector2f(850.f, 60.f));
    objectsLeft.push_back(object111Sprite);
	positionsLeft.push_back(Vector2f(850.f, 60.f));

	object1111Sprite.setTexture(Object1111PH);
	object1111Sprite.setTextureRect(IntRect(520, 290, 200, 75));
	object1111Sprite.setPosition(Vector2f(1100.f, 60.f));
	objectsLeft.push_back(object1111Sprite);
	positionsLeft.push_back(Vector2f(1100.f, 60.f));

	object2Sprite.setTexture(Object2PH);
	object2Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object2Sprite.setPosition(Vector2f(-100.f, 125.f));
	objectsRight.push_back(object2Sprite);
	positionsRight.push_back(Vector2f (-100.f, 125.f));

	object22Sprite.setTexture(Object22PH);
	object22Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object22Sprite.setPosition(Vector2f(-300.f, 125.f));
	objectsRight.push_back(object22Sprite);
	positionsRight.push_back(Vector2f(-300.f, 125.f));

	object222Sprite.setTexture(Object222PH);
	object222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object222Sprite.setPosition(Vector2f(-420.f, 125.f));
	objectsRight.push_back(object222Sprite);
	positionsRight.push_back(Vector2f(-420.f, 125.f));

	object2222Sprite.setTexture(Object2222PH);
	object2222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object2222Sprite.setPosition(Vector2f(-520.f, 125.f));
	objectsRight.push_back(object2222Sprite);
	positionsRight.push_back(Vector2f(-520.f, 125.f));

	object22222Sprite.setTexture(Object22222PH);
	object22222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object22222Sprite.setPosition(Vector2f(-620.f, 125.f));
	objectsRight.push_back(object22222Sprite);
	positionsRight.push_back(Vector2f(-620.f, 125.f));

	object222222Sprite.setTexture(Object222222PH);
	object222222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object222222Sprite.setPosition(Vector2f(-780.f, 125.f));
	objectsRight.push_back(object222222Sprite);
	positionsRight.push_back(Vector2f(-780.f, 125.f));

	object3Sprite.setTexture(Object3PH);
	object3Sprite.setTextureRect(IntRect(150, 370, 280, 75));
	object3Sprite.setPosition(Vector2f(555.f, 200.f));
	objectsLeft.push_back(object3Sprite);
	positionsLeft.push_back(Vector2f(555.f, 200.f));

	object33Sprite.setTexture(Object33PH);
	object33Sprite.setTextureRect(IntRect(150, 370, 280, 75));
	object33Sprite.setPosition(Vector2f(150.f, 200.f));
	objectsLeft.push_back(object33Sprite);
	positionsLeft.push_back(Vector2f(150.f, 200.f));


	//cars in road
	car1Spritesheet.setTexture(car1PH);
	car1Spritesheet.setTextureRect(IntRect(120, 440, 215, 70));
	car1Spritesheet.setPosition(Vector2f(100.f, 340.f));
	objectsRight.push_back(car1Spritesheet);
	positionsRight.push_back(Vector2f( 100.f, 340.f));

	car11Spritesheet.setTexture(car11PH);
	car11Spritesheet.setTextureRect(IntRect(120, 440, 215, 70));
	car11Spritesheet.setPosition(Vector2f(-300.f, 340.f));
	objectsRight.push_back(car11Spritesheet);
	positionsRight.push_back(Vector2f(-300.f, 340.f));

	car2Spritesheet.setTexture(car2PH);
	car2Spritesheet.setTextureRect(IntRect(70, 80, 65, 40));
	car2Spritesheet.setPosition(Vector2f(400.f, 420.f));
	objectsLeft.push_back(car2Spritesheet);
	positionsLeft.push_back(Vector2f(400.f, 420.f));

	car22Spritesheet.setTexture(car22PH);
	car22Spritesheet.setTextureRect(IntRect(70, 80, 65, 40));
	car22Spritesheet.setPosition(Vector2f(180.f, 420.f));
	objectsLeft.push_back(car22Spritesheet);
	positionsLeft.push_back(Vector2f(180.f, 420.f));

	car3Spritesheet.setTexture(car3PH);
	car3Spritesheet.setTextureRect(IntRect(280, 520, 160, 70));
	car3Spritesheet.setPosition(Vector2f(-160.f, 465.f));
	objectsRight.push_back(car3Spritesheet);
	positionsRight.push_back(Vector2f( -160.f, 465.f));

	car33Spritesheet.setTexture(car33PH);
	car33Spritesheet.setTextureRect(IntRect(280, 520, 160, 70));
	car33Spritesheet.setPosition(Vector2f(-450.f, 465.f));
	objectsRight.push_back(car33Spritesheet);
	positionsRight.push_back(Vector2f(-450.f, 465.f));

	car4Spritesheet.setTexture(car4PH);
	car4Spritesheet.setTextureRect(IntRect(5, 75, 70, 60));
	car4Spritesheet.setPosition(Vector2f(554.f, 525.f));
	objectsLeft.push_back(car4Spritesheet);
	positionsLeft.push_back(Vector2f( 554.f, 525.f));

	car44Spritesheet.setTexture(car44PH);
	car44Spritesheet.setTextureRect(IntRect(5, 75, 70, 60));
	car44Spritesheet.setPosition(Vector2f(280.f, 525.f));
	objectsLeft.push_back(car44Spritesheet);
	positionsLeft.push_back(Vector2f(280.f, 525.f));


	// win place 
	Winplacesprite1.setTexture(Winplace1);
	Winplacesprite1.setTextureRect(IntRect(600,0, 120, 100));
	Winplacesprite1.setPosition(650,-40);
	Wins.push_back(Winplacesprite1);

	Winplacesprite2.setTexture(Winplace2);
	Winplacesprite2.setTextureRect(IntRect(600,0, 120, 100));
	Winplacesprite2.setPosition(490,-40);
	Wins.push_back(Winplacesprite2);

	Winplacesprite3.setTexture(Winplace3);
	Winplacesprite3.setTextureRect(IntRect(600,0, 120, 100));
	Winplacesprite3.setPosition(340,-40);
	Wins.push_back(Winplacesprite3);

	Winplacesprite4.setTexture(Winplace4);
	Winplacesprite4.setTextureRect(IntRect(600,0, 120, 100));
	Winplacesprite4.setPosition(180,-40);
	Wins.push_back(Winplacesprite4);

	Winplacesprite5.setTexture(Winplace5);
	Winplacesprite5.setTextureRect(IntRect(600,0, 120, 100));
	Winplacesprite5.setPosition(15,-40);
	Wins.push_back(Winplacesprite5);


	// hearts
	heartsprite1.setTexture(heart1);
	heartsprite1.setTextureRect(IntRect(0,0, 40, 30));
	heartsprite1.setPosition(Vector2f(8.f, 605.f));
	Hearts.push_back(heartsprite1);

	heartsprite2.setTexture(heart2);
	heartsprite2.setTextureRect(IntRect(0,0, 40, 30));
	heartsprite2.setPosition(Vector2f(50.f, 605.f));
	Hearts.push_back(heartsprite2);

	heartsprite3.setTexture(heart3);
	heartsprite3.setTextureRect(IntRect(0,0, 40, 30));
	heartsprite3.setPosition(Vector2f(92.f, 605.f));
	Hearts.push_back(heartsprite3);

	
	// font bta3 el score
	score_text.setFont(score_font);
	score_text.setCharacterSize(25);
	score_text.setColor (Color( 0, 0,255));
	score_text.setPosition(550,640);
	

    //font el timer
	timer_text.setFont(timer_font);
	timer_time=seconds(188);
	timer_text.setPosition(15,640);
    timer_text.setColor(Color(0,0,255));

	// audio of the game
	mainsound.setBuffer(mainbuffer);
	mainsound.setVolume(30.f);
	mainsound.play();
	mainsound.setLoop(true);

	//audio of frogger Hop
	froggerHop_sound.setBuffer(froggerHops_buffer);

}


void level_1::playing()
{

	while (window.isOpen()) {
	
		//convert int to string bta3t el score
		count_score = to_string(countscore.size());
	    score_text.setString("score: "+count_score);
		

	//bzbt el timer 3lshan y3d mn 120 to 0
	elabsed=timer_clock.getElapsedTime();
	int a=(timer_time-elabsed).asSeconds();
	timer_string= to_string(a);
	timer_text.setString("timer: "+timer_string);


		// to change position of frogger
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) { window.close(); }

			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Right) {
					froggerSprite.move(Vector2f(40, 0));
					froggerSprite.setTextureRect(IntRect( 50*2, 50* 2, 50, 40));
					window.draw(froggerSprite);
					window.display();
					froggerSprite.setTextureRect(IntRect((50 * 1) + 5, 50 * 2, 50, 40));
					froggerHop_sound.play();
				}

				else if (event.key.code == Keyboard::Left) {
					froggerSprite.move(Vector2f(-40, 0));
					froggerSprite.setTextureRect(IntRect(50 * 2, 50 * 1, 50, 40));
					window.draw(froggerSprite);
					window.display();
					froggerSprite.setTextureRect(IntRect((50 * 1) + 3, 50 * 1, 50, 40));
				    froggerHop_sound.play();
				}

				else if (event.key.code == Keyboard::Up) {
					froggerSprite.move(Vector2f(0, -30));
					froggerSprite.setTextureRect(IntRect(50 * 2, 50 * 3, 50, 40));
					window.draw(froggerSprite);
					window.display();
					froggerSprite.setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
					froggerHop_sound.play();
					// to insert position of frogger up Hop in set to display score
					countscore.insert(froggerSprite.getPosition().y);
				}

				else if (event.key.code == Keyboard::Down) {
					froggerSprite.move(Vector2f(0, 30));
					froggerSprite.setTextureRect(IntRect(50 * 2, 50 * 0, 50, 40));
					window.draw(froggerSprite);
					window.display();
					froggerSprite.setTextureRect(IntRect(50 * 1, 0, 50, 40));
				    froggerHop_sound.play();
				}
				else if (event.key.code == Keyboard::Escape) { window.close(); }

			}

		}

		window.clear();
		window.draw(backgroundSprite);
		window.setView(view);

		for (auto i : objectsRight) {
			window.draw(i);
		}
		for (auto i : objectsLeft) {
			window.draw(i);
		}
		for (auto i : Wins) {
			window.draw(i);
		}
		for (auto i : Hearts) {
			window.draw(i);
		}
		
		window.draw(froggerSprite);
		//score draw
		window.draw(score_text);
		// timer draw
		window.draw(timer_text);
		window.display();

		for (int i = 0; i<objectsRight.size(); i++) {
			objectsRight[i].move(0.6f, 0.f);
			if (objectsRight[i].getPosition().x >  window.getSize().x + 70) {
				objectsRight[i].setPosition(-180.f, positionsRight[i].y);
			}
		}
		for (int i = 0; i<objectsLeft.size(); i++) {
			objectsLeft[i].move(-0.6f, 0.f);
			if (objectsLeft[i].getPosition().x <0 - 280.f) {
				objectsLeft[i].setPosition(window.getSize().x + 80.f, positionsLeft[i].y);
			}
		}
	}


}

// destructor
level_1::~level_1(void)
{
}
