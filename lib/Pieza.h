#pragma once

#include "Vector2D.h"
#include"Tablero.h"
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
protected:

	Vector2D _posicion;												// coordenadas de la pieza
	Player _jugador;												// identificador pieza blanca o negra

	int _tpieza;                                                    // identificador del tipo de pieza
	static Tablero* _tab;
public:
	
	//Constructor - Destructor 
	Pieza(Vector2D pos, Player j);     //Constructor común a todas las piezas, inicializa posicion y pertenencia a jugador
	static void crearTablero(Tablero* t);
	
	//Getter 
	inline Vector2D getPosicion() const { return _posicion; };		//getter devuelve la posicion de la pieza fuera del ambito
	virtual int getTipoPieza() = 0;
	
	//Setter
	void almacenarPiezaMemoria();

	//Gráficos


	//Otros métodos 
	virtual void reglasMovimiento() = 0;
	bool validarCasilla(Vector2D coord);
	friend class Interaccion;
};

