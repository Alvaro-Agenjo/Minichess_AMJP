#include <Ajedrez.h>
//placeholder temporal para código de funcion jaque, que se ejecutará al inicio de cada turno
//quizas se convierta en metodo de ajedrez.h
//variables temporales para simular input

bool turnoblanco;
bool turnonegro;
bool amenazado;
bool checkmate;
int anchotablero;
int altotablero;
bool coloramenazado;
bool coloramenazando;
Tablero tablero;
int jaque(Ajedrez a)
{
	if (turnoblanco == true)
	{
		for (int i = 0;i++;i <anchotablero)
		{
			/*
			if ((checktipo(i, j) == rey) && (checkcolor(i,j) == coloramenazado))//metodos de juego/ajedrez?
			{
				amenazado = checkamenaza(rey.i, rey.j, negro); //ponemos las coordenadas y el color que amenaza
				if (amenazado == true)
				{
					checkmate = jaquemate(tablero, coloramenazado,coloramenazando); //inputs: tablero para clonarlo, color amenazado, color amenazando
					if (jaquemate == true)
						return 2;
					if (jaquemate == false)
						return 3;
				}
				
				
			}
		*/
		}
	}
	return 1; //no amenazado
}
bool jaquemate(Tablero t, int coloramenazado, int coloramenazando)
{
	return 0;
};
