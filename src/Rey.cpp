#include "Rey.h"

Rey::Rey(Casilla* coord, Color col) :
	Pieza(coord, col)
{}

void Rey::PosiblesMov(std::vector<Casilla> tab)
{
	Casilla aux = *_myCasilla;
	//Rey movimiento hacia arriba
	
	aux = getCasilla(*_myCasilla, NORTE, tab);
	validarCasilla(aux);

	//Rey movimiento hacia arriba-dcha

	aux = getCasilla(*_myCasilla, NORESTE, tab);
	validarCasilla(aux);

	//Rey movimiento hacia dcha

	aux = getCasilla(*_myCasilla, ESTE, tab);
	validarCasilla(aux);

	//Rey movimiento hacia abajo-dcha

	aux = getCasilla(*_myCasilla, SUDESTE, tab);
	validarCasilla(aux);
	//Rey movimiento hacia abajo
	
	aux = getCasilla(*_myCasilla, SUR, tab);
	validarCasilla(aux);

	//Rey movimiento hacia abajo-izda

	aux = getCasilla(*_myCasilla, SUDOESTE, tab);
	validarCasilla(aux);

	//Rey movimiento hacia izda

	aux = getCasilla(*_myCasilla, OESTE, tab);
	validarCasilla(aux);
	

	//Rey movimiento hacia arriba-izda
	aux = getCasilla(*_myCasilla, NOROESTE, tab);
	validarCasilla(aux);
	
}

std::ostream& Rey::operator<< (std::ostream& o) const
{
	if (_color == Color::Blanco)
		o << "Y ";
	else
		o << "y ";
	return o;
}

