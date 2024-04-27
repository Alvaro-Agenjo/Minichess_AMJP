#pragma once


#include "Pieza.h"
class Reina : public Pieza
{
private:


public:

	//Constructor - Destructor
	Reina(Vector2D pos, Player j);			//Constructor de la pieza peon, accede al constructor de pieza 

	//setter

	//getter
	inline int getTipoPieza() override { return _tpieza; }
	//otros metodos
	void reglasMovimiento() override;
	//gráficos
};

