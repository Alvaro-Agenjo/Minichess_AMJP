#include "Vector2D.h"

bool operator==(const Vector2D& lhs, const Vector2D& rhs)
{
	if (lhs.x == rhs.x && lhs.y == rhs.y) { return true; }
	return false;
}

bool operator!=(const Vector2D& lhs, const Vector2D& rhs)
{
	return !operator==(lhs,rhs);
}

bool operator<(const Vector2D& lhs, const Vector2D& rhs)
{
	if (lhs.x < rhs.x && lhs.y < rhs.y) { return true; }
	return false;
}

bool operator>(const Vector2D& lhs, const Vector2D& rhs)
{
	return operator<(rhs,lhs);
}

bool operator<=(const Vector2D& lhs, const Vector2D& rhs)
{
	return !operator>(lhs,rhs);
}

bool operator>=(const Vector2D& lhs, const Vector2D& rhs)
{
	return !operator<(lhs, rhs);
}

