#pragma once

#include "Pieza.h"

class Peon :  public Pieza
{
private:


public:

	//Constructor - Destructor
	Peon(Vector2D pos, Player j);			//Constructor de la pieza peon, accede al constructor de pieza 

	//setter

	//getter
	inline int getTipoPieza() override { return _tpieza; }
	//otros metodos
	void ver_opciones();  // la idea ser�a crearlo como un virtual dado que todos
					      //la necesitan y ayuda con la legibilidad
	//gr�ficos
};

