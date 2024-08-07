#include "Caballo.h"

Caballo::Caballo(Casilla* coord, Color col) :
	Pieza(coord, col, t_pieza::CABALLO)
{}


void Caballo::PosiblesMov(const std::vector<Casilla>& tab)
{
	Casilla aux = *_myCasilla;

	//Caballo movimiento hacia arriba-izquierda
	aux = getCasilla_copia(*_myCasilla, (2*NORTE+OESTE), tab);
	validarCasilla(aux);
	
	Pieza::ResetP1();

	//Caballo movimiento hacia arriba-derecha
	aux = getCasilla_copia(*_myCasilla, 2*NORTE+ESTE, tab);
	validarCasilla(aux);

	Pieza::ResetP1();

	//Caballo movimiento hacia derecha -arriba
	aux = getCasilla_copia(*_myCasilla, 2*ESTE+NORTE, tab);
	validarCasilla(aux);

	Pieza::ResetP1();
	
	//Caballo movimiento hacia derecha-abajo
	aux = getCasilla_copia(*_myCasilla, 2*ESTE+SUR, tab);
	validarCasilla(aux);

	Pieza::ResetP1();

	//Caballo movimiento hacia abajo-derecha
	aux = getCasilla_copia(*_myCasilla, 2*SUR+ESTE, tab);
	validarCasilla(aux);

	Pieza::ResetP1();

	//Caballo movimiento hacia abajo-izquierda
	aux = getCasilla_copia(*_myCasilla, 2*SUR+OESTE, tab);
	validarCasilla(aux);

	Pieza::ResetP1();

	//Caballo movimiento hacia izquierda-abajo
	aux = getCasilla_copia(*_myCasilla, 2*OESTE+SUR, tab);
	validarCasilla(aux);

	Pieza::ResetP1();

	//Caballo movimiento hacia izquierda-arriba
	aux = getCasilla_copia(*_myCasilla, 2*OESTE+NORTE, tab);
	validarCasilla(aux);

	Pieza::ResetP1();
}

std::ostream& Caballo::operator<< (std::ostream& o) const
{
	if (_color == Color::Blanco)
		o << "C ";
	else
		o << "c ";
	return o;
}

