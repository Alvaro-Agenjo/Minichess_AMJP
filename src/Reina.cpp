#include "Reina.h"

Reina::Reina(Casilla* coord, Color col) :
	Pieza(coord, col)
{}

void Reina::PosiblesMov(const std::vector<Casilla>& tab)
{
	//Reina movimiento hacia arriba
	bool continuar = false;
	Casilla aux = *_myCasilla;

	do {
		aux = getCasilla_copia(aux, NORTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);

	//Reina movimiento hacia arriba-dcha

	aux = *_myCasilla;
	do {
		aux = getCasilla_copia(aux, NORESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);

	//Reina movimiento hacia dcha

	aux = *_myCasilla;
	do {
		aux = getCasilla_copia(aux, ESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);

	//Reina movimiento hacia abajo-dcha

	aux = *_myCasilla;
	do {
		aux = getCasilla_copia(aux, SUDESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);

	//Reina movimiento hacia abajo
	aux = *_myCasilla;
	do {
		aux = getCasilla_copia(aux, SUR, tab);
		continuar = validarCasilla(aux);
	} while (continuar);

	//Reina movimiento hacia abajo-izda

	aux = *_myCasilla;
	do {
		aux = getCasilla_copia(aux, SUDOESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);

	//Reina movimiento hacia izda

	aux = *_myCasilla;
	do {
		aux = getCasilla_copia(aux, OESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);


	//Reina movimiento hacia arriba-izda
	
	aux = *_myCasilla;
	do {
		aux = getCasilla_copia(aux, NOROESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
}

std::ostream& Reina::operator<< (std::ostream& o) const
{
	if (_color == Color::Blanco)
		o << "R ";
	else
		o << "r ";
	return o;
}

