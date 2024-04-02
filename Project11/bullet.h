#pragma once
# include<SFML/Graphics.hpp>
using namespace sf;
class bullet
{
public:
	
	
 
private:
	RectangleShape rectangleshape;
	Vector2f direction;
	float m_speed;
public:
	bullet();
	~bullet();
	void initialize(const Vector2f &position,const Vector2f& target,float speed);
 
	void update(double  deltaTime);
	void Draw(RenderWindow& window);
	inline const FloatRect& GetGlobalBounds() {
		return rectangleshape.getGlobalBounds();
	}
};

