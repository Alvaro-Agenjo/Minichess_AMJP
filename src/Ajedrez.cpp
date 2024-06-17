#include "Ajedrez.h"
#include <iostream>

Ajedrez::Ajedrez() :
	_estado(GameState::Creaccion),
	_j1(_tablero.getTablero(), Color::Blanco),
	_j2(_tablero.getTablero(), Color::Negro)
{
	std::cout << "Todo creado" << std::endl;
	_estado = GameState::Espera_blancas;
}

std::ostream& Ajedrez::printTablero(std::ostream& o)
{
	int n = 0;
	for (const auto cas : _tablero.getTableroConst())
	{
		if (cas.getOcupacion() == Dominio::Vacio)
		{
			cas.print(o);
		}
		else if (cas.getOcupacion() == Dominio::Blanca)
		{
			_j1.print(o, cas);
		}
		else _j2.print(o, cas);

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

std::ostream& operator << (std::ostream& o, const Ajedrez & aj)
{
	o << "Estado de la partida: ";
	switch (aj.getEstado())
	{
	case GameState::Creaccion:
	{
		o << "Creando la partida.";
		break;
	}
	case GameState::Espera_blancas:
	{
		o << "Esperando el movimiento de las blancas.";
		break;
	}
	case GameState::Espera_negras:
	{
		o << "Esperando el movimiento de las negras.";
		break;
	}
	case GameState::Gana_blancas:
	{
		o << "Blancas ganan";
		break;
	}
	case GameState::Gana_negras:
	{
		o << "Negras ganan";
		break;
	}
	case GameState::Mov_blancas:
	{
		o << "Blancas moviendose";
		break;
	}
	case GameState::Mov_negras:
	{
		o << "Negras moviendose";
		break;
	}
	default:
		break;
	}
	return o;
}