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

Vector2D& Vector2D::operator+=(int valor)
{
	this->x+= valor;
	if (this->x > 7)
	{
		this->x = 0;
		this->y++;
	}
	else if (this->x < 0)
	{
		this->x = 8;
		this->y--;
	}
	return *this;
}


