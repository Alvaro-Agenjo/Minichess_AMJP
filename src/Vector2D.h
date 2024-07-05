#pragma once
#include <iostream>
#include "ETSIDI.h"

struct Vector2D
{
	int x;
	int y;

	//devuelve true si el vector de posicion esta dentro de los limites del tablero
	bool out_of_bounds();	

	//conversión
	explicit operator ETSIDI::Vector2D();

	//////////////////////////////////////////////
	//			OPERACIONES ARITMÉTICAS			//
	//////////////////////////////////////////////
	
	//avanza casilla a casilla como si fuera un tablero de 1D
	Vector2D& operator +=(int valor);	
	Vector2D& operator +=(const Vector2D & rhs);
	Vector2D& operator -=(const Vector2D& rhs);
};

Vector2D operator +( Vector2D lhs, const Vector2D& rhs);
Vector2D operator -( Vector2D lhs, const Vector2D& rhs);
Vector2D operator *(int valor, Vector2D lhs);
Vector2D operator * (Vector2D lhs, int valor);
Vector2D operator /(int valor, Vector2D lhs);

//////////////////////////////////////
//			COMPARACIONES			//
//////////////////////////////////////
bool operator == (const Vector2D& lhs, const Vector2D& rhs);		//sobrecarga del operador == para condiciones (if, else if, else,...)
bool operator != (const Vector2D& lhs, const Vector2D& rhs);		//sobrecarga del operador == para condiciones (if, else if, else,...)

//////////////////////////////////////////
//			TEST POR CONSOLA			//
//////////////////////////////////////////
std::ostream& operator << (std::ostream& o, const Vector2D lhs);
std::istream& operator >> (std::istream& i, Vector2D &lhs);
