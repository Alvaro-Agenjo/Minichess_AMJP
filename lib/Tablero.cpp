#include "Tablero.h"

#include <iostream>

TABLERO::TABLERO(int DX, int DY)
{
	_dimX = DX;
	_dimY = DY;
	_tablero = Crear_Tablero();
}

void TABLERO::Colocar_Pieza(Pieza* p, int x, int y, bool inicio=0)
{
	if (!inicio)
	{
		_tablero[p->getCoord_Y()][p->getCoord_X()] = nullptr;		//borramos la pieza de la posicion anterior
	}
	_tablero[y][x] = p;											//añadimos la pieza a la nueva posicion

	p->setCoord(x, y);
}

Pieza*** TABLERO::Crear_Tablero()
{
	Pieza*** tab = new Pieza** [_dimY];
	for (int y = 0; y < _dimY; y++)
	{   
		tab[y] = new Pieza*[_dimX];
	}
	
	for (int y = 0; y < _dimY; y++)
	{
		for (int x = 0; x < _dimX; x++)
		{
			tab[y][x]= nullptr;
		}
	}
	return tab;
}

void TABLERO::Liberar_Tablero()
{
	for (int y = 0; y < _dimY; y++)
	{
		delete _tablero[y];
	}
	delete _tablero;
	_tablero = nullptr;
}

void TABLERO::Ver_Tablero_test()
{
	for (int y = 0; y < _dimY; y++)
	{
		std::cout << "[ ";
		for (int x = 0; x < _dimX; x++)
		{
			if (_tablero[y][x] != nullptr)
			{
				_tablero[y][x]->getPieza();
			}
			else
			{
				std::cout << "vacio ";
			}
		}
		std::cout << "]" << std::endl;
	}
	std::cout << "************************" << std::endl;
}
