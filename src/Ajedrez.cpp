#include "Ajedrez.h"
//????
#include <algorithm>

Ajedrez::Ajedrez() :
	_estado(GameState::Creaccion),
	_j1(_tablero.getTablero(), Color::Blanco),
	_j2(_tablero.getTablero(), Color::Negro)
{
	std::cout << "Todo creado" << std::endl;
	_estado = GameState::B_Actualizar_Amenazas;
}


static Vector2D indices{};
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
		//std::cout << *this << std::endl;
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
			//std::cout << "\njaque\n";
			tempo = 150;
			_estado = N_Espera;
			break;
		}
		case 3:
		{
			//std::cout << "\njaquemate\n";
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
			std::cout << "\njaque\n";
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
		if (_j1.ComprobarJaque()) //si se cumple, hará llamada a jaquemate
		{
			if (jaquemate())	return 3; //hay jaque mate				}
			else return 2;//hay jaque
		}
		return 1;
		break;
	}
	case B_Comprobar_Jaques: //jaque de blancas sobre negras
	{
		jaque = _j2.ComprobarJaque();

		if (jaque == true) //si se cumple, hará llamada a jaquemate
		{
			checkmate = jaquemate();
			if (checkmate == true)	return 3; //hay jaque mate				}
			else return 2;//hay jaque
		}
		return 1;
		break;
	}
	/*
	case B_CompMov:
	{
		Tablero tablerocompB(_tablero);
		std::vector<Casilla> tabB(tablerocompB.getTablero());
		Jugador jdefcompB(_j1, tabB);
		Jugador jatcompB(_j2, tabB);
		std::vector<Pieza*> piezasjd = jdefcompB.getPiezas();
		size_t cantpiezas = piezasjd.size();
		size_t tamtableroB = tabB.size();

		for (size_t l = 0; l < cantpiezas; l++)
		{
			jdefcompB = _j1;
			piezasjd = jdefcompB.getPiezas();
			std::vector<Casilla> posmovcompB= piezasjd[l]->get_PosMov();
			for (size_t m = posmovcompB.size(); m > 0; m--)
			{//avanzamos por todos los posibles movimientos de las piezas
				//asignamos la posicion de estas a "a"
				Vector2D a {posmovcompB[m].getPosicion().x, posmovcompB[m].getPosicion().y};
				Casilla* c = &tabB[indices.y];
				piezasjd[l]->ActualizarPosicion(c); //actualizamos la posicion de la pieza
				jdefcompB.CambiarTablero(tabB);
				tablerocompB.ClearAmenazas();
				jatcompB.ActualizarAmenazas(tablerocompB.getTablero());
				for (size_t i = 0; i < tamtableroB; i++) //recorremos todas las casillas
				{
					Vector2D posB{};
					//dom=cas.getOcupacion()
					dom = tabB[i].getOcupacion();
					if (dom == Dominio::Blanca)
					{
						posB = tabB[i].getPosicion();
						for (unsigned int k = 0; k <cantpiezas ; k++)
						{
							Casilla* cas_pieza_copia = piezasjd[k]->getCasilla();
							Vector2D pos_cas_copia = cas_pieza_copia->getPosicion();
							if ((posB.x == pos_cas_copia.x) && (posB.y == pos_cas_copia.y)) //cuando encontra la pieza que coincide con esas coordenadas
								if (piezasjd[k]->getT_Pieza() == t_pieza::REY)//comprueba si se trata del rey
									jaque = tabB[k].getAmenaza();//si es rey, comprueba si esta amenazado, siendo true si lo está
						}
						if (jaque == true) //si se cumple,borramos el posible movimiento
						{
							std::vector<Casilla>::iterator it;
							it = posmovcompB.begin() + m;
							std::vector<Pieza*> borrarposmov = _j1.getPiezas();
							borrarposmov[l]->get_PosMov().erase(it);
							return 2;
						}
						else
							return 1;//no hay jaque
					}
				}
			}
		}

		return 0;
	}
	case N_CompMov:
	{
		Tablero tablerocompN = _tablero;
		std::vector<Casilla> tabB;
		tabB = tablerocompN.getTablero();
		Jugador jdefcompN(_j2, tabB);
		Jugador jatcompN(_j1, tabB);
		std::vector<Pieza*> piezasjd = jdefcompN.getPiezas();
		size_t cantpiezas = piezasjd.size();
		size_t tamtableroN = tabB.size();

		for (size_t l = 0; l < cantpiezas; l++)
		{
			jdefcompN = _j1;
			piezasjd = jdefcompN.getPiezas();
			std::vector<Casilla> posmovcompN = piezasjd[l]->get_PosMov();
			for (size_t m = posmovcompN.size(); m > 0; m--)
			{//avanzamos por todos los posibles movimientos de las piezas
				//asignamos la posicion de estas a "a"
				Vector2D a{ posmovcompN[m].getPosicion().x, posmovcompN[m].getPosicion().y };
				Casilla* c = &tabB[indices.y];
				piezasjd[l]->ActualizarPosicion(c); //actualizamos la posicion de la pieza
				jdefcompN.CambiarTablero(tabB);
				tablerocompN.ClearAmenazas();
				jatcompN.ActualizarAmenazas(tablerocompN.getTablero());
				for (size_t i = 0; i < tamtableroN; i++) //recorremos todas las casillas
				{
					Vector2D posB{};
					//dom=cas.getOcupacion()
					dom = tabB[i].getOcupacion();
					if (dom == Dominio::Blanca)
					{
						posB = tabB[i].getPosicion();
						for (unsigned int k = 0; k <cantpiezas; k++)
						{
							Casilla* cas_pieza_copia = piezasjd[k]->getCasilla();
							Vector2D pos_cas_copia = cas_pieza_copia->getPosicion();
							if ((posB.x == pos_cas_copia.x) && (posB.y == pos_cas_copia.y)) //cuando encontra la pieza que coincide con esas coordenadas
								if (piezasjd[k]->getT_Pieza() == t_pieza::REY)//comprueba si se trata del rey
									jaque = tabB[k].getAmenaza();//si es rey, comprueba si esta amenazado, siendo true si lo está
						}
						if (jaque == true) //si se cumple,borramos el posible movimiento
						{
							std::vector<Casilla>::iterator it;
							it = posmovcompN.begin() + m;
							std::vector<Pieza*> borrarposmov = _j1.getPiezas();
							borrarposmov[l]->get_PosMov().erase(it);
							return 2;
						}
						else
							return 1;//no hay jaque
					}
				}
			}
		}

		return 0;
	}*/

	}
	return 0;
}

