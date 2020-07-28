#include<iostream>
#include "start.h"	
#include "level_1.h"
//#include "level_3.h"
using namespace std;


//constructor
start::start(string Name)
{
	name = Name;
	slectedItem = -1;

	if (!font.loadFromFile("Noteworthy-Bold.otf"))
		cout << "Failed loading from file \n" << endl;
	if (!men.loadFromFile("fro.png"))
		cout << "Failed loading from file \n" << endl;
	menu1.setTexture(men);

	//text play
	text[0].setFont(font);
	text[0].setFillColor(Color::Yellow);
	text[0].setString("Play");
	text[0].setCharacterSize(60);
	text[0].setPosition(Vector2f(700 / 2, 675 / (max_num + 1) * 1));

	//text Exit
	text[1].setFont(font);
	text[1].setFillColor(Color::White);
	text[1].setString("Exit");
	text[1].setCharacterSize(60);
	text[1].setPosition(Vector2f(700 / 2, 675 / (max_num + 1) * 2));
	slectedItem = 0;
	playing();


}


void start::draw(RenderWindow &window) {
	window.draw(menu1);
	for (int i = 0; i < max_num; i++) {
		window.draw(text[i]);
	}
}


void start::moveup() {
	if (slectedItem - 1 >= 0) {
		text[slectedItem].setFillColor(Color::White);
		slectedItem--;
		text[slectedItem].setFillColor(Color::Yellow);
	}
}


void start::movedown() {
	if (slectedItem + 1 < max_num) {
		text[slectedItem].setFillColor(Color::White);
		slectedItem++;
		text[slectedItem].setFillColor(Color::Yellow);
	}
}


void start::playing() {
	RenderWindow window(VideoMode(799, 675), "FROGGER DEMO");
	Event event;
	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape) { window.close(); break; }
			}

			switch (event.type) {
			case ::Event::KeyReleased:
				switch (event.key.code)
				{

				case ::Keyboard::Up:
					moveup();
					break;
				case ::Keyboard::Down:
					movedown();
					break;
				case::Keyboard::Return:
					switch (slectedItem)
					{
					case 0: {
						window.setVisible(false);
						level_1 game(name);
						break;
					}

					case 1:
						window.close();
						break;
					}
				}
				break;
			case ::Event::Closed:
				window.close();
				break;
			}

		}

		window.clear();
		draw(window);
		window.display();
	}

}

int start::getpress()
{
	return slectedItem;
}

start::~start()
{
}