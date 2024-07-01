#include "Ajedrez.h"

Ajedrez::Ajedrez() :
	_estado(GameState::Creaccion),
	_j1(_tablero.getTablero(), Color::Blanco),
	_j2(_tablero.getTablero(), Color::Negro)
{
	std::cout << "Todo creado" << std::endl;
	_estado = GameState::B_Actualizar_Amenazas;
}

static Vector2D indices{};
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
		//std::cout << *this << std::endl;
		//_indices = _j1.Movimiento(_tablero.getTableroConst());
		//_estado = B_Mov;
		break;
	}
	case B_Mov:
	{
		//std::cout << *this << std::endl;
		static bool caida;
		if (!HayMovimiento() && caida)
		{
			_estado = B_Comprobar_Jaques;
			caida = false;
		}
		else if (!HayMovimiento())
		{
			_j2.BorrarPieza(_tablero.getTablero()[indices.y]);
			AplicarGravedad();
			caida = true;
		}
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
		//std::cout << *this << std::endl;
		//_indices = _j2.Movimiento(_tablero.getTableroConst());
		//_estado = N_Mov;
		break;
	}
	case N_Mov:
	{
		std::cout << *this << std::endl;
		static bool caida;
		if (!HayMovimiento() && caida)
		{
			_estado = N_Comprobar_Jaques;
			caida = false;
		}
		else if (!HayMovimiento())
		{
			_j1.BorrarPieza(_tablero.getTablero()[indices.y]);
			AplicarGravedad();
			caida = true;
		}
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
void Ajedrez::AplicarGravedad()
{
	std::vector<Casilla*> cas_oc = _tablero.getCasillasOcupadas();
	for (Casilla* casilla : cas_oc)
	{
		if (casilla->getOcupacion() == Dominio::Blanca)
			_j1.AplicarGravedad(casilla, _tablero.getTablero());
		else
			_j2.AplicarGravedad(casilla, _tablero.getTablero());
	}
}


void Ajedrez::tecla_especial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
	{
		if (_estado == B_Espera)
		{
			_j1.modificarPosicion(OESTE);
		}
		else if (_estado == N_Espera)
		{
			_j2.modificarPosicion(OESTE);
		}
		break;
	}

	case GLUT_KEY_RIGHT:
	{
		if (_estado == B_Espera)
		{
			_j1.modificarPosicion(ESTE);
		}
		else if (_estado == N_Espera)
		{
			_j2.modificarPosicion(ESTE);
		}
		break;
	}
	case GLUT_KEY_UP:
	{
		if (_estado == B_Espera)
		{
			_j1.modificarPosicion(NORTE);
		}
		else if (_estado == N_Espera)
		{
			_j2.modificarPosicion(NORTE);
		}
		break;
	}
	case GLUT_KEY_DOWN:
	{
		if (_estado == B_Espera)
		{
			_j1.modificarPosicion(SUR);
		}
		else if (_estado == N_Espera)
		{
			_j2.modificarPosicion(SUR);
		}
		break;
	}
	case GLUT_KEY_HOME:
	{
		exit(0);
		break;
	}
	
	default:
		break;
	}
}

void Ajedrez::tecla(unsigned char key)
{
	static int pieza_selec;

	switch (key)
	{
	case 8: //backspace
	{
		_j1.GRAPH_setPrimero(true);
		_j2.GRAPH_setPrimero(true);

		_j1.deselect(indices.x);
		_j2.deselect(indices.x);
		if (pieza_selec > 0)
			pieza_selec--;
		break;
	}
	case 13:	//enter confirmar
	{
		if (_estado == B_Espera)
		{
			_j1.GRAPH_setPrimero(false);
			 indices = _j1.Movimiento(_tablero.getTableroConst(), pieza_selec);

			if (pieza_selec == 2)
			{
				pieza_selec = 0;
				_j1.ActualizarMovimiento(indices, _tablero.getTablero());
				_estado = B_Mov;
				_j1.GRAPH_setPrimero(true);
			}
		}
		else if (_estado == N_Espera)
		{
			_j2.GRAPH_setPrimero(false);
			indices = _j2.Movimiento(_tablero.getTableroConst(), pieza_selec);
			if (pieza_selec == 2)
			{
				_j2.ActualizarMovimiento(indices, _tablero.getTablero());
				_estado = N_Mov;
				pieza_selec = 0;
				_j2.GRAPH_setPrimero(true);
			}
		}
		break;
	}
	case 'z':
	{
		printTablero();
		break;
	}
	default:
		break;
	}
}

void Ajedrez::mover()
{
	_j1.mover();
	_j2.mover();
}
void Ajedrez::dibujar()
{
	//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS 
	gluLookAt(0, 7.5, 30, // posicion del ojo 
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0) 
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 	

	if (_estado == B_Espera)
	{
		_j1.dibujar(Color::Blanco, 1);
		_j2.dibujar(Color::Negro);
	}
	else if (_estado == N_Espera)
	{
		_j2.dibujar(Color::Negro, 1);
		_j1.dibujar(Color::Blanco);
	}
	else
	{
		_j1.dibujar(Color::Blanco);
		_j2.dibujar(Color::Negro);
	}
	_tablero.dibujar();

	//dibuja la mesa
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Mesa.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3d(15, 20, 0);
	glTexCoord2d(1, 1); glVertex3d(-15, 20, 0);
	glTexCoord2d(1, 0); glVertex3d(-15, -5, 0);
	glTexCoord2d(0, 0); glVertex3d(15, -5, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}


std::ostream& Ajedrez::printTablero(std::ostream& o)
{
	int n = 0;
	for (const Casilla& cas : _tablero.getTableroConst())
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

bool Ajedrez::HayMovimiento()
{
	if (_j1.HayMovimiento() || _j2.HayMovimiento()) return true;
	return false;
}

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

