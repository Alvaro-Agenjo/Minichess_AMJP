#include "Torre.h"

Torre::Torre(Casilla *coord, Color col) :
	Pieza(coord, col, t_pieza::TORRE)
{}


void Torre::PosiblesMov(const std::vector<Casilla>& tab)
{
	// marca si el bucle debe continuar comprobando la siguiente casilla en la dirección indicada
	bool continuar = false;

	//Torre movimiento hacia arriba
	Casilla aux = *_myCasilla;
	do 
	{
		aux = getCasilla_copia(aux, NORTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();

	//Torre movimiento hacia derecha
	aux = *_myCasilla;
	do 
	{
		aux = getCasilla_copia(aux, ESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();
	
	//Torre movimiento hacia abajo
	aux = *_myCasilla; 
	do 
	{
		aux = getCasilla_copia(aux, SUR, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();
	
	//Torre movimiento hacia izquierda
	aux = *_myCasilla;
	do 
	{
		aux = getCasilla_copia(aux, OESTE, tab);
		continuar = validarCasilla(aux);
	} while (continuar);
	
	Pieza::ResetP1();
}

std::ostream& Torre::operator<< (std::ostream& o) const
 {
	if (_color == Color::Blanco)
		o << "T ";
	else
		o << "t ";
	return o;
}