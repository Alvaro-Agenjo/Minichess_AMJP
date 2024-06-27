#include "Vector2D.h"

bool Vector2D::out_of_bounds()
{
	Vector2D lo_lim{ 0,0 }, hi_lim{ 7,7 };
	if (this->x < lo_lim.x || this->y < lo_lim.y) return true;
	else if (this->x > hi_lim.x || this->y > hi_lim.y) return true;

	return false;
}

Vector2D& Vector2D::operator+=(int valor)
{
	this->y+= valor;
	if (this->y> 7)
	{
		this->y = 0;
		this->x++;
	}
	else if (this->y < 0)
	{
		this->y = 7;
		this->x--;
	}
	return *this;
}	 //avanzar casilla a casilla
Vector2D& Vector2D::operator+=(const Vector2D& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}
Vector2D& Vector2D::operator-=(const Vector2D& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	return *this;
}


Vector2D operator+(Vector2D lhs, const Vector2D& rhs)
{
	lhs += rhs;
	return lhs;
}
Vector2D operator-(Vector2D lhs, const Vector2D& rhs)
{
	lhs -= rhs;
	return lhs;
}

Vector2D operator*(int valor, Vector2D lhs)
{
	return { lhs.x * valor, lhs.y * valor };
}
Vector2D operator/(int valor, Vector2D lhs)
{
	return { lhs.x / valor, lhs.y / valor };
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
std::istream& operator>>(std::istream& i, Vector2D& lhs)
{
	i >> lhs.x >> lhs.y;
	return i;
}

