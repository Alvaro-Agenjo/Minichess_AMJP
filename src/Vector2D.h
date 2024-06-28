#pragma once
#include <iostream>
#include "ETSIDI.h"

struct Vector2D
{
	int x;
	int y;

	bool out_of_bounds();	//false si dentro de tablero

	explicit operator ETSIDI::Vector2D();
	
	Vector2D& operator +=(int valor);
	Vector2D& operator +=(const Vector2D & rhs);
	Vector2D& operator -=(const Vector2D& rhs);

	
};

Vector2D operator +( Vector2D lhs, const Vector2D& rhs);
Vector2D operator -( Vector2D lhs, const Vector2D& rhs);
Vector2D operator *(int valor, Vector2D lhs);
Vector2D operator * (Vector2D lhs, int valor);
Vector2D operator /(int valor, Vector2D lhs);

bool operator == (const Vector2D& lhs, const Vector2D& rhs);		//sobrecarga del operador == para condiciones (if, else if, else,...)
bool operator != (const Vector2D& lhs, const Vector2D& rhs);		//sobrecarga del operador == para condiciones (if, else if, else,...)


std::ostream& operator << (std::ostream& o, const Vector2D lhs);
std::istream& operator >> (std::istream& i, Vector2D &lhs);
