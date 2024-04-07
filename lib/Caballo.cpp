#include <iostream>
#include <vector>
#include "Caballo.h"

void Caballo::getPieza()
{
	std::cout << "Caballo  ";
}

void Caballo::Comprobar_posibles_casillas(TABLERO& tab, int dimx, int dimy)
{
	if (tab.getOcupacion(_coordX+2, _coordY +3) == nullptr) //2 3
	{
			_posibles_movimientos.push_back({ _coordX+2, _coordY + 3 });
	}
	if (tab.getOcupacion(_coordX + 2, _coordY -3 ) == nullptr) // 2 -3
	{
		_posibles_movimientos.push_back({ _coordX + 2, _coordY - 3 });
	}
	if (tab.getOcupacion(_coordX + 3, _coordY + 2) == nullptr) // 3 2
	{
		_posibles_movimientos.push_back({ _coordX + 3, _coordY + 2 });
	}
	if (tab.getOcupacion(_coordX + 3, _coordY - 2) == nullptr) // 3 -2
	{
		_posibles_movimientos.push_back({ _coordX + 3, _coordY - 2 });
	}
	if (tab.getOcupacion(_coordX -2, _coordY + 3) == nullptr) // -2 3
	{
		_posibles_movimientos.push_back({ _coordX -2, _coordY + 3 });
	}
	if (tab.getOcupacion(_coordX - 2, _coordY - 3) == nullptr) // -2 -3
	{
		_posibles_movimientos.push_back({ _coordX - 2, _coordY - 3 });
	}
	if (tab.getOcupacion(_coordX - 3, _coordY + 2) == nullptr) // -3 2
	{
		_posibles_movimientos.push_back({ _coordX - 3, _coordY + 2 });
	}
	if (tab.getOcupacion(_coordX - 3, _coordY - 2) == nullptr) // -3 -2
	{
		_posibles_movimientos.push_back({ _coordX - 3, _coordY - 2 });
	}
}
