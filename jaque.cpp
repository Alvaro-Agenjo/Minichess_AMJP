#include <Ajedrez.h>
//placeholder temporal para código de funcion jaque, que se ejecutará al inicio de cada turno
//quizas se convierta en metodo de ajedrez.ht




bool jaquemate(Tablero t, Dominio coloramenazado, Dominio coloramenazando, Jugador jam, Jugador jat)
{
	Dominio color;
	Tablero copia_jaquemate=t;
	std::vector<Casilla> copy; 
	std::vector<Pieza*> piezasdef;
	std::vector<Pieza*> piezasat;
	std::vector<Casilla> movimientospieza;
	
	Jugador jamenazado_copia(jam,copia_jaquemate.getTablero());//copiamos jugador defensor
	Jugador jatacante_copia(jat, copia_jaquemate.getTablero()); //copiamos jugador atacante
		//copiamos el tablero para comprobar jaque mate
	piezasdef = jamenazado_copia.getPiezas(); //getter de vector piezas del jugador defensor
	piezasat = jatacante_copia.getPiezas();//" " " " " " atacante

	size_t vecsize = piezasdef.size();
	for (size_t i = 0; i < vecsize; i++) //recorremos todas las piezas del jugador
	{
		color = copia_jaquemate.getTablero()[i].getOcupacion();
		if (color == coloramenazado)
		{
			movimientospieza=piezasdef[i]->get_PosMov(); //getter de vector posibles movimientos de la pieza
			size_t cantmov = movimientospieza.size();
			for (size_t j = 0; j < cantmov; j++)//con este bucle recorreremos los posibles movimientos de la pieza
			{
				Vector2D posmovelegido;
				posmovelegido=movimientospieza[j].getPosicion();
				//al principio de cada posible mov, hay que copiar el tablero real en uno fantasma
			//... aquí tengo que hacer el movimiento elegido del vector
				Dominio dom;
			jamenazado_copia.ActualizarMovimiento(posmovelegido, copia_jaquemate.getTablero()); //como la posicion ya es adecuada al ser un pos mov, movemos la pieza ahi
			 //AHORA BUSCAMOS SI HABIA UNA PIEZA DEL OTRO COLOR EN LA CASILLA
				piezasat = jatacante_copia.getPiezas();
				 Casilla casat;
				 Casilla casat2;
				 const Casilla* dircasat=&casat;
				Vector2D posat;
				for (size_t k = 0; k < piezasat.size(); k++)
				{
					dircasat=piezasat[k]->getCasilla();
					casat2 = casat;
					posat = casat2.getPosicion();
					if((posat.x==posmovelegido.x)&&(posat.y==posmovelegido.y))
					jatacante_copia.BorrarPieza(casat);//borramos la pieza que haya del atacante en esa posicion si la hay
				}

			// 
			//	cuando el movimiento esté hecho en el jugador fantasma, lo utilizamos para actualizamar amenazas tablero copia y recorremos este para ver si el rey sigue amenazado
				copia_jaquemate.ClearAmenazas();
				jatacante_copia.ActualizarAmenazas(copia_jaquemate.getTablero()); //quitamos las amenazas previas y ponemos las actuales con el posible cambio por piezas comidas o bloqueos
			
			
			//movimiento iteración
				bool jaque=true;
				
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
						}
					}	//asi hacemos comprobacion de jaque sin volver a llamar a jaque maten en caso de true

						//CODIGO PREVIO, LO DEJO COMENTADO POR SI ACASO
				/*for (unsigned int k = 0; k < tamvector; k++) //recorremos todas las casillas
				{
					//dom=cas.getOcupacion()
					dom = copy[k].getOcupacion();
					if (dom == coloramenazado)//si es del color que sufre el jaque, comprobamos si es el rey
					{
						//if (cas.esrey == true)
						//{
						//jaque=cas.getAmenaza(); o jaque=tab[i].getAmenaza();
						//}
						if (jaque != true)
							return false; //en el caso que tras el movimiento deje de haber jaque al rey, no es jaque mate
					}
				}
				*/
				}
				
			}

		}

	}
	return false;
};

int jaque(Tablero t, Dominio colordefensor, Dominio coloratacante, Jugador jde, Jugador jat)
{
	//Casilla cas; ya que creo poder usar tab[i] lo dejo comentado a menos que lo acabe necesitando 
				Dominio dom;
				Tablero copia = t;
				Jugador jdef_copia = jde;//copiamos jugador defensor
				Jugador jat_copia = jat;//"" "" atacante
				bool jaque = false;
				bool checkmate = false;
				std::vector<Casilla> tab;
				tab = copia.getTablero();
				std::vector<Pieza> piezasjd;
				size_t cantpiezas = piezasjd.size();
				size_t tamvector = tab.size();

				for (size_t i = 0; i < tamvector; i++) //recorremos todas las casillas
				{
					Vector2D pos{};
					//dom=cas.getOcupacion()
					dom = tab[i].getOcupacion();
					if (dom == colordefensor)//si es del color que sufre el jaque, comprobamos si es el rey
					{
						pos = tab[i].getPosicion();
						//piezasjd= jdef_copia.getpiezas(); //getter de dirección vector de piezas del jugador copiado
						for (unsigned int k = 0; k < cantpiezas; k++)
						{//avanzamos
							Casilla* cas_pieza_copia = piezasjd[k].getCasilla();
							Vector2D pos_cas_copia = cas_pieza_copia->getPosicion();
							if ((pos.x == pos_cas_copia.x) && (pos.y == pos_cas_copia.y)) //cuando encontra la pieza que coincide con esas coordenadas
								if (piezasjd[k].getT_Pieza() == t_pieza::REY)//comprueba si se trata del rey
									jaque = tab[k].getAmenaza();//si es rey, comprueba si esta amenazado, siendo true si lo está
						}
						if (jaque == true) //si se cumple, hará llamada a jaquemate
						{
							checkmate = jaquemate(t, colordefensor, coloratacante,jde,jat);
							if (checkmate == true)
								return 2; //hay jaque mate
							else
								return 3;//hay jaque

						}
						else
							return 1;//no hay jaque
					}
				}
			};
