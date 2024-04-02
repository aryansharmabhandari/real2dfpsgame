 
# include<SFML/Graphics.hpp>
using namespace sf;
#pragma once
class math
{public:
	static sf::Vector2f NormalizeVector(sf::Vector2f vector);
	static bool DidRectCollide(FloatRect rect1, FloatRect rect2);
};

