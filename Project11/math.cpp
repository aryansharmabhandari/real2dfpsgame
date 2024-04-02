#include "math.h"
using namespace sf;
Vector2f math::NormalizeVector(Vector2f vector) {
	float m = sqrt(vector.x * vector.x + vector.y * vector.y);
	Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;
	return normalizedVector;
}

bool math::DidRectCollide(FloatRect rect1, FloatRect rect2)
{
	if(rect1.left + rect1.width > rect2.left &&
		rect2.left + rect1.width > rect1.left &&
		rect2.top + rect2.height > rect1.top &&
		rect1.top + rect1.height > rect2.top)
		return true;
	return false;
}
