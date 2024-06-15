#pragma once

struct Vector2D
{
	int x;
	int y;

	Vector2D& operator +=(int valor);
};
bool operator == (const Vector2D& lhs, const Vector2D& rhs);		//sobrecarga del operador == para condiciones (if, else if, else,...)
bool operator != (const Vector2D& lhs, const Vector2D& rhs);		//sobrecarga del operador == para condiciones (if, else if, else,...)