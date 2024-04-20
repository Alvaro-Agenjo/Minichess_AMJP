#pragma once

#include "Vector2D.h"
/********************************************************************************************
*		librerias para realizar test, serán eliminadas al incorporar interfaz gráfica		*
********************************************************************************************/
#include <iostream>



enum Player															//enumeracion que indica si la pieza es blanca o negra (pertenece al jugador 1 o 2)
{
	J1 = 1,
	J2
};

class Pieza
{
private:

	Vector2D _posicion;												// coordenadas de la pieza
	Player _jugador;												// identificador pieza blanca o negra
protected:
	int _tpieza;
public:

	//Constructor - Destructor 
	Pieza(Vector2D pos, Player j);									//Constructor común a todas las piezas, inicializa posicion y pertenencia a jugador
	
	//Getter 
	inline Vector2D getPosicion() const { return _posicion; };		//getter devuelve la posicion de la pieza fuera del ambito
	virtual int getTipoPieza() = 0;
	
	//Setter


	//Gráficos


	//Otros métodos 
	friend class Interaccion;
};

