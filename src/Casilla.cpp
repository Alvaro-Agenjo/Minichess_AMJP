#include "Casilla.h"

#include <iostream>
using namespace std;

Casilla::Casilla(Vector2D coord) :
	_ocupacion(	Dominio::Vacio),
	_amenaza(false),
	_comer(false),
	_mover(false),
	_coord(coord)
{}

std::ostream& Casilla::print (std::ostream & o) const
{
	o << (int)_ocupacion << " ";
	return o;
}

bool operator==(const Casilla& c1, const Casilla& c2)
{
	return (c1.getPosicion() == c2.getPosicion());
}
