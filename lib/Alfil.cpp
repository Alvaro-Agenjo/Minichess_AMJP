#include <iostream>
#include <vector>
#include "Alfil.h"

void Alfil::getPieza()
{
	std::cout << "Alfil  ";
}

void Alfil::Comprobar_posibles_casillas(TABLERO& tab, int dimx, int dimy)
{
	bool rep;
	//angulo de 45º
	int n = 1;
	do {
		if (tab.getOcupacion(_coordX + n, _coordY + n) == nullptr) 
		{
			_posibles_movimientos.push_back({ _coordX + n, _coordY + n });
		}
		n++;
	} while (rep);
	//angulo de 135º
	int n = 1;
	do {
		if (tab.getOcupacion(_coordX - n, _coordY + n) == nullptr)
		{
			_posibles_movimientos.push_back({ _coordX - n, _coordY + n });
		}
		n++;
	} while (rep);
	//angulo de 225º
	int n = 1;
	do {
		if (tab.getOcupacion(_coordX - n, _coordY - n) == nullptr)
		{
			_posibles_movimientos.push_back({ _coordX - n, _coordY - n });
		}
		n++;
	} while (rep);
	//angulo de 315º
	int n = 1;
	do {
		if (tab.getOcupacion(_coordX + n, _coordY - n) == nullptr)
		{
			_posibles_movimientos.push_back({ _coordX + n, _coordY - n });
		}
		n++;
	} while (rep);
}
