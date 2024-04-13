#pragma once
#include"Vector2D.h"

Class Casilla
{
private:
Vector2D _posición{};
int _ocupación;
bool _atacada;

public:
	// Constructor 
	Casilla(Vector2D pos);
	//Setter

	//Getter

	// Otros métodos 

	//Métodos gráficos 
	void dibujar();
};
