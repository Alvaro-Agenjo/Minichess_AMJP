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

/********************************************
* Funciones test, visualizacion en consola	*
********************************************/

void Tablero::VerTablero()
{
	for (int y = 0; y < _dimension.y; y++)
	{
		for (int x = 0; x < _dimension.x; x++)
		{
			int aux = _tablero[y][x].getOcupacion();			// obtiene el puntero a pieza almacenado en cada casilla
			if (aux < 0)									// en caso de no ser nulo (casilla no vacia), imprime el tipo de pieza
			{
				std::cout << aux;
			}
			else if (aux > 0)
			{
				std::cout << " " << aux;
			}
			else												//en caso de estar vacia imprime un 0
			{
				std::cout << " 0";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "*************************" << std::endl;
}

void Tablero::VerCasillas()
{
	for (int y = 0; y < _dimension.y; y++)
	{
		for (int x = 0; x < _dimension.x; x++)
		{
			Casilla aux = _tablero[y][x];			// obtiene el puntero a pieza almacenado en cada casilla
			if (aux.getPuedeMover() && aux.getAtacada())									// en caso de no ser nulo (casilla no vacia), imprime el tipo de pieza
			{
				std::cout << " c";
			}
			else if (aux.getAtacada())
			{
				std::cout << " a";
			}
			else if (aux.getPuedeMover())
			{
				std::cout << " m";
			}
			else												//en caso de estar vacia imprime un 0
			{
				std::cout << " 0";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "*************************" << std::endl;
}
