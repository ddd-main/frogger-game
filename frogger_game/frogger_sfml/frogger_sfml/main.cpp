#include<iostream>
#include <string>
#include<ctime>
#include <SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Network.hpp>
#include<SFML\Window.hpp>
#include<vector>
#include "start.h"
#include "level_1.h"
#include "level_2.h"
#include "level_3.h"
#include "top5.h"
using namespace sf;
using namespace std;

int main() {
	string Name;
	cout << "Enter Your Name :";
	cin >> Name;
	start s(Name);

	return 0;
}
