#include "Vector2D.h"

bool Vector2D::operator==(const Vector2D& coord)		//sobrecarga del operador ==
{
	if (x == coord.x && y ==coord.y)		//si tanto las coordenadas x como y coinciden los Vector2D son iguales
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Vector2D::operator<(const Vector2D& coord)
{
	if (x < coord.x && y < coord.y)		//si tanto las coordenadas x como y coinciden los Vector2D son iguales
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Vector2D::operator<=(const Vector2D& coord)
{
	if (x <= coord.x && y <= coord.y)
	{
		return true;
	}
	return false;
}
