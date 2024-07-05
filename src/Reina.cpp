#include "Reina.h"

Reina::Reina(Casilla* coord, Color col) :
	Pieza(coord, col, t_pieza::REINA)
{}


void Reina::PosiblesMov(const std::vector<Casilla>& tab)
{
	// marca si el bucle debe continuar comprobando la siguiente casilla en la dirección indicada
	bool continuar = false;

	//Reina movimiento hacia arriba
	Casilla aux = *_myCasilla;

	do 
	{
		aux = getCasilla_copia(aux, NORTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();

	//Reina movimiento hacia arriba-derecha
	aux = *_myCasilla;
	do 
	{
		aux = getCasilla_copia(aux, NORESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();

	//Reina movimiento hacia derecha
	aux = *_myCasilla;
	do 
	{
		aux = getCasilla_copia(aux, ESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();

	//Reina movimiento hacia abajo-derecha
	aux = *_myCasilla;
	do 
	{
		aux = getCasilla_copia(aux, SUDESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();

	//Reina movimiento hacia abajo
	aux = *_myCasilla;
	do 
	{
		aux = getCasilla_copia(aux, SUR, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();

	//Reina movimiento hacia abajo-izquierda
	aux = *_myCasilla;
	do 
	{
		aux = getCasilla_copia(aux, SUDOESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();

	//Reina movimiento hacia izquierda
	aux = *_myCasilla;
	do 
	{
		aux = getCasilla_copia(aux, OESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();

	//Reina movimiento hacia arriba-izquierda
	aux = *_myCasilla;
	do 
	{
		aux = getCasilla_copia(aux, NOROESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();
}

std::ostream& Reina::operator<< (std::ostream& o) const
{
	if (_color == Color::Blanco)
		o << "R ";
	else
		o << "r ";
	return o;
}