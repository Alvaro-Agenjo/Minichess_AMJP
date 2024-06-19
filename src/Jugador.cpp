#include "Jugador.h"

Jugador::Jugador(std::vector<Casilla>& tab, Color c)
{
	if (c == Color::Negro) _pos = { 7,0 };
	CrearJugador(tab, _pos, c);
	std::cout << "Jugador creado" << std::endl;
}

void Jugador::BorrarPieza(Casilla& c)
{
	std::vector<Pieza*>::iterator it;
	for (int n =0; n< _misPiezas.size();n++)
	{
		if (_misPiezas[n]->getCasilla() == &c)
		{
			it = _misPiezas.begin() +n;
			_misPiezas.erase(it);
			break;
		}
	}
}

void Jugador::PosiblesMov(std::vector<Casilla> tab)
{
	for (Pieza* p : _misPiezas)
	{
		p->Clear();
		p->PosiblesMov(tab);
	}
}
void Jugador::ActualizarAmenazas(std::vector<Casilla>& tab)
{
	PosiblesMov(tab);

	for (Pieza* p : _misPiezas)
	{
		p->ActualizarTablero(tab);
	}
}

Vector2D Jugador::Movimiento(const std::vector<Casilla>& tab)
{
	/*Seleccion mediante ratón de la pieza a mover, una vez seleccionada "iluminar" casillas válidas
	despues, selecionar destino. Una vez confirmado el destino --> siguiente fase*/
	Vector2D pos;
	int indice_p = 0, indice_c =0;
	
	do
	{
		do {
			// desiluminar casillas aquí

			if (indice_p == -1)
			{
				std::cout << "No puede mover la pieza seleccionada" << std::endl;
			}
			std::cout << "Indique coordenadas de la pieza a mover" << std::endl;
			std::cin >> pos;
			indice_p = ValidarPieza(pos);
		} while (indice_p == -1);
		do
		{
			//iluminar casillas validas aquí

			if (indice_c == -1)
			{
				std::cout << "No puede mover la pieza seleccionadaa esa casilla" << std::endl;
			}
			std::cout << "Indique coordenadas del destino" << std::endl;
			std::cin >> pos;
			if (pos != go_back)
				indice_c = ValidarDestino_pieza(pos, indice_p, tab);
			else
				indice_c = 0;

		} while (indice_c == -1);
	} while (pos == go_back);

	return  { indice_p, indice_c };
}
int Jugador::ValidarPieza(Vector2D pos)
{
	for (int n = 0; n < _misPiezas.size(); n++)
	{
		if (_misPiezas[n]->getCasilla()->getPosicion() == pos) return n;
	}
	return -1;
}
int Jugador::ValidarDestino_pieza(Vector2D pos, int indice, const std::vector<Casilla>& tab)
{
	return _misPiezas[indice]->ValidarDestino(pos, tab);
}

void Jugador::ActualizarMovimiento(Vector2D indices, std::vector<Casilla>& tab)
{
	_misPiezas[indices.x]->ActualizarPosicion(tab, indices.y);
}
void Jugador::AplicarGravedad(Casilla* cas, std::vector<Casilla> & tab)
{
	for (Pieza* p : _misPiezas)
	{
		if (cas == p->getCasilla())
		{
			p->Gravedad(tab);
			break;
		}
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
		_misPiezas.push_back(new Peon(c, col));
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
void Jugador::CrearJugador(std::vector<Casilla>& tab, Vector2D pos_ini, Color c)
{
	CrearPieza(&tab[pos_ini.x + pos_ini.y * 8], c, t_pieza::TORRE);
	pos_ini += 1;
	CrearPieza(&tab[pos_ini.x + pos_ini.y * 8], c, t_pieza::CABALLO);
	pos_ini += 1;
	CrearPieza(&tab[pos_ini.x + pos_ini.y * 8], c, t_pieza::ALFIL);
	pos_ini += 1;
	CrearPieza(&tab[pos_ini.x + pos_ini.y * 8], c, t_pieza::REY);
	pos_ini += 1;
	CrearPieza(&tab[pos_ini.x + pos_ini.y * 8], c, t_pieza::REINA);
	pos_ini += 1;
	CrearPieza(&tab[pos_ini.x + pos_ini.y * 8], c, t_pieza::ALFIL);
	pos_ini += 1;
	CrearPieza(&tab[pos_ini.x + pos_ini.y * 8], c, t_pieza::CABALLO);
	pos_ini += 1;
	CrearPieza(&tab[pos_ini.x + pos_ini.y * 8], c, t_pieza::TORRE);
	pos_ini += 1;

	if (c == Color::Negro) { pos_ini = { 6,0 }; }
	for (int n = 0; n < 8; n++)
	{
		CrearPieza(&tab[pos_ini.x + pos_ini.y * 8], c, t_pieza::PEON);
		pos_ini += 1;
	}
}

