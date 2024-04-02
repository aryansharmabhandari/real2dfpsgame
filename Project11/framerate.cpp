#include "framerate.h"
# include<iostream>
using namespace std;
framerate::framerate():
	timer(0) {
	 
}
framerate::~framerate()
{
 


}
void framerate::initialize()
{

}

void framerate::load()
{
	if (font.loadFromFile("D:/asstes/arial.ttf")) {
		cout << "arial.ttf font in Assets has been loaded successfully" << endl;
		frameRateText.setFont(font);
	}
	else {
		cout << "fail to load arial.ttf font in Assets  " << endl;
	}
}

void framerate::update(double deltaTime)
{
	timer += deltaTime;
	if (timer >= 100.0) {
		double fps = 1000.0 / deltaTime;
	string frameRatestring = "FPS:" + to_string((int)fps) + "Frame time is " + to_string(deltaTime);

	cout << deltaTime << endl;
	frameRateText.setString(frameRatestring);
	timer = 0;
	}
	
 
}

void framerate::Draw(RenderWindow& window)
{
	window.draw(frameRateText);
}
