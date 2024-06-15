#include "Tablero.h"

Tablero::Tablero()	
{
	for (int y = 0; y < filas; y++)
	{
		for (int x = 0; x < columnas; x++)
		{
			_tablero.push_back(*new Casilla({ x, y }));
		}
	}

	std::cout << "Tablero creado" << std::endl;
}

Tablero::~Tablero()
{
	_tablero.clear();
}
