# include<SFML/Graphics.hpp>
# include<iostream>
 

# include"framerate.h"
# include"mappi.h"
# include"player.h"
#include "skeleton.h"
# include"mapLoader.h"
using namespace std;

using namespace sf;

 
int main() {
	//-----------------Initialize--------------
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(2000, 800), "RPG game", Style::Default, settings);
	window.setFramerateLimit(360);
	//-----------------Initialize--------------
    
	framerate frameRate;
	mappi map;
	player  player;
	skeleton skeleton;
	mapLoader maploader;
	maploader.Load("D:/assets/best.txt");
	// -------------------initialize------------------------
	frameRate.initialize();
	map.initialize();
	player.initialize();
	skeleton.initialize();
	
	// -------------------initialize------------------------
	frameRate.load();
	map.load();
	player.load();
	skeleton.load();
	// -------------------load--------------------

	Clock clock;
	  
	Time deltaTimeTimer;
	while (window.isOpen()) {
		Time deltaTimeTimer = clock.restart();
		double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;
		 
		//cout << "FPS :" << 1000.0 / deltaTime << "Frame time is " << deltaTime << endl;
		//------------------------------update---------------------------------------
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		Vector2f mousePosition =  Vector2f(Mouse::getPosition(window));
		cout << "Mouse Position: "  << mousePosition.x << mousePosition.y<< endl;
		 
		//bullet.setPosition(bullet.getPosition() + bulletdirection*bulletspeed );
		frameRate.update(deltaTime);
		map.update(deltaTime);
		skeleton.update(deltaTime);
		player.update(deltaTime, skeleton, mousePosition);
		//-----------------------update--------------------------------------
		//------------------------Draw------------------
		window.clear(Color::Red);
		map.Draw(window);
		skeleton.Draw(window);
		player.Draw(window);
		frameRate.Draw(window);
		window.display(); 
		//-------------------draw---------------

	}
	return 0;
}
 