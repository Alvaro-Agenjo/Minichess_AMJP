#include "Ajedrez.h"
#include <iostream>

Ajedrez::Ajedrez() :
	_j1(_tablero.getTablero(), Color::Blanco),
	_j2(_tablero.getTablero(), Color::Negro)
{
	std::cout << "Todo creado" << std::endl;
}

std::ostream& operator << (std::ostream& o, const Ajedrez & aj)
{
	int n = 0;
	for (const auto cas : aj._tablero.getTableroConst())
	{
		if (cas.getOcupacion() == Dominio::Vacio)
		{
			cas.print(o);
		}
		else if (cas.getOcupacion() == Dominio::Blanca)
		{
			aj._j1.print(o, cas);
		}
		else aj._j2.print(o, cas);

		//separacion cada 8 casillas
		n++;
		if (n == 8)
		{
			o << std::endl;
			n = 0;
		}
		
	}
	return o;
}