#include "Ajedrez.h"
#include <iostream>

Ajedrez::Ajedrez() :
	_estado(GameState::Creaccion),
	_j1(_tablero.getTablero(), Color::Blanco),
	_j2(_tablero.getTablero(), Color::Negro)
{
	std::cout << "Todo creado" << std::endl;
	_estado = GameState::B_Actualizar_Amenazas;
}

void Ajedrez::Stateflow()
{
	switch (_estado)
	{
	case Creaccion:
		{
		std::cout << *this << std::endl;
		break;
		}
	case B_Actualizar_Amenazas:
	{
		std::cout << *this << std::endl;
		_tablero.ClearAmenazas();
		_j2.ActualizarAmenazas(_tablero.getTablero());
		_j1.PosiblesMov(_tablero.getTableroConst());

		_estado = B_Espera;
		break;
	}
	case B_Espera:
	{
		std::cout << *this << std::endl;
		_indices = _j1.Movimiento();
		_estado = B_Mov;
		break;
	}
	case B_Mov:
	{
		std::cout << *this << std::endl;
		_j1.ActualizarMovimiento(_indices, _tablero.getTablero());

		_estado = B_Comprobar_Jaques;
		// graficos, mover pieza;
		break;
	}
	case B_Comprobar_Jaques:
	{
		std::cout << *this << std::endl;
		_estado = N_Actualizar_Amenazas;
		break;
	}
	case N_Actualizar_Amenazas:
	{
		std::cout << *this << std::endl;
		_tablero.ClearAmenazas();
		_j1.ActualizarAmenazas(_tablero.getTablero());
		_j2.PosiblesMov(_tablero.getTableroConst());

		_estado = N_Espera;
		break;
	}
	case N_Espera:
	{
		std::cout << *this << std::endl;
		_indices = _j2.Movimiento();
		_estado = N_Mov;
		break;
	}
	case N_Mov:
	{
		std::cout << *this << std::endl;
		_j2.ActualizarMovimiento(_indices, _tablero.getTablero());

		_estado = N_Comprobar_Jaques;
		// graficos, mover pieza;
		break;
	}
	case N_Comprobar_Jaques:
	{
		std::cout << *this << std::endl;
		_estado = B_Actualizar_Amenazas;
		break;
	}
	default:
		break;
	}
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

std::ostream& Ajedrez::printAmenazas(std::ostream& o)
{
	int n = 0;
	for (const auto cas : _tablero.getTableroConst())
	{
		o << cas.getAmenaza() << " ";
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

std::ostream& Ajedrez::printAmenazas(std::ostream& o)
{
	int n = 0;
	for (const auto cas : _tablero.getTableroConst())
	{
		o << cas.getAmenaza() << " ";
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

std::ostream& operator << (std::ostream& o, const Ajedrez& aj)
std::ostream& operator << (std::ostream& o, const Ajedrez& aj)
{
	o << "Estado de la partida: ";
	switch (aj.getEstado())
	{
	case GameState::Creaccion:
	{
		o << "Creando la partida.";
		break;
	}
	case GameState::B_Actualizar_Amenazas:
	{
		o << "Actualizando las amenazas del tablero.";
		break;
	}
	case GameState::B_Espera:
	{
		o << "Esperando el movimiento de las blancas";
		break;
	}
	case GameState::B_Mov:
	{
		o << "Blancas moviendo";
		break;
	}
	case GameState::B_Comprobar_Jaques:
	{
		o << "Comprobando Jaque sobre negras";
		break;
	}
	case GameState::N_Actualizar_Amenazas:
	{
		o << "Actualizando las amenazas del tablero.";
		break;
	}
	case GameState::N_Espera:
	{
		o << "Esperando el movimiento de las negras";
		break;
	}
	case GameState::N_Mov:
	{
		o << "Negras moviendo";
		break;
	}
	case GameState::N_Comprobar_Jaques:
	{
		o << "Comprobando Jaque sobre blancas";
		break;
	}
	default:
		break;
	}
	return o;
}