#pragma once
# include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class skeleton
{
private:
	
	Text healthText;
	Font font;
	Texture Texture;

public:
	Sprite  Sprite;
	RectangleShape boundingRectangle;
	Vector2i size;
	int health;
public:
	skeleton();
	~skeleton();
	void changehealth(int hp);
	void initialize();
	void load();
	void update(double  deltaTime );
	void Draw(RenderWindow& window);
};

