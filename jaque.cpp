#include <Ajedrez.h>
//placeholder temporal para código de funcion jaque, que se ejecutará al inicio de cada turno
//quizas se convierta en metodo de ajedrez.ht

Ajedrez aj;
Tablero tablero;
//Jugador jdef;


bool jaquemate(Tablero t, Dominio coloramenazado, Dominio coloramenazando, Jugador jam)
{
	Dominio color;
	Tablero copia_jaquemate=t;
	std::vector<Casilla> copy; 
	std::vector<Pieza> piezasdef;
	std::vector<Pieza> piezasat;
	std::vector<Casilla> movimientospieza;
	Jugador jamenazado_copia = jam;//copiamos jugador defensor
	copy = copia_jaquemate.getTablero();//copiamos el tablero para comprobar jaque mate
	//piezasdef = jdef.getPiezas; getter de vector piezas del jugador

	unsigned int vecsize = piezasdef.size();
	for (unsigned int i = 0; i < vecsize; i++) //recorremos todas las piezas del jugador
	{
		color = copy[i].getOcupacion();
		if (color == coloramenazado)
		{
			//movimientospieza=test.getposmov(); getter de vector posibles movimientos de la pieza
			unsigned int cantmov = movimientospieza.size();
			for (int j = 0; j < cantmov; j++)//con este bucle recorreremos los posibles movimientos de la pieza
			{
				//al principio de cada posible mov, hay que copiar el tablero real en uno fantasma
				Dominio dom;
			//... aquí tengo que hacer el movimiento elegido del vector
			// 
			// 
			// 
			//	cuando el movimiento esté hecho en el tablero fantasma, actualizamos amenazas y recorremos este para ver si el rey sigue amenazado
				//movimiento iteración
				bool jaque=true;
				
				int tamvector = copy.size();

				for (unsigned int i = 0; i < tamvector; i++) //recorremos todas las casillas
				{
					Vector2D pos_am{};
					//dom=cas.getOcupacion()
					dom = copy[i].getOcupacion();
					if (dom == coloramenazado)//si es del color que sufre el jaque, comprobamos si es el rey
					{
						pos_am = copy[i].getPosicion();
						std::vector<Pieza> piezasjam;
						//piezasjam= jdef_copia.getpiezas(); //getter de dirección vector de piezas del jugador copiado
						unsigned int cantpiezas = piezasjam.size();
						for (unsigned int k = 0; i < cantpiezas; k++)
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

int jaque(Tablero t, Dominio colordefensor, Dominio coloratacante, Jugador jde)
{
	//Casilla cas; ya que creo poder usar tab[i] lo dejo comentado a menos que lo acabe necesitando 
				Dominio dom;
				Tablero copia = t;
				Jugador jdef_copia = jde;//copiamos jugador defensor
				bool jaque = false;
				bool checkmate = false;
				std::vector<Casilla> tab;
				tab = copia.getTablero();
				std::vector<Pieza> piezasjd;
				unsigned int cantpiezas = piezasjd.size();
				//obtenemos tamaño vector como entero sin signo
				unsigned int tamvector = tab.size();

				for (unsigned int i = 0; i < tamvector; i++) //recorremos todas las casillas
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
							checkmate = jaquemate(t, colordefensor, coloratacante,jde);
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
