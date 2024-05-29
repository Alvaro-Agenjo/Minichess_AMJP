#include "Vector2D.h"

bool operator == (const Vector2D& lhs, const Vector2D& rhs)		//sobrecarga del operador ==
{
	//si tanto las coordenadas x como y coinciden los Vector2D son iguales
	return  (lhs.x == rhs.x && lhs.y == rhs.y);
}

bool operator!=(const Vector2D& lhs, const Vector2D& rhs)
{
	return ! operator== (lhs,rhs);
}
