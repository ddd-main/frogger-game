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
#include "start.h"
#include <fstream>
#include <string>
using namespace sf;
using namespace std;


top5::top5(string name, int score_dis)
{
	if (!lay.loadFromFile("lay lay.ogg")) {
		cout << "Failed loading from file \n";
	}

	layy.setBuffer(lay);
	layy.setVolume(50.f);
	layy.play();
	layy.setLoop(true);
	//----------------------------------------------------------
	namak = name;
	scorak = score_dis;
	//-----------------------------------------------------------

	ifstream ff("file.txt");
	bool isfound = false;
	while (ff.good()) {
		string x;
		getline(ff, x);
		if (x == namak) {
			isfound = true;
		}
	}

	ff.close();

	if (!isfound) {
		ofstream  fff("file.txt", ios::app);
		fff << namak << endl << scorak << endl;
		fff.close();
	}

	else if (isfound) {
		ifstream fin;
		ofstream fout("file2.txt");
		fin.open("file.txt");
		while (fin.good()) {
			string x;
			getline(fin, x);
			if (x == namak) {
				fout << x << endl;
				fout << scorak << endl;
				getline(fin, x);
			}

			else
				fout << x << endl;
		}
		fin.close();
		fout.close();
		remove("file.txt");
		rename("file2.txt", "file.txt");
	}


	int i = 0, j = 0; string x;
	ifstream ll("file.txt");
	while (ll.good()) {
		if (i % 2 == 0) {
			ll >> x;
		}
		else {
			int xx;
			ll >> xx;
			vec.push_back(make_pair(xx, x));
		}
		i++;
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	//displaying 


	//--------------------------------------------------------------
	window.create(VideoMode(799, 675), "FROGGER DEMO", Style::Close);
	if (!back.loadFromFile("top5.png")) {
		cout << "failed loading from file" << endl;
	}

	if (!top_font.loadFromFile("Noteworthy-Bold.otf")) {
		cout << "Failed loading from file \n";
	}

	if (!player_font[0].loadFromFile("Noteworthy-Bold.otf")) {
		cout << "Failed loading from file \n";
	}
	if (!player_font[1].loadFromFile("Noteworthy-Bold.otf")) {
		cout << "Failed loading from file \n";
	}
	if (!player_font[2].loadFromFile("Noteworthy-Bold.otf")) {
		cout << "Failed loading from file \n";
	}
	if (!player_font[3].loadFromFile("Noteworthy-Bold.otf")) {
		cout << "Failed loading from file \n";
	}
	if (!player_font[4].loadFromFile("Noteworthy-Bold.otf")) {
		cout << "Failed loading from file \n";
	}
	if (!exit_font.loadFromFile("Noteworthy-Bold.otf")) {
		cout << "Failed loading from file \n";
	}
	if (!play_font.loadFromFile("Noteworthy-Bold.otf")) {
		cout << "Failed loading from file \n";
	}

	back_sprite.setTexture(back);

	top_text.setFont(top_font);
	top_text.setString("the top player score : ");
	top_text.setCharacterSize(25);
	top_text.setFillColor(Color::Blue);
	top_text.setCharacterSize(40);
	top_text.setPosition(50, 50);

	int q = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		player_text[i].setFont(player_font[i]);
		player_text[i].setString(vec[i].second + ": " + to_string(vec[i].first));
		player_text[i].setCharacterSize(25);
		player_text[i].setFillColor(Color::Red);
		player_text[i].setPosition(70, 120 + q);
		q += 70;
		if (i == 4)
			break;
	}

	exit_text.setFont(exit_font);
	exit_text.setString("Exit :'(");
	exit_text.setCharacterSize(50);
	exit_text.setFillColor(Color::White);
	exit_text.setPosition(550, 550);

	play_text.setFont(play_font);
	play_text.setString("Play Again :)");
	play_text.setCharacterSize(50);
	play_text.setFillColor(Color::Yellow);
	play_text.setPosition(20, 550);

	int s = 1;
	while (window.isOpen()) {
		Event event;
		window.clear();
		window.draw(back_sprite);
		window.draw(top_text);
		window.draw(player_text[0]);
		window.draw(player_text[1]);
		window.draw(player_text[2]);
		window.draw(player_text[3]);
		window.draw(player_text[4]);
		window.draw(play_text);
		window.draw(exit_text);
		window.display();

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) { window.close(); }

			switch (event.type) {
			case ::Event::KeyReleased:
				switch (event.key.code)
				{

				case ::Keyboard::Right:
				{
					exit_text.setCharacterSize(60);
					exit_text.setFillColor(Color::Yellow);
					play_text.setFillColor(Color::White);
					play_text.setPosition(20, 550);
					play_text.setCharacterSize(50);
					s = 0;
					break;

				}

				case  ::Keyboard::Left:
				{
					play_text.setCharacterSize(60);
					play_text.setFillColor(Color::Yellow);
					exit_text.setFillColor(Color::White);
					exit_text.setCharacterSize(50);
					s = 1;

					break;

				}

				case ::Keyboard::Return:
				{
					if (s == 0)
					{

						window.close();
						layy.stop();
						break;
					}
					else if (s == 1) {
						window.close();
						layy.stop();
						level_1 lev(namak);

					}

					break;
				}

				}
			}
		}

		window.clear();
		window.draw(back_sprite);
		window.draw(top_text);
		window.draw(player_text[0]);
		window.draw(player_text[1]);
		window.draw(player_text[2]);
		window.draw(player_text[3]);
		window.draw(player_text[4]);
		window.draw(play_text);
		window.draw(exit_text);
		window.display();
	}
}



top5::~top5(void)
{
}
