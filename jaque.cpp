#include <Ajedrez.h>
//placeholder temporal para código de funcion jaque, que se ejecutará al inicio de cada turno
//quizas se convierta en metodo de ajedrez.ht

Ajedrez aj;
Tablero tablero;
//Jugador jdef;


bool jaquemate(Tablero t, Dominio coloramenazado, Dominio coloramenazando)
{
	Dominio color;
	Tablero copia_jaquemate=t;
	std::vector<Casilla> copy; 
	std::vector<Pieza> piezasdef;
	std::vector<Casilla> movimientospieza;
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
			//	cuando el movimiento esté hecho en el tablero fantasma, actualizamos amenazas y recorremos este para ver si el rey sigue amenazado
				//movimiento iteración
				bool jaque=true;
				
				int tamvector = copy.size();
				for (unsigned int k = 0; k < tamvector; k++) //recorremos todas las casillas
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
			}

		}

	}
	return false;
};

int jaque(Tablero t, Dominio colordefensor, Dominio coloratacante)
{
	//Casilla cas; ya que creo poder usar tab[i] lo dejo comentado a menos que lo acabe necesitando 
	Dominio dom;
	Tablero copia=t;//placeholder de la información del color ocupando la casilla
	bool jaque = false;
	bool checkmate=false;
	std::vector<Casilla> tab;
	tab = copia.getTablero();
	//obtenemos tamaño vector como entero sin signo
	unsigned int tamvector = tab.size();

	for (unsigned int i = 0; i < tamvector; i++) //recorremos todas las casillas
	{
		//dom=cas.getOcupacion()
		dom = tab[i].getOcupacion();
		if (dom == colordefensor)//si es del color que sufre el jaque, comprobamos si es el rey
		{
			//if (cas.esrey == true)
			//{
			//jaque=cas.getAmenaza(); o jaque=tab[i].getAmenaza();
			//}
			if (jaque == true)
			{
				
				checkmate = jaquemate(t, colordefensor, coloratacante);
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
