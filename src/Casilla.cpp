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


