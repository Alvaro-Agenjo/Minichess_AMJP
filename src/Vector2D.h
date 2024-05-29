#pragma once

struct Vector2D
{
	int x;
	int y;

	
};
bool operator == (const Vector2D& lhs, const Vector2D& rhs);		//sobrecarga del operador == para condiciones (if, else if, else,...)
bool operator != (const Vector2D& lhs, const Vector2D& rhs);		//sobrecarga del operador == para condiciones (if, else if, else,...)