#include "Ajedrez.h"


Ajedrez::Ajedrez() :
	_estado(GameState::Creaccion),
	_j1(_tablero.getTablero(), Color::Blanco),
	_j2(_tablero.getTablero(), Color::Negro)
{
	std::cout << "Todo creado" << std::endl;
	_estado = GameState::B_Actualizar_Amenazas;
}


//almacena el indice de la pieza seleccionada (respecto al vector de piezas)
// y el indice de la casilla de destino (respecto al tablero)
static Vector2D indices{};	
//se utiliza como temporizador para mostrar los mensajes de jaque y jaque mate
static int tempo;
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
		ValidarMovimientos(_j2, _j1);

		_estado = N_Comprobar_Jaques;
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
		std::cout << *this << std::endl;
		
		//indica si el movimiento de las piezas es devido a la gravedad (true) o al jugador (false)
		static bool caida;

		if (!HayMovimiento() && caida)
		{
			_estado = N_Actualizar_Amenazas;
			caida = false;
		}
		
		else if (!HayMovimiento())
		{
			_j2.BorrarPieza(_tablero.getTablero()[indices.y]);
			AplicarGravedad(_tablero, _j1, _j2);
			caida = true;
		}
		
		break;
	}
	case B_Comprobar_Jaques:
	{
		switch (jaque())
		{
		case 1:
		{
			tempo = 0;
			_estado = N_Espera;
			break;
		}
		case 2:
		{
			tempo = 150;
			_estado = N_Espera;
			break;
		}
		case 3:
		{
			ETSIDI::stopMusica();
			ETSIDI::play("sonidos/VICTORIA.wav");
		
			tempo = 250;
			wait = true;
			
			_estado = B_Win;
			break;
		}
		}
		break;
	}
	case N_Actualizar_Amenazas:
	{
		std::cout << *this << std::endl;
		
		_tablero.ClearAmenazas();
		_j1.ActualizarAmenazas(_tablero.getTablero());
		
		_j2.PosiblesMov(_tablero.getTableroConst());
		ValidarMovimientos(_j1, _j2);

		_estado = B_Comprobar_Jaques;
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
			_estado = B_Actualizar_Amenazas;
			caida = false;
		}
		
		else if (!HayMovimiento())
		{
			_j1.BorrarPieza(_tablero.getTablero()[indices.y]);
			AplicarGravedad(_tablero, _j1, _j2);
			caida = true;
		}
		break;
	}

	case N_Comprobar_Jaques:
	{
		switch (jaque())
		{
		case 1:
		{
			tempo = 0;
			_estado = B_Espera;
			break;
		}
		case 2:
		{
			tempo = 150;
			_estado = B_Espera;
			break;
		}
		case 3:
		{
			ETSIDI::stopMusica();
			ETSIDI::play("sonidos/VICTORIA.wav");
		
			tempo = 250;
			wait = true;
			
			_estado = N_Win;
			break;
		}
		}
		break;
	}
	default:
	{
		break;
	}
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
	default:
		break;
	}
}
void Ajedrez::tecla(unsigned char key)
{
	//indica la fase dentro del proceso de movimiento.
	// 0 no se ha seleccionado pieza, 1 pieza seleccionada valida procede a seleccion de destino,
	// 2 pieza y destino seleccionados validos procede a mover la pieza
	static int fase;

	switch (key)
	{
	case 8: //backspace --> deselecciona la pieza
	{
		_j1.GRAPH_setPrimero(true);
		_j2.GRAPH_setPrimero(true);

		_j1.deselect(indices.x);
		_j2.deselect(indices.x);
		if (fase > 0)
			fase--;
		break;
	}
	case 13:	//enter confirmar pieza o destino
	{
		if (_estado == B_Espera)
		{
			indices = _j1.Movimiento(_tablero.getTableroConst(), fase);
			if (fase != 0)
				_j1.GRAPH_setPrimero(false);

			if (fase == 2)
			{
				fase = 0;
				_j1.ActualizarMovimiento(indices, _tablero.getTablero());
				_j1.GRAPH_setPrimero(true);

				_estado = B_Mov;
			}
		}
		else if (_estado == N_Espera)
		{
			indices = _j2.Movimiento(_tablero.getTableroConst(), fase);
			if (fase != 0)
				_j2.GRAPH_setPrimero(false);

			if (fase == 2)
			{
				fase = 0;
				_j2.ActualizarMovimiento(indices, _tablero.getTablero());				
				_j2.GRAPH_setPrimero(true);

				_estado = N_Mov;
			}
		}
		break;
	}
	//////////////////////////////////////////
	//				DEBUG/ATAJOS			//
	//////////////////////////////////////////
	/*
	case 'z':
	{
		//debug posicione
		printTablero();
		break;
	}
	case 'n':
	{
		//debug jaque mate a favor de negras
		ETSIDI::stopMusica();
		ETSIDI::play("sonidos/VICTORIA.wav");

		tempo = 250;
		wait = true;

		_estado = N_Win;
		break;
	}
	case 'b':
	{
		//debug jaque mate a favor de blancas
		ETSIDI::stopMusica();
		ETSIDI::play("sonidos/VICTORIA.wav");

		tempo = 250;
		wait = true;

		_estado = B_Win;
		break;
	}
	
	case 'r':
	{
		//retroceso al estado de juego
		wait = false;

		_estado = B_Actualizar_Amenazas;
		break;
	}
	*/
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
	gluLookAt(0, 7.5, 30, // posicion del ojo 
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0) 
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 	

	//dibujo de piezas de ambos jugadores y cursor si es necesario
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

	//dibujo del tablero
	_tablero.dibujar();

	//dibujo de la mesa
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

	//impresion de notificaciones
	if (tempo > 0)
	{
		switch (_estado)
		{
		case B_Espera:
		{
			Notificacion(Color::Negro, 0, tempo);
			break;
		}
		case N_Espera:
		{
			Notificacion(Color::Blanco, 0, tempo);
			break;
		}
		case B_Win:
		{
			Notificacion(Color::Blanco, 1, tempo);
			break;
		}
		case N_Win:
		{
			Notificacion(Color::Negro, 1, tempo);
			break;
		}
		default:
			break;
		}
	}
	else
		wait = false;
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

		//salto de linea cada 8 casillas
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
		
		//salto de linea cada 8 casillas
		n++;
		if (n == 8)
		{
			o << std::endl;
			n = 0;
		}
	}
	return o;
}


