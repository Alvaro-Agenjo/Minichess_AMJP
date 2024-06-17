#include "Caballo.h"

Caballo::Caballo(Casilla* coord, Color col) :
	Pieza(coord, col)
{}

void Caballo::PosiblesMov(std::vector<Casilla> tab)
{
	Casilla aux = *_myCasilla;
	//Caballo movimiento hacia arriba-izda

	aux = getCasilla(*_myCasilla, (2*NORTE+OESTE), tab);
	validarCasilla(aux);

	//Caballo movimiento hacia arriba-dcha

	aux = getCasilla(*_myCasilla, 2*NORTE+ESTE, tab);
	validarCasilla(aux);

	//Caballo movimiento hacia dcha-arriba

	aux = getCasilla(*_myCasilla, 2*ESTE+NORTE, tab);
	validarCasilla(aux);

	//Caballo movimiento hacia dcha-abajo

	aux = getCasilla(*_myCasilla, 2*ESTE+SUR, tab);
	validarCasilla(aux);

	//Caballo movimiento hacia abajo-dcha

	aux = getCasilla(*_myCasilla, 2*SUR+ESTE, tab);
	validarCasilla(aux);

	//Caballo movimiento hacia abajo-izda

	aux = getCasilla(*_myCasilla, 2*SUR+OESTE, tab);
	validarCasilla(aux);

	//Caballo movimiento hacia izda-abajo

	aux = getCasilla(*_myCasilla, 2*OESTE+SUR, tab);
	validarCasilla(aux);

	//Caballo movimiento hacia izda-arriba
	aux = getCasilla(*_myCasilla, 2*OESTE+NORTE, tab);
	validarCasilla(aux);

}

std::ostream& Caballo::operator<< (std::ostream& o) const
{
	if (_color == Color::Blanco)
		o << "C ";
	else
		o << "c ";
	return o;
}

