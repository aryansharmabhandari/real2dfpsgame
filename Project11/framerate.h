#pragma once
 
# include<SFML/Graphics.hpp>
using namespace sf;
class framerate
{
private:
	Text frameRateText;
	Font font;
	double timer;
public:
	framerate();
	~framerate();
	void initialize();
	void load();
	void update(double deltaTime);
	void Draw(RenderWindow& window);
};

