#pragma once
#pragma once
#include"Vector2D"
#include"Pieza"
#include <vector>
Class Jugador
{
private:
Vector2D _posici�n;
std::vector<Pieza*> _misPiezas{};
enum jugador ?

public:
	//Constructor 
	Jugador(Vector2D pos, enum jugador);
	//Getter 

	//Setter

	//Gr�ficos

	//Otros m�todos 
	Mover().     //Funci�n para movimiento general,llamada a sub funciones.

	int Seleccionar_pieza(); //elige la casilla de inicio, devuelve la posici�n de la pieza elegida en el vector de piezas.
	Mover pieza(int�posPieza);
};
