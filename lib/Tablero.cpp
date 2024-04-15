#include "Tablero.h"

/********************************************************************************************
*		librerias para realizar test, serán eliminadas al incorporar interfaz gráfica		*
********************************************************************************************/
#include <iostream>


Tablero::Tablero(Vector2D dim) :
	_dimension(dim)
{
	//reserva de memoria para el tablero, no se pueden inicializar la posicion de las casillas al ser en bloque
	Casilla** tab = new Casilla* [dim.y];
	for (int i = 0; i < dim.y; i++)
	{
		tab[i] = new Casilla[dim.x];
	}

	//inicializacion de posicion de casillas
	for (int y = 0; y < _dimension.y; y++)
	{
		for (int x = 0; x < _dimension.x; x++)
		{
			tab[y][x].setPosicion(Vector2D{ x,y });
		}
	}
	_tablero = tab;
}

Tablero::~Tablero()
{
	for (int y = 0; y < _dimension.y; y++)
	{
		delete[] _tablero[y];
	}
	delete[] _tablero;
}

void Tablero::Refresh(const Jugador& j1, const Jugador& j2)
{
	// limpia toda la informacion del tablero
	for (int y = 0; y < _dimension.y; y++)
	{
		for (int x = 0; x < _dimension.x; x++)
		{
			_tablero[y][x].clearCasilla();
		}
	}

	//vuelve a colocar las piezas del j1
	for (auto n : j1.getMisPiezas())
	{
		Vector2D pos_pieza = n->getPosicion();
		_tablero[pos_pieza.y][pos_pieza.x].setOcupacion(n);
	}
	//vuelve a colocar las piezas del j1
	for (auto n : j2.getMisPiezas())
	{
		Vector2D pos_pieza = n->getPosicion();
		_tablero[pos_pieza.y][pos_pieza.x].setOcupacion(n);
	}
}


/********************************************
* Funciones test, visualizacion en consola	*
********************************************/

void Tablero::VerTablero()
{
	for (int y = 0; y < _dimension.y; y++)
	{
		for (int x = 0; x < _dimension.x; x++)
		{
			Pieza* aux = _tablero[y][x].getOcupacion();			// obtiene el puntero a pieza almacenado en cada casilla
			if (aux != nullptr)									// en caso de no ser nulo (casilla no vacia), imprime el tipo de pieza
			{
				std::cout << aux->getTipoPieza();
			}
			else												//en caso de estar vacia imprime un 0
			{
				std::cout << 0;
			}
		}
		std::cout << std::endl;
	}
	std::cout << "*************************" << std::endl;
}
