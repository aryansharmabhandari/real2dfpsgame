#include "player.h"
# include"math.h"
#include<iostream>
using namespace sf;
using namespace std;

player::player():
 
 playerSpeed (1.0f),   maxfirerate(250),
fireratetimer(0)
{
}

player::~player()
{
}

void player::initialize()
{
	boundingRectangle.setFillColor(Color::Transparent);
	boundingRectangle.setOutlineColor(Color:: Red);
	boundingRectangle.setOutlineThickness(3);
	size = Vector2i(64, 64);
	 

}

void player::load()
{
	if (Texture.loadFromFile("D:/BODY_animation.png")) {
		cout << "player image loaded";
		Sprite.setTexture(Texture);
		int xindex = 0; int yindex = 0;
		Sprite.setTextureRect(IntRect(size.x * xindex, size.y * yindex, size.x, size.y));
	 

		 Sprite.setPosition(Vector2f(800, 400));
		 Sprite.scale(Vector2f(3, 3));
		 boundingRectangle.setSize(
			 Vector2f(size.x * Sprite.getScale().x, Sprite.getScale().y * size.y)
		 );
	}
	else {
		cout << "player image fail to loaded";
	}
}

void player::update(double  deltaTime,skeleton & skeleton, Vector2f& mousePosition)
{
	Vector2f position = Sprite.getPosition();
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		Sprite.setPosition(position + Vector2f(1, 0)* playerSpeed *(float) deltaTime);
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {

		Sprite.setPosition(position + Vector2f(-1, 0) * playerSpeed * (float)deltaTime);
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {

		Sprite.setPosition(position + Vector2f(0, -1) * playerSpeed *(float) deltaTime);
	}
	if ( Keyboard::isKeyPressed(Keyboard::S)) {

		Sprite.setPosition(position + Vector2f(0, 1) * playerSpeed *(float) deltaTime);
	}


	//----------------------------------------------------------------------------------------
	fireratetimer += deltaTime;
 
	if (Mouse::isButtonPressed(Mouse::Button::Left)&& fireratetimer>=maxfirerate) {

		bullets.push_back(bullet());
		int i = bullets.size() - 1;
		bullets[i].initialize(Sprite.getPosition(), mousePosition,0.5f);


		 
		fireratetimer = 0;

	}  
	for (size_t i = 0; i < bullets.size(); i++) {
		//Vector2f  bulletDirection = mousePosition - bullets[i].getPosition();
	//	bulletDirection = math::NormalizeVector(bulletDirection);
	//	bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletspeed  * deltaTime);
		bullets[i].update(deltaTime);
		if (skeleton.health > 0) {
if (math::DidRectCollide(bullets[i].GetGlobalBounds(), skeleton.Sprite.getGlobalBounds())) {
		skeleton.changehealth(-10);
		bullets.erase(bullets.begin() + i);
		}
	
		 
	}
	}
	boundingRectangle.setPosition(Sprite.getPosition());
	
	//----------------------------------------------------------------------------------------

}

void player::Draw(RenderWindow& window)
{
	window.draw(Sprite);
	window.draw(boundingRectangle);
	for (int i = 0; i < bullets.size(); i++) {
		 bullets[i].Draw(window);

	}
}
