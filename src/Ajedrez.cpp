#include "Ajedrez.h"

Ajedrez::Ajedrez() :
	_estado(GameState::Creaccion),
	_j1(_tablero.getTablero(), Color::Blanco),
	_j2(_tablero.getTablero(), Color::Negro),
	copia_t_it{}
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
			AplicarGravedad();
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
			_estado = N_Espera;
			break;
		}
		case 2:
		{
			std::cout << "\njaque\n";
			tempo = 150;
			_estado = N_Espera;
			break;
		}
		case 3:
		{
			std::cout << "\njaquemate\n";
			tempo = 150;
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
			AplicarGravedad();
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
			std::cout << "\njaquemate\n";
			tempo = 150;
			_estado = N_Win;
			break;
		}
		}
		break;
	}
	default: //para las pantllas de vistoria espera un poco para ver la notificacion
	{
		Sleep(1500);
		break;
	}

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

bool Ajedrez::jaquemate()
{

	bool jaque;
	switch (_estado)
	{
	case N_Comprobar_Jaques:	//comprueba si las negras dan jaque a las blancas
	{
		/*
		bool jaqueit;
		Tablero copia_jaquemate(_tablero);
		std::vector<Pieza*> piezasdef;
		std::vector<Casilla> movimientospieza;
		for (size_t i = 0; i < _j1.getPiezas().size(); i++) //recorremos todas las piezas del jugador
		{
			Tablero copia_t_it(_tablero);
			Jugador Jamenazado_iteracion(_j1);
			Jamenazado_iteracion.CambiarTablero(copia_t_it.getTablero());
			Jugador Jatacante_iteracion(_j2);
			Jatacante_iteracion.CambiarTablero(copia_t_it.getTablero());
			//Jugador Jamenazado_iteracion(_j1,copia_t_it.getTablero());
			//Jugador Jatacante_iteracion(_j2,copia_t_it.getTablero());//copiamos los valores originales copiados para resetear los movimientos comprobados
			piezasdef = Jamenazado_iteracion.getPiezas();
			//cada iteracion se reinician las posiciones de las piezas para evitar que se acumulen los cambios de las simulaciones
			copia_t_it.ClearAmenazas();
			Jatacante_iteracion.ActualizarAmenazas(copia_t_it.getTablero());
			Jamenazado_iteracion.PosiblesMov(copia_t_it.getTableroConst());
			for (size_t j = 0; j < Jamenazado_iteracion.getPiezas()[i]->get_PosMov().size(); j++)//con este bucle recorreremos los posibles movimientos de la pieza
			{
				Vector2D posmovelegido;
				posmovelegido = Jamenazado_iteracion.getPiezas()[i]->get_PosMov()[j].getPosicion();
	
				copia_t_it.ClearAmenazas();
				Jatacante_iteracion.ActualizarAmenazas(copia_t_it.getTablero());
				Dominio dom;
				//movemos la pieza "i" a la posicion del posible movimimiento "j".
				Jamenazado_iteracion.getPiezas()[i]->setCasilla(&Jamenazado_iteracion.getPiezas()[i]->get_PosMov()[j]);
				for (size_t m = 0; m < copia_t_it.getTablero().size(); m++) //buscamos la casilla destino
				{
					//Vector2D posacomerit = copia_t_it.getTablero()[m].getPosicion();
					if (copia_t_it.getTablero()[m].getPosicion() == Jamenazado_iteracion.getPiezas()[i]->get_PosMov()[j].getPosicion())//encuentra la casilla seleccionada para mover
					{
						Jatacante_iteracion.BorrarPieza(copia_t_it.getTablero()[m]);//si hay una pieza enemiga en ese casilla, la borra
						Jamenazado_iteracion.getPiezas()[i]->setCasilla(&copia_t_it.getTablero()[m]);//colocamos la pieza a mover a
						Jamenazado_iteracion.AplicarGravedad(Jamenazado_iteracion.getPiezas()[i]->getCasilla(),copia_t_it.getTablero());//comprobamos gravedad para el caso de que se haya movido a una casilla sin pieza debajo
						copia_t_it.ClearAmenazas();
						Jatacante_iteracion.ActualizarAmenazas(copia_t_it.getTablero());
					}
				}
				//ahora que hemos movido la pieza, comprobamos si el rey esta amenazado todavia

				jaqueit = Jamenazado_iteracion.ComprobarJaque();
				if (jaqueit == false)
					return false;
			}

		}*/
		return false;

	}
	case B_Comprobar_Jaques: // comprobamos si las blancas dan jaque a las negras
	{
		copia_t_it = _tablero;
		bool jaqueit{ true };
		//Tablero copia_jaquemate(_tablero);
		//std::vector<Pieza*> piezasdef;
		//std::vector<Casilla> movimientospieza;
		Jugador Jatacante_iteracionB(_j1, copia_t_it.getTablero());
		Jugador Jamenazado_iteracionB(_j2, copia_t_it.getTablero());
		for (size_t i = 0; i < Jamenazado_iteracionB.getPiezas().size(); i++) //recorremos todas las piezas del jugador
		{
			std::cout << "\nprimer bucle=recorriendo piezas\n";
			//Tablero copia_t_it(_tablero);
			//Jugador Jamenazado_iteracionB(_j2, copia_t_it.getTablero());
			//Jugador Jatacante_iteracionB(_j1, copia_t_it.getTablero());//copiamos los valores originales copiados para resetear los movimientos comprobados
			//cada iteracion se reinician las posiciones de las piezas para evitar que se acumulen los cambios de las simulaciones
			//for (auto p : _j2.getPiezas()[i]->get_PosMov())
			for(size_t j=0; j<_j2.getPiezas()[i]->get_PosMov().size(); j++)
			{
				std::cout << "\nsegundo bucle=recorriendo pos mov\n";
				copia_t_it = _tablero;
				Jatacante_iteracionB = _j1;
				Jamenazado_iteracionB = _j2;
				copia_t_it.ClearAmenazas();
				Jatacante_iteracionB.ActualizarAmenazas(copia_t_it.getTablero());
				for (size_t m = 0; m < _tablero.getTablero().size(); m++) //buscamos la casilla destino
				{
					Jatacante_iteracionB = _j1;
					Jamenazado_iteracionB = _j2;
					//copia_t_it.ClearAmenazas();
					//Jatacante_iteracionB.ActualizarAmenazas(copia_t_it.getTablero());
					std::cout << "\n tercer bucle=buscando casilla destino\n";
					if ((copia_t_it.getTablero()[m].getPosicion() == _j2.getPiezas()[i]->get_PosMov()[j].getPosicion()))//encuentra la casilla seleccionada para mover
					{
						std::cout << "\nborrarpieza\n";
						Jatacante_iteracionB.BorrarPieza(copia_t_it.getTablero()[m]);//si hay una pieza enemiga en ese casilla, la borra
						Jamenazado_iteracionB.getPiezas()[i]->setCasilla(&copia_t_it.getTablero()[m]);//colocamos la pieza a mover a
						Jamenazado_iteracionB.AplicarGravedad(Jamenazado_iteracionB.getPiezas()[i]->getCasilla(), copia_t_it.getTablero());//comprobamos gravedad para el caso de que se haya movido a una casilla sin pieza debajo
						//Jamenazado_iteracion.CambiarTablero(copia_t_it.getTablero());
						//Jatacante_iteracion.CambiarTablero(copia_t_it.getTablero());
						copia_t_it.ClearAmenazas();
						Jatacante_iteracionB.ActualizarAmenazas(copia_t_it.getTablero());
						jaqueit=Jamenazado_iteracionB.ComprobarJaque();
						if (jaqueit == false)
							return false;
					}
				}
			}
			/*for (size_t j = 0; j < Jamenazado_iteracion.getPiezas()[i]->get_PosMov().size(); j++)//con este bucle recorreremos los posibles movimientos de la pieza
			{
				std::cout << "\nsegundo bucle=recorriendo pos mov\n";
				Vector2D posmovelegido;
				posmovelegido = Jamenazado_iteracion.getPiezas()[i]->get_PosMov()[j].getPosicion();

				copia_t_it.ClearAmenazas();
				Jatacante_iteracion.ActualizarAmenazas(copia_t_it.getTablero());
				//movemos la pieza "i" a la posicion del posible movimimiento "j".
				//Jamenazado_iteracion.getPiezas()[i]->setCasilla(&Jamenazado_iteracion.getPiezas()[i]->get_PosMov()[j]);
				for (size_t m = 0; m < copia_t_it.getTablero().size(); m++) //buscamos la casilla destino
				{
					std::cout << "\n tercer bucle=buscando casilla destino\n";
					//Vector2D posacomerit = copia_t_it.getTablero()[m].getPosicion();
					if ((copia_t_it.getTablero()[m].getPosicion() == Jamenazado_iteracion.getPiezas()[i]->get_PosMov()[j].getPosicion())&&(copia_t_it.getTablero()[m].getOcupacion()==Jatacante_iteracion.getPiezas()[0]->getCasilla()->getOcupacion()))//encuentra la casilla seleccionada para mover
					{
						std::cout << "\nborrarpieza\n";
						Jatacante_iteracion.BorrarPieza(copia_t_it.getTablero()[m]);//si hay una pieza enemiga en ese casilla, la borra
						Jamenazado_iteracion.getPiezas()[i]->setCasilla(&copia_t_it.getTablero()[m]);//colocamos la pieza a mover a
						Jamenazado_iteracion.AplicarGravedad(Jamenazado_iteracion.getPiezas()[i]->getCasilla(), copia_t_it.getTablero());//comprobamos gravedad para el caso de que se haya movido a una casilla sin pieza debajo
						copia_t_it.ClearAmenazas();
						Jatacante_iteracion.ActualizarAmenazas(copia_t_it.getTablero());
						bool jaqueit;
						jaqueit = Jamenazado_iteracion.ComprobarJaque();
						if (jaqueit == false)
							return false;
					}
				}
			}
			*/
		}
		return true;
	}

	}
}
int Ajedrez::jaque()
{
	bool jaque = false;
	bool checkmate = false;
	Dominio dom;
	switch (_estado)
	{
	case N_Comprobar_Jaques: //jaque de negras sobre blancas
	{

		jaque = _j1.ComprobarJaque();
		if (jaque == true) //si se cumple, hará llamada a jaquemate
		{
			checkmate = jaquemate();
			if (checkmate == true)	return 3; //hay jaque mate				}
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
	
	/*
	case 'z':
	{
	//debug posicion
		printTablero();
		break;
	}
	case '1':
	{
	//debug color jaque
		tempo = 150;
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
void Ajedrez::Notificacion(Color col, bool mate, int &tempo)
{
	if (col == Color::Blanco) ETSIDI::setTextColor(0.7843, 0.5686, 0.0780);
	else ETSIDI::setTextColor(0.05, 0.052, 0);

	ETSIDI::setFont("fuentes/A.C.M.E. Secret Agent.ttf", 48);
	if (mate)
		ETSIDI::printxy("JAQUE MATE", -5, 16);
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

