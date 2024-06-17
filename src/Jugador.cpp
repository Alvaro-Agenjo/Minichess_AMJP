#include "Jugador.h"

Jugador::Jugador(std::vector<Casilla>& tab, Color c)
{
	if (c == Color::Negro) _pos = { 7,7 };
	CrearJugador(tab, _pos, c);
	std::cout << "Jugador creado" << std::endl;
}

void Jugador::Actualizar_Amenazas( std::vector<Casilla> &tab)
{
	PosiblesMov(tab);

	for (Pieza* p : _misPiezas)
	{
		p->ActualizarTablero(tab);
	}
}

void Jugador::PosiblesMov(std::vector<Casilla> tab)
{
	for (Pieza* p : _misPiezas)
	{
		p->PosiblesMov(tab);
	}
}

std::ostream& Jugador::print(std::ostream& o, Casilla cas) const
{
	for (const Pieza* p : _misPiezas)
	{
 		if (*p->getCasilla() == cas)
		{
			*p << o;
			return o;
		}
	}
	return o;
}

void Jugador::CrearPieza(Casilla* c, Color col, t_pieza p)
{
	switch (p)
	{
	case t_pieza::PEON:
	{
		//_misPiezas.push_back(new Peon(c, col));
		break;
	}
	case t_pieza::TORRE:
	{
		_misPiezas.push_back(new Torre(c, col));
		break;
	}
	case t_pieza::CABALLO:
	{

		_misPiezas.push_back(new Caballo(c, col));
		break;
	}
	case t_pieza::ALFIL:
	{
		_misPiezas.push_back(new Alfil(c, col));
		break;
	}
	case t_pieza::REINA:
	{
		_misPiezas.push_back(new Reina(c, col));
		break;
	}
	case t_pieza::REY:
	{
		_misPiezas.push_back(new Rey(c, col));
		break;
	}
	default:
		break;
	}
}

void Jugador::CrearJugador(std::vector<Casilla> &tab, Vector2D pos_ini, Color c)
{
	CrearPieza(&tab[pos_ini.x + pos_ini.y*8], c, t_pieza::TORRE);
	pos_ini+=static_cast<int>(c);
	CrearPieza(&tab[pos_ini.x + pos_ini.y*8], c, t_pieza::CABALLO);
	pos_ini+=static_cast<int>(c);
	CrearPieza(&tab[pos_ini.x + pos_ini.y*8], c, t_pieza::ALFIL);
	pos_ini+=static_cast<int>(c);
	CrearPieza(&tab[pos_ini.x + pos_ini.y*8], c, t_pieza::REINA);
	pos_ini+=static_cast<int>(c);
	CrearPieza(&tab[pos_ini.x + pos_ini.y*8], c, t_pieza::REY);
	pos_ini+=static_cast<int>(c);
	CrearPieza(&tab[pos_ini.x + pos_ini.y*8], c, t_pieza::ALFIL);
	pos_ini+=static_cast<int>(c);
	CrearPieza(&tab[pos_ini.x + pos_ini.y*8], c, t_pieza::CABALLO);
	pos_ini+=static_cast<int>(c);
	CrearPieza(&tab[pos_ini.x + pos_ini.y*8], c, t_pieza::TORRE);
	pos_ini+=static_cast<int>(c);

	for (int n = 0; n < 8; n++)
	{
		CrearPieza(&tab[pos_ini.x + pos_ini.y*8], c, t_pieza::PEON);
		pos_ini+=static_cast<int>(c);
	}
}

