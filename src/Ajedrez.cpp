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

<<<<<<< Updated upstream

=======
static Vector2D indices{};
static Vector2D indicecompB{};
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======


>>>>>>> Stashed changes
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

		_estado = B_Comprobar_Jaques;
		break;
	}
	case B_Comprobar_Jaques:
	{
		int jaqueBlancas;
		jaqueBlancas = jaque();
		if (jaqueBlancas == 1) // no jaque
		{
			_estado = B_Espera;
		}
		if (jaqueBlancas == 2) // jaque mate, ganan las negras
		{
			_estado = N_Win;
		}
		if (jaqueBlancas == 3) //jaque
		{
			//aviso en pantalla de que blancas esta en jaque
			_estado = B_Espera;
		}
		break;
	}
	case B_CompMov:
	{
		int stateB = jaque();
		if (stateB != 0)
			_estado = B_Espera;
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
		static bool caida;
		if (!HayMovimiento() && caida)
		{
			_estado = B_Comprobar_Jaques;
			caida = false;
		}
		else if (!HayMovimiento())
		{
			AplicarGravedad();
			caida = true;
		}
		
		// graficos, mover pieza;
		break;
	}
<<<<<<< Updated upstream
	case B_Comprobar_Jaques:
	{
		std::cout << *this << std::endl;
		_j1.ComprobarJaque(); //Comprueba si alguna de las piezas blancas esta dando jaque al rey negro
		_estado = N_Actualizar_Amenazas;
		break;
	}