void Ajedrez::AplicarGravedad(Tablero& tab, Jugador& blancas, Jugador& negras)
{
	std::vector<Casilla*> cas_oc = tab.getCasillasOcupadas();
	for (Casilla* casilla : cas_oc)
	{
		if (casilla->getOcupacion() == Dominio::Blanca)
			blancas.AplicarGravedad(casilla, tab.getTablero());
		else
			negras.AplicarGravedad(casilla, tab.getTablero());
	}
}
bool Ajedrez::jaquemate()
{
	switch (_estado)
	{
	case N_Comprobar_Jaques:	//comprueba si las negras dan jaque mate a las blancas
	{
		return ValidarMovimientos(_j2, _j1);		
	}
	case B_Comprobar_Jaques: // comprobamos si las blancas dan jaque mate a las negras
	{
		return ValidarMovimientos(_j1, _j2);
	}
	}
}
int Ajedrez::jaque()
{
	bool jaque = false;
	bool checkmate = false;
	switch (_estado)
	{
	case N_Comprobar_Jaques: //jaque de negras sobre blancas
	{
		if (_j1.ComprobarJaque()) //si detecta jaque, hará llamada a jaquemate
		{
			if (jaquemate())
				return 3; //hay jaque mate
			else 
				return 2;//hay jaque
		}
		return 1;	//no ha detectado jaque
	}
	case B_Comprobar_Jaques: //jaque de blancas sobre negras
	{
		if (_j2.ComprobarJaque()) //si detecta jaque, hará llamada a jaquemate
		{
			if (jaquemate())
				return 3; 
			else
				return 2;
		}
		return 1;
	}
	default:
		break;
	}
}
bool Ajedrez::ValidarMovimientos(Jugador& da, Jugador& recibe)
{
	//al finalizar la funcion indica si hay o no jaque mate
	bool jaquemate = true;
	//indica en cada posible movimiento evaluado si se mantiene el jaque o no
	bool jaque = true;
	for (int n = 0; n < recibe.getMisPiezasSize(); n++)
	{
		for (int m = recibe.getPosMovSize(n) - 1; m >= 0; m--)
		{
			jaque = false;
			Tablero Copia(_tablero);
			Jugador blancas(da, Copia.getTablero());
			Jugador negras(recibe, Copia.getTablero());
			Vector2D indice_mate{ n,negras.getIndiceTab(n,m,Copia.getTableroConst()) };
			
			negras.ActualizarMovimiento(indice_mate, Copia.getTablero(), false);
			blancas.BorrarPieza(Copia.getTablero()[indice_mate.y]);
			AplicarGravedad(Copia, blancas, negras);
			
			Copia.ClearAmenazas();
			blancas.ActualizarAmenazas(Copia.getTablero());
			if (negras.ComprobarJaque())
			{
				jaque = true;
				recibe.BorrarMovimiento(n, m);
			}
		}
		if (!jaque)
		{
			jaquemate = false;
		}
	}
	return jaquemate;
}


bool Ajedrez::HayMovimiento()
{
	if (_j1.HayMovimiento() || _j2.HayMovimiento()) return true;
	return false;
}
void Ajedrez::Notificacion(Color col, bool mate, int& tempo)
{
	if (col == Color::Blanco) ETSIDI::setTextColor(0.7843, 0.5686, 0.0780);
	else ETSIDI::setTextColor(0.05, 0.052, 0);

	ETSIDI::setFont("fuentes/Action Man Shaded Italic.ttf", 48);
	if (mate)
	{
		ETSIDI::printxy("JAQUE MATE", -5, 16);
		if (col == Color::Blanco)
			ETSIDI::printxy("Ganan  Blancas", -7, -3);
		else
			ETSIDI::printxy("Ganan Negras", -6, -3);
	}
	else
		ETSIDI::printxy("JAQUE", -2, 16);
	
	tempo--;
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

