#pragma once

#include"Vector2D.h"

class Casilla
{
private:
	Vector2D _posicion{};
	int _ocupaci�n;
	bool _atacada;

public:
	// Constructor 
	Casilla(Vector2D pos);
	//Setter

	//Getter

	// Otros m�todos 

	//M�todos gr�ficos 
	void dibujar();
};
