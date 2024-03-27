#include <iostream>
#include <vector>
#include "Peon.h"

void Peon::getPieza()
{
	std::cout << "Peon  ";
}

void Peon::Comprobar_posibles_casillas(TABLERO& tab, int dimx, int dimy)
{
	switch (_jugador)
	{
	case Jugador::Jugador_1:
	{
		if (tab.getOcupacion(_coordX, _coordY + 1) == nullptr)
		{
			_posibles_movimientos.push_back({ _coordX, _coordY + 1 });
		}
		if (tab.getOcupacion(_coordX, _coordY + 2) == nullptr && )
		{
			_posibles_movimientos.push_back({ _coordX, _coordY + 2 });
		}
		break;
	}
	case Jugador::Jugador_2:
	{
		if (tab.getOcupacion(_coordX, _coordY - 1) == nullptr)
		{
			_posibles_movimientos.push_back({ _coordX, _coordY + 1 });
		}
		if (tab.getOcupacion(_coordX, _coordY - 2) == nullptr && )
		{
			_posibles_movimientos.push_back({ _coordX, _coordY + 2 });
		}
		break;
	}
	default:
		break;
	}
	if (tab.getOcupacion(_coordX, _coordY + 1) == nullptr)
	{
		_posibles_movimientos.push_back({ _coordX, _coordY + 1 });
	}
}
