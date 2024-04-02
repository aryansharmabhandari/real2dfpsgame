#pragma once
# include<SFML/Graphics.hpp>
# include"skeleton.h"
# include"bullet.h"
class player

{private:
	Texture Texture;
	vector<bullet>bullets;
	//vector<RectangleShape>bullets;
     
	float maxfirerate;
	double fireratetimer;
	float playerSpeed ;
	RectangleShape boundingRectangle;
	Vector2i size;

public:
	Sprite  Sprite;
public:

	player();
	~player();
	void initialize();
	void load();
	void update(double  deltaTime ,skeleton& skeleton,Vector2f& mousePosition);
	void Draw(RenderWindow& window);
};

