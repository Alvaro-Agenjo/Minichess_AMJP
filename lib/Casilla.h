#pragma once
#include"Vector2D.h"

Class Casilla
{
private:
Vector2D _posici�n{};
int _ocupaci�n;
bool _atacada;

public:
	// Constructor 
	Casilla(Vector2D pos);
	//Setter

	//Getter

	// Otros m�todos 

	//M�todos gr�ficos 
	void�dibujar();
};
