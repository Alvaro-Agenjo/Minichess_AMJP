#include "Torre.h"

Torre::Torre(Casilla *coord, Color col) :
	Pieza(coord, col)
{}

void Torre::PosiblesMov(std::vector<Casilla> tab)
{
	//Torre movimiento hacia arriba
	bool continuar = false;
	Casilla aux = *_myCasilla;
	do {
		aux = getCasilla(aux, NORTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);

	//Torre movimiento hacia derecha

	aux = *_myCasilla;
	do {
		aux = getCasilla(aux, ESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);

	//Torre movimiento hacia abajo

	aux = *_myCasilla; 
	do {
		aux = getCasilla(aux, SUR, tab);
		continuar = validarCasilla(aux);
	} while (continuar);

	//Torre movimiento hacia izquierda

	aux = *_myCasilla;
	do {
		aux = getCasilla(aux, OESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
}

std::ostream& Torre::operator<< (std::ostream& o) const
 {
	if (_color == Color::Blanco)
		o << "T ";
	else
		o << "t ";
	return o;
}

