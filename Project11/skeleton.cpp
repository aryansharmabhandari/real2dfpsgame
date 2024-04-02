#include "skeleton.h"

#include<iostream>
skeleton::skeleton():health(100)
{
	 
}
skeleton::~skeleton()
{
}
void skeleton::changehealth(int hp)
{
	health += hp;
	healthText.setString(to_string(health));
}
void skeleton::initialize()
{
	boundingRectangle.setFillColor(Color::Transparent);
	boundingRectangle.setOutlineColor(Color::Blue);
	boundingRectangle.setOutlineThickness(3);
	size = Vector2i(64, 64);

} 

void skeleton::load()
{

	if (font.loadFromFile("D:/asstes/arial.ttf")) {
		cout << "arial.ttf font in Assets has been loaded successfully" << endl;
		healthText.setFont(font);
	 healthText.setString(to_string(health));
	}
	else {
		cout << "fail to load arial.ttf font in Assets  " << endl;
	}
 
	if ( Texture.loadFromFile("D:\BODY_animation.png")) {
		cout << "skeleton Image is loaded" << endl;
	 Sprite.setTexture(Texture);
		 Sprite.setPosition(Vector2f(1600,700)); 
 
		int xindex = 0; int yindex = 2;
		 Sprite.setTextureRect(IntRect(size.x * xindex, size.y * yindex, size.x, size.y));
		 
		 Sprite.scale(Vector2f(3, 3));
		 boundingRectangle.setSize(
			 Vector2f(size.x * Sprite.getScale().x, Sprite.getScale().y * size.y)
		 );

	}
	else {
		cout << "skeleton image fail to loaded";
	}

}

void skeleton::update(double deltaTime )
{
	if (health > 0) {
		boundingRectangle.setPosition(Sprite.getPosition());
		healthText.setPosition(Sprite.getPosition());
	}
	

}

void skeleton::Draw(RenderWindow& window)
{if(health>0){window.draw(Sprite);
	window.draw(boundingRectangle);
	window.draw(healthText);}
	
}