bool Ajedrez::ValidarMovimientos(Jugador& da, Jugador& recibe)
{
	//j1 da el jaque, j2 lo recibe
	bool jaquemate = true;
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
			
			negras.ActualizarMovimiento(indice_mate, Copia.getTablero());
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

			indices = _j1.Movimiento(_tablero.getTableroConst(), pieza_selec);
			if (pieza_selec != 0)_j1.GRAPH_setPrimero(false);

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
			indices = _j2.Movimiento(_tablero.getTableroConst(), pieza_selec);
			if (pieza_selec != 0)_j2.GRAPH_setPrimero(false);

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
		//debug posicione
		printTablero();
		break;
	}
	/*
	case '1':
	{
		//debug color jaque
		tempo = 150;
		break;
	}
	*/
	case 'n':
	{
		//debug jaque mate
		ETSIDI::stopMusica();
		ETSIDI::play("sonidos/VICTORIA.wav");
		std::cout << "\njaquemate\n";
		tempo = 250;
		_estado = N_Win;
		wait = true;
		break;
	}
	case 'b':
	{
		//debug jaque mate
		ETSIDI::stopMusica();
		ETSIDI::play("sonidos/VICTORIA.wav");
		std::cout << "\njaquemate\n";
		tempo = 250;
		_estado = B_Win;
		wait = true;
		break;
	}
	case 'r':
	{
		_estado = B_Actualizar_Amenazas;
		wait = false;
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

