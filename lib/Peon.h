#pragma once

#include "Pieza.h"

class Peon : public Pieza
{
public:

	//Constructores
	using Pieza::Pieza;

	//getters
	void getPieza() override;
	//setters

	//Otros métodos
	void Comprobar_posibles_casillas( TABLERO& tab, int dimx, int dimy) override;

private:
	bool _mov1 = false;
	
};




