#include "bullet.h"
# include"math.h"
bullet::bullet():
	m_speed(0)
{
}

bullet::~bullet()
{
}

void bullet::initialize(const Vector2f & position,const Vector2f &target, float speed)
{
	m_speed = speed;
	rectangleshape.setSize(Vector2f(50, 25));
	rectangleshape.setPosition(position );
	direction = math::NormalizeVector(target - position);
}

 

void bullet::update(double deltaTime)
{
	rectangleshape.setPosition(rectangleshape.getPosition() + direction * m_speed* (float)deltaTime);
}

void bullet::Draw(RenderWindow& window)
{
	window.draw(rectangleshape);
}
