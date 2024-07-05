#include "Alfil.h"

Alfil::Alfil(Casilla* coord, Color col) :
	Pieza(coord, col, t_pieza::ALFIL)
{}

void Alfil::PosiblesMov(const std::vector<Casilla>& tab)
{
	// marca si el bucle debe continuar comprobando la siguiente casilla en la dirección indicada
	bool continuar = false;

	//Alfil movimiento hacia arriba-derecha
	Casilla aux = *_myCasilla;
	do 
	{
		aux = getCasilla_copia(aux, NORESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);

	Pieza::ResetP1();

	//Alfil movimiento hacia abajo-derecha
	aux = *_myCasilla;
	do 
	{
		aux = getCasilla_copia(aux, SUDESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();

	//Alfil movimiento hacia abajo-izquierda
	aux = *_myCasilla;
	do
	{
		aux = getCasilla_copia(aux, SUDOESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();
	
	//Alfil movimiento hacia arriba-izquierda
	aux = *_myCasilla;
	do
	{
		aux = getCasilla_copia(aux, NOROESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();
}

std::ostream& Alfil::operator<< (std::ostream& o) const
{
	if (_color == Color::Blanco)
		o << "A ";
	else
		o << "a ";
	return o;
}

