#pragma once


#include "Pieza.h"
class Caballo : public Pieza
{
private:


public:

	//Constructor - Destructor
	Caballo(Vector2D pos, Player j);			//Constructor de la pieza peon, accede al constructor de pieza 

	//setter

	//getter
	inline int getTipoPieza() override { return _tpieza; }
	//otros metodos

	//gráficos
};

