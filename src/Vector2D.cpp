#include "Vector2D.h"

Vector2D operator+(Vector2D lhs, const Vector2D& rhs)
{
	lhs += rhs;
	return lhs;
}

Vector2D operator*(int valor, Vector2D lhs)
{
	Vector2D aux{};
	for (int n = 0; n < valor; n++)
	{
		aux += lhs;
	}
	return aux;
}

bool operator == (const Vector2D& lhs, const Vector2D& rhs)		//sobrecarga del operador ==
{
	//si tanto las coordenadas x como y coinciden los Vector2D son iguales
	return  (lhs.x == rhs.x && lhs.y == rhs.y);
}

bool operator!=(const Vector2D& lhs, const Vector2D& rhs)
{
	return ! operator== (lhs,rhs);
}

std::ostream& operator<<(std::ostream& o, const Vector2D lhs)
{
	o << "[ " << lhs.x << ", " << lhs.y << " ]";
	return o;
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

Vector2D& Vector2D::operator+=(const Vector2D& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

