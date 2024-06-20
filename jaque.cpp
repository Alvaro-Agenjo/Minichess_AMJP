#include <Ajedrez.h>
//placeholder temporal para código de funcion jaque, que se ejecutará al inicio de cada turno
//quizas se convierta en metodo de ajedrez.ht

Ajedrez aj;
Tablero tablero;

bool jaquemate(Tablero t, Dominio coloramenazado, Dominio coloramenazando)
{
	std::vector<Casilla> copia; 
	copia = t.getTablero(); //copiamos el tablero para comprobar jaque mate
	return false;
};

int jaque(Tablero t, Dominio colordefensor, Dominio coloratacante)
{
	Casilla cas; //placeholder de la información de cada casilla que se observe en cada iteración del bucle for
	Dominio dom;	 //placeholder de la información del color ocupando la casilla
	bool jaque = false;
	std::vector<Casilla> tab;
	tab = t.getTablero();
	//obtenemos tamaño vector como entero sin signo
	unsigned int tamvector = tab.size();

	for (unsigned int i = 0; i < tamvector; i++) //recorremos todas las casillas
	{
		cas = tab[i];
		dom = cas.getOcupacion();
		if (dom == colordefensor)//si es del color que sufre el jaque, comprobamos si es el rey
		{
			//if (cas.esrey == true)
			//{
			//jaque=cas.getAmenaza();
			//}
			if (jaque == true)
			{
				bool checkmate;
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