=======
>>>>>>> Stashed changes
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
			AplicarGravedad();
			caida = true;
		}
		// graficos, mover pieza;
		break;
	}
	case N_Comprobar_Jaques:
	{
		int jaqueNegras;
		jaqueNegras = jaque();
		if (jaqueNegras == 1) // no jaque
		{
			_estado = N_Espera;
		}
		if (jaqueNegras == 2) // jaque mate, ganan las blancas
		{
			_estado = B_Win;
		}
		if (jaqueNegras == 3) //jaque
		{
			//aviso en pantalla de que negras esta en jaque
			_estado = N_Espera;
		}
		break;
	}
	case N_CompMov:
	{
		int stateN = jaque();
		if (stateN != 0)
			_estado = B_Espera;
	}
	case B_Win:
	{

	}
	case N_Win:
	{

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

bool Ajedrez::jaquemate()
{
	Dominio color;
	Dominio coloramenazado;
	bool jaque = true;
	switch (_estado)
	{
	case B_Comprobar_Jaques:
	{
		coloramenazado = Dominio::Blanca;
		Tablero copia_jaquemate = _tablero;
		std::vector<Casilla> copy;
		std::vector<Pieza*> piezasdef;
		std::vector<Pieza*> piezasat;
		std::vector<Casilla> movimientospieza;

		Jugador jamenazado_copia(_j1, copia_jaquemate.getTablero());//copiamos jugador defensor y enlazamos a tablero copia
		Jugador jatacante_copia(_j2, copia_jaquemate.getTablero()); //copiamos jugador atacante " " " " "

		piezasat = jatacante_copia.getPiezas();//" " " " " " atacante
		piezasdef = jamenazado_copia.getPiezas(); //getter de vector piezas del jugador defensor
		size_t vecsize = piezasdef.size();
		for (size_t i = 0; i < vecsize; i++) //recorremos todas las piezas del jugador
		{
			jamenazado_copia = _j1;
			jatacante_copia = _j2;
			//cada iteracion se reinician las posiciones de las piezas para evitar que se acumulen los cambios de las simulaciones
			copia_jaquemate.ClearAmenazas();
			jamenazado_copia.ActualizarAmenazas(copia_jaquemate.getTablero());
			jatacante_copia.ActualizarAmenazas(copia_jaquemate.getTablero()); 
				movimientospieza = piezasdef[i]->get_PosMov(); //getter de vector posibles movimientos de la pieza
				size_t cantmov = movimientospieza.size();
				for (size_t j = 0; j < cantmov; j++)//con este bucle recorreremos los posibles movimientos de la pieza
				{
					Vector2D posmovelegido;
					posmovelegido = movimientospieza[j].getPosicion();
					//al principio de cada posible mov, hay que copiar el tablero real en uno fantasma
				//... aquí tengo que hacer el movimiento elegido del vector
					jamenazado_copia = _j1;
					jatacante_copia = _j2;
					copia_jaquemate.ClearAmenazas();
					jamenazado_copia.ActualizarAmenazas(copia_jaquemate.getTablero());
					jatacante_copia.ActualizarAmenazas(copia_jaquemate.getTablero());
					Dominio dom;
					jamenazado_copia.ActualizarMovimiento(posmovelegido, copia_jaquemate.getTablero()); //como la posicion ya es adecuada al ser un pos mov, movemos la pieza ahi
					//AHORA BUSCAMOS SI HABIA UNA PIEZA DEL OTRO COLOR EN LA CASILLA
					piezasat = jatacante_copia.getPiezas();
					Casilla casat;
					Casilla casat2;
					const Casilla* dircasat = &casat;
					Vector2D posat;
					for (size_t k = 0; k < piezasat.size(); k++)
					{
						dircasat = piezasat[k]->getCasilla();
						casat2 = casat;
						posat = casat2.getPosicion();
						if ((posat.x == posmovelegido.x) && (posat.y == posmovelegido.y))
							jatacante_copia.BorrarPieza(casat);//borramos la pieza que haya del atacante en esa posicion si la hay
					}
					//	cuando el movimiento esté hecho en el jugador fantasma, lo utilizamos para actualizamar amenazas tablero copia y recorremos este para ver si el rey sigue amenazado
					copia_jaquemate.ClearAmenazas();
					jatacante_copia.ActualizarAmenazas(copia_jaquemate.getTablero()); //quitamos las amenazas previas y ponemos las actuales con el posible cambio por piezas comidas o bloqueos
					//movimiento iteración
					copy = copia_jaquemate.getTablero();
					size_t tamvector = copy.size();

					for (size_t i = 0; i < tamvector; i++) //recorremos todas las casillas
					{
						Vector2D pos_am{};
						//dom=cas.getOcupacion()
						dom = copy[i].getOcupacion();
						if (dom == coloramenazado)//si es del color que sufre el jaque, comprobamos si es el rey
						{
							pos_am = copy[i].getPosicion();
							std::vector<Pieza> piezasjam;
							//piezasjam= jdef_copia.getpiezas(); //getter de dirección vector de piezas del jugador copiado
							size_t cantpiezas = piezasjam.size();
							for (size_t k = 0; i < cantpiezas; k++)
							{//avanzamos
								Casilla* cas_pieza_copia = piezasjam[k].getCasilla();
								Vector2D pos_cas_copia = cas_pieza_copia->getPosicion();
								if ((pos_am.x == pos_cas_copia.x) && (pos_am.y == pos_cas_copia.y)) //cuando encontra la pieza que coincide con esas coordenadas
									if (piezasjam[k].getT_Pieza() == t_pieza::REY)//comprueba si se trata del rey
										jaque = copy[k].getAmenaza();//si es rey, comprueba si esta amenazado, siendo true si lo está
								if (jaque == false)
									return jaque;
							}
						}	//asi hacemos comprobacion de jaque sin volver a llamar a jaque maten en caso de true
					}
				}
			
		}
	}
	case N_Comprobar_Jaques:
	{
		coloramenazado = Dominio::Blanca;
		Tablero copia_jaquemate = _tablero;
		std::vector<Casilla> copy;
		std::vector<Pieza*> piezasdef;
		std::vector<Pieza*> piezasat;
		std::vector<Casilla> movimientospieza;

		Jugador jamenazado_copia(_j2, copia_jaquemate.getTablero());//copiamos jugador defensor y enlazamos a tablero copia
		Jugador jatacante_copia(_j1, copia_jaquemate.getTablero()); //copiamos jugador atacante " " " " "

		piezasat = jatacante_copia.getPiezas();//" " " " " " atacante
		piezasdef = jamenazado_copia.getPiezas(); //getter de vector piezas del jugador defensor
		size_t vecsize = piezasdef.size();
		for (size_t i = 0; i < vecsize; i++) //recorremos todas las piezas del jugador
		{
			jamenazado_copia = _j2;
			jatacante_copia = _j1;
			copia_jaquemate = _tablero;
			//cada iteracion se reinician las posiciones de las piezas y se vuelve a copiar el tablero para evitar que se acumulen los cambios de las simulaciones
			copia_jaquemate.ClearAmenazas();
			jamenazado_copia.ActualizarAmenazas(copia_jaquemate.getTablero());
			jatacante_copia.ActualizarAmenazas(copia_jaquemate.getTablero());
			movimientospieza = piezasdef[i]->get_PosMov(); //getter de vector posibles movimientos de la pieza
			size_t cantmov = movimientospieza.size();
			for (size_t j = 0; j < cantmov; j++)//con este bucle recorreremos los posibles movimientos de la pieza
			{
				Vector2D posmovelegido;
				posmovelegido = movimientospieza[j].getPosicion();
				//al principio de cada posible mov, hay que copiar el tablero real en uno fantasma
			//... aquí tengo que hacer el movimiento elegido del vector
				jamenazado_copia = _j1;
				jatacante_copia = _j2;
				copia_jaquemate.ClearAmenazas();
				jamenazado_copia.ActualizarAmenazas(copia_jaquemate.getTablero());
				jatacante_copia.ActualizarAmenazas(copia_jaquemate.getTablero());
				Dominio dom;
				jamenazado_copia.ActualizarMovimiento(posmovelegido, copia_jaquemate.getTablero()); //como la posicion ya es adecuada al ser un pos mov, movemos la pieza ahi
				//AHORA BUSCAMOS SI HABIA UNA PIEZA DEL OTRO COLOR EN LA CASILLA
				piezasat = jatacante_copia.getPiezas();
				Casilla casat;
				Casilla casat2;
				const Casilla* dircasat = &casat;
				Vector2D posat;
				for (size_t k = 0; k < piezasat.size(); k++)
				{
					dircasat = piezasat[k]->getCasilla();
					casat2 = casat;
					posat = casat2.getPosicion();
					if ((posat.x == posmovelegido.x) && (posat.y == posmovelegido.y))
						jatacante_copia.BorrarPieza(casat);//borramos la pieza que haya del atacante en esa posicion si la hay
				}
				//	cuando el movimiento esté hecho en el jugador fantasma, lo utilizamos para actualizamar amenazas tablero copia y recorremos este para ver si el rey sigue amenazado
				copia_jaquemate.ClearAmenazas();
				jatacante_copia.ActualizarAmenazas(copia_jaquemate.getTablero()); //quitamos las amenazas previas y ponemos las actuales con el posible cambio por piezas comidas o bloqueos
				//movimiento iteración
				copy = copia_jaquemate.getTablero();
				size_t tamvector = copy.size();

				for (size_t i = 0; i < tamvector; i++) //recorremos todas las casillas
				{
					Vector2D pos_am{};
					//dom=cas.getOcupacion()
					dom = copy[i].getOcupacion();
					if (dom == coloramenazado)//si es del color que sufre el jaque, comprobamos si es el rey
					{
						pos_am = copy[i].getPosicion();
						std::vector<Pieza> piezasjam;
						//piezasjam= jdef_copia.getpiezas(); //getter de dirección vector de piezas del jugador copiado
						size_t cantpiezas = piezasjam.size();
						for (size_t k = 0; i < cantpiezas; k++)
						{//avanzamos
							Casilla* cas_pieza_copia = piezasjam[k].getCasilla();
							Vector2D pos_cas_copia = cas_pieza_copia->getPosicion();
							if ((pos_am.x == pos_cas_copia.x) && (pos_am.y == pos_cas_copia.y)) //cuando encontra la pieza que coincide con esas coordenadas
								if (piezasjam[k].getT_Pieza() == t_pieza::REY)//comprueba si se trata del rey
									jaque = copy[k].getAmenaza();//si es rey, comprueba si esta amenazado, siendo true si lo está
							if (jaque == false)
								return jaque;
						}
					}	//asi hacemos comprobacion de jaque sin volver a llamar a jaque maten en caso de true
				}
			}

		}
	}
	
	}
	return true;
}

int Ajedrez::jaque()
{
	bool jaque=false;
	bool checkmate=false;
	Dominio dom;
	switch (_estado)
	{
	case B_Comprobar_Jaques:
	{
		Tablero tablerocopiaB = _tablero;
		std::vector<Casilla> tabB;
		tabB = tablerocopiaB.getTablero();
		Jugador jdefcopia = _j1;
		Jugador jatcopia = _j2;
		std::vector<Pieza*> piezasjd = _j1.getPiezas();
		size_t cantpiezas = piezasjd.size();
		size_t tamtableroB = tabB.size();

		for (size_t i = 0; i < tamtableroB; i++) //recorremos todas las casillas
		{
			Vector2D posB{};
			//dom=cas.getOcupacion()
			dom = tabB[i].getOcupacion();
			if (dom == Dominio::Blanca)
			{
				posB = tabB[i].getPosicion();
				for (unsigned int k = 0; k < cantpiezas; k++)
				{
					Casilla* cas_pieza_copia = piezasjd[k]->getCasilla();
					Vector2D pos_cas_copia = cas_pieza_copia->getPosicion();
					if ((posB.x == pos_cas_copia.x) && (posB.y == pos_cas_copia.y)) //cuando encontra la pieza que coincide con esas coordenadas
						if (piezasjd[k]->getT_Pieza() == t_pieza::REY)//comprueba si se trata del rey
							jaque = tabB[k].getAmenaza();//si es rey, comprueba si esta amenazado, siendo true si lo está
				}
				if (jaque == true) //si se cumple, hará llamada a jaquemate
				{
					checkmate = jaquemate();
					if (checkmate == true)
						return 2; //hay jaque mate
					else
						return 3;//hay jaque

				}
				else
					return 1;//no hay jaque
			}
		}

	}
	case N_Comprobar_Jaques:
	{
		Tablero tablerocopiaN = _tablero;
		std::vector<Casilla> tabN;
		tabN = tablerocopiaN.getTablero();
		Jugador jdefcopia = _j2;
		Jugador jatcopia = _j1;
		std::vector<Pieza*> piezasjd = _j2.getPiezas();
		size_t cantpiezas = piezasjd.size();
		size_t tamtableroB = tabN.size();

		for (size_t i = 0; i < tamtableroB; i++) //recorremos todas las casillas
		{
			Vector2D posB{};
			//dom=cas.getOcupacion()
			dom = tabN[i].getOcupacion();
			if (dom == Dominio::Blanca)
			{
				posB = tabN[i].getPosicion();
				for (unsigned int k = 0; k < cantpiezas; k++)
				{
					Casilla* cas_pieza_copia = piezasjd[k]->getCasilla();
					Vector2D pos_cas_copia = cas_pieza_copia->getPosicion();
					if ((posB.x == pos_cas_copia.x) && (posB.y == pos_cas_copia.y)) //cuando encontra la pieza que coincide con esas coordenadas
						if (piezasjd[k]->getT_Pieza() == t_pieza::REY)//comprueba si se trata del rey
							jaque = tabN[k].getAmenaza();//si es rey, comprueba si esta amenazado, siendo true si lo está
				}
				if (jaque == true) //si se cumple, hará llamada a jaquemate
				{
					checkmate = jaquemate();
					if (checkmate == true)
						return 2; //hay jaque mate
					else
						return 3;//hay jaque

				}
				else
					return 1;//no hay jaque
			}
		}
	}
	case B_CompMov:
	{
		Tablero tablerocompB = _tablero;
		std::vector<Casilla> tabB;
		tabB = tablerocompB.getTablero();
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
	}
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
		if (pieza_selec > 0)
			pieza_selec--;
		break;
	}
	case 13:	//enter confirmar
	{
		if (_estado == B_Espera)
		{
			Vector2D indices = _j1.Movimiento(_tablero.getTableroConst(), pieza_selec);
			if (pieza_selec == 2)
			{
				pieza_selec = 0;
				_j2.BorrarPieza(_tablero.getTablero()[indices.y]);
				_j1.ActualizarMovimiento(indices, _tablero.getTablero());
				_estado = B_Mov;

			}
		}
		else if (_estado == N_Espera)
		{
			Vector2D indices = _j2.Movimiento(_tablero.getTableroConst(), pieza_selec);
			if (pieza_selec == 2)
			{

				_j1.BorrarPieza(_tablero.getTablero()[indices.y]);
				_j2.ActualizarMovimiento(indices, _tablero.getTablero());
				_estado = N_Mov;
				pieza_selec = 0;
			}
		}
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
		_j1.dibujar(Color::Blanco);
		_j2.dibujar(Color::Negro, 1);
	}
	else
	{
		_j1.dibujar(Color::Blanco);
		_j2.dibujar(Color::Negro);
	}
	//_tablero.dibujar();
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

