#pragma once

#include"Vector2D"
#include"Pieza"
#include <vector>
Class Jugador
{
private:
Vector2D _posición;
std::vector<Pieza*> _misPiezas{};
enum jugador ?

public:
	//Constructor 
	Jugador(Vector2D pos, enum jugador);
	//Getter 

	//Setter

	//Gráficos

	//Otros métodos 
	void Mover().     //Función para movimiento general,llamada a sub funciones.

	int Seleccionar_pieza(); //elige la casilla de inicio, devuelve la posición de la pieza elegida en el vector de piezas.
	void Mover pieza(int posPieza);
};