#pragma once

#include "Vector2D.h"
/********************************************************************************************
*		librerias para realizar test, ser�n eliminadas al incorporar interfaz gr�fica		*
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


public:

	//Constructor - Destructor 
	Pieza(Vector2D pos, Player j);									//Constructor com�n a todas las piezas, inicializa posicion y pertenencia a jugador
	
	//Getter 
	inline Vector2D getPosicion() const { return _posicion; };		//getter devuelve la posicion de la pieza fuera del ambito
	
	
	//Setter


	//Gr�ficos


	//Otros m�todos 

	/****************************************************************
	*			Funciones test, visualizacion en consola			*
	****************************************************************/
protected:

	std::string _tpieza;													// variable creada �nicamente para la visualizacion por consola durante el desarrollo, sera eliminada cuando se incorpore la interfaz gr�fica

public:

	inline std::string getTipoPieza() { return _tpieza; };					//funcion creada �nicamente para la visualizacion por consola durante el desarrollo, sera eliminada cuando se incorpore la interfaz gr�fica
};

