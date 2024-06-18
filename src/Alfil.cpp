#include "Alfil.h"

Alfil::Alfil(Casilla* coord, Color col) :
	Pieza(coord, col)
{}

//Comentario

void Alfil::PosiblesMov(const std::vector<Casilla>& tab)
{
	//Alfil movimiento hacia arriba-dcha
	bool continuar = false;
	Casilla aux = *_myCasilla;
	do {
		aux = getCasilla(aux, NORESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);

	//Alfil movimiento hacia abajo-derecha

	aux = *_myCasilla;
	do {
		aux = getCasilla(aux, SUDESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);

	//Alfil movimiento hacia abajo-izda

	aux = *_myCasilla;
	do {
		aux = getCasilla(aux, SUDOESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);

	//Alfil movimiento hacia arriba-izquierda

	aux = *_myCasilla;
	do {
		aux = getCasilla(aux, NOROESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
}

std::ostream& Alfil::operator<< (std::ostream& o) const
{
	if (_color == Color::Blanco)
		o << "A ";
	else
		o << "a ";
	return o;
}

