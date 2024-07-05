#include "Rey.h"

Rey::Rey(Casilla* coord, Color col) :
	Pieza(coord, col, t_pieza::REY)
{}



void Rey::PosiblesMov(const std::vector<Casilla>& tab)
{
	//Rey movimiento hacia arriba
	Casilla aux = *_myCasilla;
	aux = getCasilla_copia(*_myCasilla, NORTE, tab);
	validarCasilla(aux);
	
	Pieza::ResetP1();

	//Rey movimiento hacia arriba-derecha
	aux = getCasilla_copia(*_myCasilla, NORESTE, tab);
	validarCasilla(aux);

	Pieza::ResetP1();

	//Rey movimiento hacia derecha
	aux = getCasilla_copia(*_myCasilla, ESTE, tab);
	validarCasilla(aux);

	Pieza::ResetP1();

	//Rey movimiento hacia abajo-derecha
	aux = getCasilla_copia(*_myCasilla, SUDESTE, tab);
	validarCasilla(aux);

	Pieza::ResetP1();
	
	//Rey movimiento hacia abajo
	aux = getCasilla_copia(*_myCasilla, SUR, tab);
	validarCasilla(aux);

	Pieza::ResetP1();

	//Rey movimiento hacia abajo-izquierda
	aux = getCasilla_copia(*_myCasilla, SUDOESTE, tab);
	validarCasilla(aux);

	Pieza::ResetP1();

	//Rey movimiento hacia izquierda
	aux = getCasilla_copia(*_myCasilla, OESTE, tab);
	validarCasilla(aux);
	
	Pieza::ResetP1();

	//Rey movimiento hacia arriba-izquierda
	aux = getCasilla_copia(*_myCasilla, NOROESTE, tab);
	validarCasilla(aux);

	Pieza::ResetP1();
}


std::ostream& Rey::operator<< (std::ostream& o) const
{
	if (_color == Color::Blanco)
		o << "Y ";
	else
		o << "y ";
	return o;
}